#include "itemfactory.h"



//**************************************************************ItemFactory()***************************************************************************
// Constructor of items factory to create new items for the read from file codes after hashing them and make them subscripts in the factory array
//******************************************************************************************************************************************************
ItemFactory::ItemFactory() {
	int subscript = hash('F');
	itemObj[subscript] = new FictionBook();
	subscript = hash('P');
	itemObj[subscript] = new Periodical();
	subscript = hash('Y');
	itemObj[subscript] = new YouthBook();
}



//*******************************************************************hash()*****************************************************************************
// Hash read from file codes and make them subscripts in the factory array
//******************************************************************************************************************************************************
int ItemFactory::hash(char code) {
	return code-'A';
}




//**************************************************************~ItemFactory()**************************************************************************
// Destructor to deallocate allocated memory
//******************************************************************************************************************************************************
ItemFactory::~ItemFactory() {
	
	delete itemObj['F'-'A'];
	itemObj['F'-'A'] = NULL;
	
	delete itemObj['P'-'A'];
	itemObj['P'-'A'] = NULL;
	
	delete itemObj['Y'-'A'];
	itemObj['Y'-'A'] = NULL;
}


//********************************************************************createIt()************************************************************************
// Return a new empty specific type of object according to the imported read code from the file
// Uses the create method of the specific item to create that empty item
//******************************************************************************************************************************************************
Item* ItemFactory::createIt(char code) {
	return itemObj[code -'A']->create();
}

