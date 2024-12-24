#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int64.hpp>

class FibonacciSubscriber : public rclcpp::Node {
public:
    FibonacciSubscriber() : Node("fibonacci_subscriber") {
        subscription_ = this->create_subscription<std_msgs::msg::Int64>(
            "fibonacci_topic",
            10,
            std::bind(&FibonacciSubscriber::topic_callback, this, std::placeholders::_1)
        );
        RCLCPP_INFO(this->get_logger(), "Fibonacci subscriber node has started.");
    }

private:
    void topic_callback(const std_msgs::msg::Int64::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "Received: %ld", msg->data);
    }

    rclcpp::Subscription<std_msgs::msg::Int64>::SharedPtr subscription_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<FibonacciSubscriber>());
    rclcpp::shutdown();
    return 0;
}

