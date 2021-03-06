#include "..\Subsystems/Esophagus.h"
#include "ToggleEsophagus.h"

ToggleEsophagus::ToggleEsophagus() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
//	Requires(CommandBase::esophagus.get());
	Requires(CommandBase::esophagus);
}

// Called just before this Command runs the first time
void ToggleEsophagus::Initialize() {
//	Esophagus::MoveEsophagusToGearCollection();	//start out with it closed
}

// Called repeatedly when this Command is scheduled to run
void ToggleEsophagus::Execute()
{

	CommandBase::esophagus->ToggleEsophagus(); //Toggle Esophagus from closed to open

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleEsophagus::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ToggleEsophagus::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleEsophagus::Interrupted() {

}
