/*
roboRIO to Arduino Byte Naming List
0 - Game State (teleop, auton, unknown)
1 - Alliance
2 - Tote Count
3 - Bin Count
4 - Elevator Height
5 - Unload?
*/ //LOL ^ THIS AINT TRUE

#define FINGER_ON 1
#define FINGER_OFF 0

#define SAFE 2
#define AUTO 1
#define MANUAL 0

#define SAFE 2
#define AUTO 1
#define MANUAL 0

#define RED_ALLIANCE 0
#define BLUE_ALLIANCE 1
#define UNKNOWN_ALLIANCE 2

#define MODE_UNKNOWN 0
#define MODE_DISABLED 1
#define MODE_AUTO 2
#define MODE_TELEOP 3

volatile uint8_t gameState = MODE_UNKNOWN;
volatile uint8_t alliance = UNKNOWN_ALLIANCE;
volatile uint8_t totes = 4;
volatile uint8_t bins = 1;
volatile uint8_t rollers = MANUAL;
volatile uint8_t elevator = AUTO;
volatile uint8_t elevator_height = 0;
volatile uint8_t finger = 0;
volatile bool newData =false;
//volatile bool newTote = true;
volatile bool stabilizer = true;
volatile bool newStabilizer = true;
volatile bool newBin = false;

void getPackets(int numBytes)
{

	Wire.read();
	
	uint8_t oldGameState = gameState;
	gameState = Wire.read();
	if(gameState != oldGameState)
	{
		newData=true;
	}
	
	//alliance = Wire.read();
	finger = Wire.read();
	elevator = Wire.read();
	
	
	uint8_t oldstabilizer = stabilizer;
	stabilizer = Wire.read();
	if(stabilizer != oldstabilizer)
	{
		newData=true;
		newStabilizer=true;
	}
	
	elevator_height = Wire.read();
	
/*	uint8_t oldtotes = totes;
	totes = Wire.read();
	if(totes != oldtotes)
	{
		newData=true;
		if(totes>oldtotes)
		{
			newTote=true;
		}
	}
*/

	
	rollers = Wire.read();
	/*
	uint8_t oldunload = unload;
	unload = Wire.read();
	if(unload != oldunload)
	{
		newData=true;
	} */
	//fieldPos = Wire.read();
}