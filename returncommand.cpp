#include "returncommand.h"

//**************************************************************ReturnCommand()*************************************************************************
// Default constructor
//******************************************************************************************************************************************************
ReturnCommand::ReturnCommand() {}


//**************************************************************~ReturnCommand()*************************************************************************
// Destructor
//*******************************************************************************************************************************************************
ReturnCommand::~ReturnCommand() {}


//***********************************************************ReturnCommand::execute()*******************************************************************
// is a bool pure virtual function from class command returns true when excute the return command
//******************************************************************************************************************************************************
bool ReturnCommand::execute(ItemTree* categTable[], Patron* accounts[], istream& infile) {	
	int id;
	string temp =" ";
	char bookCode, formatCode;

	// Read data from infile and check their validity
	infile.get();
	infile >> id;
	if(id >= 0 && id <= 9999 && accounts[id] != NULL) {
		infile.get();
		infile >> bookCode;
		if (bookCode - 'A' >= 0 && bookCode - 'A' < 26 && categTable[bookCode -'A'] != NULL) {
			infile.get();
			infile >> formatCode;
			if( formatCode == 'H') {

				// Create the *Item to be searched in the PatronHistory
				Item* searchForItem = itemFactory.createIt(bookCode);

				// Set data read from infile in Item to be searched
				searchForItem->setDataToSearch(infile);

				// Create another *Item to store the address of the found searched item
				Item* retreivedItem = NULL;
				if(accounts[id]->getHistory() != NULL) {
					if( accounts[id]->getHistory()->retrieve(&retreivedItem, searchForItem)) {	

						// Create a bool and involve it in the construction of the HistoryNode and set it false to know how to 
						// search history when displaying PatronHistory
						bool isCheckedOut = false;
						accounts[id]->getHistory()->appendToHistory(retreivedItem, isCheckedOut);
						retreivedItem->returnItem();

						delete searchForItem;
						searchForItem = NULL;
						return true;
					}
					else
						// ignore the rest of the line
						getline(infile, temp, '\n');
						delete searchForItem;
						searchForItem = NULL;
				}
				else
					getline(infile, temp, '\n');
			}
			else
				getline(infile, temp, '\n');
		}
		else 
			getline(infile, temp, '\n');
		return false;
	}
}


//******************************************************************create()****************************************************************************
// Creates and return a Command* to a new return command object
//******************************************************************************************************************************************************
	Command* ReturnCommand::create() {
		return new ReturnCommand();
	}


