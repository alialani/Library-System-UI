#pragma once

#include <string>
using namespace std;

//-----------------------------------------------------------------------------
// Item is a general representation of an item within the library.  It stores
// the total amount of the item within the system, the amount currently
// available, its format, its category, and its title.  The user is able to
// "checkout" the item (deduct availability by 1), "return" it (add availability
// by 1), set the total amount of items, check its availability, and compare the
// item with others based on fields specified in its children classes.
class Item {
	protected:
		int total;
		int available;
		char format;
		string title;
		int year;
		
	public:

//****************************************************************Item()********************************************************************************
// Default constructor
//******************************************************************************************************************************************************
		Item();


//****************************************************************~Item()********************************************************************************
// Destructor
//******************************************************************************************************************************************************
		virtual ~Item();


//***************************************************************checkout()*****************************************************************************
// Decrease available by 1 and return true for that
// Used in the checkout command excute method
//******************************************************************************************************************************************************
		bool checkout(); 


//***************************************************************returnItem()**************************************************************************
// Increase available by 1 and return true for that
// Used in the return command excute method
//*****************************************************************************************************************************************************
		bool returnItem();	



//****************************************************************setTotal()****************************************************************************
// Bool pure virtual method to modify the total of a specific items when initializing the items library and return true
//******************************************************************************************************************************************************
		virtual bool setTotal() =0;


//*****************************************************************setData()****************************************************************************
// Bool pure virtual method to set data for a specicfic item according to a specific sequence to read these data from the file
// set avialable to either 5 or 1
//******************************************************************************************************************************************************
		virtual void setData(istream&) =0;


//*****************************************************************setDataToSearch()********************************************************************
// Bool pure virtual method to set data for a specicfic item (to search for later and retrieve) according to another specific sequence to read these
// data from the file
// Reading only author, title and year
//******************************************************************************************************************************************************
		virtual void setDataToSearch(istream&) =0;


//*************************************************************getAvailable()***************************************************************************
// Pure virtual method return int available
//******************************************************************************************************************************************************
		virtual int getAvailable();


//**************************************************************create()******************************************************************************
// Return a new empty youth book item
//****************************************************************************************************************************************************
		virtual Item* create() =0;	


//************************************************************************display()*********************************************************************
// Void pure virtual method to display data of the fiction book item in any specific order
//******************************************************************************************************************************************************
		virtual void display() const =0;
		

//********************************************************************displayInHistory()****************************************************************
// Void pure virtual method to display data of the fiction book item when displaying history required in any specific order
//******************************************************************************************************************************************************
		virtual void displayInHistory() const =0;


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


