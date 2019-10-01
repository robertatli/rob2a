

#include "../RobClawbot/headers/v2v2.h";
//endurstillir encoder
void resetSensorValue(){
	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;
}
//stoppar motora
void stopMotor(){
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
	wait1Msec(1000);
}

void drivedist(bool b_f, int dist){
	resetSensorValue();
	int dir = (b_f)? (1):(-1); //faer annad hvort 1 eda 0, eftir thvi hvort slegi er inn true eda false
	while(abs(SensorValue[leftEncoder]) < dist)  // While less than 50 cm
  		{
  			//motorar fara afram ef true, aftur ef false
				motor[rightMotor] = FULL_POWER*dir;
				motor[leftMotor] = FULL_POWER*dir;
			}
	stopMotor();
}
