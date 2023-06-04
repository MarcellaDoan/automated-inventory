/*
    Classic.h: The h file for Classic.cpp, a classic movie of a dvd, holds a title, director, ammount of stock in inventory, a genre, date of release, and 
    major actors. 

    Created by: Marcella Doan

    Debugged by: 
    Steven Wenzel
    Long Ly
*/
#ifndef CLASSIC_H
#define CLASSIC_H

#include "dvd.h"

class Classic : public Dvd
{
public:
	Classic();
	Classic(Commands command);
	Classic(int month, int year, string firstName, string lastName); 
	~Classic();

	int getMonth() const;

	void setMonth(const int newMonth);

	bool getMajorActor(const int index, string &actor) const; //grabs a major actor from a certain index in the actor vector

	bool hasMajorActor(string actor) const;

	void addMajorActor(string actor); 

	int getNumberOfActors() const; //returns the number of major actors in this object 

	bool operator==(const Classic& rhs) const;
	bool operator!=(const Classic& rhs) const;
	bool operator>(const Classic& rhs) const;
	bool operator<(const Classic& rhs) const;

	//stream overloads
	// display all the info 
	friend ostream& operator<< (ostream& stream, const Classic& classic);

	Classic operator+ (const Classic& rhs) const;
    Classic& operator+= (const Classic& rhs); 
	Classic& operator=(const Classic& rhs); 

	bool isEqual(const Classic& rhs) const;
private:
	
	int month = 0;
	int nextActorIndex = 0; //the amount of actors

	vector<string> majorActors;
};
#endif // CLASSIC_H
