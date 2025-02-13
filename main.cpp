
#include <list>
#include <mylist/mylist.h>
#include <iostream>

int main()
{

    MyList<int> myList;
    MyList<int> testList;

    myList.pushBack(1);
    myList.pushBack(2);
    myList.pushBack(3);

    auto iter = myList.begin();
    std::cout << *iter << " - element of original list" << std::endl;
    iter++;
    std::cout << *iter << " - element of original list" << std::endl;
    iter++;
    std::cout << *iter << " - element of original list" << std::endl;
    iter++;
    if (nullptr == myList.end()) {

        std::cout << "original list is over" << std::endl << std::endl;
    }

    testList = myList;

    auto iter1 = myList.begin();
    auto iter2 = testList.begin();

    if (*iter1 == *iter2) {
        std::cout << "1 equal to " << *iter1 << std::endl;
    }
    iter1++; iter2++;
    if (*iter1 == *iter2) {
        std::cout << "2 equal to " << *iter1 << std::endl;
    }
    iter1++; iter2++;
    if (*iter1 == *iter2) {
        std::cout << "3 equal to " << *iter1 << std::endl;
    }

}

