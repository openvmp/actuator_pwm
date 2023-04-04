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

  auto prefix = get_prefix_();
  topic_pwm_ = node->create_publisher<std_msgs::msg::Float64>(
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

  double value = 0.5 + (int)(0.5 * position / position_mod_);
  topic_pwm_->publish(std_msgs::msg::Float64().set__data(value));
}

void Implementation::velocity_set_real_(double velocity) {
  std::lock_guard<std::mutex> guard(param_maxmin_lock_);

  double value = 0.5 + (int)(0.5 * velocity / velocity_mod_);
  topic_pwm_->publish(std_msgs::msg::Float64().set__data(value));
}

}  // namespace actuator_pwm
