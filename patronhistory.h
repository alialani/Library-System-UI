#pragma once

#include "historynode.h"
#include <iostream>


//-----------------------------------------------------------------------------
// PatronHistory is a linked list of HistoryNodes, storing the rental history
// of a patron.  The user is able to append HistoryNodes to the head of the
// list (most recent rental).
class PatronHistory {
	private:
		HistoryNode *head;
		
	public:

//**********************************************************PatronHistory()*****************************************************************************
// Constructor
//******************************************************************************************************************************************************
		PatronHistory();\


//****************************************************************~PatronHistory()*****************************************************************************
// Destructor deallocate allocated memory using deleteHistory()
//******************************************************************************************************************************************************
		~PatronHistory();


//***************************************************************deleteHistory()************************************************************************
// Deallocate allocated memory recursively
//******************************************************************************************************************************************************
		void deleteHistory();
		


//***********************************************************appendToHistory()**************************************************************************
// Return true after appending a new HistoryNode() after creating it using the passed prameters 
//******************************************************************************************************************************************************
		bool appendToHistory(Item* item, bool isCheckedOut);
		

//******************************************************************retrieve()**************************************************************************
// Returns true if the passed parameter Item* searchForItem is found and set the passed parameter Item** retrievedItem
// Returns false if not found
//******************************************************************************************************************************************************
		bool retrieve(Item** retreivedItem, Item* searchForItem) const;



//*****************************************************************display()****************************************************************************
// Display what Item* in each HistoryNode pionts to and print either "Checkout" or "Return" before it, depending on what getStatus() returning
//******************************************************************************************************************************************************
		void display();
		
};

