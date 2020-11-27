#include <iostream>

using namespace std;

bool is_perfect(int n) {
    int sum = 1;
    if(n < 6)
        return false;

    for(int i = 2; i <= n / 2; i++) {
        if(n % i == 0)
            sum += i;
    }
    return sum == n;
}

int main() {
    int a;

    cin >> a;

    cout << is_perfect(a) << endl;

    return 0;
}