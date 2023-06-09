/*
 * OpenVMP, 2022
 *
 * Author: Roman Kuzmenko
 * Created: 2023-04-05
 *
 * Licensed under Apache License, Version 2.0.
 */

#ifndef OPENVMP_ACTUATOR_PWM_NODE_H
#define OPENVMP_ACTUATOR_PWM_NODE_H

#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "remote_actuator_pwm/implementation.hpp"

namespace remote_actuator_pwm {

class Node : public rclcpp::Node {
 public:
  Node();

 private:
  std::shared_ptr<Implementation> intf_;
};

}  // namespace remote_actuator_pwm

#endif  // OPENVMP_ACTUATOR_PWM_NODE_H
