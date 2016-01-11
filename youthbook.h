#pragma once

#include "book.h"

//-----------------------------------------------------------------------------
// YouthBook is an extension of the Book object.  YouthBooks are sorted
// first by their title, then by their author.  YouthBooks have the category
// 'Y'.
class YouthBook: public Book {
	public:

//***********************************************************YouthBook()********************************************************************************
// Default constructor
//******************************************************************************************************************************************************
		YouthBook();


//***********************************************************~YouthBook()********************************************************************************
// Destructor
//*****************************************************************************************************************************************************
		~YouthBook();


//****************************************************************setTotal()****************************************************************************
// Bool pure virtual method to modify the total of a specific items when initializing the items library and return true
//******************************************************************************************************************************************************
		virtual bool setTotal();


//*****************************************************************setData()****************************************************************************
// Bool pure virtual method to set data for a specicfic item according to a specific sequence to read these data from the file
// Reading only author, title and year and set avialable to 5
//******************************************************************************************************************************************************
		virtual void setData(istream&);


//*****************************************************************setDataToSearch()********************************************************************
// Bool pure virtual method to set data for a specicfic item (to search for later and retrieve) according to another specific sequence to read these
// data from the file
// Reading only author, title and year
//******************************************************************************************************************************************************
		virtual void setDataToSearch(istream&);


//**************************************************************create()******************************************************************************
// Return a new empty youth book item
//****************************************************************************************************************************************************
		virtual Item* create();


//************************************************************************display()*********************************************************************
// Bool pure virtual method to display data of the fiction book item in a specific order
//******************************************************************************************************************************************************
		virtual void display() const;


//********************************************************************displayInHistory()****************************************************************
// Bool pure virtual method to display data of the fiction book item when displaying history required in another specific order
//******************************************************************************************************************************************************
		virtual void displayInHistory() const;
		
//********************************************************************operator==()**********************************************************************
// Bool pure virtual method overloads the == operator. Returns true when data of compared items are identical 
//******************************************************************************************************************************************************	
		virtual bool operator==(const Item& rhs) const;

		
//*********************************************************************operator<()**********************************************************************
// Bool pure virtual method overloads the < operator. Returns true when data of the calling object is less than the called object
// Titles are compared first, if equal then authers are compared
//******************************************************************************************************************************************************
		virtual bool operator<(const Item& rhs) const;
	
};

