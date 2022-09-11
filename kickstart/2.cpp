#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int a[10005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int lap = 1; lap <= t; lap++) {
    int n, answer = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int cnt = 0, maxCnt = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] > a[i - 1]) cnt++;
      else if (a[i] < a[i - 1]) cnt = 0;
      maxCnt = max(maxCnt, cnt);
      if (maxCnt > 3) {
        answer++;
        maxCnt = 0;
        cnt = 0;
      }
    }
    cnt = 0;
    int minCnt = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] < a[i - 1]) cnt++;
      else if (a[i] > a[i - 1]) cnt = 0;
      minCnt = max(minCnt, cnt);
      if (minCnt > 3) {
        answer++;
        minCnt = 0;
        cnt = 0;
      }
    }
      
    cout << "Case #" << lap << ": ";
    cout << answer << "\n";
  }
}