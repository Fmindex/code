#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>

using namespace std;
int answer[300010];
int cnt[300010];
deque<pair<int, int> > Q;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, k, q, qSize = 0;
  cin >> n >> k >> q;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x <= k) {
      Q.push_back({ x, i });
      if (cnt[x] == 0) qSize++;
      cnt[x]++;
    }
    while (!Q.empty() && cnt[Q.front().first] > 1 ) {
      cnt[Q.front().first]--;
      Q.pop_front();
    }
    if (Q.empty() || qSize < k) {
      answer[i] = -1;
    } else {
      answer[i] = Q.front().second;
    }
  }
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    if (x <= answer[y] && answer[y] != -1) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  
}