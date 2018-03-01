
#include <Drive/DifferentialDrive.h>
#include <IterativeRobot.h>
#include <Joystick.h>
#include <LiveWindow/LiveWindow.h>
#include <Spark.h>
#include <Timer.h>



class Robot : public frc::IterativeRobot {

	Spark *flipspark;
	Spark *liftspark;

public:

	Robot() {

		m_robotDrive.SetExpiration(0.1);
		m_timer.Start();
		flipspark = new Spark(0);
		liftspark = new Spark(1);
		//set safeties on the arm motors so they don't burn out
		flipspark->SetSafetyEnabled(true);
		liftspark->SetSafetyEnabled(true);
		flipspark->SetExpiration(10);
		liftspark->SetExpiration(10);
	}


	void AutonomousInit() override {
		m_timer.Reset();
		m_timer.Start();
	}

	void AutonomousPeriodic() override {
		// Drive for 2 seconds
		if (m_timer.Get() < 5.0) {
			// Drive forwards half speed
			m_robotDrive.ArcadeDrive(-0.5, 0.0);
		} else 
		{	if(5.0 < m_timer.Get() < 9.0) {
			 // Stop robot
			m_robotDrive.ArcadeDrive(0.0, 0.0);
			//run motor to flip up arm
			flipspark->Set((double)0.6);
			}/* timer nine seconds curly brace */ else 
			{	if (9.0 < m_timer.Get() < 9.2) {
				//drive backwards to fell arm
				flipspark->Set((double)0.0);
				liftspark->Set((double)0.3);
				m_robotDrive.ArcadeDrive(0.5, 0.0);
				} else
				{ //stop the robot, hopefully ahead of the auto line
				   m_robotDrive.ArcadeDrive(0.0, 0.0)
				}// the last curly brace in this forsaken auto code I SWEAR
			 
			
		}//drive forward end curly brace

	}


	void TeleopInit() override {}


	void TeleopPeriodic() override {
		// TOASTER BOT DRIVES
		m_robotDrive.ArcadeDrive(m_stick.GetY(), m_stick.GetX());

		//THINE ARM SHALL RAISE BUT LIKE WE ALREADY FLIPPED OUT ba-dum tiss! puns are 30% of my personality guys
		
		if ( m_stick.GetTrigger() == 1){
		// if trigger pressed, drive arm motor at mild speed
			flipspark->Set((double)0.6);
		}
		else
		{	 if (m_stick.GetRawButton(3)== 1)
				{
				flipspark->Set((double)-0.4);
				}
			else {
				flipspark->Set((double)0.0);
				}//curly brace for button 3
		}//curly brace for Trigger


//lift TIME
		if (m_stick.GetRawButton(9)== 1)
		{//lower the arm
			liftspark->Set((double)-1.0);
		}

		else {
			if (m_stick.GetRawButton(10)== 1)
			{
						//raise the arm, hopefully with power cubicle
				liftspark->Set((double)1.0);
			}
			else{
				liftspark->Set((double)0.0);
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
