#include <gtest/gtest.h>

#include "../include/state_manager.h"

TEST(StateManagerTransition, 1_Arm) {
  StateManager sm = StateManager();
  sm.set_state(unarmed);
  sm.push_arm_button();

	EXPECT_EQ(armed, sm.get_state());
}

TEST(StateManagerTransition, 2_Disarm) {
  StateManager sm = StateManager();
  sm.set_state(armed);
  sm.push_disarm_button();

	EXPECT_EQ(unarmed, sm.get_state());
}

TEST(StateManagerTransition, 3_PushHoverButton) {
  StateManager sm = StateManager();
  sm.set_state(armed);
  sm.push_hover_button();

	EXPECT_EQ(hovering, sm.get_state());
}

TEST(StateManagerTransition, 4_PushGoDestinationButton) {
  StateManager sm = StateManager();
  sm.set_state(armed);
  sm.set_destination("area_a");
  sm.push_go_destination_button();

	EXPECT_EQ(go_destination, sm.get_state());
}

TEST(StateManagerTransition, 5_PushGoDestinationButton) {
  StateManager sm = StateManager();
  sm.set_state(hovering);
  sm.set_destination("area_a");
  sm.push_go_destination_button();

	EXPECT_EQ(go_destination, sm.get_state());
}

TEST(StateManagerTransition, 6_PushStopButton) {
  StateManager sm = StateManager();
  sm.set_state(hovering);
  sm.push_stop_button();

	EXPECT_EQ(landing, sm.get_state());
}

TEST(StateManagerTransition, 7_DetectInvalidSensoryMeasurement) {
  StateManager sm = StateManager();
  sm.set_state(hovering);
  sm.set_invalid_sensory_measurement_flag(true);
  sm.check_sensory_measurement();

	EXPECT_EQ(landing, sm.get_state());
}

TEST(StateManagerTransition, 8_PushHoverButton) {
  StateManager sm = StateManager();
  sm.set_state(go_destination);
  sm.push_hover_button();

	EXPECT_EQ(hovering, sm.get_state());
}

TEST(StateManagerTransition, 9_PushStopButton) {
  StateManager sm = StateManager();
  sm.set_state(go_destination);
  sm.push_stop_button();

	EXPECT_EQ(landing, sm.get_state());
}

TEST(StateManagerTransition, 10_DetectInvalidSensoryMeasurement) {
  StateManager sm = StateManager();
  sm.set_state(go_destination);
  sm.set_invalid_sensory_measurement_flag(true);
  sm.check_sensory_measurement();

	EXPECT_EQ(landing, sm.get_state());
}

TEST(StateManagerTransition, 11_ReachTheDestination) {
  StateManager sm = StateManager();
  sm.set_destination("area_b");
  sm.set_state(go_destination);
  sm.set_position("area_b");
  sm.check_position();

	EXPECT_EQ(hovering, sm.get_state());
}

TEST(StateManagerTransition, 12_LandingFinish) {
  StateManager sm = StateManager();
  sm.set_state(landing);
  sm.set_touch_ground_flag(true);
  sm.check_touch_ground();

	EXPECT_EQ(armed, sm.get_state());
}
