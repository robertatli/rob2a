
#include "../header/v2v3.h";

void resetSensorValue(){
	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;
}
void stopMotor(){
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
	wait1Msec(1000);
}

void rotate(int dir, int degreesToTurn){
	resetSensorValue();
	if(dir == 1){
		while(abs(SensorValue[leftEncoder]) < 240){ //ef dir er true => turn right, ef fale => turn left
			motor[leftMotor] = TURN_POWER*dir;
			motor[rightMotor] = TURN_POWER*-(dir);
		}
	}else if(dir == -1){
		while(abs(SensorValue[leftEncoder]) < 220){ //ef dir er true => turn right, ef fale => turn left
			motor[leftMotor] = TURN_POWER2*dir;
			motor[rightMotor] = TURN_POWER2*-(dir);
		}
	}
	stopMotor();
	wait1Msec(1000);
}

void driveForward50(int degreesToTurn){
	resetSensorValue();
	while(SensorValue[leftEncoder] < degreesToTurn)  // While less than 50 cm
	{
			motor[rightMotor] = FULL_POWER;
			motor[leftMotor] = FULL_POWER;
	}
	stopMotor();
	wait1Msec(1000);
}

void driveturn(int drivetime,bool b_f, int degreesToTurn){
	int dir = (b_f)? (1):(-1);
	driveForward50(degreesToTurn);
	rotate(dir,degreesToTurn);
}
