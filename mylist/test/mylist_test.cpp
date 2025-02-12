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

    EXPECT_EQ(myList.empty(), testList.empty());
}

/// тест конструктора, заполняющего список count количеством копий элемента со значением value
 TEST(MyListTests, Constructor2HoldValues) {

     int size = 2;
     int value = 1;
     MyList<int> myList(size,value);
     std::list<int> testList(size, value);

     EXPECT_EQ(myList.front(), testList.front());
     EXPECT_EQ(myList.back(), testList.back());
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

    EXPECT_EQ(myList.getSize(), testList.size());

    myList.pushBack(1);
    testList.push_back(1);

    EXPECT_EQ(myList.getSize(), testList.size());
}

/// Тест возможности передачи ссылки на последний элемент списка посредством проверки его значения
TEST(MyListTests, backCheck) {

    MyList<int> myList;
    std::list<int> testList;

    myList.pushBack(1);
    testList.push_back(1);

    EXPECT_EQ(myList.back(), testList.back());

    myList.pushBack(2);
    testList.push_back(2);

    EXPECT_EQ(myList.back(), testList.back());
}

/// Тест возможности изменения последнего элемента списка по передаваемой ссылке
TEST(MyListTests, backCheckChangingValueCheck) {

    MyList<int> myList;
    std::list<int> testList;

    myList.pushBack(1);
    testList.push_back(1);

    myList.back() += 1;
    testList.back() += 1;

    EXPECT_EQ(myList.back(), testList.back());
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

    EXPECT_EQ(myList.getSize(), testList.size());

    myList.pushFront(1);
    testList.push_front(1);

    EXPECT_EQ(myList.getSize(), testList.size());
}

/// Тест возможности передачи ссылки на первый элемент списка посредством проверки его значения
TEST(MyListTests, frontCheck) {

    MyList<int> myList;
    std::list<int> testList;

    myList.pushBack(1);
    testList.push_back(1);

    EXPECT_EQ(myList.front(), testList.front());

    myList.pushBack(2);
    testList.push_back(2);

    EXPECT_EQ(myList.front(), testList.front());
}

/// Тест возможности изменения значения первого элемента списка по передаваемой ссылке на него
TEST(MyListTests, frontCheckChangingValueCheck) {

    MyList<int> myList;
    std::list<int> testList;

    myList.pushBack(1);
    testList.push_back(1);

    myList.back() += 1;
    testList.back() += 1;

    EXPECT_EQ(myList.front(), testList.front());
}

////////////////////////////////////////////////////////////
/// ТЕСТЫ УДАЛЕНИЯ ПЕРВОГО И ПОСЛЕДНЕГО ЭЛЕМЕНТОВ СПИСКА ///
////////////////////////////////////////////////////////////

/// Проверка количества элементов после удаления последних элементов списка,
/// и не будет ли ошибки при удалении последнего элемента у пустого списка
TEST(MyListTests, popBackCheckSize) {

    MyList<int> myList;
    std::list<int> testList;

    myList.pushBack(1);
    testList.push_back(1);

    myList.pushBack(1);
    testList.push_back(1);

    myList.popBack();
    testList.pop_back();

    EXPECT_EQ(myList.getSize(), testList.size());

    myList.popBack();
    testList.pop_back();

    EXPECT_EQ(myList.getSize(), testList.size());

    myList.popBack();
}

/// Проверка количества элементов после удаления первых элементов списка
/// и не будет ли ошибки после удаления первого элемента у пустого списка
TEST(MyListTests, popFrontCheckSize) {

    MyList<int> myList;
    std::list<int> testList;

    myList.pushBack(1);
    testList.push_back(1);

    myList.pushBack(1);
    testList.push_back(1);

    myList.popFront();
    testList.pop_front();

    EXPECT_EQ(myList.getSize(), testList.size());

    myList.popFront();
    testList.pop_front();

    EXPECT_EQ(myList.getSize(), testList.size());

    myList.popFront();
}

/// Тест функции очищения списка
TEST(MyListTests, clearListCheck) {

    MyList<int> myList;
    std::list<int> testList;

    myList.clearList(); // вызов очистки пустого списка
    testList.clear();

    myList.pushBack(1);
    testList.push_back(1);

    myList.pushBack(1);
    testList.push_back(1);

    myList.clearList(); // обычная очистка списка
    testList.clear();

    EXPECT_EQ(myList.getSize(), testList.size());

    myList.clearList(); // попытка очистить список, который уже был очищен
    testList.clear();
}

/////////////////////////////////////////////////////////////////////////////////////
//////////////////// ТЕСТЫ ФУНКЦИЙ НА РАБОТУ С ЭЛЕМЕНТАМИ СПИСКА ////////////////////
/////////////////////////////////////////////////////////////////////////////////////

/// тест функции замены содержимого пустого списка на некоторое количество одинаковых элементов
TEST(MyListTests, assignCheckEmpty) {

    MyList<int> myList;
    std::list<int> testList;

    myList.assign(2, 2);
    testList.assign(2, 2);

    EXPECT_EQ(myList.front(), testList.front());
    EXPECT_EQ(myList.back(), testList.back());
}

/// тест функции замены содержимого не пустого списка на некоторое количество одинаковых элементов
TEST(MyListTests, assignCheckNotEmpty) {

    MyList<int> myList;
    std::list<int> testList;

    myList.pushBack(1);
    testList.push_back(1);

    myList.pushBack(1);
    testList.push_back(1);

    myList.assign(2, 2);
    testList.assign(2, 2);

    EXPECT_EQ(myList.front(), testList.front());
    EXPECT_EQ(myList.back(), testList.back());
}


/////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// ТЕСТЫ ИТЕРАТОРА //////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

/// тест возвращения итератора на первый узел списка и оператора разыменования
 TEST(MyListTests, beginCheck) {

     MyList<int> myList;

     myList.pushBack(1);
     myList.pushBack(2);
     myList.pushBack(3);

     auto iter = myList.begin();

     EXPECT_EQ(myList.front(), *iter);
 }

 /// тест возвращения итератора на первый узел списка и оператора декремента
  TEST(MyListTests, endCheck) {

      MyList<int> myList;

      myList.pushBack(1);
      myList.pushBack(2);
      myList.pushBack(3);

      auto iter = myList.end()--;

      EXPECT_EQ(myList.back(), *iter);

      iter--;

      EXPECT_EQ(2, *iter);
  }

  /// тест префиксного инкремента
   TEST(MyListTests, prefixIncrementCheck) {

       MyList<int> myList;

       myList.pushBack(1);
       myList.pushBack(2);
       myList.pushBack(3);

       auto iter = myList.begin();
       EXPECT_EQ(1, *iter);

       iter++;
       EXPECT_EQ(2, *iter);

       iter++;
       EXPECT_EQ(3, *iter);
   }

   /// тест постфиксного инкремента
    TEST(MyListTests, postfixIncrementCheck) {

        MyList<int> myList;

        myList.pushBack(1);
        myList.pushBack(2);
        myList.pushBack(3);

        auto iter = myList.begin();

        ++iter;
        EXPECT_EQ(2, *iter);

        ++iter;
        EXPECT_EQ(3, *iter);
    }

    /// тест префиксного декремента
     TEST(MyListTests, prefixDecrementCheck) {

         MyList<int> myList;

         myList.pushBack(1);
         myList.pushBack(2);
         myList.pushBack(3);

         auto iter = myList.end()--;
         EXPECT_EQ(3, *iter);

         iter--;
         EXPECT_EQ(2, *iter);

         iter--;
         EXPECT_EQ(1, *iter);
     }

     /// тест постфиксного инкремента
      TEST(MyListTests, postfixDecrementCheck) {

          MyList<int> myList;

          myList.pushBack(1);
          myList.pushBack(2);
          myList.pushBack(3);

          auto iter = myList.end();

          --iter;
          EXPECT_EQ(2, *iter);

          --iter;
          EXPECT_EQ(1, *iter);
      }
