
#include <list>
#include <mylist/mylist.h>
#include <iostream>

void counter() {
    static int count = 0;
    std::cout << count++;
}

int main()
{
    for (size_t i =0; i < 10; i++) {
        counter();
    }

}

