#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int a[300005];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int lap = 1; lap <= t; lap++)
  {
    int answer = 0, n, cur, pre, curDif = 2e9 + 10, curL = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> cur;
      if (i == 0)
      {
        pre = cur;
        continue;
      }
      int diff = cur - pre;
      if (diff == curDif)
        curL++;
      else
        curL = 1;

      curDif = diff;
      pre = cur;

      answer = max(curL + 1, answer);
    }
    cout << "Case #" << lap << ": ";
    cout << answer << "\n";
  }
}