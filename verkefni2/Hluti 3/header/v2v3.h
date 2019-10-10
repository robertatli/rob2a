const int FULL_POWER = 60;
const int TURN_POWER = 75;
const int TURN_POWER2 = 90;
const int BASE_TIME = 700;

	// reyknar ut snuninga a hjoli
	float diameterOfWheel = 4.133858; //inches
	float circumference = diameterOfWheel*PI; //inches

	float distanceToGo = 19.6850394; // til ad fara 50 cm
	float rotations = distanceToGo / circumference;
	int degreesToTurn = rotations*360;
