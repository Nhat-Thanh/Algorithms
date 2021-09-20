#include <deque>
#include <iostream>

void printKMax(int arr[], int n, int k) {
    std::deque<int> dq;
    for (int i = 0; i < k; ++i) {
        while (!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();
        dq.emplace_back(i);
    }

    for (int i = k; i < n; ++i) {
        std::cout << arr[dq.front()] << " ";
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        while (!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();
        dq.emplace_back(i);
    }

    std::cout << arr[dq.front()] << "\n";
}

int main() {
    int t;
    std::cin >> t;
    while (t > 0) {
        int n, k;
        std::cin >> n >> k;
        int i;
        int arr[n];
        for (i = 0; i < n; i++)
            std::cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}
