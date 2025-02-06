
#include <list>
#include <mylist/mylist.h>
#include <iostream>

int main()
{

    //MyList<int> mylist(1,1);
    MyList<int> mylist;
    mylist.pushBack(1);
    mylist.pushBack(2);
    mylist.pushBack(3);

    std::cout << mylist.front()->value << std::endl;
    std::cout << mylist.back()->value << std::endl;

    mylist.popFront();

    std::cout << mylist.front()->value << std::endl;

    std::cout << "---" << std::endl;
    return 1;
}
