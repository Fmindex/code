#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int lap = 1; lap <= t; lap++) {
        int n, k, p;
        int v[52][1505] = {0};
        int dp[52][1505] = {0};        
        cin >> n >> k >> p;
        for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= k; j++) { 
            int x;
            cin >> v[i][j];
          }
        }
        for (int i = 1; i <= n; i++) {
          dp[i][0] = 0;
          for (int j = 1; j <= k; j++) {
            v[i][j] += v[i][j - 1];
          }
          for (int l = 1; l <= p; l++) {
            for (int j = 0; j <= k; j++) {
              if (l >= j) {
                dp[i][l] = max(dp[i - 1][l - j] + v[i][j], dp[i][l]);
              }
            }
          } 
        }
        int ans = -1;
        for (int i = 1; i <= p; i++) {
          ans = max(ans, dp[n][i]);
        }
        cout << "Case #" << lap << ": " << ans << "\n";
    }
}