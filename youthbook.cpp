#include "item.h"
#include "youthbook.h"
#include "book.h"


//***********************************************************YouthBook()********************************************************************************
// Default constructor
//******************************************************************************************************************************************************
YouthBook::YouthBook() {
	available = 0;
}


//***********************************************************~YouthBook()********************************************************************************
// Destructor
//******************************************************************************************************************************************************
YouthBook::~YouthBook() {}


//****************************************************************setTotal()****************************************************************************
// Bool pure virtual method to modify the total of a specific items when initializing the items library and return true
//******************************************************************************************************************************************************
bool YouthBook::setTotal() {
	available = available + 5;
	return true;
}


//*****************************************************************setData()****************************************************************************
// Bool pure virtual method to set data for a specicfic item according to a specific sequence to read these data from the file
// Reading only author, title and year and set avialable to 5
//******************************************************************************************************************************************************
void YouthBook::setData(istream& infile) {	
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
void YouthBook::setDataToSearch(istream& infile) {	
	infile.get();						// get (and ignore) blank before title
	getline(infile, title, ',');		// input title, looks for comma terminator
	infile.get();						// get (and ignore) blank before author
	getline(infile, author, ',');		// input author, looks for comma terminator
}



//**************************************************************create()******************************************************************************
// Return a new empty youth book item
//****************************************************************************************************************************************************
Item* YouthBook::create() {
	return new YouthBook();
}



//************************************************************************display()*********************************************************************
// Bool pure virtual method to display data of the fiction book item in a specific order
//******************************************************************************************************************************************************
void YouthBook::display() const {
	cout << left << "  " << setw(8) << available << setw(30) <<author << setw(40) << title << setw(33) << year << endl;
}


//********************************************************************displayInHistory()****************************************************************
// Bool pure virtual method to display data of the fiction book item when displaying history required in another specific order
//******************************************************************************************************************************************************
void YouthBook::displayInHistory() const {
	cout << setw(30) <<author << setw(40) << title << setw(33) << year << endl;
}



//********************************************************************operator==()**********************************************************************
// Bool pure virtual method overloads the == operator. Returns true when data of compared items are identical 
//******************************************************************************************************************************************************
bool YouthBook::operator==(const Item& rhs) const {
	const YouthBook& youBook = static_cast<const YouthBook&>(rhs);
	return (title == youBook.title && author == youBook.author);
}



//*********************************************************************operator<()**********************************************************************
// Bool pure virtual method overloads the < operator. Returns true when data of the calling object is less than the called object
// Titles are compared first, if equal then authers are compared
//******************************************************************************************************************************************************
bool YouthBook::operator<(const Item& rhs) const {
	const YouthBook& youBook = static_cast<const YouthBook&>(rhs);
	if(title < youBook.title) return true;
	if(title == youBook.title && author < youBook.author) return true;
	else return false;
}


