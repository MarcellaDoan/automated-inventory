/*
    Classic.cpp: A classic movie of a dvd, holds a title, director, ammount of stock in inventory, a genre, date of release, and 
    major actors. 

    Created by: Marcella Doan

    Debugged by: 
    Steven Wenzel
    Long Ly

*/
#ifndef CLASSIC_CPP
#define CLASSIC_CPP

#include "classic.h"
#include <vector>
#include <sstream>

/*----------------------------------------------------------
Classic(): default constructor, sets the genre to 'C'
but nothing else is filled out.

params: none
*/

Classic::Classic()
{
    setGenre('C');
}

// passes in a command that contains all the needed data to create a Classic object

/*----------------------------------------------------------
Classic(Command command): given the command object it pulls
out all the needed data and inserts into the Classic object.

params: Command command
*/
Classic::Classic(Commands command)
{
    setTitle(command.getVector(3));
    setDirector(command.getVector(2));
    setStock(stoi(command.getVector(1)));
    // setYear(command.getVector(4));
    setGenre('C');

    vector<string> actorAndDate = command.spaceParser(command.getVector(4));
    // vector<string> actorAndDate = command.spaceSplitter(4);
    string temp = actorAndDate[0] + " " + actorAndDate[1];
    addMajorActor(temp);
    int month = (stoi(actorAndDate[2]));
    setMonth(month);
    int year = stoi(actorAndDate[3]);
    setYear(year);

    setHashString(to_string(month) + to_string(year) + temp);
}

/*----------------------------------------------------------
Classic(int month, int year, string firstName, string lastName)
Constructor: Takes in the information only need to sort it.

params: int month, int year, string firstName, string lastName
{
*/
Classic::Classic(int month, int year, string firstName, string lastName)
{
    setMonth(month);
    setYear(year);
    string actor = firstName + " " + lastName;
    addMajorActor(actor);

    setHashString(to_string(month) + to_string(year) + actor);
}

// destructor: has no dynamic memory to free
Classic::~Classic()
{
}

/*----------------------------------------------------------
setMonth(const int newMonth):

sets the month to the given integer as long as that number
is betweeen 1 and 12, else the month will be defaulted to
12 and an error message will be printed.

params: const int newMonth;

returns: none
*/
void Classic::setMonth(const int newMonth)
{
    if (newMonth > 12 || newMonth < 1)
    {
        month = 12;
        cout << "Month given was not between 1 and 12, the month has been defaulted to 12" << endl;
    }
    else
    {
        month = newMonth;
    }
}

/*----------------------------------------------------------
int getMonth():
returns the month of the classic object

params: none

returns: int month
*/
int Classic::getMonth() const
{
    return month;
}

/*----------------------------------------------------------
    getMajorActor(int const index) const


    if the index is valid, the actor will be returned (first and last name in one string),
    through reference. True is retuned if it's found, false if not. 

    params: nt const index, string &actor

    returns: bool, string actor through reference
*/
bool Classic::getMajorActor(int const index, string &actor) const
{
    if (index < nextActorIndex)
    {
        actor = majorActors[index]; // I don't think this makes a copy?
        return true;
    }
    else
    {
        return false;
    }
}

/*----------------------------------------------------------
int getNumberOfActors() const:
returns the number of actors that the classic objects has
(this is also the index of the next open spot in the vector
that holds the major actors)

params: none

returns: int numOfActors
*/
int Classic::getNumberOfActors() const
{
    return nextActorIndex;
}

/*----------------------------------------------------------
addMajorActor(string actor):

adds a major actor to the classic object. String must be
first name and last naem with a space between
"firstName LastName"

params: string actor

returns: none
*/
void Classic::addMajorActor(string actor)
{
    // majorActors[nextActorIndex] = actor;
    majorActors.push_back(actor);
    nextActorIndex++;
}

bool Classic::hasMajorActor(string actor) const
{
    int numOfActors = getNumberOfActors();
    for (int i = 0; i < numOfActors; i++)
    {
        if (majorActors[i] == actor)
        {
            return true;
        }
    }

    return false;
}

/*----------------------------------------------------------
operator==(const Classic& rhs) const:

checks if two classic objects are equal. This is a comparison
of the director, the title, and the month and year date.
Does not consider the major actors, as there might
be two lines for the same classic movie but featuring a
different major actor.

returns true if equal, returns false if not equal

params: const Classic& rhs

returns: bool
*/
bool Classic::operator==(const Classic &rhs) const
{
    if (&rhs != nullptr)
    {
        if (getDirector() == rhs.getDirector() && getTitle() == rhs.getTitle() && getYear() == rhs.getYear() && getMonth() == rhs.getMonth())
        {
            return true;
        }
    }

    return false;
}

/*----------------------------------------------------------
isEqual(const Classic &rhs): 

compares two classic object to see if there equal only using
the data relevent to sorting. True if equal, false if not.

params: const Classic &rhs

returns: bool
*/
bool Classic::isEqual(const Classic &rhs) const
{
    if (&rhs != nullptr)
    {
        if (getYear() == rhs.getYear() && getMonth() == rhs.getMonth())
        {
            for (int i = 0; i < rhs.getNumberOfActors(); i++)
            {
                string actor;
                rhs.getMajorActor(i, actor);

                if (majorActors[0] == actor)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

/*----------------------------------------------------------
operator!=(const Classic& rhs) const:

checks if two classic obejcts are not equal. This is a comparison
of the director, the title, and the month and year date.
Does not consider the major actors, as there might
be two lines for the same classic movie but featuring a
different major actor.

returns true if not equal, returns false if equal

params: const Classic& rhs

returns: bool
*/
bool Classic::operator!=(const Classic &rhs) const
{
    return !(*this == rhs);
}

// sorted by release date and major actor, the first major actor added

/*----------------------------------------------------------
bool operator>(const Classic& rhs):

compares two classic objects, returns true if the classic
object on the left (the calling object) is greater than
the classic object on the right.

Comparison is based off the the release date, and the first major actor
listed.

params: const Classic& rhs

returns: bool
*/
bool Classic::operator>(const Classic &rhs) const
{
    string actor1;
    string actor2;
    getMajorActor(0, actor1);
    rhs.getMajorActor(0, actor2);

    if (getYear() > rhs.getYear())
    {
        return true;
    }
    else if (getYear() == rhs.getYear() && getMonth() > rhs.getMonth())
    {
        return true;
    }
    else if (getYear() == rhs.getYear() && getMonth() == rhs.getMonth() && actor1 > actor2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*----------------------------------------------------------
bool operator>(const Classic& rhs):

compares two classic objects, returns true if the classic
object on the left (the calling object) is less than
the classic object on the right.

Comparison is based off the the release date, and the first major actor
listed.

params: const Classic& rhs

returns: bool
*/
bool Classic::operator<(const Classic &rhs) const
{
    string actor1;
    string actor2;
    getMajorActor(0, actor1);
    rhs.getMajorActor(0, actor2);

    if (getYear() < rhs.getYear())
    {
        return true;
    }
    else if (getYear() == rhs.getYear() && getMonth() < rhs.getMonth())
    {
        return true;
    }
    else if (getYear() == rhs.getYear() && getMonth() == rhs.getMonth() && actor1 < actor2)
    {
        return true;
    }
    else if (getYear() == rhs.getYear() && getMonth() == rhs.getMonth() && actor1 == actor2)
    {
        return false;
    }
    else
    {
        return false;
    }
}

/*----------------------------------------------------------
operator+(const Classic &rhs) const:

Creates a new classic object with the combined value of the
two objects used to create it (the stock and the actors).

params: const Classic &rhs

returns: Classic object
*/
Classic Classic::operator+(const Classic &rhs) const
{
    Classic classic;
    classic = *this;

    classic.setStock(classic.getStock() + rhs.getStock());

    string actor;
    int numOfActors = rhs.getNumberOfActors();
    for (int i = 0; i < numOfActors; i++)
    {
        rhs.getMajorActor(i, actor);

        if (classic.hasMajorActor(actor) == false)
        {
            classic.addMajorActor(actor);
        }
    }

    return classic;
}

/*----------------------------------------------------------
Classic& operator+= (const Classic& rhs):

Gives the calling classic object the combined value of the
two objects added together (the stock and the actors).

params: const Classic &rhs

returns: Classic &object

*/
Classic &Classic::operator+=(const Classic &rhs)
{
    setStock(getStock() + rhs.getStock());

    string actor;
    int numOfActors = rhs.getNumberOfActors();
    for (int i = 0; i < numOfActors; i++)
    {
        rhs.getMajorActor(i, actor);

        if (hasMajorActor(actor) == false)
        {
            addMajorActor(actor);
        }
    }
    return *this; 
}

/*----------------------------------------------------------
Classic& operator=(const Classic& rhs):

Assignment opperator. Gives the values of the right
hand object to the calling left hand object.

params: const Classic &rhs

returns: Classic &classic

*/
Classic &Classic::operator=(const Classic &rhs)
{
    setTitle(rhs.getTitle());
    setDirector(rhs.getDirector());
    setStock(rhs.getStock());
    setYear(rhs.getYear());
    setGenre(rhs.getGenre());

    string actor;
    int numOfActors = rhs.getNumberOfActors();
    for (int i = 0; i < numOfActors; i++)
    {
        rhs.getMajorActor(i, actor);
        if (hasMajorActor(actor) == false)
        {
            addMajorActor(actor);
        }
    }

    return *this;
}

/*----------------------------------------------------------
ostream &operator<<(ostream &stream, const Classic &classic):

outstream overload, prints out the classic objects data
what used with a ostream. 

params: ostream &stream, const Classic &classic

returns: ostream &
*/
ostream &operator<<(ostream &stream, const Classic &classic)
{
    string actor;

    stream << classic.getGenre() << ", " << classic.getStock() << ", " << classic.getDirector() << ", " << classic.getTitle() << ", ";

    for (int i = 0; i < classic.getNumberOfActors(); i++) // prints all the actors
    {
        classic.getMajorActor(i, actor);
        stream << actor << ", ";
    }

    stream << classic.getMonth() << " " << classic.getYear();

    return stream;
}

#endif // CLASSIC_H

