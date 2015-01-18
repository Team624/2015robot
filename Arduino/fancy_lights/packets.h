/*
roboRIO to Arduino Byte Naming List
0 - Game State (teleop, auton, unknown)
1 - Robot State (Unknown, Disabled, Auto, Teleop)
2 - Alliance
3 - Tote Count
4 - Bin Count
5 - Elevator Height
6 - Strafe?
*/

#define RED_ALLIANCE 0
#define BLUE_ALLIANCE 1
#define UNKNOWN_ALLIANCE 2

#define MODE_UNKNOWN 0
#define MODE_DISABLED 1
#define MODE_AUTO 2
#define MODE_TELEOP 3

volatile uint8_t gameState = MODE_UNKNOWN;
//volatile uint8_t robotState = STATE_UNKNOWN;
volatile uint8_t alliance = UNKNOWN_ALLIANCE;
volatile uint8_t totes = 2;
volatile uint8_t bins = 1;
volatile uint8_t rollers = 0;
volatile uint8_t elevator = 0;
volatile uint8_t omni = 0;
volatile bool newData = false;

void getPackets(int numBytes)
{

	Wire.read();
	
	uint8_t oldGameState = gameState;
	gameState = Wire.read();
	if(gameState != oldGameState)
	{
		newData=true;
	}
	/*
	uint8_t oldRobotState = robotState;
	robotState = Wire.read();
	if(robotState != oldRobotState)
	{
		newData=true;
	}
	*/
	alliance = Wire.read();
	
	uint8_t oldtotes = totes;
	totes = Wire.read();
	if(totes != oldtotes)
	{
		newData=true;
	}
	
	uint8_t oldbins = bins;
	bins = Wire.read();
	if(bins != oldbins)
	{
		newData=true;
	}
	
	rollers = Wire.read();
	elevator = Wire.read();
	omni = Wire.read();
	//fieldPos = Wire.read();
}