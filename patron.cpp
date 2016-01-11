
#include "patron.h"


//*****************************************************************Patron()*****************************************************************************
// Constructor to initialize Patron's data
//******************************************************************************************************************************************************
Patron::Patron(int idNum, string last, string first) {
	id = idNum;
	lastName = last;
	firstName = first;
	history = NULL;
}


//****************************************************************~Patron()*****************************************************************************
// Destructor deallocate allocated memory using deletePatronHistory()
//******************************************************************************************************************************************************
Patron::~Patron() {
	deletePatronHistory();
}



//***********************************************************deletePatronHistory()**********************************************************************
// Deallocate allocated memory using deleteHistory() defined in PatronHistory() class
//******************************************************************************************************************************************************
void Patron::deletePatronHistory() {
		if (history != NULL) {

		// Using deleteHistory() defined in PatronHistory() class
		history->deleteHistory();
		delete history;
		history = NULL;
	}
}


//*********************************************************************display()************************************************************************
// Displays patrons data with the required sort
//******************************************************************************************************************************************************
void Patron::display() const {
	cout << "*** Patron ID = " << id << " " << lastName << " " << firstName << endl << endl;
}


//********************************************************************getHistory()**********************************************************************
// Return PatronHistory* history
//******************************************************************************************************************************************************
PatronHistory* Patron::getHistory() {
	return history;
}


//*****************************************************************setHistory()*************************************************************************
// set PatronHistory* History to whatever passed
//******************************************************************************************************************************************************
void Patron::setHistory(PatronHistory* newHistory ) {
	history = newHistory; 
}

