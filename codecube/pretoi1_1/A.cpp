#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  int dp[3][8000] = {0};
  int ans[8000] = {0};
  int maxAns = -1;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= m; j++) {
      int x, cur = (i + 1) % 2, pre = i % 2;
      x = s[j - 1] - '0';
      if (x == 1) dp[cur][j] = min(dp[pre][j], min(dp[cur][j - 1], dp[pre][j - 1])) + 1;
      else dp[cur][j] = 0;
      ans[dp[cur][j]]++;
      maxAns = max(maxAns, dp[cur][j]);
    }
  }
  for (int i = maxAns; i >= 1; i--) ans[i] += ans[i + 1];
  for (int i = 1; i <= min(m, n); i++) cout << ans[i] << "\n";
}