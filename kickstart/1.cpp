#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int a[300005];
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
    int maxEle = -1;
    for (int i = 0; i < n; i++) {
      bool isNewMax = false, more = false;
      if (a[i] > maxEle) {
        isNewMax = true;
        maxEle = a[i];
      }
      if (i == n - 1) {
         more = true;
      } else {
        more = a[i] > a[i + 1];
      }
      if (more && isNewMax) answer++;
    }
      cout << "Case #" << lap << ": ";
    cout << answer << "\n";
    
  }
}