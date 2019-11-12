
task drive();
task stopTasks();

task drive(){
	wait1Msec(1000);						// Robot waits for 2000 milliseconds before executing program
	while(1==1){
		if(SensorValue(lightSensor) > 650){
			//while(SensorValue(lightSensor) > 650){
				motor[rightMotor] = 0;
				motor[leftMotor] = 0;
			//}	
		}
		if(SensorValue(lightSensor) < 650){
			while(SensorValue(lightSensor) < 650) // While the ambient lightSensor reads a value lesser than 200
			{
					if(SensorValue(sonarSensor) > 35 || SensorValue(sonarSensor) == -1){
						motor[rightMotor] = 83;
						motor[leftMotor] = 	83;
					}
					else{
					motor[rightMotor] = 83;			// Motor on port2 is run at half (63) power forward
					motor[leftMotor]  = -83;			// Motor on port3 is run at half (63) power forward
					wait1Msec(500);
					}
			}
		}
	}
}
task stopTasks(){
		while(1==1){
	if(vexRT[Btn7U]==1 || touchSensor == 1){
		StopAllTasks();
	}}
}
