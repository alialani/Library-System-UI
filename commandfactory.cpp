#include "commandfactory.h"


//**************************************************************CommandFactory()************************************************************************
// Constructor of commands factory to create new commands for the read from file codes after hashing them and make them subscripts in the factory array
//******************************************************************************************************************************************************
CommandFactory::CommandFactory() {
	int subscript = hash('C');
	commandObj[subscript] = new CheckoutCommand();
	subscript = hash('D');
	commandObj[subscript] = new DisplayCommand();
	subscript = hash('H');
	commandObj[subscript] = new HistoryCommand();	
	subscript = hash('R');
	commandObj[subscript] = new ReturnCommand();		
}


//*******************************************************************hash()*****************************************************************************
// Hash read from file codes and make them subscripts in the factory array
//******************************************************************************************************************************************************
int CommandFactory::hash(char code) {
	return code-'A';
}


//**************************************************************~CommandFactory()***********************************************************************
// Destructor to deallocate allocated memory
//******************************************************************************************************************************************************
CommandFactory::~CommandFactory() {
		delete commandObj['C'-'A'];
		commandObj['C'-'A'] = NULL;
		delete commandObj['D'-'A'];
		commandObj['D'-'A'] = NULL;
		delete commandObj['H'-'A'];
		commandObj['H'-'A'] = NULL;
		delete commandObj['R'-'A'];
		commandObj['R'-'A'] = NULL;
}


//********************************************************************createIt()************************************************************************
// Return a new empty specific type of object according to the imported read code from the file
// Uses the create method of the specific command to create that empty command
//******************************************************************************************************************************************************
Command* CommandFactory::createIt(char code) {
	return  commandObj[code -'A']->create();
}


	
