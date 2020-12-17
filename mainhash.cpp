#include "hash.h"
#include "Autotest2.h"

int main(void) {
    Autotest();
    Hash<int> s;
    for (int i = 0; i < 30; ++i) {
        s.Insert(i);
        cout << s << endl;
    }
    s.Delete(27);
    cout << s << endl;
    return 0;
}

