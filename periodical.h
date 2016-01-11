#pragma once

#include "item.h"
#include <iostream>
#include <iomanip>


//-----------------------------------------------------------------------------
 //Periodical is an extension of the Item object.  It has a specified category,
 //and includes a publish date.  Periodicals are sorted by date, then by title.
class Periodical : public Item {
	private :
		int month;
		
	public:

//***********************************************************Periodical()*******************************************************************************
// Default constructor
//******************************************************************************************************************************************************
		Periodical();


//***********************************************************~Periodical()*******************************************************************************
// Destructor
//******************************************************************************************************************************************************
		~Periodical();


//****************************************************************setTotal()****************************************************************************
// Bool pure virtual method to modify the total of a specific items when initializing the items library and return true
//******************************************************************************************************************************************************
		virtual bool setTotal();



//*****************************************************************setData()****************************************************************************
// Pure virtual method to set data for a specicfic item according to a specific sequence to read these data from the file
// Reading only title, month and year and set avialable to 5
//******************************************************************************************************************************************************
		virtual void setData(istream&);


//*****************************************************************setDataToSearch()********************************************************************
// Pure virtual method to set data for a specicfic item (to search for later and retrieve) according to another specific sequence to read these
// data from the file
// Reading only year, month and title
//******************************************************************************************************************************************************
		virtual void setDataToSearch(istream&);



//**************************************************************create()******************************************************************************
// Return a new empty periodical item
//****************************************************************************************************************************************************
		virtual Item* create();


//************************************************************************display()*********************************************************************
// Pure virtual method to display data of the fiction book item in a specific order
//******************************************************************************************************************************************************
		virtual void display() const;


//********************************************************************displayInHistory()****************************************************************
// Pure virtual method to display data of the fiction book item when displaying history required in another specific order
//******************************************************************************************************************************************************
		virtual void displayInHistory() const;


		
//********************************************************************operator==()**********************************************************************
// Bool pure virtual method overloads the == operator. Returns true when data of compared items are identical 
//******************************************************************************************************************************************************
		virtual bool operator==(const Item& rhs) const;


//*********************************************************************operator<()**********************************************************************
// Bool pure virtual method overloads the < operator. Returns true when data of the calling object is less than the called object
// Years are compared first, if equal then months are compared, if equal then title
//******************************************************************************************************************************************************
		virtual bool operator<(const Item& rhs) const;

};

