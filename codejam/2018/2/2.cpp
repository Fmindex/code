#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

bool bmp(int edge[105][105], int n, int cur, int matchOf[], int seen[]) {
  for (int i = 1; i <= n; i++) {
    if (edge[cur][i] && !seen[i]) {
      seen[i] = 1;
      if (matchOf[i] == 0 || bmp(edge, n, matchOf[i], matchOf, seen)) {
        matchOf[i] = cur;
        return true;
      }
    }
  }
  return false;
}

int maxBpm(int edge[105][105], int n) {
  int matchOf[105] = {0}, answer = 0;
  for (int i = 1; i <= n; i++) {
    int seen[105] = {0};
    if (bmp(edge, n, i, matchOf, seen)) answer++;
  }
  return answer;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int lap = 1; lap <= t; lap++)
  {
    int n, answer = 0;
    cin >> n;
    int arr[105][105] = {0};
    int edge[105][105] = {0};
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> arr[i][j];
      }
    }
    for (int x = -n; x <= n; x++) {
      int cnt = 0;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (arr[i][j] == x) edge[i][j] = 1, cnt++;
          else edge[i][j] = 0;
        }
      }
      answer += cnt - maxBpm(edge, n);
      // cout << maxBpm(edge, n) << "\n";
    }
    cout << "Case #" << lap << ": ";
    cout << answer << "\n";
  }
}