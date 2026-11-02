#include <iostream>
#include "c.h"

//void call(int n) {
    //if (n==0) {
    //    return;
   // }
   // C a;
  //  call(n-1);
//}

//int main() {
  //      int n;
   //     std::cin >> n;
   //     call(n);
   //     return 0;
   // }

int main() {
    int n;
    std::cin >> n;
    C** array=new C*[n];

    for (int i=0;i<n;i++) {
        array[i]=new C;
    }

    for (int i=n-1;i>=0;i--) {
        delete array[i];
    }

    delete[] array;
    return 0;
}