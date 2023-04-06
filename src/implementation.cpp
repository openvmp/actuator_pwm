/*
 * OpenVMP, 2022
 *
 * Author: Roman Kuzmenko
 * Created: 2023-04-01
 *
 * Licensed under Apache License, Version 2.0.
 */

#include "actuator_pwm/implementation.hpp"

namespace actuator_pwm {

Implementation::Implementation(rclcpp::Node *node)
    : remote_actuator::Implementation(node) {
  RCLCPP_DEBUG(node_->get_logger(),
               "Implementation::Implementation(): started");

  node->declare_parameter("pwm_type", "velocity");
  node->get_parameter("pwm_type", param_pwm_type_);

  node->declare_parameter(
      "pwm_path",
      std::string("/actuator/") + std::string(node_->get_name()) + "/pwm");
  node->get_parameter("pwm_path", param_pwm_path_);

  node->declare_parameter("pwm_min", 0);
  node->get_parameter("pwm_min", param_pwm_min_);
  node->declare_parameter("pwm_max", 255);
  node->get_parameter("pwm_max", param_pwm_max_);
  pwm_min_ = param_pwm_min_.as_int();
  pwm_max_ = param_pwm_max_.as_int();
  // TODO(clairbee): create a parameter event handler to update the limits

  auto prefix = get_prefix_();
  topic_pwm_ = node->create_publisher<std_msgs::msg::UInt16>(
      prefix + param_pwm_path_.as_string(), 1);

  RCLCPP_DEBUG(node_->get_logger(), "Implementation::Implementation(): ended");
}

bool Implementation::has_position() {
  return param_pwm_type_.as_string() == "position";
}

bool Implementation::has_velocity() {
  return param_pwm_type_.as_string() == "velocity";
}

void Implementation::position_set_real_(double position) {
  std::lock_guard<std::mutex> guard(param_maxmin_lock_);

  position -= position_min_;
  position /= position_max_ - position_min_;
  // position is now remaped from [min;max] to [0;1]

  uint16_t value = pwm_min_ + position * (pwm_max_ - pwm_min_);
  topic_pwm_->publish(std_msgs::msg::UInt16().set__data(value));
}

void Implementation::velocity_set_real_(double velocity) {
  std::lock_guard<std::mutex> guard(param_maxmin_lock_);

  velocity -= velocity_min_;
  velocity /= velocity_max_ - velocity_min_;
  // velocity is now remaped from [min;max] to [0;1]

  uint16_t value = pwm_min_ + velocity * (pwm_max_ - pwm_min_);
  topic_pwm_->publish(std_msgs::msg::UInt16().set__data(value));
}

}  // namespace actuator_pwm
