
#include <list>
#include <mylist/mylist.h>
#include <iostream>

int main()
{
    std::list<int> test;
    test.push_back(3);

    test.front() = 4;

    std::cout << test.front()+1 << std::endl;

    // MyList<int> mylist;
    //
    // mylist.pushBack(1);
    // mylist.pushBack(2);
    // mylist.pushBack(3);
    //
    // std::cout << mylist.front()->value << std::endl;
    // std::cout << mylist.back()->value << std::endl;
    //
    // mylist.popFront();
    //
    // std::cout << mylist.front()->value << std::endl;
    //
    // MyList<int> mylist2(1,1);

    // MyList<int> mylist3{1, 2, 3, 4};
    // std::cout << mylist3.front()->value << std::endl;
    // std::cout << mylist3.back()->value << std::endl;

    std::cout << "---" << std::endl;
    return 1;
}
