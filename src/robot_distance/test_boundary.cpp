#include <gtest/gtest.h>

#include "robot_distance.h"

TEST(RobotDistanceBoundary, NormalLower) {
	RobotDistance rd = RobotDistance();
	EXPECT_EQ("normal", rd.get_robot_state(30));
}

TEST(RobotDistanceBoundary, NormalLowerPlusOne) {
	RobotDistance rd = RobotDistance();
	EXPECT_EQ("normal", rd.get_robot_state(31));
}

TEST(RobotDistanceBoundary, NormalLowerMinusOne) {
	RobotDistance rd = RobotDistance();
	EXPECT_EQ("slow", rd.get_robot_state(29));
}

TEST(RobotDistanceBoundary, SlowUpperMinusOne) {
	RobotDistance rd = RobotDistance();
	EXPECT_EQ("slow", rd.get_robot_state(28));
}

TEST(RobotDistanceBoundary, SlowLower) {
	RobotDistance rd = RobotDistance();
	EXPECT_EQ("slow", rd.get_robot_state(10));
}

TEST(RobotDistanceBoundary, SlowLowerPlusOne) {
	RobotDistance rd = RobotDistance();
	EXPECT_EQ("slow", rd.get_robot_state(11));
}

TEST(RobotDistanceBoundary, SlowLowerMinusOne) {
	RobotDistance rd = RobotDistance();
	EXPECT_EQ("stop", rd.get_robot_state(9));
}

TEST(RobotDistanceBoundary, StopUpperMinusOne) {
	RobotDistance rd = RobotDistance();
	EXPECT_EQ("stop", rd.get_robot_state(8));
}

TEST(RobotDistanceBoundary, StopLower) {
	RobotDistance rd = RobotDistance();
	EXPECT_EQ("stop", rd.get_robot_state(0));
}

TEST(RobotDistanceBoundary, StopLowerPlusOne) {
	RobotDistance rd = RobotDistance();
	EXPECT_EQ("stop", rd.get_robot_state(1));
}

TEST(RobotDistanceBoundary, StopLowerMinusOne) {
	RobotDistance rd = RobotDistance();
	EXPECT_EQ("error", rd.get_robot_state(-1));
}

TEST(RobotDistanceBoundary, ErrorUpperMinusOne) {
	RobotDistance rd = RobotDistance();
	EXPECT_EQ("error", rd.get_robot_state(-2));
}
