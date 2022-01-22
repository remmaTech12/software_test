#include <gtest/gtest.h>

#include "robot_multi_sensors.h"

RobotMultiSensors rms = RobotMultiSensors();
InfraredSensor is = InfraredSensor();
HumanSensor hs = HumanSensor();
LightSensor ls = LightSensor();

TEST(RobotMultiSensorsDecisionTableTest, rule1) {
	float i_dist = 0.1; float h_dist = 0.1; float l_bright = 1;
	float i_lv = is.limit_vel(i_dist);
	float h_lv = hs.limit_vel(h_dist);
	float l_lv = ls.limit_vel(l_bright);

	double expected_lv = 0.0;
	EXPECT_FLOAT_EQ(expected_lv, rms.limit_vel_fusion(i_lv, h_lv, l_lv));
}

TEST(RobotMultiSensorsDecisionTableTest, rule2) {
	float i_dist = 0.1; float h_dist = 0.3; float l_bright = 15;
	float i_lv = is.limit_vel(i_dist);
	float h_lv = hs.limit_vel(h_dist);
	float l_lv = ls.limit_vel(l_bright);

	double expected_lv = 0.0;
	EXPECT_FLOAT_EQ(expected_lv, rms.limit_vel_fusion(i_lv, h_lv, l_lv));
}

TEST(RobotMultiSensorsDecisionTableTest, rule3) {
	float i_dist = 0.08; float h_dist = 1.0; float l_bright = 1;
	float i_lv = is.limit_vel(i_dist);
	float h_lv = hs.limit_vel(h_dist);
	float l_lv = ls.limit_vel(l_bright);

	double expected_lv = 0.3;
	EXPECT_FLOAT_EQ(expected_lv, rms.limit_vel_fusion(i_lv, h_lv, l_lv));
}

TEST(RobotMultiSensorsDecisionTableTest, rule4) {
	float i_dist = 0.1; float h_dist = 1.0; float l_bright = 20;
	float i_lv = is.limit_vel(i_dist);
	float h_lv = hs.limit_vel(h_dist);
	float l_lv = ls.limit_vel(l_bright);

	double expected_lv = 0.3;
	EXPECT_FLOAT_EQ(expected_lv, rms.limit_vel_fusion(i_lv, h_lv, l_lv));
}

TEST(RobotMultiSensorsDecisionTableTest, rule5) {
	float i_dist = 0.5; float h_dist = 0.2; float l_bright = 7;
	float i_lv = is.limit_vel(i_dist);
	float h_lv = hs.limit_vel(h_dist);
	float l_lv = ls.limit_vel(l_bright);

	double expected_lv = 0.0;
	EXPECT_FLOAT_EQ(expected_lv, rms.limit_vel_fusion(i_lv, h_lv, l_lv));
}

TEST(RobotMultiSensorsDecisionTableTest, rule6) {
	float i_dist = 0.5; float h_dist = 0.2; float l_bright = 18;
	float i_lv = is.limit_vel(i_dist);
	float h_lv = hs.limit_vel(h_dist);
	float l_lv = ls.limit_vel(l_bright);

	double expected_lv = 0.0;
	EXPECT_FLOAT_EQ(expected_lv, rms.limit_vel_fusion(i_lv, h_lv, l_lv));
}

TEST(RobotMultiSensorsDecisionTableTest, rule7) {
	float i_dist = 0.5; float h_dist = 1.2; float l_bright = 6;
	float i_lv = is.limit_vel(i_dist);
	float h_lv = hs.limit_vel(h_dist);
	float l_lv = ls.limit_vel(l_bright);

	double expected_lv = 0.5;
	EXPECT_FLOAT_EQ(expected_lv, rms.limit_vel_fusion(i_lv, h_lv, l_lv));
}

TEST(RobotMultiSensorsDecisionTableTest, rule8) {
	float i_dist = 0.7; float h_dist = 0.7; float l_bright = 70;
	float i_lv = is.limit_vel(i_dist);
	float h_lv = hs.limit_vel(h_dist);
	float l_lv = ls.limit_vel(l_bright);

	double expected_lv = 5.0;
	EXPECT_FLOAT_EQ(expected_lv, rms.limit_vel_fusion(i_lv, h_lv, l_lv));
}
