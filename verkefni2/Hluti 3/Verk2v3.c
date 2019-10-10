#pragma config(Sensor, in1,    leftLineFollower, sensorLineFollower)
#pragma config(Sensor, in2,    centerLineFollower, sensorLineFollower)
#pragma config(Sensor, in3,    rightLineFollower, sensorLineFollower)
#pragma config(Sensor, in4,    potentiometer,  sensorPotentiometer)
#pragma config(Sensor, in5,    lightSensor,    sensorReflection)
#pragma config(Sensor, in6,    gyro,           sensorGyro)
#pragma config(Sensor, in7,    accelerometer,  sensorAccelerometer)
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  armTouchSensor, sensorTouch)
#pragma config(Sensor, dgtl6,  touchSensor,    sensorTouch)
#pragma config(Sensor, dgtl8,  sonarSensor,    sensorSONAR_cm)
#pragma config(Sensor, dgtl11, armEncoder,     sensorQuadEncoder)
#pragma config(Motor,  port1,           leftMotor,     tmotorVex393, openLoop)
#pragma config(Motor,  port6,           clawMotor,     tmotorVex393, openLoop)
#pragma config(Motor,  port7,           armMotor,      tmotorVex393, openLoop)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex393, openLoop, reversed)


//==============================================
//= Forrit sem leysir thraut
//= keyrir ymist afram og til haegri eda vinstri
//= notar ummal hjols
//==============================================

#include "/includes/v2v3_functions.c";
bool b_f = true;

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{

	driveturn(BASE_TIME, true,degreesToTurn); 	// right
	for(int i= 0; i < 2; i++){
		driveturn(BASE_TIME, false,degreesToTurn); // left
	}
	for(int i = 0; i< 2;i++){
		driveturn(BASE_TIME, true,degreesToTurn); 	// right
	}
	driveturn(BASE_TIME, false,degreesToTurn); // left
	for(int i = 0; i< 2;i++){
		driveturn(BASE_TIME, true,degreesToTurn); 	// right
	}
	driveturn(BASE_TIME, false,degreesToTurn); // left
	for(int i = 0; i< 2;i++){
		driveturn(BASE_TIME, true,degreesToTurn); 	// right
	}
	for(int i= 0; i < 2; i++){
		driveturn(BASE_TIME, false,degreesToTurn); // left
	}
	driveturn(BASE_TIME, true,degreesToTurn); 	// right

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
