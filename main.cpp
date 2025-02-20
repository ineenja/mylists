
#include "mylist/include/mylist/mylist.h"
#include <list>
#include <iostream>

struct President
{
    std::string name;
    std::string country;
    int year;
    bool wasMoved = false;
    bool wasConstructed = false;

    President(std::string && p_name, std::string && p_country, int p_year)
        : name(std::move(p_name)), country(std::move(p_country)), year(p_year)
    {
        wasConstructed = true;
    }
    President(President&& other)
        : name(std::move(other.name)), country(std::move(other.country)), year(other.year)
    {
        wasMoved = true;
    }
    President& operator=(President& other) = default;
};

int main()
{

    MyList<President> elections;
    elections.emplaceBack("Nelson Mandela", "South Africa", 1994);
    std::cout << elections.front().wasMoved << std::endl;

    MyList<President> reElections;
    reElections.pushBack(President("Franklin Delano Roosevelt", "the USA", 1936));
    std::cout << elections.front().wasMoved << std::endl;
}

