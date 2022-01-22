#include <bits/stdc++.h>
#include <string>
using namespace std;

class RobotMultiSensors
{
	private:
	public:
		RobotMultiSensors() {}
		~RobotMultiSensors() {}
		float limit_vel_fusion(float inf_vel, float hum_vel, float lit_vel);
};

class InfraredSensor
{
	private:
	public:
		InfraredSensor() {}
		~InfraredSensor() {}
		float limit_vel(float distance);
};

class HumanSensor
{
	private:
	public:
		HumanSensor() {}
		~HumanSensor() {}
		float limit_vel(float distance);
};

class LightSensor
{
	private:
	public:
		LightSensor() {}
		~LightSensor() {}
		float limit_vel(float brightness);
};
