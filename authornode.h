#pragma once
#include <string>
#include "authornode.h"


//-----------------------------------------------------------------------------
// AuthorNodes are data containers for use in Book objects.  They possess a
// node structure to accomodate for multiple authors.
class AuthorNode {
	private:
		string firstName;
		string lastName;
		AuthorNode *next;
		
	public:
		AuthorNode(string first, string last);	// constructor, must have name
		~AuthorNode();							// destructor
		
		void setName(string first, string last);
			// firstName = first; lastName = last;
		string getName();
			// return first + last;
	
};
