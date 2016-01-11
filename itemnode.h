#pragma once

#include "item.h"
using namespace std;


//-----------------------------------------------------------------------------
// ItemNode is a data container for use in the CategoryHash object.  ItemNodes
// function as BST nodes, held in ItemTree, pointing to left/right children.  
class ItemNode {
	private:
		Item *item;
		ItemNode *left;
		ItemNode *right;
		
	public:

//******************************************************************ItemNode()**************************************************************************
// Default constructor set item* to the passed itemData* and set both left and right to NULL
//******************************************************************************************************************************************************
		ItemNode(Item* itemData); 


//**********************************************************************~ItemNode()*********************************************************************
// Destructor deallocates all allocated memory using deleteChildren() to delete left and right children and deleteItem() to delete Item
//******************************************************************************************************************************************************
		~ItemNode();	


//************************************************************************getItem()*********************************************************************
// Returns Item*
//******************************************************************************************************************************************************
		Item* getItem();


//******************************************************************setItem()***************************************************************************
// Stes item* to whatever passed
//******************************************************************************************************************************************************			
		void setItem(Item *item);


//*****************************************************************deleteChildren()**********************************************************************
// Delete bothe left and right children and their items recursively
//******************************************************************************************************************************************************
		void deleteChildren();


//*********************************************************************deleteItem()*********************************************************************
// Used in the destrucotr and it deletes item*
//******************************************************************************************************************************************************
		void deleteItem();
	

//*************************************************************************getLeft()********************************************************************
// Returns ItemNode* left 
//******************************************************************************************************************************************************
		ItemNode* getLeft();


//*************************************************************************getRight()********************************************************************
// Returns ItemNode* right 
//******************************************************************************************************************************************************			
		ItemNode* getRight();


//*************************************************************************setLeft()********************************************************************
// Sets left to whatever passed
//******************************************************************************************************************************************************			
		void setLeft(ItemNode *item);


//*************************************************************************setright()*******************************************************************
// Sets right to whatever passed
//******************************************************************************************************************************************************			
		void setRight(ItemNode *item);
};

