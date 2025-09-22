#include <iostream>
using namespace std;

int iterativeFib(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
int main() {
    cout << "C++ Fibonacci:" << endl;
    cout << "Iterative fib(10): " << iterativeFib(10) << endl;
    
    return 0;
}