#include <iostream>
using namespace std;

//Сформировать массив строк.Удалить из него К строк,
//начиная со строки с заданным номером.

int main()
{
    setlocale(LC_ALL, "russian");
    int rows = -1, k, n,f=0;
    while (rows <= 0)
    {
        cout << "Введите количество строк:";
        cin >> rows;
        if (rows <= 0)
        {
            cout << "Ошибка!" << endl;
        }
    }

    char** arr = new char* [rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new char[rows+1];
    }
    cout << "\nВводимые строки не должны превышать " << rows << endl << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "Введите строку № "<< i+1 << endl;
        for (int j = 0; j < rows; j++)
        {
            cin >> arr[i][j];
        }
        arr[i][rows] = '\0';
    }
    cout << "\nВведите номер строки, с которой начать удаление" << endl;
    cin >> n;
    cout << "\nВведите количество удалемых строк" << endl;
    cin >> k;

    char** arr2 = new char* [rows-k];
    for (int i = 0; i < rows; i++)
    {
        arr2[i] = new char[rows-k+1];
    }

    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < rows+1; j++)
        {
            arr2[i][j] = arr[i][j];
        }
        f++;
    }
    
    for (int i = n + k - 1; i < rows; i++)
    {
        for (int j = 0; j < rows+1; j++)
        {
            arr2[f][j] = arr[i][j];
        }
        f++;
    }

    for (int i = 0; i < rows; i++)
    {
        delete[]  arr[i];
    }
    delete[]  arr;

    cout << endl << endl << "Массив:" << endl;
    for (int i = 0; i < rows-k; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout << arr2[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < rows-k; i++)
    {
        delete[]  arr2[i];
    }
    delete[]  arr2;
}

