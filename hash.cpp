#include "hash.h"

template <typename T>
ostream& operator<<(ostream &cout, Hash<T> &s) {
    for (size_t i = 0; i < s.vect.size(); ++i) {
        for (typename list<T>::iterator it = s.vect[i].begin(); it != s.vect[i].end(); ++it) {
            cout << *it << " ";
        }
    }
    cout << ";";
    return cout;
}
template <typename T> Hash<T>::Hash(int m) {
    N = 0;
    vect.resize(m);
}

template <typename T> bool Hash<T>::Find(const T &x) { // Ãîâîðèò, íàøåëñÿ ëè òàêîé ýëåìåíò â íàøåì êîíòåéíåðå
    size_t i = h(x);
    for (typename list<T>::iterator it = vect[i].begin(); it != vect[i].end(); ++it) {
        if (*it == x) {
            return true; // Íàøëè
        }
    }
    return false; // Íå íàøëè
}

template<typename T> bool Hash<T>::Insert(const T &x) {
    if (Find(x)) {
        return false;
    }
    vect[h(x)].push_back(x);
    N++;
    if (N > vect.size()*4) { // Ðàçðåøàåì â ñðåäíåì 4 ýëåìåíòà â ñïèñêå
        size_t m = vect.size();
        Hash<T> s_(2*m);
        for (size_t i = 0; i < m; ++i) {
            for (typename list<T>::iterator it = vect[i].begin(); it != vect[i].end(); ++it) {
                s_.Insert(*it);
            }
        }
        vect.swap(s_.vect);
        N = s_.N;
    }
    return true;
}
template <typename T> size_t Hash<T>::h(const T& x) {
    return x % vect.size(); // äîëæåí áûòü îïðåäåëåí îïåðàòîð %
}
template <typename T> bool Hash<T>::Delete(const T& x) {
    size_t i = h(x);
    for (typename list<T>::iterator it = vect[i].begin(); it != vect[i].end(); ++it) {
        if (*it == x) {
            vect[i].erase(it);
            N--;
            return true; // Íàøëè
        }
    }
    return false; // Íå íàøëè
}

template bool Hash<int>::Insert(const int& x);
template ostream& operator<<(ostream& cout, Hash<int> &s);
template bool Hash<int>::Find(const int& x);
template size_t Hash<int>::h(const int& x);
template bool Hash<int>::Delete(const int& x);
