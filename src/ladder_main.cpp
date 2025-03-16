#include "ladder.h"

void test_is_adjacent() {
    cout << is_adjacent("apple", "bapple") << endl;
    cout << is_adjacent("apple", "appleD") << endl;
    cout << is_adjacent("apdple", "apple") << endl;
}


int main() {
    test_is_adjacent();
    return 0;
}