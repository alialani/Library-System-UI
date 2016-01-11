
#include "fictionbook.h"



//***********************************************************FictionBook()******************************************************************************
// Default constructor
//******************************************************************************************************************************************************
FictionBook::FictionBook() {
	available = 0;
}


//***********************************************************~FictionBook()******************************************************************************
// Defstructor
//******************************************************************************************************************************************************
FictionBook::~FictionBook() {}
 


//**************************************************************create()******************************************************************************
// Return a new empty fiction book item
//****************************************************************************************************************************************************
Item* FictionBook::create() {
	return new FictionBook();
 }


//****************************************************************setTotal()****************************************************************************
// Bool pure virtual method to modify the total of a specific items when initializing the items library and return true
//******************************************************************************************************************************************************
bool FictionBook::setTotal() {
	available = available + 5;
	return true;
}


//*****************************************************************setData()****************************************************************************
// Bool pure virtual method to set data for a specicfic item according to a specific sequence to read these data from the file
// Reading only author, title and year and set avialable to 5
//******************************************************************************************************************************************************
void FictionBook::setData(istream& infile) {	
	infile.get();						// get (and ignore) blank before title
	getline(infile, author, ',');		// input title, looks for comma terminator
	infile.get();						// get (and ignore) blank before author
	getline(infile, title, ',');		// input author, looks for comma terminator
	infile >> year;
	available = 5;
}



//*****************************************************************setDataToSearch()********************************************************************
// Bool pure virtual method to set data for a specicfic item (to search for later and retrieve) according to another specific sequence to read these
// data from the file
// Reading only author, title and year
//******************************************************************************************************************************************************
void FictionBook::setDataToSearch(istream& infile) {	
	infile.get();						// get (and ignore) blank before title
	getline(infile, author, ',');		// input title, looks for comma terminator
	infile.get();						// get (and ignore) blank before author
	getline(infile, title, ',');		// input author, looks for comma terminator
}



//************************************************************************display()*********************************************************************
// Bool pure virtual method to display data of the fiction book item in a specific order
//******************************************************************************************************************************************************
void FictionBook::display() const {
	cout << left << "  " << setw(8) << available << setw(30) <<author << setw(40) << title << setw(33) << year << endl;
}



//********************************************************************displayInHistory()****************************************************************
// Bool pure virtual method to display data of the fiction book item when displaying history required in another specific order
//******************************************************************************************************************************************************
void FictionBook::displayInHistory() const {
	cout << setw(30) <<author << setw(40) << title << setw(33) << year << endl;
}



//********************************************************************operator==()**********************************************************************
// Bool pure virtual method overloads the == operator. Returns true when data of compared items are identical 
//******************************************************************************************************************************************************
bool FictionBook::operator==(const Item& rhs) const {
	const FictionBook& ficBook = static_cast<const FictionBook&>(rhs);
	return (title == ficBook.title && author == ficBook.author);
}



//*********************************************************************operator<()**********************************************************************
// Bool pure virtual method overloads the < operator. Returns true when data of the calling object is less than the called object
// Authers are compared first, if equal then titles are compared
//******************************************************************************************************************************************************
bool FictionBook::operator<(const Item& rhs) const {
	const FictionBook& ficBook = static_cast<const FictionBook&>(rhs);
	if(author < ficBook.author) return true;
	if(author == ficBook.author && title < ficBook.title) return true;
	else return false;
}


