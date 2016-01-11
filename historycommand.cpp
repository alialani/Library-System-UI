#include "historycommand.h"


//***************************************************************HistoryCommand()***********************************************************************
// Default constructor
//******************************************************************************************************************************************************
HistoryCommand::HistoryCommand() {}


//***************************************************************~HistoryCommand()***********************************************************************
// Destructor
//******************************************************************************************************************************************************
HistoryCommand::~HistoryCommand() {}


//************************************************************HistoryCommand::execute()*****************************************************************
// is a bool pure virtual function from class command returns true when displaying the history of an specific account specified by the read Patron ID
// from file
//******************************************************************************************************************************************************
bool HistoryCommand::execute(ItemTree* categTable[], Patron* accounts[], istream& infile) {
	int id;
	infile >> id;
	if(id >= 0 && id <= 9999 && accounts[id] != NULL) {
		// Using the display method of the Patron history link list
		accounts[id]->display();
		if(accounts[id]->getHistory() != NULL)
			accounts[id]->getHistory()->display();
		return true;
	}
	return false;
}


//******************************************************************create()****************************************************************************
// Creates and return a Command* to a new history command object
//******************************************************************************************************************************************************
	Command* HistoryCommand::create() {
		return new HistoryCommand();
	}
