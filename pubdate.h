#pragma once
#include <string>
#include "pubdate.h"


//-----------------------------------------------------------------------------
// pubDate is a data container for use in Periodical and Book objects.  They
// specify the publish date of the objects (month, day, and year, if available)
class pubDate {
	private:
		int year;
		int month;
		int day;
		
	public:
		pubDate(int m, int d, int y);	// constructor
		~pubDate();						// destructor
		
		bool setDate(int m, int d, int y);
			// month = m, day = d, year = y;
			// if any ints are invalid, return false
		string getDate();
			// print month/day/year
			
};