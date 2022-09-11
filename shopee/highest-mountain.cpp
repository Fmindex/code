#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int lap = 1; lap <= t; lap++) {
    int n, a[1005];
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int answer = -1, ianswer = -1, cnt = 1;
    for (int i = 0; i < n; i++) {
      if (a[i] == cnt) cnt++;
      else cnt = 1;

      if (answer < cnt - 1 || (answer <= cnt - 1 && i < ianswer)) {
        answer = cnt - 1;
        ianswer = i;
      }
    }
    cnt = 1;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] == cnt) cnt++;
      else cnt = 1;

      if (answer < cnt - 1 || (answer <= cnt - 1 && i < ianswer)) {
        answer = cnt - 1;
        ianswer = i;
      }
    }
    if (answer == 0) {
      answer = -1;
      ianswer = -1;
    }
    cout << "Case #" << lap << ": " << answer << " " << ianswer << "\n";
  }
}
