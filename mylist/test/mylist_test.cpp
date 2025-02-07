#include <gtest/gtest.h>
#include <iostream>
#include <list>
#include <mylist/mylist.h>

//////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// ТЕСТЫ ДЛЯ КОНСТРУКТОРОВ ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

/// тест конструктора по умолчанию
TEST(MyListTests, Constructor1IsEmpty) {

    MyList<int> myList;
    std::list<int> testList;

    ASSERT_EQ(myList.empty(), testList.empty());
}

//////////////////////////////////////////////////////////////////////////////////////////////
/////// ТЕСТЫ ПЕРЕДАЧИ ПОСЛЕДНЕГО ЭЛЕМЕНТА СПИСКА И ДОБАВЛЕНИЯ ЭЛЕМЕНТА В КОНЕЦ СПИСКА ///////
//////////////////////////////////////////////////////////////////////////////////////////////

/// Тест на количество элементов списка после добавления нескольких элементов в его конец
TEST(MyListTests, pushBackCheckSize) {

    MyList<int> myList;
    std::list<int> testList;

    myList.pushBack(1);
    testList.push_back(1);

    ASSERT_EQ(myList.getSize(), testList.size());

    myList.pushBack(1);
    testList.push_back(1);

    ASSERT_EQ(myList.getSize(), testList.size());
}

/// Тест возможности передачи ссылки на последний элемент списка посредством проверки его значения
TEST(MyListTests, backCheck) {

    MyList<int> myList;
    std::list<int> testList;

    myList.pushBack(1);
    testList.push_back(1);

    ASSERT_EQ(myList.back(), testList.back());

    myList.pushBack(2);
    testList.push_back(2);

    ASSERT_EQ(myList.back(), testList.back());
}

/// Тест возможности изменения последнего элемента списка по передаваемой ссылке
TEST(MyListTests, backCheckChangingValueCheck) {

    MyList<int> myList;
    std::list<int> testList;

    myList.pushBack(1);
    testList.push_back(1);

    myList.back() += 1;
    testList.back() += 1;

    ASSERT_EQ(myList.back(), testList.back());
}

/////////////////////////////////////////////////////////////////////////////////////////////
////// ТЕСТЫ ВОЗВРАЩЕНИЯ ПЕРВОГО ЭЛЕМЕНТА СПИСКА И ДОБАВЛЕНИЯ ЭЛЕМЕНТА В НАЧАЛО СПИСКА //////
/////////////////////////////////////////////////////////////////////////////////////////////

/// Проверка размера списка после добавления элементов в начало
TEST(MyListTests, pushFrontCheckSize) {

    MyList<int> myList;
    std::list<int> testList;

    myList.pushFront(1);
    testList.push_front(1);

    ASSERT_EQ(myList.getSize(), testList.size());

    myList.pushFront(1);
    testList.push_front(1);

    ASSERT_EQ(myList.getSize(), testList.size());
}

/// Тест возможности передачи ссылки на первый элемент списка посредством проверки его значения
TEST(MyListTests, frontCheck) {

    MyList<int> myList;
    std::list<int> testList;

    myList.pushBack(1);
    testList.push_back(1);

    ASSERT_EQ(myList.front(), testList.front());

    myList.pushBack(2);
    testList.push_back(2);

    ASSERT_EQ(myList.front(), testList.front());
}

/// Тест возможности изменения значения первого элемента списка по передаваемой ссылке на него
TEST(MyListTests, frontCheckChangingValueCheck) {

    MyList<int> myList;
    std::list<int> testList;

    myList.pushBack(1);
    testList.push_back(1);

    myList.back() += 1;
    testList.back() += 1;

    ASSERT_EQ(myList.front(), testList.front());
}

////////////////////////////////////////////////////////////
/// ТЕСТЫ УДАЛЕНИЯ ПЕРВОГО И ПОСЛЕДНЕГО ЭЛЕМЕНТОВ СПИСКА ///
////////////////////////////////////////////////////////////

/// Проверка количества элементов после удаления последних элементов списка
TEST(MyListTests, popBackCheckSize) {

    MyList<int> myList;
    std::list<int> testList;

    myList.pushBack(1);
    testList.push_back(1);

    myList.pushBack(1);
    testList.push_back(1);

    myList.popBack();
    testList.pop_back();

    ASSERT_EQ(myList.getSize(), testList.size());

    myList.popBack();
    testList.pop_back();

    ASSERT_EQ(myList.getSize(), testList.size());
}

/// Проверка количества элементов после удаления первых элементов списка
TEST(MyListTests, popFrontCheckSize) {

    MyList<int> myList;
    std::list<int> testList;

    myList.pushBack(1);
    testList.push_back(1);

    myList.pushBack(1);
    testList.push_back(1);

    myList.popFront();
    testList.pop_front();

    ASSERT_EQ(myList.getSize(), testList.size());

    myList.popFront();
    testList.pop_front();

    ASSERT_EQ(myList.getSize(), testList.size());
}

/// проверка функции очищения списка
TEST(MyListTests, clearListCheck) {

    MyList<int> myList;
    std::list<int> testList;

    myList.pushBack(1);
    testList.push_back(1);

    myList.pushBack(1);
    testList.push_back(1);

    myList.clearList();
    testList.clear();

    ASSERT_EQ(myList.getSize(), testList.size());
}

// TEST(MyListTests, myIteratorTest) {
//
//     MyList<int> myList;
//
//     myList.pushBack(1);
//     myList.pushBack(2);
//     myList.pushBack(3);
//
//     int test = 1;
//     for (auto iter : myList) {
//         std::cout << iter << std::endl;
//     }
// }




