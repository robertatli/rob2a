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
const int TURN_POWER = 40;
const int BASE_TIME = 700;
// reiknar ut snuninga a hjoli
float diameterOfWheel = 4.133858; //inches
float circumference = diameterOfWheel*PI; //inches


void resetSensorValue(){
	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;
}
void stopMotor(){
	wait1Msec(1000);
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
}

void drivedist(bool b_f, int dist){
	resetSensorValue();
	int dir = (b_f)? (1):(-1);
	while(SensorValue[leftEncoder] < dist)  // While less than 50 cm
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


	for(int i = 1; i<6;i++){
		drivedist(true,wheelTurns);
		stopMotor();
		drivedist(false,wheelTurns);
		wheelTurns += wheelTurns
	}



/*
			bool direction = true;
			if(i % 2 == 0) direction = false;
				else direction = true;*/

	/*for(int i=1;i<6;i++){
	drive(BASE_TIME*i,true);
	drive(BASE_TIME*i,false);
	}*/

}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++






/*
task display(){
		bLCDBacklight = true;									// Turn on LCD Backlight
	string mainBattery, backupBattery;
	while(true)														// An infinite loop to keep the program running until you terminate it
	{
		clearLCDLine(0);											// Clear line 1 (0) of the LCD
		clearLCDLine(1);											// Clear line 2 (1) of the LCD
		//Display the Primary Robot battery voltage
		displayLCDString(0, 0, "Primary: ");
		sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V'); //Build the value to be displayed
		displayNextLCDString(mainBattery);
		//Display the Backup battery voltage
		displayLCDString(1, 0, "Backup: ");
		sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'V');	//Build the value to be displayed
		displayNextLCDString(backupBattery);
		//Short delay for the LCD refresh rate
		wait1Msec(100);
	}
}*/
/*
void drive(int drivetime, bool b_f){
	int dir = (b_f)? (1):(-1);
	motor[rightMotor] = FULL_POWER*dir;
	motor[leftMotor]  = FULL_POWER*dir;
	wait1Msec(drivetime);
}*/









