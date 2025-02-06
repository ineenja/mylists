#ifndef MYLIST
#define MYLIST

#include <algorithm>
#include <list>
#include <memory>

// используемая структура узла списка
template <typename Y>
struct Node {
    explicit Node(const Y& value, Node* prev = nullptr, Node* next = nullptr) : value(value), prev(prev), next(next) {};

    Y value;
    Node *prev;
    Node *next;
};

template <class T>
class MyList {

    Node<T>* first;
    Node<T>* last;
    size_t size;

public:
    //////////////////////////////////////////////////////////////
    /////////////////////// КОНСТРУКТОРЫ /////////////////////////
    //////////////////////////////////////////////////////////////

    // конструктор по умолчанию, создающий пустой контейнер
    explicit MyList() : first(nullptr), last(nullptr), size(0) {};

    // конструктор с числом count копий элемента имеющего значение value
    explicit MyList(size_t count, const T& value = nullptr) {
        MyList();
        size = count;
        for (size_t i = 0; i < count; i++) {
            pushBack(value);
        }
    };

    // конструктор копирования
    MyList(const MyList& other) {
        MyList();
        size = other.size;
        for (const T& value : other) {
            pushBack(value);
        }
    };

    // конструктор перемещения
    //MyList(MyList&& other) {
    //    MyList(other);
    //    other.clearList();
    //};

    // конструктор для создания контейнера с содержимым списка инициализации init
    MyList(std::initializer_list<T> init) {
        MyList();
        size = init.size();
        for (size_t i = 0; i < size; i++) {
            pushBack(init[i]);
        }
    };


    ////////////////////////////////////////////////////////
    ///////////// ДЕСТРУКТОР, ОЧИЩЕНИЕ ПАМЯТИ //////////////
    ////////////////////////////////////////////////////////

    ~MyList() {
        clearList();
    }

    void clearList() {
        while (first) {
            popFront();
        }
    }


    ////////////////////////////////////////////////////////
    ////////////////////// ОПЕРАТОРЫ ///////////////////////
    ////////////////////////////////////////////////////////

    MyList& operator= (const MyList& other) {
        clearList();
        size = other.size;
        for (const T& value : other) {
            pushBack(value);
        }
        return *this;
    }


    ////////////////////////////////////////////////////////
    //////// МЕТОДЫ ДОБАВЛЕНИЯ И УДАЛЕНИЯ ЭЛЕМЕНТОВ ////////
    ////////////////////////////////////////////////////////

    // добавление элемента в конец списка
    void pushBack(const T value) {
        Node<T>* newNode = new Node<T>(value, last, nullptr);
        if (last) {
            last->next = newNode;
        } else {
            first = newNode;
        }
        last = newNode;
        size++;
    }

    // добавление элемента в начало списка
    void pushFront(const T value) {
        Node<T>* newNode = new Node<T>(value, nullptr, first);
        if (first) {
            first->prev = newNode;
        } else {
            last = newNode;
        }
        first = newNode;
        size++;
    }

    // удаление последнего элемента списка
    void popBack() {
        if (last) {
            Node<T>* temp = last;
            last = last->prev;
            if (last) {
                last->next = nullptr;
            } else {
                first = nullptr;
            }
            delete temp;
            size--;
        }
    }

    // удаление первого элемента списка
    void popFront() {
        if (first) {
            Node<T>* temp = first;
            first = first->next;
            if (first) {
                first->prev = nullptr;
            } else {
                last = nullptr;
            }
            delete temp;
            size--;
        }
    }

    void assign(size_t count, const T& value) {
        clearList();
        for (size_t i = 0; i < count; i++) {
            pushBack(value);
        }
    }


    //////////////////////////////////////////////////
    ////////////// ВОЗВРАЩЕНИЯ ЗНАЧЕНИЙ //////////////
    //////////////////////////////////////////////////

    Node<T>* front() {
        return first;
    }

    Node<T>* back() {
        return last;
    }

    size_t getSize() {
        return size;
    }

    bool empty() const {
        return size == 0;
    }

    size_t getSize() const {
        return size;
    }


    //////////////////////////////////////////////////
    /////////// ПОЛЬЗОВАТЕЛЬСКИЙ ИТЕРАТОР ////////////
    //////////////////////////////////////////////////

    class Iterator {
        Node<T>* current;

    public:
        Iterator(Node<T>* node) : current(node) {}

        // оператор ++
        Iterator operator++() {
            if (current) {
                current = current->next;
            }
            return *this;
        }

        // оператор --
        Iterator operator--() {
            if (current) {
                current = current->prev;
            }
            return *this;
        }

        // оператор *
        T& operator*() {
            if (current) {
                return current->value;
            }
        }

        // оператор ==
        bool operator==(const Iterator& other) {
            return current == other.current;
        }

        // оператор !=
        bool operator!=(const Iterator& other) {
            return current != other.current;
        }


        ////////////////////////////////////////////////////
        /////////////// РАБОТА С ИТЕРАТОРАМИ ///////////////
        ////////////////////////////////////////////////////

        Iterator begin() {
            current = first;
            return Iterator(current);
        }

        Iterator end() {
            current = last;
            return Iterator(current->next);
        }

        Iterator rBegin() {
            current = last;
            return Iterator(current);
        }

        Iterator rEnd() {
            current = first;
            return Iterator(current->prev);
        }


    };

};


#endif
