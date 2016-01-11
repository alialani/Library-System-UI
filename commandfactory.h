#pragma once

#include "checkoutcommand.h"
#include "displaycommand.h"
#include "historycommand.h"
#include "returncommand.h"

class CommandFactory {
private: 
	Command* commandObj[26];
	int hash(char code);
public:

//**************************************************************CommandFactory()************************************************************************
// Constructor of commands factory to create new commands for the read from file codes after hashing them and make them subscripts in the factory array
//******************************************************************************************************************************************************
	CommandFactory();


//*******************************************************************hash()*****************************************************************************
// Hash read from file codes and make them subscripts in the factory array
//******************************************************************************************************************************************************
	~CommandFactory();


//********************************************************************createIt()************************************************************************
// Return a new empty specific type of object according to the imported read code from the file
// Uses the create method of the specific command to create that empty command
//******************************************************************************************************************************************************
	Command* createIt(char code);
	
};

