const int FULL_POWER = 45;
float diameterOfWheel = 4.133858; //inches
float circumference = diameterOfWheel*PI; //inches

float distanceToGo = 19.6850394; // til ad fara 50 cm
	float rotations = distanceToGo / circumference;
	int wheelTurns = rotations*360;
