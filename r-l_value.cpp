#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

using namespace std;

class Array {
    int* arr;
    int size;
public:
    Array(int usize = 5) : arr{ new int[usize] }, size{ usize }
    {
        randomize(10, 20);
        cout << "Конструктор с параметром\n";
    }
    Array(const Array& obj) : arr{ new int[obj.size] }, size{ obj.size } {
        for (int i = 0; i < size; i++)
        {
            arr[i] = obj.arr[i];
        }

    }
    Array(Array&& obj) : arr{ obj.arr }, size{ obj.size } {
        obj.arr = nullptr;
        obj.size = 0;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    Array& operator=(Array&& obj) {

        if (this != nullptr) {
            delete[] arr;
        }
        arr = obj.arr;
        size = obj.size;

        obj.arr = nullptr;
        obj.size = 0;

        return *this;
    }

    ~Array()
    {
        if (arr)
        {
            delete[]arr;
        }
        cout << "Деструктор\n";
    }

    void randomize(int a, int b) //10 20
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = a + rand() % (b - a + 1); //10-29
        }
    }
    void setElem(int ind, int x)
    {
        arr[ind] = x;
    }
    int getElem(int ind) 
    {
        return arr[ind];
    }
    int getSize()  {
        return size;
    }
};

class Name {
    char* name;
    char* surname;
    void setString(char*& word, const char* worder) {
        if (word) {
            delete[] word;
        }
        word = new char[strlen(worder) + 1];
        strcpy(word, worder);
    }
    void remove() {
        if (name) {
            delete[] name;
        }
        if (surname) {
            delete[] surname;
        }
    }
public:
    Name(const char* name, const char* surname) {
        if (name != nullptr && surname != nullptr) {
            this->name = new char[strlen(name) + 1];
            this->surname = new char[strlen(surname) + 1];
            strcpy(this->name, name);
            strcpy(this->surname, surname);
        }
        else
        {
            this->name = nullptr;
            this->surname = nullptr;
        }
    }
    Name(const Name& obj) {
        Name(obj.name, obj.surname);
    }
    Name() {
        Name(nullptr, nullptr);
    }
    void print() {
        if (name != nullptr && surname != nullptr) {
            cout << "Name: " << name << endl;
            cout << "Surname: " << surname << endl;
        }
        else if(name == nullptr && surname != nullptr){
            cout << "Name: Nullptr\n";
            cout << "Surname: " << surname << endl;
        }
        else if (name != nullptr && surname == nullptr) {
            cout << "Name: " << name << endl;
            cout << "Surname: Nullptr\n";
        }
        else {
            cout << "Name: Nullptr\n";
            cout << "Surname: Nullptr\n";
        }
    }
    ~Name() {
        if (name != nullptr && surname != nullptr) {
            delete[] name;
            delete[] surname;
        }
    }
};
int main() {

    setlocale(0, "");
    srand(time(NULL));

    Array a;
    a.print();
    Array b{ move(a) };
    cout << "a(null): "; a.print();
    b.print();
    a = move(b);
    cout << "a2: "; a.print();
}
