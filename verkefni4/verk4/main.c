
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
#pragma config(Sensor, dgtl9,  sonarSensor,    sensorSONAR_cm)
#pragma config(Sensor, dgtl11, armEncoder,     sensorQuadEncoder)
#pragma config(Motor,  port1,           leftMotor,     tmotorVex393, openLoop)
#pragma config(Motor,  port6,           clawMotor,     tmotorVex393, openLoop)
#pragma config(Motor,  port7,           armMotor,      tmotorVex393, openLoop)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex393, openLoop, reversed)

#include "../verk4/tasks.c"

task main()
{
StartTask(drive);
StartTask(stopTasks);
while(1==1){}
}
