#include "patronhistory.h"


//**********************************************************PatronHistory()*****************************************************************************
// Constructor
//******************************************************************************************************************************************************
PatronHistory::PatronHistory() {
	head = NULL;
}


//****************************************************************~PatronHistory()*****************************************************************************
// Destructor deallocate allocated memory using deleteHistory()
//******************************************************************************************************************************************************
PatronHistory::~PatronHistory() {
	deleteHistory();
}



//***************************************************************deleteHistory()************************************************************************
// Deallocate allocated memory recursively
//******************************************************************************************************************************************************
void PatronHistory::deleteHistory() {
	if(head != NULL) {

		// Recursive call for the rest of the link list
		head->deleteHistory();
		delete head;
		head = NULL;
	}	
}



//***********************************************************appendToHistory()**************************************************************************
// Return true after appending a new HistoryNode() after creating it using the passed prameters 
//******************************************************************************************************************************************************
bool PatronHistory::appendToHistory(Item* retreivedItem, bool isCheckedOut) {

	// Create a new HistoryNode() using the passed prameters
	HistoryNode* newNode = new HistoryNode(retreivedItem, isCheckedOut);
	if (head == NULL) {
		head = newNode;
		return true;
	} else {
		HistoryNode* current = head;
		while(current->getNext() != NULL) {
			current = current->getNext();
		}
		current->setNext(newNode);
		return true;
	}
	return false;
}



//******************************************************************retrieve()**************************************************************************
// Returns true if the passed parameter Item* searchForItem is found and set the passed parameter Item** retrievedItem
// Returns false if not found
//******************************************************************************************************************************************************
bool PatronHistory::retrieve(Item** retrievedItem, Item* searchForItem) const {
	HistoryNode *current = head;
	for (HistoryNode* current = head; current != NULL && current->getStatus() == true; current = current->getNext()) {
		if (*current->getItem() == *searchForItem){
			*retrievedItem = current->getItem();
			return true;
		}
	}
	return false;
}


//*****************************************************************display()****************************************************************************
// Display what Item* in each HistoryNode pionts to and print either "Checkout" or "Return" before it, depending on what getStatus() returning
//******************************************************************************************************************************************************
void PatronHistory::display() {
	for (HistoryNode* current = head; current != NULL; current = current->getNext()) {

		// getStatus() returns isCheckedOut which is either true or false
		if(current->getStatus()) {
			cout << "CheckOut ";

			// displayInHistory() is a pure virtual method for each 
			// item displays item data with the required sort
			current->getItem()->displayInHistory();
			cout << endl;
		} else {
			cout << "Return   ";
			current->getItem()->displayInHistory();
			cout << endl;
		}
	}
	cout << endl;
}

