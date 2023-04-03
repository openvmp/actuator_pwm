/*
 * OpenVMP, 2022
 *
 * Author: Roman Kuzmenko
 * Created: 2023-04-01
 *
 * Licensed under Apache License, Version 2.0.
 */

#ifndef OPENVMP_ACTUATOR_PWM_IMPLEMENTATION_H
#define OPENVMP_ACTUATOR_PWM_IMPLEMENTATION_H

#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "remote_actuator/implementation.hpp"
#include "std_msgs/msg/float64.hpp"

namespace actuator_pwm {

class Node;

class Implementation : public remote_actuator::Implementation {
 public:
  Implementation(rclcpp::Node *node);
  virtual ~Implementation() {}

  virtual bool has_position() override;
  virtual bool has_velocity() override;

 protected:
  rclcpp::Parameter param_pwm_type_;
  rclcpp::Parameter param_pwm_path_;

  virtual void position_set_real_(double velocity) override;
  virtual void velocity_set_real_(double velocity) override;

 private:
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr topic_pwm_;
};

}  // namespace actuator_pwm

#endif  // OPENVMP_ACTUATOR_PWM_IMPLEMENTATION_H
