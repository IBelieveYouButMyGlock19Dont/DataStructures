#include <iostream>
#include "Point on a Plane.cpp"
using namespace std;

int main() {
    Point a(2, 3);
    Point b(5, 7);
    cout << a << "\n";
    cout << b << "\n";

    cout << a.Dist2(b) << "\n";

    a.Move(3, 4);

    cout << a << "\n";

    if (a == b) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}