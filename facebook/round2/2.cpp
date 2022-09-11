#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

long long L[1000005], H[1000005], W[1000005];
long long Ah, Bh, Ch, Dh;
long long Aw, Bw, Cw, Dw;
long long Al, Bl, Cl, Dl;
long long MOD = (long long)(1e9 + 7);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int lap = 1; lap <= t; lap++) {
    int n, k;
    long long answer = 1LL;
    unordered_map<long long, long long> M;
    set<long long> S;
    cin >> n >> k;
    for (int i = 0; i < k; i++) cin >> L[i];
    cin >> Al >> Bl >> Cl >> Dl;
    for (int i = k; i < n; i++) L[i] = (Al * L[i - 2] + Bl * L[i - 1] + Cl) % Dl + 1LL;

    for (int i = 0; i < k; i++) cin >> W[i];
    cin >> Aw >> Bw >> Cw >> Dw;
    for (int i = k; i < n; i++) W[i] = (Aw * W[i - 2] + Bw * W[i - 1] + Cw) % Dw + 1LL;

    for (int i = 0; i < k; i++) cin >> H[i];
    cin >> Ah >> Ah >> Ah >> Ah;
    for (int i = k; i < n; i++) H[i] = (Ah * H[i - 2] + Bh * H[i - 1] + Ch) % Dh + 1LL;

    long long p = 0LL;

    for (int i = 0; i < n; i++) {
        long long LEFT;
        long long RIGHT;

        if (S.find(L[i]) == S.end()) {
            S.insert(L[i]);
            auto start = S.find(L[i]);
            if (start == S.begin()) {
                LEFT = L[i];
            } else {
                start--;
                if(M[(*start)] < 0) {
                    LEFT  = *start;
                }else {
                    LEFT = L[i];
                }
            }
            S.erase(L[i]);
        } else {
            if(M[L[i]] < 0){
                LEFT = L[i];
            }else {
                auto start = S.find(L[i]);
                start--;
                LEFT = *start;
            }
        }

        
        if (S.find(L[i] + W[i]) == S.end()) {
            S.insert(L[i] + W[i]);
            auto start = S.find(L[i] + W[i]);
            start++;
            if (start == S.end()) {
                RIGHT = L[i] + W[i];
            } else {
                if (M[(*start)] < 0){
                    RIGHT = L[i] + W[i];
                } else {
                    RIGHT = *start;
                }
            }
            S.erase(L[i] + W[i]);
        } else {
            auto start = S.find(L[i] + W[i]);
            if (M[(*start)] > 0) {
                RIGHT = L[i] + W[i];
            } else {
                start++;
                RIGHT = *start;
            }
        }

        S.insert(LEFT);
        S.insert(RIGHT);

        long long sumW = 0LL;
        long long sumH = 0LL;
        long long P = 0LL;
        auto start = S.find(LEFT);
        auto stop = S.find(RIGHT);
        long long pre = LEFT;
        while (start != stop) {
            if (M[(*start)] < 0) {
                sumW += (*start) - pre;
                sumH++;
                P -= M[(*start)];
                pre = (*start);
            } else if (M[(*start)] > 0) {
                pre = (*start);
                sumH++;
            }
            auto temp = start;
            start++;
            S.erase(temp);
        }

        if (M[(*start)] == 0) {
            sumW += (*start) - pre;
        } else {
            sumH++;
        }

        p -= P;
        P -= ((H[i] * (sumH - 2LL)) % MOD);
        P %= MOD;
        sumW %= MOD;
        P += (2LL * sumW);
        P += MOD;
        P %= MOD;

        S.insert(LEFT);
        S.insert(RIGHT);
        M[LEFT] = -P;
        M[RIGHT] = P;

        p += P;
        p %= MOD;
        P += MOD;
        p %= MOD;

        answer *= p;
        answer %= MOD;
    }
    cout << "Case #" << lap << ": " << answer << "\n";
  }
}