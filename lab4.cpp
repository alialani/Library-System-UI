#include "librarysystem.h"

int main () {
	LibrarySystem manager;
	
	manager.activate();
	manager.run();
	manager.close();
	
	return 0;
}