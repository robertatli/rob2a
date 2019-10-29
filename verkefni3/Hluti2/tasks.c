

task maze();
task stopTasks();

const int FULL_POWER = 60;
const int TURN_POWER = 75;
const int TURN_POWER2 = 90;
const int BASE_TIME = 700;

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
task maze()
{

float diameterOfWheel = 4.133858; //inches
	float circumference = diameterOfWheel*PI; //inches

	float distanceToGo = 19.6850394; // til ad fara 50 cm
	float rotations = distanceToGo / circumference;
	int degreesToTurn = rotations*360;


	driveturn(BASE_TIME,true,degreesToTurn); 	// right
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


task stopTasks(){
		while(1==1){
	if(vexRT[Btn7U]==1){
		StopAllTasks();
	}}
}
