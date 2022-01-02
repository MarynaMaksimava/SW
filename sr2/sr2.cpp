#include <iostream>
#include <time.h>
#include <math.h>
/*Задание 1
Написать функцию, которая будет выводить позицию первого элемента массива, равного введённому числу.

Есть массив [1,2,3,4,5,5,6,8,7,8,8,9] -> позиция числа 5 равна 4, для 1 - 0, для 3 - 2

Дополнительно: написать функцию, которая будет находить подстроку в строке (без ипользования строенного функционала) :
 "Я люблю ТРПО" - найти люб -> 2

Задание 2
Написать функцию, которая будет находить все числа в массиве, которые меньше разности двух предыдущих.
[5,1,2,0,1] -> 2,1

Задание 3
Написать функцию, которая находит длину наибольшей последовательности одинаковых чисел, идущих подряд.
[1,1,1,3,3,3,3,3,1,1,1] -> 5.


Задание 4
Транспонировать матрицу относительно побочной и главной диагоналей.

Задание 5
Существует набор точек. Найти максимальное расстояние между двумя точками среди набора точек.
Точка характеризуется двумя координатами -> x,y. Чтобы хранить информацию о точке, можно использовать матрицу,
где первый столбец X, а второй - Y.*/
using namespace std;

void findNumber(int* a, int SIZE, int Number)
{
    int k = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (a[i] == Number)
        {
            cout << i << " - place of " << Number << endl;
            k++;
            break;
        }

    }
    if (!k) cout << " there is no " << Number << endl;
}

void lessThan2PreviousDifference(int* a, int SIZE)
{

    for (int i = 2; i < SIZE; i++)
    {
        if (a[i - 2] - a[i - 1] > a[i])
            cout << a[i] << " ";
    }
    cout << endl;
}
int findNumberSequence(int* a, int SIZE)
{
    int maxi = 1, counter = 1;
    for (int i = 1; i < SIZE; i++)
    {
        if (a[i] == a[i - 1])
        {
            counter++;
            if (counter > maxi)
            {
                maxi = counter;
            }
        }
        else
        {
            counter = 1;
        }
    }
    return maxi;
}
int* arrayCreate(int SIZE)
{
    int* a;
    a = new int[SIZE];
    return a;
}
void arrayFill(int* a, int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        a[i] = rand() % 10 - 5;
    }
}
void arrayOut(int* a, int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << "a[" << i << "]=" << a[i] << endl;
    }

}
double points(int num)
{
    int* x, * y;
    double maxx = 0, l = 0, distance;
    x = arrayCreate(num);
    arrayFill(x, num);
    y = arrayCreate(num);
    arrayFill(y, num);
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            l = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            if (l > maxx)
            {
                maxx = l;
            }

        }
    }
    for (int i = 0; i < num; i++)
    {
        cout << x[i] << "  " << y[i] << endl;
    }
    delete[]x;
    delete[]y;
    distance = sqrt(maxx);
    return distance;
}


int main()
{
    int Size, NumToFind;
    cout << "input size of array" << endl;
    cin >> Size;
    cout << "input number to look for" << endl;
    cin >> NumToFind;
    int* arr = arrayCreate(Size);
    arrayFill(arr, Size);
    arrayOut(arr, Size);
    findNumber(arr, Size, NumToFind);
    cout << "numbers, which are less than the difference between two previous numbers:" << endl;
    lessThan2PreviousDifference(arr, Size);
    cout << "longest sequence contains " << findNumberSequence(arr, Size) << " numbers" << endl;
    delete[]arr;
    int ammount;
    cout << "input ammount of points" << endl;
    cin >> ammount;
    double distance = points(ammount);
    cout << "distance=" << distance;

    return 0;
}
