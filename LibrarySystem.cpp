#include "librarysystem.h"


//********************************************************************activate()************************************************************************
// Activates (initializes) Library system through calling catalogue.initCatalogue() and catalogue.initAccounts();
//******************************************************************************************************************************************************
bool LibrarySystem::activate() {

	// Defines infile1 used to initialize library catalogue books
	ifstream infile1("data3books.txt");
	if (!infile1) {
		cout << "Books file could not be opened." << endl;
		return false;
	}

	// Defines infile2 used to initialize library catalogue patrons accounts
	ifstream infile2("data3patrons.txt");
	if (!infile2) {
		cout << "Patrons file could not be opened." << endl;
		return false;
	}

   catalogue.initCatalogue(infile1);
   catalogue.initAccounts(infile2);
   return true;
}


//*************************************************************************run()************************************************************************
// Runs the command lines read from infile
//******************************************************************************************************************************************************
bool LibrarySystem::run() {

	// Defines infile used to read command lines from infile
	ifstream infile("data3commands.txt");
	if (!infile) {
		cout << "Commands file could not be opened." << endl;
		return false;
	}

   catalogue.performCommand(infile);
   return true;
}

