#include "../include/state_manager.h"

void StateManager::push_arm_button() {
  if (state_ == unarmed)
  {
    state_ = armed;
  }
}

void StateManager::push_disarm_button() {
  if (state_ == armed)
  {
    state_ = unarmed;
  }
}

void StateManager::push_hover_button() {
  if (state_ == armed || state_ == go_destination)
  {
    state_ = hovering;
  }
}

void StateManager::push_go_destination_button() {
  if ((state_ == armed || state_ == hovering) && destination_ != "")
  {
    state_ = go_destination;
  }
}

void StateManager::push_stop_button() {
  if (state_ == hovering || state_ == go_destination)
  {
    state_ = landing;
  }
}

void StateManager::check_sensory_measurement() {
  if ((state_ == hovering || state_ == go_destination) &&
      is_sensory_measurement_invalid_)
  {
    state_ = landing;
  }
}

void StateManager::check_position() {
  if (state_ == go_destination && (position_ == destination_))
  {
    state_ = hovering;
  }
}

void StateManager::check_touch_ground() {
  if (state_ == landing && is_touch_ground_)
  {
    state_ = armed;
  }
}
