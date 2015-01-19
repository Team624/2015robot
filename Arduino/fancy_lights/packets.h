/*
roboRIO to Arduino Byte Naming List
0 - Game State (teleop, auton, unknown)
1 - Alliance
2 - Tote Count
3 - Bin Count
4 - Elevator Height
5 - Unload?
*/

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
//volatile uint8_t rollers = 0;
volatile uint8_t elevator = 0;
volatile uint8_t unload = 0;
volatile bool newData =false;
volatile bool newTote = true;
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
	
	alliance = Wire.read();
	
	uint8_t oldtotes = totes;
	totes = Wire.read();
	if(totes != oldtotes)
	{
		newData=true;
		if(totes>oldtotes)
		{
			newTote=true;
		}
	}
	
	uint8_t oldbins = bins;
	bins = Wire.read();
	if(bins != oldbins)
	{
		newData=true;
		if(bins>oldbins)
		{
			newBin=true;
		}
	}
	
	//rollers = Wire.read();
	elevator = Wire.read();
	
	uint8_t oldunload = unload;
	unload = Wire.read();
	if(unload != oldunload)
	{
		newData=true;
	}
	//fieldPos = Wire.read();
}