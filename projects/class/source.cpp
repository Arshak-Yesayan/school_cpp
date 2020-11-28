#include <iostream>
#include <math.h>

using namespace std;

double get_distance(int x_1, int y_1, int x_2, int y_2) {
    return  sqrt( pow(x_1 - x_2, 2) + pow(y_1 - y_2, 2) );
}

int main() {
    int n, r;
    int array[200];
    int max_pos_1, max_pos_2;
    double max_distance = 0;

    cin >> n >> r;

    for(int i = 0; i < n; i++) {
        cin >> array[2 * i] >> array[2 * i + 1];
        for(int j = 0; j < i; j++) {
            if(max_distance <= get_distance(array[2 * i], array[2 * i + 1], array[2 * j], array[2 * j + 1])) {
                max_pos_1 = j;
                max_pos_2 = i;
            }
        }
    }

    cout << max_pos_1 << " " << max_pos_2 << endl;

    return 0;
}