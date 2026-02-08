#pragma once

// Speed constants (out of 127) - can be used across multiple files
extern const int DRIVE_SPEED;
extern const int TURN_SPEED;
extern const int SWING_SPEED;

void default_constants();

// Our Autonomous test functions
void test();

// Our Autonomous functions
void awp_right_1();
void awp_right_2();
void awp_left_1();
void awp_left_2();
void awp_left_3();
void skills_1();
void skills_2();

// Autonomous function examples from EZ-Template. Keeping as reference.
void drive_example();
void turn_example();
void drive_and_turn();
void wait_until_change_speed();
void swing_example();
void motion_chaining();
void combining_movements();
void interfered_example();
void odom_drive_example();
void odom_pure_pursuit_example();
void odom_pure_pursuit_wait_until_example();
void odom_boomerang_example();
void odom_boomerang_injected_pure_pursuit_example();
void measure_offsets();