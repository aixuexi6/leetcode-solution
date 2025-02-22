#include<vector>
#include<iostream>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec(n, vector<int>(m, 0));
    int sum = 0;

    //n行m列填充
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> vec[i][j];
            sum += vec[i][j];
        }
    }

    //横向
    int result = INT_MAX;
    int hsum = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            hsum += vec[i][j];
        }
        result = result < abs(sum - hsum - hsum) ? result : abs(sum - hsum - hsum);
    }

    //纵向
    int zsum = 0;
    for (int j = 0; j < m - 1; j++) {
        for (int i = 0; i < n; i++) {
            zsum += vec[i][j];
        }
        result = result < abs(sum - zsum - zsum) ? result : abs(sum - zsum - zsum);
    }

    cout << result << endl;
}