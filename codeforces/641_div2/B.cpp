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

  int t;
  cin >> t;
  for (int lap = 1; lap <= t; lap++)
  {
    int n, dp[100005] = {0}, arr[100005], answer = -1;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
      for (int j = i + i; j <= n; j += i) {
        if (arr[j] > arr[i]) dp[j] = max(dp[j], dp[i] + 1);
      }
      answer = max(answer, dp[i]);
    }
    cout << answer + 1 << "\n";
  }
}