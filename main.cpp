
#include <list>
#include <mylist/mylist.h>
#include <iostream>

int main()
{
    int size = 2;
    int value = 1;

    //MyList<int> mylist1;
    //mylist1.assign(size, value);

    MyList<int> myList(size,value);

    std::cout << "---" << std::endl;
    return 1;
}

