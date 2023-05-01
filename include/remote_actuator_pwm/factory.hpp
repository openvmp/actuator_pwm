/*
 * OpenVMP, 2023
 *
 * Author: Roman Kuzmenko
 * Created: 2023-03-18
 *
 * Licensed under Apache License, Version 2.0.
 */

#ifndef OPENVMP_ACTUATOR_PWM_FACTORY_H
#define OPENVMP_ACTUATOR_PWM_FACTORY_H

#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "remote_actuator/interface.hpp"

namespace remote_actuator_pwm {

class Factory {
 public:
  static std::shared_ptr<remote_actuator::Interface> New(rclcpp::Node *node);
};

}  // namespace remote_actuator_pwm

#endif  // OPENVMP_ACTUATOR_PWM_FACTORY_H
