/*
    Comedy.cpp, a comedy movie of a dvd. Holds a title, director, ammount of stock in inventory, a genre, and year of release.

    Created by: Marcella Doan

    Debugged by:
    Steven Wenzel
    Long Ly
*/

#include "dvd.h"
#include "bstree.h"
#include "comedy.h"

/*----------------------------------------------------------
Comedy(): defult constructor. Leaves all fields by
genre blank.

params: none
*/
Comedy::Comedy()
{
    setGenre('F');
}

/*----------------------------------------------------------
Comedy(Commands command):
Constructor, passes in a command that contains all the needed data to create a Comedy object

params: Commands command
*/
Comedy::Comedy(Commands command)
{
    setTitle(command.getVector(3));
    setDirector(command.getVector(2));
    setStock(stoi(command.getVector(1)));
    setYear(stoi(command.getVector(4)));
    setGenre('F');

    setHashString(command.getVector(3) + command.getVector(4));
}

/*----------------------------------------------------------
Comedy(Commands command):
Constructor, passes in the minimally needed data to create
a Comedy object that can be sorted.

params: Commands string title, int year
*/
Comedy::Comedy(string title, int year)
{
    setTitle(title);
    setYear(year);

    setHashString(title + to_string(year));
}

// destructor
Comedy::~Comedy()
{
}

/*----------------------------------------------------------
operator==(const Comedy &rhs) const

returns true if the two comedy object have the same title,
director, year, and genre

params: const Comedy &rhs
*/

bool Comedy::operator==(const Comedy &rhs) const
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
isEqual(const Comedy &rhs):

compares two comedy objects to see if there equal only using
the data relevent to sorting. True if equal, false if not.

params: const Comedy &rhs

returns: bool
*/
bool Comedy::isEqual(const Comedy &rhs) const
{
    if (&rhs != nullptr)
    {
        if (getTitle() == rhs.getTitle() && getYear() == rhs.getYear())
        {
            return true;
        }
    }

    return false;
}

/*----------------------------------------------------------
operator!=(const Comedy& rhs) const:

checks if two comedy obejcts are not equal. This is a comparison
of the director, the title, genre and year date.

returns true if not equal, returns false if equal

params: const Comedy& rhs

returns: bool
*/
bool Comedy::operator!=(const Comedy &rhs) const
{
    return !(*this == rhs);
}

// comparison overloads - sorted by title then year

/*----------------------------------------------------------
operator>(const Comedy &rhs) const:

greater than comparison overload, sorts by title then year.
True if greater, false if less then.

params: const Comedy &rhs

returns: bool
*/
bool Comedy::operator>(const Comedy &rhs) const
{
    if (getTitle() > rhs.getTitle())
    {
        return true;
    }
    else if (getTitle() == rhs.getTitle() && getYear() > rhs.getYear())
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*----------------------------------------------------------
operator<(const Comedy &rhs) const:

less than comparison overload, sorts by title then year.
True if less than, false if greater then.

params: const Comedy &rhs

returns: bool
*/
bool Comedy::operator<(const Comedy &rhs) const
{
    if (getTitle() > rhs.getTitle())
    {
        return false;
    }
    else if (getTitle() == rhs.getTitle() && getYear() > rhs.getYear())
    {
        return false;
    }
    else if (getYear() == rhs.getYear() && getTitle() == rhs.getTitle())
    {
        return false;
    }
    else
    {
        return true;
    }
}

/*----------------------------------------------------------
operator+(const Comedy &rhs) const

Creates a new comedy object with the combined value of the
two objects used to create it (the stock).

params: const Comedy &rhs

returns: Comedy object

*/
Comedy Comedy::operator+(const Comedy &rhs) const
{
    Comedy comedy;
    comedy = *this;
    comedy.setStock(getStock() + rhs.getStock());
    return comedy;
}

/*----------------------------------------------------------
operator+= (const Comedy& rhs):

Gives the calling comedy object the combined value of the
two objects added together (the stock).

params: const Comedy &rhs

returns: Comedy &object
*/
Comedy &Comedy::operator+=(const Comedy &rhs)
{
    setStock(getStock() + rhs.getStock());
    return *this;
}

/*----------------------------------------------------------
operator=(const Comedy& rhs):

Assignment opperator. Gives the values of the right
hand object to the calling left hand object.

params: const Comedy &rhs

returns: Comedy &comedy

*/
Comedy &Comedy::operator=(const Comedy &rhs)
{
    // string title = "title";
    setTitle(rhs.getTitle());
    setDirector(rhs.getDirector());
    setStock(rhs.getStock());
    setYear(rhs.getYear());
    setGenre(rhs.getGenre());

    return *this;
}

/*----------------------------------------------------------
ostream &operator<<(ostream &stream, const Comedy &Comedy):

outstream overload, prints out the Comedy objects data
what used with a ostream. 

params: ostream &stream, const Comedy &comedy

returns: ostream &
*/
ostream &operator<<(ostream &stream, const Comedy &comedy)
{
    stream << comedy.getGenre() << ", " << comedy.getStock() << ", " << comedy.getDirector() << ", " << comedy.getTitle() << ", " << comedy.getYear();

    return stream;
}
