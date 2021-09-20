#include <cmath>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

class Server {
  private:
    static int load;

  public:
    static int compute(long long A, long long B) {
        load += 1;
        if (A < 0) {
            throw std::invalid_argument("A is negative");
        }
        std::vector<int> v(A, 0);
        int real = -1, cmplx = sqrt(-1);
        if (B == 0)
            throw 0;
        real = (A / B) * real;
        int ans = v.at(B);
        return real + A - B * ans;
    }
    static int getLoad() {
        return load;
    }
};
int Server::load = 0;

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        long long A, B;
        std::cin >> A >> B;
        try {
            int res = Server::compute(A, B);
            std::cout << res << "\n";
        } catch (std::invalid_argument& ex) {
            std::cout << "Exception: " << ex.what() << "\n";
        } catch (std::bad_alloc& ex) {
            std::cout << "Not enough memory\n";
        } catch (std::exception& ex) {
            std::cout << "Exception: " << ex.what() << "\n";
        } catch (...) {
            std::cout << "Other Exception\n";
        }
    }
    std::cout << Server::getLoad() << '\n';
    return 0;
}