#include <Commands/FlywheelDecreaseSpeed.h>
#include "SmartDashboard/SmartDashboard.h"

FlywheelDecreaseSpeed::FlywheelDecreaseSpeed() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void FlywheelDecreaseSpeed::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void FlywheelDecreaseSpeed::Execute() {
	SmartDashboard::PutBoolean("Decreasing shooter speed", true);
	CommandBase::shooter->AdjustShooterSpeed(-20);
}

// Make this return true when this Command no longer needs to run execute()
bool FlywheelDecreaseSpeed::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void FlywheelDecreaseSpeed::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FlywheelDecreaseSpeed::Interrupted() {

}
