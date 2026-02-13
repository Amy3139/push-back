#include "main.h"
#include "pros/motors.h"

void distance_with_oscillation(double hold_distance, double hold_time, double max_speed, double delta) {

    double kP = 0.8;
    // double delta = 25;  // mm to oscillate
    uint32_t oscillate_period = 500;  // ms per half cycle
    
    uint32_t elapsed = 0;
    uint32_t startTime = pros::millis();
    uint32_t last_toggle = startTime;
    bool moving_forward = true;
    
    // pros::lcd::print(6, "HD: %.1f, CD: %.1f, Elapsed: %.1f", hold_distance, distanceSensor.get(), elapsed);
    while (elapsed < hold_time) {

        // Toggle target distance every oscillate_period ms
        if (elapsed - (last_toggle - startTime) >= oscillate_period) {
            moving_forward = !moving_forward;
            last_toggle = pros::millis();
        }
        
        double target_distance = moving_forward ? hold_distance + delta : hold_distance - delta;
        double current = distanceSensor.get();

        if (current > 0) {  // valid reading

            double error = current - target_distance;
            double output = kP * error;
            double speed = output;

            if (fabs(error) < 5) speed = 0;

            if (speed > max_speed) speed = max_speed;
            else if (speed < -max_speed) speed = -max_speed;

            chassis.drive_set(speed, speed);

            // pros::lcd::print(5, "HD: %.1f, CD: %.1f, E: %.1f, O: %.1f, S: %.1f, in loop", hold_distance, current, error, output, speed);
            // pros::lcd::print(5, "D: %.1f, E: %.1f, O: %.1f, S: %.1f", current, error, output, speed);
        }

        pros::delay(20);
        elapsed = pros::millis() - startTime;
        // pros::lcd::print(6, "HD: %.1f, CD: %.1f, Elapsed: %.1f, in loop", hold_distance, current, elapsed);
        // pros::lcd::print(6, "Elapsed: %.1f, Distance: %.1f, in loop", elapsed, distanceSensor.get());
    }
}

void drive_to_distance(double distance, double max_time, double max_speed) {

    double kP = 0.8;
    double error_threshold = 5;  // mm
    uint32_t elapsed = 0;
    uint32_t startTime = pros::millis();
    double current = distanceSensor.get();
    
    // pros::lcd::print(6, "TD: %.1f, CD: %.1f, Elapsed: %.1f", distance, distanceSensor.get(), elapsed);
    while ((fabs(current - distance) > error_threshold) && (elapsed < max_time)) {
        current = distanceSensor.get();
        
        if (current > 0) {  // valid reading

            double error = current - distance;
            double output = kP * error;
            double speed = output;

            if (fabs(error) < error_threshold) speed = 0;

            if (speed > max_speed) speed = max_speed;
            else if (speed < -max_speed) speed = -max_speed;

            chassis.drive_set(speed, speed);

            // pros::lcd::print(5, "TD: %.1f, CD: %.1f, E: %.1f, O: %.1f, S: %.1f, in loop", distance, current, error, output, speed);
        }

        pros::delay(20);
        elapsed = pros::millis() - startTime;
        // pros::lcd::print(6, "TD: %.1f, CD: %.1f, Elapsed: %.1f, in loop", distance, current, elapsed);
        // pros::lcd::print(6, "Elapsed: %.1f, Distance: %.1f, in loop", elapsed, distanceSensor.get());
    }
}
