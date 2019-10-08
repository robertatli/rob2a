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

const int FULL_POWER = 60;
const int TURN_POWER = 75;
const int BASE_TIME = 700;
bool b_f = true;


void resetSensorValue(){
	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;
}
void stopMotor(){
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
	wait1Msec(1000);
}

void rotateLeft(int dir, int degreesToTurn){
	resetSensorValue();
	while(abs(SensorValue[leftEncoder]) < 200){
		motor[rightMotor] = TURN_POWER*dir;
		motor[leftMotor] = TURN_POWER*(-dir);
	}
}

void rotateRight(int dir, int degreesToTurn){
	resetSensorValue();
	while(abs(SensorValue[leftEncoder]) < 200){
		motor[leftMotor] = TURN_POWER*dir;
		motor[rightMotor] = TURN_POWER*(-dir);
	}
}

void driveForward50(int dir, int degreesToTurn){
	resetSensorValue();
	while(SensorValue[leftEncoder] < degreesToTurn)  // While less than 50 cm
	{
			motor[rightMotor] = FULL_POWER*dir;
			motor[leftMotor] = FULL_POWER*dir;
	}
	stopMotor();
}

void driveturn(int drivetime,bool b_f, bool turnLeft, int degreesToTurn){
	int dir = (b_f)? (1):(-1);
	if(turnLeft){
			driveForward50(dir, degreesToTurn);
			wait1Msec(drivetime);
			rotateLeft(dir,degreesToTurn);
		}
		else if(!turnLeft){
			driveForward50(dir, degreesToTurn);
			wait1Msec(drivetime);
			rotateRight(dir,degreesToTurn);
		}
		wait1Msec(drivetime);
}

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{

	// reyknar ut snuninga a hjoli
	float diameterOfWheel = 4.133858; //inches
	float circumference = diameterOfWheel*PI; //inches

	float distanceToGo = 19.6850394; // til ad fara 50 cm
	float rotations = distanceToGo / circumference;
	int degreesToTurn = rotations*360;


	driveturn(BASE_TIME,true, true,degreesToTurn); 	// right
	for(int i= 0; i < 2; i++){
		driveturn(BASE_TIME,true, false,degreesToTurn); // left
	}
	for(int i = 0; i< 2;i++){
		driveturn(BASE_TIME,true, true,degreesToTurn); 	// right
	}
	driveturn(BASE_TIME,true, false,degreesToTurn); // left
	for(int i = 0; i< 2;i++){
		driveturn(BASE_TIME,true, true,degreesToTurn); 	// right
	}
	driveturn(BASE_TIME,true, false,degreesToTurn); // left
	for(int i = 0; i< 2;i++){
		driveturn(BASE_TIME,true, true,degreesToTurn); 	// right
	}
	for(int i= 0; i < 2; i++){
		driveturn(BASE_TIME,true, false,degreesToTurn); // left
	}
	driveturn(BASE_TIME,true, true,degreesToTurn); 	// right

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
