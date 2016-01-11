#include "displaycommand.h"


//******************************************************************DisplayCommand()********************************************************************
// Default constructor
//******************************************************************************************************************************************************
DisplayCommand::DisplayCommand() {}



//******************************************************************~DisplayCommand()********************************************************************
// Destructor
//******************************************************************************************************************************************************
DisplayCommand::~DisplayCommand() {}


//******************************************************DisplayCommand::execute()***********************************************************************
// is a bool pure virtual function from class command returns true when excute the display command
// Uses the display method in each tree to display the items in that tree
//******************************************************************************************************************************************************
bool DisplayCommand::execute(ItemTree* categTable[], Patron* accounts[], istream& infile) {
	cout << "Fiction:" << endl;
	cout << left << setw(10) << "AVAIL" << setw(30) <<"AUTHOR" << setw(40) << "TITLE" << setw(33) << "YEAR" << endl;
	// Using the display method in each tree to display the items in that tree
	categTable['F'-'A']->display();
	cout << endl;
	cout << "Youth:" << endl;
	cout << left << setw(10) << "AVAIL" << setw(30) <<"AUTHOR" << setw(40) << "TITLE" << setw(33) << "YEAR" << endl;
	categTable['Y'-'A']->display();
	cout << endl;
	cout << "Periodicals:" << endl;
	cout << left << setw(10) << "AVAIL" << setw(10) <<"YEAR" << setw(20) << "MO" << setw(40) << "TITLE" << endl;
	categTable['P'-'A']->display();
	cout << endl << endl;
	return true;
}


//******************************************************************create()****************************************************************************
// Creates and return a Command* to a new display command object
//******************************************************************************************************************************************************
Command* DisplayCommand::create() {
	return new DisplayCommand();
}


