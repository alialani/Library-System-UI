#pragma once

#include "periodical.h"
#include "fictionbook.h"
#include "youthbook.h"


//-----------------------------------------------------------------------------
// ItemFactory is being used create empty Item object of any desired type using the hash
// method for it
class ItemFactory {
private: 
	Item* itemObj[26];
	int hash(char code);

public:

//**************************************************************ItemFactory()***************************************************************************
// Constructor of items factory to create new items for the read from file codes after hashing them and make them subscripts in the factory array
//******************************************************************************************************************************************************
	ItemFactory();


//**************************************************************~ItemFactory()**************************************************************************
// Destructor to deallocate allocated memory
//******************************************************************************************************************************************************
	~ItemFactory();


//********************************************************************createIt()************************************************************************
// Return a new empty specific type of object according to the imported read code from the file
// Uses the create method of the specific item to create that empty item
//******************************************************************************************************************************************************
	Item* createIt(char code);
	
};

