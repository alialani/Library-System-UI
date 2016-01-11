#include "periodical.h"


//***********************************************************Periodical()*******************************************************************************
// Default constructor
//******************************************************************************************************************************************************
Periodical::Periodical() {}


//***********************************************************~Periodical()*******************************************************************************
// Destructor
//******************************************************************************************************************************************************
Periodical::~Periodical() {}



//****************************************************************setTotal()****************************************************************************
// Bool pure virtual method to modify the total of a specific items when initializing the items library and return true
//******************************************************************************************************************************************************
bool Periodical::setTotal() {
	available = available + 1;
	return true;
}



//*****************************************************************setData()****************************************************************************
// Pure virtual method to set data for a specicfic item according to a specific sequence to read these data from the file
// Reading only title, month and year and set avialable to 5
//******************************************************************************************************************************************************
void Periodical::setData(istream& infile) {	
	infile.get();						// get (and ignore) blank before title
	getline(infile, title, ',');		// input title, looks for comma terminator
	infile.get();						// get (and ignore) blank before author
	infile >> month;					// input author, looks for comma terminator
 	infile >> year;
	available = 1;
}



//*****************************************************************setDataToSearch()********************************************************************
// Pure virtual method to set data for a specicfic item (to search for later and retrieve) according to another specific sequence to read these
// data from the file
// Reading only year, month and title
//******************************************************************************************************************************************************
void Periodical::setDataToSearch(istream& infile) {	
	infile.get();						// get (and ignore) blank before author
	infile >> year;						// input author, looks for comma terminator
 	infile >> month;					// get (and ignore) blank before title
	infile.get();	
	getline(infile, title, ',');
}



//************************************************************************display()*********************************************************************
// Pure virtual method to display data of the fiction book item in a specific order
//******************************************************************************************************************************************************
void Periodical::display() const {
	cout << left << "  " << setw(8) << available << setw(10) <<year << setw(20) << month << setw(40) << title << endl;
}


//********************************************************************displayInHistory()****************************************************************
// Pure virtual method to display data of the fiction book item when displaying history required in another specific order
//******************************************************************************************************************************************************
void Periodical::displayInHistory() const {
	cout << setw(10) <<year << setw(20) << month << setw(40) << title << endl;
}


//**************************************************************create()******************************************************************************
// Return a new empty periodical item
//****************************************************************************************************************************************************
Item* Periodical::create() {
	return new Periodical();
}


//********************************************************************operator==()**********************************************************************
// Bool pure virtual method overloads the == operator. Returns true when data of compared items are identical 
//******************************************************************************************************************************************************
bool Periodical::operator==(const Item& rhs) const {
	const Periodical& perItem = static_cast<const Periodical&>(rhs);
	return (title == perItem.title && month == perItem.month && year == perItem.year);
}



//*********************************************************************operator<()**********************************************************************
// Bool pure virtual method overloads the < operator. Returns true when data of the calling object is less than the called object
// Years are compared first, if equal then months are compared, if equal then title
//******************************************************************************************************************************************************
bool Periodical::operator<(const Item& rhs) const {
	const Periodical& perItem = static_cast<const Periodical&>(rhs);
	if(year < perItem.year) return true;
	if(year == perItem.year && month < perItem.month) return true;
	if(year == perItem.year && month == perItem.month && title < perItem.title) return true;
	else return false;
}




