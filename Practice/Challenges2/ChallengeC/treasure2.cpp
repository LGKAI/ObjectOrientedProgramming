#include <bits/stdc++.h>
#include "treasure2lib.h"
using namespace std;

const int N = 1026;
const int KEY_CONST = 1027;

int get_back_door(const vector<int>& info) {
    int v1 = info[1];
    int v2 = info[2];
    if (v1 > 0) {
        if (v2 <= 0 || v1 < v2) return 1;
    }
    return 2;
}

void robustGoFlipReturn(int steps, const vector<int>& moves_out) {
    if (steps == 0) return;
    vector<int> doors_to_return;
    for (int d : moves_out) {
        vector<int> info = move(d);
        doors_to_return.push_back(get_back_door(info));
    }
    flip();
    for (int i = doors_to_return.size() - 1; i >= 0; i--) {
        move(doors_to_return[i]);
    }
}

void solveAlice(vector<int> s) {
    vector<int> left_lights, right_lights;
    vector<int> left_moves, right_moves;

    if (s[1] != -1) {
        vector<int> cur = s;
        int d = 1;
        while (true) {
            left_moves.push_back(d);
            cur = move(d);
            left_lights.push_back(cur[0]);
            if (cur[1] == 0) d = 1;
            else if (cur[2] == 0) d = 2;
            else break;
        }
        for (int i = 0; i < left_moves.size(); ++i) {
            cur = move(get_back_door(cur));
        }
    }

    if (s[2] != -1) {
        int d = 2;
        vector<int> cur;
        while (true) {
            right_moves.push_back(d);
            cur = move(d);
            right_lights.push_back(cur[0]);
            if (cur[1] == 0) d = 1;
            else if (cur[2] == 0) d = 2;
            else break;
        }
        for (int i = 0; i < right_moves.size(); ++i) {
            cur = move(get_back_door(cur));
        }
    }

    vector<int> lights;
    for (int i = left_lights.size() - 1; i >= 0; i--) lights.push_back(left_lights[i]);
    lights.push_back(s[0]);
    for (int x : right_lights) lights.push_back(x);

    int n = lights.size();
    int T_idx = left_lights.size() + 1;

    long long S_fwd_curr = 0;
    long long S_rev_curr = 0;

    for (int i = 0; i < n; ++i) {
        if (lights[i]) {
            S_fwd_curr ^= (i + 1);
            S_rev_curr ^= (n - i);
        }
    }

    long long Target_Fwd = T_idx;
    long long Target_Rev = KEY_CONST - T_idx;

    vector<int> flips;
    bool found = false;

    if (S_fwd_curr == Target_Fwd && S_rev_curr == Target_Rev) {
        found = true;
    }

    if (!found) {
        for (int u = 1; u <= n; ++u) {
            long long next_fwd = S_fwd_curr ^ u;
            long long next_rev = S_rev_curr ^ (KEY_CONST - u);
            if (next_fwd == Target_Fwd && next_rev == Target_Rev) {
                flips.push_back(u);
                found = true;
                break;
            }
        }
    }

    if (!found) {
        long long req_xor_fwd = S_fwd_curr ^ Target_Fwd;
        for (int u = 1; u <= n; ++u) {
            int v = (int)(req_xor_fwd ^ u);
            if (v >= 1 && v <= n && v != u) {
                long long next_rev = S_rev_curr ^ (KEY_CONST - u) ^ (KEY_CONST - v);
                if (next_rev == Target_Rev) {
                    flips.push_back(u);
                    flips.push_back(v);
                    found = true;
                    break;
                }
            }
        }
    }

    for (int t : flips) {
        if (t == T_idx) {
            flip();
        } else if (t < T_idx) {
            int dist = T_idx - t;
            vector<int> steps_out;
            for (int i = 0; i < dist; ++i) steps_out.push_back(left_moves[i]);
            robustGoFlipReturn(dist, steps_out);
        } else {
            int dist = t - T_idx;
            vector<int> steps_out;
            for (int i = 0; i < dist; ++i) steps_out.push_back(right_moves[i]);
            robustGoFlipReturn(dist, steps_out);
        }
    }
}

void solveBob(vector<int> s) {
    vector<int> cur = s;
    int d = (cur[1] != -1) ? 1 : 2;

    while (cur[1] != -1 && cur[2] != -1) {
        cur = move(d);
        if (cur[1] == 0) d = 1;
        else d = 2;
    }

    vector<int> lights_val;
    lights_val.push_back(cur[0]);

    int d_run = (cur[1] != -1) ? 1 : 2;

    while (true) {
        cur = move(d_run);
        lights_val.push_back(cur[0]);
        if (cur[1] == -1 || cur[2] == -1) break;
        if (cur[1] == 0) d_run = 1;
        else d_run = 2;
    }

    int n = lights_val.size();
    long long S = 0;

    for (int i = 0; i < n; ++i) {
        if (lights_val[i]) S ^= (i + 1);
    }

    int steps_back = n - (int)S;

    for (int i = 0; i < steps_back; ++i) {
        cur = move(get_back_door(cur));
    }
}