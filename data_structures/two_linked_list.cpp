#include <iostream>
#include <vector>
#include <string>
using namespace std;

// класс, отвечающий за элемент списка
class Node {
public:
    double data;
    // указатели на предыдущий и следующий элемент
    Node* prev, * next;
// конструктор класса
public: 
    Node(double data) {
        this -> data = data;
        this->prev = this->next = NULL;
    }
};

class LinkedList {
public:
        Node* head, * tail;
public:
    // конструктор класса
    LinkedList() {
        // указатели head и tail по умолчанию должны быть NULL
        head = tail = NULL;
    }
    // деструктор класса
    ~LinkedList() {
        while (head != NULL)
            pop_front();
    }

    // добавление первого элемента в массив
    Node* push_front(double data) {
        // ptr - временный указатель на новый объект класса Node
        Node* ptr = new Node(data);
        // если head не существует, то NULL, иначе next = head
        ptr->next = head;
        if (head != NULL)
            head->prev = ptr;
        if (tail == NULL)
            tail = ptr;
        // передвигаем указатель head на первый добавленный объект
        head = ptr;
        return ptr;
    }

    Node* push_back(double data) {
        // ptr - временный указатель на новый объект класса Node
        Node* ptr = new Node(data);
        // если head не существует, то NULL, иначе next = head
        ptr->prev = tail;
        if (tail != NULL)
            tail->next = ptr;
        if (head == NULL)
            head = ptr;
        // передвигаем указатель head на первый добавленный объект
        tail = ptr;
        return ptr;
    }

    void pop_front() {
        if (head == NULL) return;
        /* если уже существует объект, то создаём временный ук-ль на след. элемент,
         prev тогда будет NULL, и удаляем левый объект
         */
        Node* ptr = head-> next;
        if (ptr != NULL)
            ptr->prev = NULL;
        else 
        /* если второго объекта не сущ-ет, тогда и head и tail ссылаются на первый
         поэтому чтобы после удаления и head и tail были равны NULL доп. условие:
         */
            tail = NULL;
        delete head;
        head = ptr;
    }

    void pop_back() {
        if (tail == NULL) return;
        // ссылка на предпоследний эл-т
        Node* ptr = tail-> prev;
        if (ptr != NULL)
            ptr->next = NULL;
        else 
        /* если второго объекта не сущ-ет, тогда и head и tail ссылаются на первый
         поэтому чтобы после удаления и head и tail были равны NULL доп. условие:
         */
            head = NULL;
        delete tail;
        tail = ptr;
    }
    // метод для произвольного доступа к элементу двусвязного списка
    Node* getAt(int index) {
        Node* ptr = head;
        int n = 0;

        while (n != index) {
            if (ptr == NULL)
                return ptr;
            ptr = ptr->next;
            n++;
        }
        return ptr;
    }

    // оператор, возвращающий эл-т по индексу

    Node* operator[] (int index) {
        return getAt(index);
    }

    Node* insert(int index, double data) {
        Node* right = getAt(index);
        if (right == NULL)
            return push_back(data);

        Node* left = right->prev;
        if (left == NULL)
            return push_front(data);
        
        Node* ptr = new Node(data);

        ptr->prev = left;
        ptr->next = right;

        left->next = ptr;
        right->prev = ptr;

        return ptr;
    }

    // метод удаления промежуточного элемента
    void earse(int index) {
        Node* ptr = getAt(index);
        if (ptr == NULL)
            return;

        if (ptr->prev == NULL) {
            pop_front();
            return;
        }

        if (ptr->next == NULL) {
            pop_back();
            return;
        }

        Node* left = ptr->prev;
        Node* right = ptr->next;
        left-> next = right;
        right->prev = left;

        delete ptr;
    }
};

int main()
{
    LinkedList lst;
    lst.push_back(1.0);
    lst.push_back(2.0);
    lst.push_back(3.0);
    return 0;
};