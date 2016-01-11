#pragma once


#include "item.h"
#include <iostream>
#include <iomanip>

//-----------------------------------------------------------------------------
// Book is an extension of the Item object.  Books includes authors.
class Book : public Item {
	protected:
		string author;
		
	public:

//**************************************************************create()******************************************************************************
// Return a new empty youth book item
//****************************************************************************************************************************************************
		virtual Item* create() =0;


//************************************************************************display()*********************************************************************
// Bool pure virtual method to display data of the fiction book item in a specific order
//******************************************************************************************************************************************************
		virtual void display() const =0;
		

//********************************************************************operator==()**********************************************************************
// Bool pure virtual method overloads the == operator. Returns true when data of compared items are identical 
//******************************************************************************************************************************************************
		virtual bool operator==(const Item& rhs) const =0;


//*********************************************************************operator<()**********************************************************************
// Bool pure virtual method overloads the < operator. Returns true when data of the calling object is less than the called object
// Titles are compared first, if equal then authers are compared
//******************************************************************************************************************************************************
		virtual bool operator<(const Item& rhs) const =0;
};



