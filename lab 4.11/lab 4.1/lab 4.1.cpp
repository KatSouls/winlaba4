#include <iostream>
#include <windows.h>
#include <sstream>
using namespace std;
//объявления функций
int se(string s, long double& z); //проверка на ввод символа
void read(string* aa, int n, long double* a, long double* b); //ввод массива
void write(long double* a, int n); //вывод массива
void sortv(long double* a, int n); //сортировка по возрастанию
void sortu(long double* a, int n); //сортировка по убыванию
//главная функция
int main() {
    setlocale(LC_ALL, "rus");
    time_t start, end; time(&start);
    string nn; long double n;
    cout << "Количество элементов массива: "; cin >> nn; se(nn, n);
    if ((int)n != n || n <= 0) { cout << "ERROR: Не является натуральным числом" << endl; exit(0); }
    while (cin.get() != '\n') {}
    cout << "Элементы массива: ";
    string* aa = new string[n]; long double* a = new long double[n]; long double* b = new long double[n];
    read(aa, n, a, b); sortv(a, n); sortu(b, n);
    cout << "Отсортированный массив по возрастанию: "; write(a, n);
    cout << "Отсортированный массив по убыванию: "; write(b, n);
    delete[]aa; time(&end); double seconds = difftime(end, start);
    printf("The time: %f ms\n", seconds);
    for (int i = 0; i < 10; ++i)
    {
        if (cin.get() == '\n')
            continue;
    }
    return 0;
    
}
//проверка на символ
int se(string s, long double& z) {
    stringstream(s) >> z;
    if (z == 0 && s != "0") {
        cout << "ERROR: " << s << " Не является числом" << endl; exit(0);
    }
    return z;
}
//ввод массива
void read(string* aa, int n, long double* a, long double* b) {
    for (int i = 0; i < n; i++) { cin >> aa[i]; se(aa[i], a[i]); se(aa[i], b[i]); }
    while (cin.get() != '\n') {}
}
//вывод массива
void write(long double* a, int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
}
//сортировка по возрастанию
void sortv(long double* a, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
}
//сортировка по убыванию
void sortu(long double* a, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i; j++)
            if (a[j] < a[j + 1]) swap(a[j], a[j + 1]);
}