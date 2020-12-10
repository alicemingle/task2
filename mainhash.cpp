#include "hash.h"

int main(void) {
    Hash<int> s;
    for (int i = 0; i < 30; ++i) {
        s.Insert(i);
        cout << s << endl;
    }
    s.Delete(27);
    cout << s << endl;
    return 0;
}
