/*
    Drama.h, the h file for Drama.cpp, a drama movie of a dvd. Holds a title, director, ammount of stock in inventory, a genre, and year of release.

    Created by: Marcella Doan

    Debugged by:
    Steven Wenzel
    Long Ly
*/

#ifndef DRAMA_H
#define DRAMA_H

#include "dvd.h"
#include "bstree.h"

class Drama : public Dvd
{
public:
	Drama();
	// passes in a command that contains all the needed data to create a Drama object
	Drama(Commands command);
	Drama(string director, string title); 
	~Drama();



	//comparison overloads - sorted by director then title
	bool operator==(const Drama& rhs) const;
	bool operator!=(const Drama& rhs) const;
	bool operator>(const Drama& rhs) const;
	bool operator<(const Drama& rhs) const;

	Drama operator+ (const Drama& rhs) const; 
    Drama& operator+= (const Drama& rhs); 
	Drama& operator=(const Drama& rhs);

	bool isEqual(const Drama& rhs) const;

	//stream overloads
	// display all the info 
	friend ostream& operator<< (ostream& stream, const Drama& drama);

private:

};
#endif
