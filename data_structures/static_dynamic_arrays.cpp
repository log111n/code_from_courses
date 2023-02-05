#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(){cout << '\n';}

template<typename T, typename ...TAIL>
void print(const T &t, TAIL... tail)
{
    cout << t << ' ';
    print(tail...);
}

/* Будем хранить в переменной y значения y=kx+b при различных значениях x*/
int main()
{
    float k = 0.5f, b = -7.4f;
    float y1[100];

/*
*y2 - указатель, 
new - оператор для выделение динамической памяти в куче 
*/
    int n = 100;
    float* y2 = new float[n];
    y1[0] = k * 0 + b;
    printf("%.2f \n", y1[0]);

    for (int x = 0; x < 100; ++x)
        y2[x] = k * x + b;
    // выведем первые 10 значений

    for (int i = 0; i < 10; ++i)
        printf("%.2f \n", y2[i]);
    delete[] y2;

// оценки студентов, необходимо вставить 4ку после первой 2ки
    const int N = 20;
    char marks[N] = { 2, 2, 3 };
    int count_marks = 3;

    // индекс для вставки нового элемента в массив
    int indx_insert = 1;
    /*сначала сдвиг всех элементов от count до indx вправо, 
    но если count = N, то сдвигать дальше нельзя, вводим end
    */ 
    int end = (count_marks < N ? count_marks : N-1);
    for (int i = end; i > indx_insert; --i)
        marks[i] = marks[i - 1];
    marks[indx_insert] = 4;
    if (count_marks < N) count_marks++;
    printf("Marks after insert: \n");
    for (int i = 0; i < count_marks; ++i)
        printf("%d \n", marks[i]);

// оценки студента, удаление первой двойки
const int K = 20;
    char marks_del[K] = { 2, 4, 2, 3 };
    int count_marks_del = 4;

    // индекс для вставки нового элемента в массив
    int indx_del = 0;
    /*сначала сдвиг всех элементов от count до indx вправо, 
    но если count = N, то сдвигать дальше нельзя, вводим end
    */ 
 
    for (int i = indx_del; i < count_marks_del; ++i)
        marks_del[i] = marks_del[i + 1];
    marks_del[indx_insert] = 4;
    if (count_marks_del > 0) count_marks_del--;
    printf("Marks after delete: \n");
    for (int i = 0; i < count_marks_del; ++i)
        printf("%d", marks_del[i]);
    
// работа с динамическим массивом с помощью вектора
    std::vector<double> digits;
    // Изменяем физический размер массива до 20
    digits.reserve(20);
    // добавляем элементы
    digits.push_back(5.0);
    digits.push_back(3.0);
    digits.push_back(4.3);
    digits.push_back(7.1);

    //std::cout << "digits[0] =" << digits[0] << std::endl;
    //std::cout << digits.size();
    printf("\n\nLogical size: ");
    print(digits.size());
    printf("\n\nPhysical size: ");
    print(digits.capacity());
    printf("\nMy dynamic array:\n");
    for (int i = 0; i < digits.size(); ++i)
        print(digits[i]);

    // удаляем последений элемент
    digits.pop_back();
    // вставка insert() удаление erase(), но работают за О(N)

    // очистка массива 
    digits.clear();
    return 0;

}