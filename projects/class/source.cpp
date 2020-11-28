#include <iostream>
#include <math.h>

using namespace std;

double get_distance(int x_1, int y_1, int x_2, int y_2) {
    return sqrt( pow(x_1 - x_2, 2) + pow(y_1 - y_2, 2) );
}

int main() {
    int n, r;
    int arr[200];
    int max_pos_1, max_pos_2;
    double max_distance = -1;

    cin >> n >> r;

    for(int i = 0; i < n; i++) {
        cin >> arr[2 * i] >> arr[2 * i + 1];
        for(int j = 0; j < i; j++) {
            double new_distance = get_distance(arr[2 * i], arr[2 * i + 1], arr[2 * j], arr[2 * j + 1]);
            if(max_distance == -1 || max_distance > new_distance) {
                max_pos_1 = j;
                max_pos_2 = i;
                max_distance = new_distance;
            }
        }
    }

    cout << max_pos_1 << " " << max_pos_2 << endl;

    return 0;
}