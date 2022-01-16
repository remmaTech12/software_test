#include "robot_distance.h"

string RobotDistance::get_robot_state(int dist) {
	string state = "normal";
	if (dist >= 30) state = "normal";
	else if (dist >= 10) state = "slow";
	else if (dist >= 0) state = "stop";
	else state = "error";

	return state;
}
