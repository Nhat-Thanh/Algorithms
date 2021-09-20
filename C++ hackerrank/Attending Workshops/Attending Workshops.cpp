#include <bits/stdc++.h>

// My Code
struct Workshops {
    int start;
    int duration;
    int end;
};

struct Available_Workshops : public Workshops {
    int n;
    Workshops* num_wk;
    Available_Workshops(int n) {
        this->n = n;
        num_wk = new Workshops[n];
    }
};

Available_Workshops* initialize(int start_time[], int duration[], int n) {
    Available_Workshops* aw = new Available_Workshops(n);
    for (int i = 0; i < n; ++i) {
        aw->num_wk[i].start = start_time[i];
        aw->num_wk[i].duration = duration[i];
        aw->num_wk[i].end = start_time[i] + duration[i];
    }
    std::sort(aw->num_wk, aw->num_wk + n,
              [](const Workshops& a, const Workshops& b) { return a.end < b.end; });
    return aw;
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
    int num = 1;
    int time_finish_prev = ptr->num_wk[0].end;
    for (int i = 1; i < ptr->n; ++i) {
        if (time_finish_prev <= ptr->num_wk[i].start) {
            time_finish_prev = ptr->num_wk[i].end;
            num += 1;
        }
    }
    return num;
}
// End My Code

int main(int argc, char* argv[]) {
    int n;     // number of workshops
    std::cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> start_time[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> duration[i];
    }

    Available_Workshops* ptr;
    ptr = initialize(start_time, duration, n);
    std::cout << CalculateMaxWorkshops(ptr) << '\n';
    return 0;
}
