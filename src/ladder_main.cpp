#include "ladder.h"

void test_is_adjacent() {
    cout << is_adjacent("Pog", "pog") << endl;
    cout << is_adjacent("Fwg", "pog") << endl;
    cout << is_adjacent("Dog", "Dogg") << endl;
}


int main() {
    test_is_adjacent();
    return 0;
}