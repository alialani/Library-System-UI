#pragma once

#include "command.h"

//-----------------------------------------------------------------------------
// A ReturnComman object has the sole function of returning an item.  It has
// the character 'R' for its command call, and requires a Patron object and a
// ItemTree object and the istream file in order to execute.
class ReturnCommand : public Command {
	private:
		// return is called using 'R'
		// char commandCall = 'R';
		
	public:

//**************************************************************ReturnCommand()*************************************************************************
// Default constructor
//******************************************************************************************************************************************************
		ReturnCommand();


//**************************************************************~ReturnCommand()*************************************************************************
// Destructor
//*******************************************************************************************************************************************************
		~ReturnCommand();

		
		
//***********************************************************ReturnCommand::execute()*******************************************************************
// is a bool pure virtual function from class command returns true when excute the return command
//******************************************************************************************************************************************************
		virtual bool execute(ItemTree* [], Patron* [], istream&);


//******************************************************************create()****************************************************************************
// Creates and return a Command* to a new return command object
//******************************************************************************************************************************************************
	virtual Command* create();
};


