#pragma once

#include "item.h"
#include "itemfactory.h"
#include "commandfactory.h"
#include "checkoutcommand.h"
#include "displaycommand.h"
#include "historycommand.h"
#include "returncommand.h"
#include "patron.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;



//-----------------------------------------------------------------------------
// Data associated with the library are centralized in this
// container.  LibraryCat hosts two hash tables that library items first organized 
// by format, and eligible commands to manipulate the library data stores and array
//  to hold the patron accounts

class LibraryCat {
	private:
		Patron* accounts[9999]; 		// holds patron accounts
		Command* commands[26];		// holds eligible commands
		CommandFactory commandFactory;
		ItemTree* categTable[26];		// holds library items
		ItemFactory itemFactory;
		
	public:
//**************************************************************LibraryCat()****************************************************************************
// Default constructor initializes ItemTree* categTable[], Patron* accounts[] and Commands* commands[] to NULL
//******************************************************************************************************************************************************
		LibraryCat();


//***************************************************************~LibraryCat()**************************************************************************
// Destructor deallocates allocated memory of categTable[] using makeEmpty() defined in ItemTree class and accounts[] using deletePatronHistory()
// defined in PatronHistory class and commands[] by setting them all to NULL
//
//******************************************************************************************************************************************************
		~LibraryCat();		

	
//**************************************************************initCatalogue()************************************************************************
// Initializes the librarby catalogue items with the read data from the infile
//*****************************************************************************************************************************************************
		void initCatalogue(istream&);


//**************************************************************initAccounts()*************************************************************************
// Initializes the librarby catalogue Patron accounts with the read data from the infile
//*****************************************************************************************************************************************************
		void initAccounts(istream&);


		
//***********************************************************performCommand()***************************************************************************
// Performs each line of command read from the infile
//******************************************************************************************************************************************************
		void performCommand(istream&);
			
};
