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
public class DartSubsystem extends Subsystem {
  // Put methods for controlling this subsystem
  // here. Call these from Commands.
  public Spark leftDart = new Spark(RobotMap.leftDartMotorPort);
  public Spark rightDart = new Spark(RobotMap.rightDartMotorPort);

  SpeedControllerGroup dartMotorGroup = new SpeedControllerGroup(leftDart, rightDart);
  public DifferentialDrive drive = new DifferentialDrive(leftDart, rightDart);
  

  public void dartMove(double move) {

    if (Math.abs(move) < 0.10) {				
      move = 0;
    }
    leftDart.set(move);
    rightDart.set(move);
    // drive.arcadeDrive(move, 0);
  }

  @Override
  public void initDefaultCommand() {
    // Set the default command for a subsystem here.
    // setDefaultCommand(new MySpecialCommand());
  }
}
