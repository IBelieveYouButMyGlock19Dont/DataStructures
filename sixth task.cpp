#include <iostream>
#include <c.h>

int main() {
    int n;
    std::cin >> n;
    C** array=new C*[n];

    for (int i=0;i<n;i++) {
        array[i]=new C;
    }

    for (int i=0;i<n;i++) {
        delete array[i];
    }

    delete[] array;
    return 0;
}