#include <iostream>
#include <vector>
#include <string>
using namespace std;

// forward_list - стандартная реализация односвязного списка

// объект списка реализуем через класс Node
class Node {
public: 
    double data;
    // ссылка на следующий объект
    Node* next;
// объявляем конструктор для сохранения данных
public:
    Node(double data) {
        this -> data = data;
        this -> next = NULL;
    }
};

// класс для работы со списком
class OneLinkedList{
public: 
    // ссылки на первый и последний элементы
    Node* head, * tail;
public:
    OneLinkedList() {
        // head и tail ссылаются на NULL, значит объектов в списке нет
        this-> head = this-> tail = NULL;
    }

    // деструктор класса (когда он удаляется)
    ~OneLinkedList() {
        // удаляем все элементы, чтобы не было утечки памяти
        // удаляем в цикле первый объект, пока объекты существуют
        while(head != NULL) pop_front();
    }

    // метод для удаления первого элемента
    void pop_front() {
        if (head == NULL) return;
        if (head == tail) {
            delete tail;
            head = tail = NULL;
        }
        // если эти проверки не проходят, то в списке 2 и более элементов
        Node* node = head;
        head = node -> next;
        delete node;
    }
    
    // метод для добавления элемента в конец
    void push_back(double data) {
        // создаём объект в памяти компьютера
        Node* node = new Node(data);
        // если указатель принимает значение null, значит мы добавляем первый объект
        if (head == NULL) head = node;
        // если есть tail, то next=NULL, при добавлении next присваиваем node
        if (tail != NULL) tail->next = node;
        tail = node;
    }
    
    // метод для добавления элемента в начало
    void push_front(double data) {
        // создаём объект в памяти компьютера
        Node* node = new Node(data);
        node->next= head;
        head = node;
        if (tail == NULL) tail = node;
    }

    void pop_back() {
        if (tail == NULL) return;
        if (head == tail) {
            delete tail;
            head = tail = NULL;
            return;
        }
        Node* node = head;
        // будем перебирать все элементы, пока не дойдём до предпоследнего
        for(; node->next != tail; node = node->next);
        // next будет равен NULL
        node->next = NULL;
        // освобождаем память последнего эл-та и переместим указатель
        delete tail;
        tail = node;
    }
    // метод, который будет возвращать элемент по индексу k
    Node* getAt(int k) {
        if (k < 0) return NULL;

        Node* node = head;
        int n = 0;
        // если node=null; n=k, или будет конец списка (node.next=null):
        while(node && n != k && node->next) {
            // переставляем указатель на след. объект
            node = node->next;
            n++;
        }
        // если n=k, то возвращаем индекс, иначе-null
        return (n == k) ? node : NULL;
    }

    void insert(int k, double data) {
        // объект, на который будет вести указатель left получаем по индексу
        Node* left = getAt(k);
        // если left не существует, то вставить элемент не можем
        if (left == NULL) return;
        Node* right = left->next;
        // создаём новый объект в памяти
        Node* node = new Node(data);
        // создаём связи для нового объекта
        left->next = node;
        node->next = right;
        // если вставляем последний элемент, то tail-это новый элемент
        if (right == NULL) tail = node;
    }    

    void earse(int k) {
        if (k < 0) return;
        if (k == 0) {
            pop_front();
            return;
        }
        // left элемент - с индексом k - 1
        Node* left = getAt(k - 1);
        Node* node = left->next;
        if(node == NULL) return;
        // определяем правый элемент
        Node* right = node->next;
        left->next = right;
        if (node == tail) tail = left;
        delete node;
    }
};

int main() {
    OneLinkedList lst;
    lst.push_front(1);
    lst.push_back(3);
    lst.push_back(6);
    lst.insert(1, 5);

    // возьмём элемент по нулевому индексу
    Node* n = lst.getAt(1);
    // d будет представлять данные элемента
    double d = (n != NULL) ? n->data : 0;
    std::cout << d << std::endl;

    for (Node* node = lst.head; node != NULL; node = node->next)
        std::cout << node->data << " ";

    std::cout << std::endl;
    return 0;
}