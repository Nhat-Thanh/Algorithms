#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

struct Matrix {
    std::vector<std::vector<int> > a;
    Matrix operator+(const Matrix& b) {
        Matrix res = b;
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < a[i].size(); ++j) {
                res.a[i][j] = this->a[i][j] + b.a[i][j];
            }
        }
        return res;
    }
};

int main() {
    int cases, k;
    std::cin >> cases;
    for (k = 0; k < cases; k++) {
        Matrix x;
        Matrix y;
        Matrix result;
        int n, m, i, j;
        std::cin >> n >> m;
        for (i = 0; i < n; i++) {
            std::vector<int> b;
            int num;
            for (j = 0; j < m; j++) {
                std::cin >> num;
                b.push_back(num);
            }
            x.a.push_back(b);
        }
        for (i = 0; i < n; i++) {
            std::vector<int> b;
            int num;
            for (j = 0; j < m; j++) {
                std::cin >> num;
                b.push_back(num);
            }
            y.a.push_back(b);
        }
        result = x + y;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                std::cout << result.a[i][j] << " ";
            }
            std::cout << '\n';
        }
    }
    return 0;
}
