/*----------------------------------------------------------------------------*/

/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */

/* Open Source Software - may be modified and shared by FRC teams. The code   */

/* must be accompanied by the FIRST BSD license file in the root directory of */

/* the project.                                                               */

/*----------------------------------------------------------------------------*/

#include <Drive/DifferentialDrive.h>
#include <IterativeRobot.h>
#include <Joystick.h>
#include <LiveWindow/LiveWindow.h>
#include <Spark.h>
#include <Timer.h>



class Robot : public frc::IterativeRobot {

	Spark *armspark;
	Spark *shovelspark;

public:

	Robot() {

		m_robotDrive.SetExpiration(0.1);
		m_timer.Start();
		armspark = new Spark(0);
		shovelspark = new Spark(1);
	}


	void AutonomousInit() override {
		m_timer.Reset();
		m_timer.Start();
	}

	void AutonomousPeriodic() override {
		// Drive for 2 seconds
		if (m_timer.Get() < 2.0) {
			// Drive forwards half speed
			m_robotDrive.ArcadeDrive(-0.5, 0.0);
		} else {
			// Stop robot
			m_robotDrive.ArcadeDrive(0.0, 0.0);
		}

	}


	void TeleopInit() override {}


	void TeleopPeriodic() override {
		// TOASTER BOT DRIVES
		m_robotDrive.ArcadeDrive(m_stick.GetY(), m_stick.GetX());

		//THINE ARM SHALL RAISE

		if ( m_stick.GetTrigger() == 1){
		// if trigger pressed, drive arm motor at hundredth speed
			armspark->Set((double)0.6);
		}
		else
		{	 if (m_stick.GetRawButton(3)== 1)
				{
				armspark->Set((double)-0.4);
				}
			else {
				armspark->Set((double)0.0);
				}//curly brace for button 3
		}//curly brace for Trigger


//SHOVEL TIME
		if (m_stick.GetRawButton(9)== 1)
		{//lower the shovel
			shovelspark->Set((double)-1.0);
		}

		else {
			if (m_stick.GetRawButton(10)== 1)
			{
						//raise the shovel
				shovelspark->Set((double)1.0);
			}
			else{
				shovelspark->Set((double)0.0);
			}//curly brace for button 10 else
		}//curly brace for button 9 else



	} //curly brace for teleop periodic DO NOT ERASE
	void TestPeriodic() override {}



private:

	// Robot drive system

	frc::Spark m_left{2};

	frc::Spark m_right{3};;

	frc::DifferentialDrive m_robotDrive{m_left, m_right};

	frc::Joystick m_stick{0};

	frc::LiveWindow& m_lw = *frc::LiveWindow::GetInstance();

	frc::Timer m_timer;

};



START_ROBOT_CLASS(Robot)
