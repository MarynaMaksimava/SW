/*Задание 1
Составить программу, которая будет считывать введённое целое число.
После чего, каждую цифру этого числа необходимо вывести в новой строке. 1 балл

Задание 2
Составить программу, которая по введенному номеру дня недели будет выводить его название.
Нумерация дней недели начинается с 1 – понедельник, 2 — вторник и т. д. 1 балл

Задание 3
Написать программу, которая будет принимать два целых числа n и k и возвращает число, содержащее k первых цифр числа n. 2 балла

Задание 4
Написать программу, которая должна определить, пройдёт ли параллелепипед в отверстие.
Размеры отверстия и габариты параллелепипеда (длина, высота, ширина) вводятся пользователем. 2 балла

Задание 5
Написать программу, которая будет угадывать пароль. Пароль состоит из 4 цифр (не четырёхзначное число).
Необходимо, чтобы программа угадала его. Символы для пароля генерируются случайно.
После того как программа угадала пароль, он выводится на экран. 3 балла*/


#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

int main()
{
    int digits[10], number, check = 0;
    cout << "input a number" << endl;
    cin >> number;

    digits[9] = number % 10;
    digits[8] = number / 10 % 10;
    digits[7] = number / 100 % 10;
    digits[6] = number / 1000 % 10;
    digits[5] = number / 10000 % 10;
    digits[4] = number / 100000 % 10;
    digits[3] = number / 1000000 % 10;
    digits[2] = number / 10000000 % 10;
    digits[1] = number / 100000000 % 10;
    digits[0] = number / 1000000000 % 10;

    for (int i = 0; i < 10; i++)
    {
        if (digits[i] != 0)
        {
            check = 1;
        }

        if (check == 1)
        {
            cout << digits[i] << endl;
        }

    }









    int day;
    cout << endl << "input the number of the day of week" << endl;
    cin >> day;
    switch (day)
    {
    case 1:
        cout << "the day is Monday" << endl;
        break;
    case 2:
        cout << "the day is Tuesday" << endl;
        break;
    case 3:
        cout << "the day is Wednesday" << endl;
        break;
    case 4:
        cout << "the day is Thursday" << endl;
        break;
    case 5:
        cout << "the day is Friday" << endl;
        break;
    case 6:
        cout << "the day is Saturday" << endl;
        break;
    case 7:
        cout << "the day is Sunday" << endl;
        break;
    default:
        cout << "not the day of week" << endl;
        break;
    }
    //---------------------------------------------------
    int n, n1, k, finalNumber, power = 1, digitsOfN = 1;
    cout << endl << "input a number n" << endl;
    cin >> n;
    n1 = n;
    cout << "input the number k - the number of digits that final number will include" << endl;
    cin >> k;
    while ((n1 = n1 / 10) > 0)
    {
        digitsOfN++;
    }

    for (int i = 1; i <= (digitsOfN - k); i++)
    {
        power = power * 10;
    }

    finalNumber = n / (power);
    cout << "final number is " << finalNumber << endl;














    int a, b, c;
    double diag, d;
    cout << endl << "input sides a,b,c" << endl;
    cin >> a >> b >> c;
    cout << "input diameter of a circle" << endl;
    cin >> d;

    if (a > b && a > c) //выбираем наименьшую грань, диагональ которой будем считать
    {
        diag = sqrt(b * b + c * c);
    }
    else
    {
        if (b > a && b > c)
        {
            diag = sqrt(a * a + c * c);
        }
        else
        {
            diag = sqrt(b * b + a * a);
        }

    }
    if (diag <= d)
    {
        cout << "parallelepiped can pass the circle" << endl;
    }
    else
    {
        cout << "parallelepiped can not pass the circle" << endl;
    }





    int pass[4], hack[4];
    srand(time(0));
    for (int i = 0; i < 4; i++)
    {
        pass[i] = rand() % 10;
    }


    cout << endl;
    for (int i0 = 0; i0 <= 9; i0++)
        for (int i1 = 0; i1 <= 9; i1++)
            for (int i2 = 0; i2 <= 9; i2++)
                for (int i3 = 0; i3 <= 9; i3++)
                {
                    hack[0] = i0;
                    hack[1] = i1;
                    hack[2] = i2;
                    hack[3] = i3;


                    if (pass[0] == hack[0] && pass[1] == hack[1] && pass[2] == hack[2] && pass[3] == hack[3])
                    {
                        cout << "password is " << pass[0] << pass[1] << pass[2] << pass[3] << endl << "hack is " << hack[0] << hack[1] << hack[2] << hack[3] << endl;
                        return 0;

                    }


                }



    return 0;
}
