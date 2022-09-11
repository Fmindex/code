#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
#include <math.h>

using namespace std;

long long dp[1005][1005][2];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int lap = 1; lap <= t; lap++)
  {
    int n, k;
    long long sum = 0LL;
    cin >> n >> k;
    for (int i = 0; i <= 1000; i++)
      for (int j = 0; j <= 1000; j++)
        dp[i][j][0] = dp[i][j][1] = 0LL;
    for (int i = 1; i <= 1000; i++) dp[0][i][0] = dp[0][i][1] = 1e15;
    for (int i = 0; i <= 1000; i++) dp[i][0][1] = 1e15;
    for (int i = 1; i <= n; i++) {
      long long x;
      cin >> x;
      sum += x;
      for (int j = 1; j <= k; j++) {
        if (j > i) dp[i][j][0] = dp[i][j][1] = 1e15;
        else {
          dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1]);
          dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j - 1][1]);
          if (i > 1 && j > 1) dp[i][j][0] = min(dp[i][j][0], min(dp[i - 2][j - 2][0], dp[i - 2][j - 2][1]) + x);
          dp[i][j][1] = min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + x;
        }
        // cout << "(" << dp[i][j][0] << ", " << dp[i][j][1] << ") ";
      }
      // cout << "\n";
    }    
  
    cout << "Case " << lap << ": " << min(dp[n][k][0], dp[n][k][1]) << "\n";
  }
}
