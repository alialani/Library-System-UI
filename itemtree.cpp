#include "itemtree.h"


//*******************************************************************ItemTree()*************************************************************************
//Defaul constructor set root to NULL
//******************************************************************************************************************************************************
ItemTree::ItemTree() {
	root = NULL;
}


//********************************************************************~ItemTree()***********************************************************************
// Destructor deallocates allocated memory using makeEmpty()
//******************************************************************************************************************************************************
ItemTree::~ItemTree() {	
	 makeEmpty();
}


//*********************************************************************makeEmpty()**********************************************************************
// Deallocates allocated memory deletes ItemNode* root and its children using deleteChildren() defined in ItemNode class
//******************************************************************************************************************************************************
void ItemTree::makeEmpty() {
	if (root != NULL) {
		root->deleteChildren();
		delete root;
		root = NULL;
	}
}



//***********************************************************************add()**************************************************************************
// Adds the passed ItemNode* to teh tree and returns true for it
//******************************************************************************************************************************************************
bool ItemTree::add(ItemNode* itemNode) {
	if (root == NULL){
		root = itemNode;
		return true;
	}else{
		ItemNode *current = root;
		bool inserted = false;
		while (!inserted) {
			if (*itemNode->getItem() == *current->getItem()) {
				// add 5 to the fiction or youth books available or only 1 to
				// the periodicals available
				current->getItem()->setTotal();
				return true;
			}
			if (*itemNode->getItem() < *current->getItem())
				if (current->getLeft() == NULL) {
					current->setLeft(itemNode);
					inserted = true;
				}
				else
					current = current->getLeft();
			else {
				if (current->getRight() == NULL) {
					current->setRight(itemNode);
					inserted = true;
				}
				else 
					current = current->getRight();
			}
		}
	}
	return true;
}



//***************************************************************retrieve()*****************************************************************************
// Returns true when the passed (Item* searchForItem) is found and set the passed (Item** retrievedItem) to it to be used oustside the method
// Returns false when not found
//******************************************************************************************************************************************************
bool ItemTree::retrieve(Item** retrievedItem, Item* searchForItem) const {
	ItemNode *current = root;
	while (current != NULL) {
		if (*current->getItem() == *searchForItem){
			*retrievedItem = current->getItem();
			return true;
		}
		else if (*searchForItem < *current->getItem()){
			current = current->getLeft();
		}else{
			current = current->getRight();
		}
	}
	retrievedItem = NULL;
	return false;
}


//****************************************************************display()*****************************************************************************
// Displays the ItemTree items using displayHelper()
//******************************************************************************************************************************************************
void ItemTree::display() const {
	displayHelper(root);
}


//*************************************************************displayHelper()**************************************************************************
// Displays the ItemTree items recusively with an in-order sort
//******************************************************************************************************************************************************
void ItemTree::displayHelper(ItemNode* root) const {
    if (root != NULL) {
        displayHelper(root->getLeft());
		// Displays data (accordding to the required equence) for each ItemNode in the
		// ItemTree using its own pure vitual display() method for every specific Item
        root->getItem()->display();			
		cout << endl;
        displayHelper(root->getRight());
    }
}

