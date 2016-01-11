#pragma once

#include "command.h"

//-----------------------------------------------------------------------------
// A DisplayCommand object has the sole function of displaying the library's
// entire catalogue of items.  It has the character 'D' as its command call,
// and requires a FormatHash object in order to execute.
class DisplayCommand : public Command {		
	public:

//******************************************************************DisplayCommand()********************************************************************
// Default constructor
//******************************************************************************************************************************************************
		DisplayCommand();


//******************************************************************~DisplayCommand()********************************************************************
// Destructor
//******************************************************************************************************************************************************
		~DisplayCommand();
	

//******************************************************DisplayCommand::execute()***********************************************************************
// is a bool pure virtual function from class command returns true when excute the display command
// Uses the display method in each tree to display the items in that tree
//******************************************************************************************************************************************************
		virtual bool execute(ItemTree* [], Patron* [], istream&);


//******************************************************************create()****************************************************************************
// Creates and return a Command* to a new display command object
//******************************************************************************************************************************************************
		virtual Command* create();
};

