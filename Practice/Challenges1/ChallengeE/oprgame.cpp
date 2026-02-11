#include <bits/stdc++.h>
using namespace std;

class Player {
private:
    int total_balls;
    int last_taken;

public:
    Player(int n) {
        total_balls = n;
        last_taken = 0;
    }

    bool goFirst() {
        return (total_balls & (total_balls - 1)) != 0;
    }

    void playBack(int k) {
        last_taken = k;
        total_balls -= k;
    }

    int play() {
        if (last_taken == 0) {
            int target = 1;
            while (target * 2 <= total_balls) {
                target *= 2;
            }
            return total_balls - target;
        } else {
            if (last_taken % 2 == 1) return 1;
            if (last_taken % 4 == 0) return min(last_taken, total_balls);
            else if (last_taken % 2 == 0) return 2;
        }
    }
};

// #include "main.h"