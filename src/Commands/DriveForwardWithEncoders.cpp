#include "DriveForwardWithEncoders.h"

DriveForwardWithEncoders::DriveForwardWithEncoders() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::driveBase);
}

// Called just before this Command runs the first time
void DriveForwardWithEncoders::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveForwardWithEncoders::Execute() {
	driveBase->DriveForward(KRevsToBaseLine, KAutonStraightSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveForwardWithEncoders::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveForwardWithEncoders::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForwardWithEncoders::Interrupted() {

}
