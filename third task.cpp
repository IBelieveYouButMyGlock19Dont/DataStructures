#include <iostream>
#include "c.h"

int main() {
    C a;
    C b;
    a=b;
    a=(C&&) b;
    return 0;
}