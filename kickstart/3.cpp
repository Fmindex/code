#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> e[500005];
int mem[500005];

void dp(int cur, int cnt, int X) {
  if (cnt != 0) {
    for (int to : e[cur]) {
      dp(to, cnt - 1, X);
    }
    return;
  }
  mem[cur] = 1;
  for (int to : e[cur]) {
      dp(to, X, X);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int lap = 1; lap <= t; lap++) {
    int n, A, B;
    cin >> n >> A >> B;
    for (int k = 0; k <= n; k++) e[k] = vector<int>();
    for (int i = 2; i <= n; i++) {
      int p;
      cin >> p;
      e[i].push_back(p);
    }
    double answer = 0.0;
    double all = (double)n;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        for (int k = 0; k <= n; k++) mem[k] = 0;
        dp(i, 0, A - 1);
        dp(j, 0, B - 1);

        int cnt = 0;
        for (int k = 1; k <= n; k++) {
          if (mem[k]) cnt++;
        }
        // cout << i << " " << j << " " << cnt << "\n";
        answer += ((double)cnt);
      }
    }
    all *= all;
    // cout << answer << " " << all << "\n";
    cout << "Case #" << lap << ": ";
    cout << answer / all << "\n";
    
  }
}