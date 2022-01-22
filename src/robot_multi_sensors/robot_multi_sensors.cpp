#include "robot_multi_sensors.h"

float RobotMultiSensors::limit_vel_fusion(float inf_vel, float hum_vel, float lit_vel)
{
	float limit_vel = min(inf_vel, hum_vel);
	limit_vel = min(limit_vel, lit_vel);
	return limit_vel;
}

float InfraredSensor::limit_vel(float distance)
{
	float limit_vel = (distance >= 0 && distance <= 0.3) ? 0.3 : 5.0;
	return limit_vel;
}

float HumanSensor::limit_vel(float distance)
{
	float limit_vel = (distance >= 0 && distance <= 0.5) ? 0.0 : 5.0;
	return limit_vel;
}

float LightSensor::limit_vel(float brightness)
{
	float limit_vel = (brightness >= 0 && brightness <= 10) ? 0.5 : 5.0;
	return limit_vel;
}
