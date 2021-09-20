#define toStr(str) #str
#define io(v) std::cin >> v
#define FUNCTION(name, op)            \
    inline void name(int& x, int y) { \
        if (!(x op y)) {              \
            x = y;                    \
        }                             \
    }
#define INF 10000000
#define foreach(v, i) for (int i = 0; i < v.size(); ++i)

#include <iostream>
#include <vector>

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    foreach (v, i) {
        io(v)[i];
    }
    int mn = INF;
    int mx = -INF;
    foreach (v, i) {
        minimum(mn, v[i]);
        maximum(mx, v[i]);
    }
    int ans = mx - mn;
    std::cout << toStr(Result =) << ' ' << ans;
    return 0;
}