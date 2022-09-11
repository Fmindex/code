#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long L[1000005], H[1000005];
long long Ah, Bh, Ch, Dh;
long long Al, Bl, Cl, Dl;
long long M = (long long)(1e9 + 7);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int lap = 1; lap <= t; lap++) {
    int n, k;
    long long answer, w;
    cin >> n >> k >> w;

    for (int i = 0; i < k; i++)
      cin >> L[i];
    cin >> Al >> Bl >> Cl >> Dl;
    for (int i = k; i < n; i++)
      L[i] = (Al * L[i - 2] + Bl * L[i - 1] + Cl) % Dl + 1LL;

    for (int i = 0; i < k; i++)
      cin >> H[i];
    cin >> Ah >> Bh >> Ch >> Dh;
    for (int i = k; i < n; i++)
      H[i] = (Ah * H[i - 2] + Bh * H[i - 1] + Ch) % Dh + 1LL;
     
    long long p = 2 * (w + H[0]);
    answer = p % M;
    // cout << p << "\n";
    for (int i = 1; i < n; i++) {
      long long peak = 0;
      for (int j = 1; j <= w; j++) {
        int t = i - j;
        if (t < 0) break;
        if (L[t] < L[i] && L[i] <= L[t] + w) {
          peak = max(peak, H[t]);
        }
      }
      if (peak >= H[i]) {
        p = p + 2 * min((L[i] - L[i - 1]), w);
      } else {
        p = p + 2 * min((L[i] - L[i - 1]), w) + 2 * (H[i] - peak);
      }
      p %= M;
      answer *= p;
      answer %= M;
      // cout << p << " " << peak << "\n";
    }

    cout << "Case #" << lap << ": " << answer << "\n";
  }
}