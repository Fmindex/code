#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>

using namespace std;
pair<long long, long long> a[100005];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int lap = 1; lap <= t; lap++)
  {
    long long used = 0LL, answer = 0LL, sum = 0LL, ansUsed = 0LL;
    int n;
    cin >> n;
    vector<pair<long long, int>> v;
    for (int i = 0; i < n; i++) {
      long long x, y;
      cin >> x >> y;
      a[i] = {x, y};
      sum += x;
    }
    for (int i = 0; i < n; i++) {
      v.push_back({ a[i].second + a[i].first, i });
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    long long acc = 0LL;
    for (int i = 0; i < n; i++) {
      // cout << v[i].first << " " << v[i].second << " " << acc << "\n";
      if (v[i].first > sum - acc) {
        used++;
        acc += a[v[i].second].first;
      }
    }
    cout << "Case #" << lap << ": ";
    if (used < n) {
      cout << used << " " << "INDEFINITELY" << "\n";
      continue;
    }
    answer = sum;
    long long cur = sum, maxPre = -1e18;
    acc = 0LL;
    used = 0LL;
    for (int i = 0; i < n; i++) {
      if (a[i].second - (sum - a[i].first) + acc > 0) {
        if (maxPre + acc + a[i].first > 0) break;
        acc += a[i].first;
        cur -= a[i].first;
        used++;
      } else {
        cur += a[i].first;
        maxPre = max(maxPre, a[i].second - (sum - a[i].first));
      }
      if (answer <= cur) {
        if (answer < cur) {
          answer = cur;
          ansUsed = used;
        } else {
          if (used < ansUsed) {
            ansUsed = used;
          }
        }
      }
    }
    cout << ansUsed << " " << answer << "\n";
  }
}