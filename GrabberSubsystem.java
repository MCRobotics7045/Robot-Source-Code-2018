/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

package frc.robot.subsystems;
import edu.wpi.first.wpilibj.*;
import edu.wpi.first.wpilibj.command.Subsystem;
import edu.wpi.first.wpilibj.drive.DifferentialDrive;
import frc.robot.RobotMap;


/**
 * Add your docs here.
 */
public class GrabberSubsystem extends Subsystem {
  // Put methods for controlling this subsystem
  // here. Call these from Commands.
  public Spark leftGrab = new Spark(RobotMap.leftGrabMotorPort);
  public Spark rightGrab = new Spark(RobotMap.rightGrabMotorPort);

  public DifferentialDrive drive = new DifferentialDrive(leftGrab, rightGrab);
  

  public void grabDrive(double move) {

    if (Math.abs(move) < 0.10) {				
      move = 0;
    }
    

    drive.arcadeDrive(move, 0.0);

  }

  public void shootDrive(double move) {

    if (Math.abs(move) < 0.10) {				
      move = 0;
    }
    

    drive.arcadeDrive(move, 0.0);

  }


  @Override
  public void initDefaultCommand() {
    // Set the default command for a subsystem here.
    // setDefaultCommand(new MySpecialCommand());
  }
}
