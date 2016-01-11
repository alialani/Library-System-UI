#include "librarycat.h"


//**************************************************************LibraryCat()****************************************************************************
// Default constructor initializes ItemTree* categTable[], Patron* accounts[] and Commands* commands[] to NULL
//******************************************************************************************************************************************************
LibraryCat::LibraryCat() {
	for(int i=0; i<26; i++)
		categTable[i] = NULL;
	for(int i=0; i<9999; i++)
		accounts[i] = NULL;
	for(int i=0; i<26; i++)
		commands[i] = NULL;
}


//***************************************************************~LibraryCat()**************************************************************************
// Destructor deallocates allocated memory of categTable[] using makeEmpty() defined in ItemTree class and accounts[] using deletePatronHistory()
// defined in PatronHistory class and commands[] by setting them all to NULL
//
//******************************************************************************************************************************************************
LibraryCat::~LibraryCat() {
	for(int i=0; i<9999; i++) {
		if( accounts[i] != NULL ) {
			// using deletePatronHistory() defined in PatronHistory class
			accounts[i]->deletePatronHistory();	
			delete accounts[i];
			accounts[i] = NULL;
		}
	}

	for(int i=0; i<26; i++) {
		if (commands[i] != NULL) {			
			commands[i] = NULL;
			delete commands[i];
		}
	}

	for(int i=0; i<26; i++) {
		if (categTable[i] != NULL) {
			// using makeEmpty() defined in ItemTree class
			categTable[i]->makeEmpty();
			delete categTable[i];
			categTable[i] = NULL;
		}
	}
}



//**************************************************************initCatalogue()************************************************************************
// Initializes the librarby catalogue items with the read data from the infile
//*****************************************************************************************************************************************************
void LibraryCat::initCatalogue(istream& infile) {

	// Sets only the needed pointers of the of the ItemTree* categTable[] to new tree
	categTable['F'-'A'] = new ItemTree();
	categTable['P'-'A'] = new ItemTree();
	categTable['Y'-'A'] = new ItemTree();

	char bookCode;
	string temp = " ";

	for( ; ; ) {
		if (infile.eof()) break;

		// Read item data from infile
		infile >> bookCode;
		if (bookCode - 'A' >= 0 && bookCode - 'A' < 26 && categTable[bookCode -'A'] != NULL) {

			// Create a specific type of item using itemFactory
			// according to bookCode read from infile 
			Item* item = itemFactory.createIt(bookCode);

			// Set data differently for each type of item using
			// it's pure virtual setdata() through sending the
			// rest of the data line in the infile
			item->setData(infile);

			// Create a new ItemNode to add to the ItemTree of
			// that specific type of item
			ItemNode* itemNode = new ItemNode(item);
			categTable[bookCode -'A']->add(itemNode);
			bookCode = 0;
		}
		else
			// ignore to the end of the line
			getline(infile, temp, '\n');
	}
}



//**************************************************************initAccounts()*************************************************************************
// Initializes the librarby catalogue Patron accounts with the read data from the infile
//*****************************************************************************************************************************************************
void LibraryCat::initAccounts(istream& infile) {
	int id;
	string first, last;
	for( ; ; ) {
		if (infile.eof()) break;

		// Read accounts data from infile
		infile >> id;
		infile.get();
		infile >> last;
		infile.get();
		infile >> first;

		// create Patron account
		accounts[id] = new Patron(id, first, last);
	}
}



//***********************************************************performCommand()***************************************************************************
// Performs each line of command read from the infile
//******************************************************************************************************************************************************
void LibraryCat::performCommand(istream& infile) {

	// Sets only the needed pointers of the of the Command* commands[] to 
	// specific new command created and returned by the commandFactory
	commands['C'-'A'] = commandFactory.createIt('C');
	commands['D'-'A'] = commandFactory.createIt('D');
	commands['H'-'A'] = commandFactory.createIt('H');
	commands['R'-'A'] = commandFactory.createIt('R');

	char commandCode;
	string temp = " ";
	for( ; ; ) {
		if (infile.eof()) break;

		// Read command data from infile
		infile >> commandCode;
		if (commandCode - 'A' >= 0 && commandCode - 'A' < 26 && commands[commandCode -'A'] != NULL) {

			// Execute a specific transaction accourding to the 
			// commandCode read from infile through using a
			// pure virtual method execute() of each command
			commands[commandCode -'A']->execute(categTable, accounts, infile);
		commandCode = 0;
		}
		else  
			// ignore to the end of the line
			getline(infile, temp, '\n');
	}
}



