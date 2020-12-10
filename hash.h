#pragma once
#include <iostream>
#include <list>
#include <vector>
using namespace std;

template <typename T> // шаблон ф-ии
class Hash {
private:
    vector<list<T> > vect;
    size_t N; // Суммарная длина всех списков.
public:
    Hash(int m = 3);
    bool IsEmpty();
    size_t h(const T &x); // сама функция
    bool Find(const T &x);
    bool Insert(const T &x); // Добавление элемента
    bool Delete(const T &x);
    template <typename T_1> friend ostream& operator<<(ostream &cout, Hash<T_1> &s);
};
