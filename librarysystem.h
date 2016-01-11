#pragma once

#include "librarycat.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

//-----------------------------------------------------------------------------
// The manager class for the library system.  The user can activate the system
class LibrarySystem {
	private:
		// data store for all accounts, items, and function commands held by
		// the library
		LibraryCat catalogue;
		
	public:		

//********************************************************************activate()************************************************************************
// Activates (initializes) Library system through calling catalogue.initCatalogue() and catalogue.initAccounts();
//******************************************************************************************************************************************************
		bool activate();

		
//*************************************************************************run()************************************************************************
// Runs the command lines read from infile
//******************************************************************************************************************************************************
		bool run();		
};

