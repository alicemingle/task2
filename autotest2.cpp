#include "hash.h"
#include "Autotest2.h"


void Autotest(void) {
    Hash<int> a;
    int b = 0, c = 0;
    for (int i = 0; i < 3; ++i) {
        a.Insert(i);
        b = b + 1;
    }
    if (b == 3) {
        c = c + 1;
    }
    a.Delete(2);
    if (b == 3) {
        c = c + 1;
    }
    if (c == 2) {
        cout << "Autotest passed!!!" << endl;
    } else {
        cout << "Smth went wrong..." << endl;
    }
}
