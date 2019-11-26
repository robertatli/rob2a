bool left,center,right = false;
int threshold = 2000;
int speed = 63;

void StopMotors()
{
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
}

void drive()
{
 while(vexRT[Btn7U]!=1)
	{
		if(SensorValue(leftLineFollower)>threshold)left = true; else left = false;
		if(SensorValue(centerLineFollower)>threshold)center = true; else center = false;
		if(SensorValue(rightLineFollower)>threshold)right = true; else right = false;
		if(center || center && right || center && left){
			motor[rightMotor] = speed;
			motor[leftMotor] = speed;
			}
		if(left && !right){
			motor[rightMotor] = speed*1.2;
			motor[leftMotor] = 0;
		}
		if(right && !left){
			motor[rightMotor] = 0;
			motor[leftMotor] =  speed*1.2;
	}
		if(!right && !center && !left) StopMotors();
	}
}
