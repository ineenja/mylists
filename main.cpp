
#include <list>
#include <mylist/mylist.h>
#include <iostream>

int main()
{


    MyList<int> myList;

    myList.pushBack(1);
    myList.pushBack(1);

    auto iter = myList.begin();
    iter++;

    myList.insert(iter, 2,1);

    for (iter = myList.begin(); iter != myList.end(); iter++) {
        std::cout << *iter << std::endl;
    }

    std::cout << myList.getSize() << std::endl;

}

