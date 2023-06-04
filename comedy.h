/*
    Comedy.h, the h file for Comedy.cpp, a comedy movie of a dvd. Holds a title, director, ammount of stock in inventory, a genre, and year of release.

    Created by: Marcella Doan

    Debugged by:
    Steven Wenzel
    Long Ly
*/

#ifndef COMEDY_H
#define COMEDY_H

#include "dvd.h"
#include "bstree.h"

class Comedy : public Dvd
{
public:
	Comedy();
	Comedy(Commands command); //build the item with the data from the comand object.
	Comedy(string title, int year); 
	~Comedy();
	
	//comparison overloads - sorted by title then year
	bool operator==(const Comedy& rhs) const;
	bool operator!=(const Comedy& rhs) const;
	bool operator>(const Comedy& rhs) const;
	bool operator<(const Comedy& rhs) const;

	Comedy& operator=(const Comedy& rhs);
	Comedy operator+ (const Comedy& rhs) const;
	Comedy& operator+= (const Comedy& rhs);
	
	bool isEqual(const Comedy& rhs) const;

	//stream overloads
	// display all the info 
	friend ostream& operator<< (ostream& stream, const Comedy& comedy);

private:
};
#endif // COMEDY_H
