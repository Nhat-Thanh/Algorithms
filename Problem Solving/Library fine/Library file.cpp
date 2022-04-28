#include <iostream>

struct date {
	int d, m, y;
};

int cal_hackos(const date& d1, const date& d2) {
	bool y1_eq_y2 = (d1.y == d2.y);
	bool m1_eq_m2 = (d1.m == d2.m);
	if (d1.y > d2.y)
		return 10000;
	if (y1_eq_y2 && d1.m > d2.m)
		return 500 * (d1.m - d2.m);
	if (y1_eq_y2 && m1_eq_m2 && d1.d > d2.d)
		return 15 * (d1.d - d2.d);
	return 0;
}

int main() {
	int d1, m1, y1;
	int d2, m2, y2;
	std::cin >> d1 >> m1 >> y1;
	std::cin >> d2 >> m2 >> y2;
	date d_1 = {d1, m1, y1};
	date d_2 = {d2, m2, y2};
	std::cout << cal_hackos(d_1, d_2);
	return 0;
}
