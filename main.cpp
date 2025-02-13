
#include <list>
#include <mylist/mylist.h>
#include <iostream>

int main()
{

    MyList<int> myList;

    myList.pushBack(1);
    myList.pushBack(5);

    auto iter = myList.begin();
    iter++;

    myList.insert(iter, {2,3,4});

    int check = 1;
    for (auto iter = myList.begin(); iter != myList.end(); iter++) {
        std::cout << check << " = " << *iter << std::endl;
        check++;
    }

    std::cout << myList.getSize() << std::endl;

}

