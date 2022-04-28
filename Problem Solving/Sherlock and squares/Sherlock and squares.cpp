#include <iostream>
#include <math.h>

int main() {
	int q, a, b;
	std::cin >> q;
	int arr[q];
	for (int i = 0; i < q; ++i) {
		std::cin >> a >> b;
		int low = ceil(sqrt(a));
		int high = floor(sqrt(b));
		arr[i] = (low <= high) * (high - low + 1);
	}

	for (int i = 0; i < q; ++i)
		std::cout << arr[i] << '\n';
	return 0;
}
