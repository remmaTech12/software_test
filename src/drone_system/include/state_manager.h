#include <bits/stdc++.h>
#include <string>

enum State {
  armed,
  unarmed,
  hovering,
  go_destination,
  landing
};

class StateManager
{
	private:
    State state_ = unarmed;

    std::string destination_ = "";
    std::string position_ = "";

    bool is_sensory_measurement_invalid_ = false;
    bool is_touch_ground_ = false;

	public:
		StateManager() {}
    State get_state() { return state_; }
    State set_state(State state) { state_ = state; }

    // E1: Arm
    void push_arm_button();

    // E2: Disarm
    void push_disarm_button();

    // E3: Push hover button
    void push_hover_button();

    // E4: Push go_destination button
    void set_destination(std::string destination) { destination_ = destination; };
    void push_go_destination_button();

    // E5: Push stop button
    void push_stop_button();

    // E6: Detect invalid sensory measurement
    void set_invalid_sensory_measurement_flag(bool flag) {
      is_sensory_measurement_invalid_ = flag;
    };
    void check_sensory_measurement();

    // E7: Reach the destination
    void set_position(std::string position) { position_ = position; };
    void check_position();

    // E8: Landing finish
    void set_touch_ground_flag(bool flag) { is_touch_ground_ = flag; };
    void check_touch_ground();
};
