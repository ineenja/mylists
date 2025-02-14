
//#include <mylist/mylist.h>
#include <list>
#include <iostream>

int main()
{
    std::list<int> list = {1,2,3};
    std::list<std::list<int>> lists;

    lists.push_back(list);
    std::cout << list.empty() << std::endl;

    lists.emplace_back(list);
    std::cout << list.empty() << std::endl;
}

