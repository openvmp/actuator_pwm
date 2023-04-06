/*
 * OpenVMP, 2022
 *
 * Author: Roman Kuzmenko
 * Created: 2023-04-05
 *
 * Licensed under Apache License, Version 2.0.
 */

#include "actuator_pwm/node.hpp"

namespace actuator_pwm {

Node::Node() : rclcpp::Node::Node("actuator_pwm") {
  intf_ = std::make_shared<Implementation>(this);
}

}  // namespace actuator_pwm
