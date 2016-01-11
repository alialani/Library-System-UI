#include "librarysystem.h"



//*****************************************************************main()***************************************************************************
// Calls activate() to initialize books and patron accounts data in the library
// Calls run() to perform commands
//******************************************************************************************************************************************************
int main () {
	LibrarySystem manager;	
	
	manager.activate();
	manager.run();
	return 0;
}

