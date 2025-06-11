#include <iostream>
#include "add.h"

using namespace std;

int main() {
    int a, b, c;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    c = add(a,b);
    cout << "The sum is: " << c << endl;
    return 0;
}