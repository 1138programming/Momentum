#include <memory>

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>


#include "CommandBase.h"
#include "Commands/AutonCommandGroup.h"
#include "Commands/TurnToFacePilotTower.h"
#include "Commands/MoveBackwardWithEncoders.h"
#include "Commands/AutonomousLineDrive.h"
#include "Commands/AutonomousCenterGear.h"
//#include "Commands/AutonomousRightGear.h"
#include "Commands/AutonomousRightSide.h"
//#include "Commands/AutonomousLeftGear.h"
#include "Commands/AutonomousLeftSide.h"

class Robot: public frc::IterativeRobot {

public:
	void RobotInit() override {
		CommandBase::init();
		CameraServer::GetInstance()->StartAutomaticCapture();

		chooser.AddObject("Cross The Line", new AutonomousLineDrive());
//		chooser.AddObject("Left Gear Autonomous", new AutonomousLeftGear());
		chooser.AddObject("Left Gear Autonomous", new AutonomousLeftSide());
		chooser.AddDefault("Center Gear Autonomous", new AutonomousCenterGear());
//		chooser.AddObject("Right Gear Autonomous", new AutonomousRightGear());
		chooser.AddObject("Right Gear Autonomous", new AutonomousRightSide());
		chooser.AddObject("No Autonomous", NULL);
		SmartDashboard::PutData("Auto Modes", &chooser);

	}

	/**
	 * This function is called once each time the robot enters Disabled mode.
	 * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
	 */
	void DisabledInit() override {

	}

	void DisabledPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString code to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional commands to the
	 * chooser code above (like the commented example) or additional comparisons
	 * to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit() override {
		/* std::string autoSelected = frc::SmartDashboard::GetString("Auto Selector", "Default");
		if (autoSelected == "My Auto") {
			autonomousCommand.reset(new MyAutoCommand());
		}
		else {
			autonomousCommand.reset(new Command());
		} */

		autonomousCommand.reset(chooser.GetSelected());

		if (autonomousCommand.get() != nullptr)
		{
			SmartDashboard::PutBoolean("Start Auton", true);
			autonomousCommand->Start();
		}
	}

	void AutonomousPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	void TeleopInit() override {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != nullptr) {
			autonomousCommand->Cancel();
		}
	}

	void TeleopPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	void TestPeriodic() override {
		frc::LiveWindow::GetInstance()->Run();
	}

private:
	std::unique_ptr<frc::Command> autonomousCommand;
	frc::SendableChooser<frc::Command*> chooser;
};

START_ROBOT_CLASS(Robot)
