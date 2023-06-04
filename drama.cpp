/*
    Drama.cpp, a drama movie of a dvd. Holds a title, director, ammount of stock in inventory, a genre, and year of release.

    Created by: Marcella Doan

    Debugged by:
    Steven Wenzel
    Long Ly
*/

#ifndef DRAMA_CPP
#define DRAMA_CPP

#include "drama.h"

/*----------------------------------------------------------
Drama(): default constructor. Only sets genre.

params: none
*/
Drama::Drama()
{
    setGenre('D');
}

/*----------------------------------------------------------
Drama(Commands command):

Constructor, passes in a command that contains all the needed data to create a Drama object

params: Commands command
*/
Drama::Drama(Commands command)
{
    setTitle(command.getVector(3));
    setDirector(command.getVector(2));
    setStock(stoi(command.getVector(1)));
    setYear(stoi(command.getVector(4)));
    setGenre('D');

    setHashString(command.getVector(3) + command.getVector(2));
}

/*----------------------------------------------------------
Drama(string director, string title):

Constructor, passes in the minimal sorting data to create 
a Drama object

params: string director, string title
*/
Drama::Drama(string director, string title)
{
    setDirector(director);
    setTitle(title);

    setHashString(title + director);
}

//destructor, no dynamic memory to delete
Drama::~Drama()
{
}



/*----------------------------------------------------------
operator==(const Drama &rhs) const:

checks if the two drama objects are equal, comparing
tite, director, genre, and year. 

true is equal, false if not. 

params: const Drama &rhs

returns: bool
*/
bool Drama::operator==(const Drama &rhs) const
{
    if (&rhs != nullptr)
    {
        if (getTitle() == rhs.getTitle() && getDirector() == rhs.getDirector() && getYear() == rhs.getYear() && getGenre() == rhs.getGenre())
        {
            return true;
        }
    }

    return false;
}

/*----------------------------------------------------------
isEqual(const Drama &rhs): 

compares two drama objects to see if there equal only using
the data relevent to sorting. True if equal, false if not.

params: const Drama &rhs

returns: bool
*/
bool Drama::isEqual(const Drama &rhs) const
{
    if (&rhs != nullptr)
    {
        if (getTitle() == rhs.getTitle() && getDirector() == rhs.getDirector())
        {
            return true;
        }
    }

    return false;
}

/*----------------------------------------------------------
operator!=(const Drama &rhs) const:

returns true if the two drama object are not equal, reutrns
false if they are equal. 

params: const Drama &rhs

return: bool
*/
bool Drama::operator!=(const Drama &rhs) const
{
    return !(*this == rhs);
}

/*----------------------------------------------------------
operator>(const Drama &rhs) const

returns true if the left hand drama object is greater than,
false if it's less than.

params: const Drama &rhs

returns: bool
*/
bool Drama::operator>(const Drama &rhs) const
{
    // director then Title
    if (getDirector() > rhs.getDirector())
    {
        return true;
    }
    else if (getDirector() == rhs.getDirector() && getTitle() > rhs.getTitle())
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*----------------------------------------------------------
operator<(const Drama &rhs) const

returns true if the left hand drama object is less than,
false if it's greater than.

params: const Drama &rhs

returns: bool
*/
bool Drama::operator<(const Drama &rhs) const
{
    if (getDirector() > rhs.getDirector())
    {
        return false;
    }
    else if (getDirector() == rhs.getDirector() && getTitle() > rhs.getTitle())
    {
        return false;
    }
    else if (getDirector() == rhs.getDirector() && getTitle() == rhs.getTitle())
    {
        return false;
    }
    else
    {
        return true;
    }
}

/*----------------------------------------------------------
operator+(const Drama &rhs) const

Creates a new drama object with the combined value of the
two objects used to create it (the stock).

params: const Drama &rhs

returns: Drama object

*/
Drama Drama::operator+(const Drama &rhs) const
{
    Drama drama;
    drama = *this;
    drama.setStock(getStock() + rhs.getStock());
    return drama;
}

/*----------------------------------------------------------
operator+= (const Drama& rhs):

Gives the calling Drama object the combined value of the
two objects added together (the stock).

params: const Drama &rhs

returns: Drama &object
*/
Drama &Drama::operator+=(const Drama &rhs)
{
    setStock(getStock() + rhs.getStock());
    return *this;
}

/*----------------------------------------------------------
operator=(const Drama& rhs):

Assignment opperator. Gives the values of the right
hand object to the calling left hand object.

params: const Drama &rhs

returns: Drama &drama

*/
Drama &Drama::operator=(const Drama &rhs)
{
    setTitle(rhs.getTitle());
    setDirector(rhs.getDirector());
    setStock(rhs.getStock());
    setYear(rhs.getYear());
    setGenre(rhs.getGenre());

    return *this;
}

/*----------------------------------------------------------
ostream &operator<<(ostream &stream, const Drama &drama):

outstream overload, prints out the Drama objects data
what used with a ostream. 

params: ostream &stream, const Drama &drama

returns: ostream &
*/
ostream &operator<<(ostream &stream, const Drama &drama)
{
    stream << drama.getGenre() << ", " << drama.getStock() << ", " << drama.getDirector() << ", " << drama.getTitle() << ", " << drama.getYear();

    return stream;
}

#endif
