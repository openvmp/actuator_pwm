/*
 * OpenVMP, 2023
 *
 * Author: Roman Kuzmenko
 * Created: 2023-04-01
 *
 * Licensed under Apache License, Version 2.0.
 */

#include "actuator_pwm/factory.hpp"

#include <exception>

#include "actuator_pwm/implementation.hpp"
#include "remote_actuator/interface_remote.hpp"

namespace actuator_pwm {

std::shared_ptr<remote_actuator::Interface> Factory::New(rclcpp::Node *node) {
  return std::make_shared<Implementation>(node);
}

}  // namespace actuator_pwm
