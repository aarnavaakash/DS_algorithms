#include <iostream>
using namespace std;

int main() {
    int n = 9;

    int H = (n << 3);
    int Z = H-n;

    cout << ((((n << 3) - n)) >> 3) << endl;
    cout << "7*n/8 = " << (Z >> 3);

    return 0;
}
