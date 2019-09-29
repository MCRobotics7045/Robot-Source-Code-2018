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
import frc.robot.commands.DriveManuallyCommand;

/**
 * Add your docs here.
 */
public class DriveSubsystem extends Subsystem {
  // Put methods for controlling this subsystem
  // here. Call these from Commands.

  // instantiate new motor controller objects
  public Spark leftFront = new Spark(RobotMap.leftFrontMotorPort);
  public Spark leftRear = new Spark(RobotMap.leftRearMotorPort);
  public Spark rightFront = new Spark(RobotMap.rightFrontMotorPort);
  public Spark rightRear = new Spark (RobotMap.rigthRearMotorPort);

  SpeedControllerGroup leftMotorGroup = new SpeedControllerGroup(leftFront, leftRear); 
  SpeedControllerGroup rightMotorGroup = new SpeedControllerGroup(rightFront, rightRear); 


  public DifferentialDrive drive = new DifferentialDrive(leftMotorGroup, rightMotorGroup);
  //public DifferentialDrive drive = new DifferentialDrive(leftFront, rightFront);

  public void manualDrive(double move, double turn) {
    double moveAdjust = 0.9;
    double turnAdjust = 0.9;

    move = move * moveAdjust;
    turn = turn * turnAdjust;
    
    if (Math.abs(move) < 0.10) {				
      move = 0;
    }
    if (Math.abs(turn) < 0.10) {
      turn = 0;
    }

    drive.arcadeDrive(move, turn);

  }

  @Override
  public void initDefaultCommand() {
    // Set the default command for a subsystem here.
    // setDefaultCommand(new MySpecialCommand());
    setDefaultCommand(new DriveManuallyCommand());
  }
}
