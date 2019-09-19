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

const int full_power=30;
const int WHEELBASE1 = 3;
const int TURNCONST = 2;

void drive(int dist, bool bf)
{
	while(abs(SensorValue[leftEncoder]) < (dist/WHEELBASE1)*360){
	if(bf)
	{
		motor[rightMotor] = full_power;
		motor[leftMotor]  = full_power;
	}
	else
	{
		motor[rightMotor] = -full_power;
		motor[leftMotor]  = -full_power;
	}
	}
}

void resetEncoder()
{
	SensorValue[leftEncoder]=0;
	SensorValue[rightEncoder]=0;
}

void stopMotors()
{
	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
}

void turn(int deg, bool left_right)
{
	//int encoder = (abs(SensorValue[leftEncoder])+ abs(SensorValue[rightEncoder]))/2;
	while(abs(SensorValue[leftEncoder]) < deg*TURNCONST)
		{
			if(left_right)
			{
				motor[rightMotor] = full_power;
				motor[leftMotor]  = -full_power;
			}
			else
			{
				motor[rightMotor] = -full_power;
				motor[leftMotor]  = full_power;
			}
		}
}

task main()
{
	drive(1,true);
}
