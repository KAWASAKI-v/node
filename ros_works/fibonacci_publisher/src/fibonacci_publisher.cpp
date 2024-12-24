#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int64.hpp>

class FibonacciPublisher : public rclcpp::Node {
public:
    FibonacciPublisher() : Node("fibonacci_publisher"), prev_(0), curr_(1) {
        // Создаем Publisher
        publisher_ = this->create_publisher<std_msgs::msg::Int64>("fibonacci_sequence", 10);
        // Запускаем таймер с частотой 1 раз в секунду
        timer_ = this->create_wall_timer(
            std::chrono::seconds(1), 
            std::bind(&FibonacciPublisher::publish_next_number, this)
        );
    }

private:
    void publish_next_number() {
        auto message = std_msgs::msg::Int64();
        message.data = prev_;  // Публикуем текущее значение
        RCLCPP_INFO(this->get_logger(), "Publishing: %ld", message.data);

        publisher_->publish(message);

        // Обновляем числа Фибоначчи
        auto next = prev_ + curr_;
        prev_ = curr_;
        curr_ = next;
    }

    rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    int64_t prev_, curr_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<FibonacciPublisher>());
    rclcpp::shutdown();
    return 0;
}
