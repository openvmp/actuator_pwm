/*
 * OpenVMP, 2022
 *
 * Author: Roman Kuzmenko
 * Created: 2023-04-05
 *
 * Licensed under Apache License, Version 2.0.
 */

#include "remote_actuator_pwm/node.hpp"

namespace remote_actuator_pwm {

Node::Node() : rclcpp::Node::Node("remote_actuator_pwm") {
  intf_ = std::make_shared<Implementation>(this);
}

}  // namespace remote_actuator_pwm
