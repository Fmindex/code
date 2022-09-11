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
    int n, k;
    cin >> n >> k;
    int cnt = k, answer = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x != cnt) cnt = k;
      if (x == cnt) cnt--;
      if (cnt == 0) answer++, cnt = k;
    }
    cout << "Case #" << lap << ": ";
    cout << answer << "\n";
  }
}
