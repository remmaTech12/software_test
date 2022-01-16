#include <gtest/gtest.h>

#include "robot_distance.h"

TEST(RobotDistanceClass, Normal) {
	RobotDistance rd = RobotDistance();
	EXPECT_EQ("normal", rd.get_robot_state(45));
}

TEST(RobotDistanceClass, Slow) {
	RobotDistance rd = RobotDistance();
	EXPECT_EQ("slow", rd.get_robot_state(20));
}

TEST(RobotDistanceClass, Stop) {
	RobotDistance rd = RobotDistance();
	EXPECT_EQ("stop", rd.get_robot_state(5));
}

TEST(RobotDistanceClass, Error) {
	RobotDistance rd = RobotDistance();
	EXPECT_EQ("error", rd.get_robot_state(-5));
}
