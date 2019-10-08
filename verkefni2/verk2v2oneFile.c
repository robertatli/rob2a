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

const int FULL_POWER = 45;
// reiknar ut snuninga a hjoli
float diameterOfWheel = 4.133858; //inches
float circumference = diameterOfWheel*PI; //inches


void resetSensorValue(){
	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;
}
void stopMotor(){
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
	wait1Msec(1000);
}

void drivedist(bool b_f, int dist){
	resetSensorValue();
	int dir = (b_f)? (1):(-1);
	while(abs(SensorValue[leftEncoder]) < dist)  // While less than 50 cm
  		{
				motor[rightMotor] = FULL_POWER*dir;
				motor[leftMotor] = FULL_POWER*dir;
			}
	stopMotor();
}


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{

	

	float distanceToGo = 19.6850394; // til ad fara 50 cm
	float rotations = distanceToGo / circumference;
	int wheelTurns = rotations*360;


	for(int i = 1; i<5;i++){
		drivedist(true,wheelTurns);
		wait10Msec(1);
		drivedist(false,wheelTurns);
		wheelTurns += wheelTurns;
	}

