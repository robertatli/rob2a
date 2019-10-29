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
#pragma config(Motor,  port5,           clawMotor,     tmotorVex393, openLoop)
#pragma config(Motor,  port6,           armMotor,      tmotorVex269, openLoop)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex393, openLoop, reversed)

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	while(1==1){

		motor[leftMotor]  = (vexRT[Ch2] + vexRT[Ch1])/2;  // (y + x)/2
		motor[rightMotor] = (vexRT[Ch2] - vexRT[Ch1])/2;  // (y - x)/2
		motor[armMotor] = vexRT[Ch3];
		if(vexRT[Btn5U]==1){
			motor[armMotor]=127;
		}
		else if(vexRT[Btn6U]==1){
			motor[clawMotor]=-127;
		}
		else{
			motor[clawMotor]=0;
		}
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
