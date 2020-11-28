#include <iostream>
#include <math.h>

using namespace std;

double get_distance(int pos_1[2], int pos_2[2]) { // pos_1[2] = {x_1, y_1}; pos_2[2] = {x_2, y_2}
    return sqrt( pow(pos_1[0] - pos_2[0], 2) + pow(pos_1[1] - pos_2[1], 2) );
}

int main() {
    int n, r, i, j, arr[100][2], near_1 = 0, near_2 = 1;
    double min_distance, new_distance;

    cin >> n >> r;
    cin >> arr[0][0] >> arr[0][1];
    cin >> arr[1][0] >> arr[1][1];
    min_distance = get_distance(arr[0], arr[1]);

    for(i = 2; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
        for(j = 0; j < i; j++) {
            new_distance = get_distance(arr[i], arr[j]); // arr[i] = {x_i, y_i}; arr[j] = {x_j, y_j}
            if(min_distance >= new_distance) {
                near_1 = j;
                near_2 = i;
                min_distance = new_distance;
            }
        }
    }

    cout << near_1 << " " << near_2 << endl;

    return 0;
}