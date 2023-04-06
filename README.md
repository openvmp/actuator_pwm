# OpenVMP

[![License](./license.svg)](./LICENSE.txt)

This package is a part of [the OpenVMP project](https://github.com/openvmp/openvmp).
But it's designed to be universal and usable independently from the rest of OpenVMP or in a combination with select OpenVMP packages.

## ROS2 package for PWM-controlled actuators

This package can be used for any position or velocity controlled actuators
if their driver exposes an `std_msgs::msg::UInt16` subscriber.

The interfaces exposed by this package can be driven by `ros2_control` using [remote_hardware_interface](https://github.com/openvmp/remote_hardware_interface/).

Here is an example of producing a `ros2_control` compatible interface to a `simple_pwm` channel created by [remote_microcontroller](https://github.com/openvmp/microcontroller):

```bash
ros2 run actuator_pwm actuator_pwm_standalone --ros-args -p pwm_prefix:=/pwm0 -p pwm_min:=0 -p pwm_max:=255
```