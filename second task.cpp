#include <iostream>
#include "c.h"

int main() {
    C a;
    C b((C&&)a);
    return 0;
}