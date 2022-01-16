#include <gtest/gtest.h>

#include "robot_distance.h"

TEST(RobotDistanceFail, Normal) {
	RobotDistance rd = RobotDistance();
	EXPECT_EQ("stop", rd.get_robot_state(45));
}
