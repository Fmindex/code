#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int arr[200010];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int lap = 1; lap <= t; lap++)
  {
    int n;
    cin >> n;
    int pre = 0, answer = 0;
    for (int i = 0; i < n; i++) {
      int cur;
      cin >> cur;
      if (i == 0 || cur >= pre) {
        pre = cur;
        continue;
      }
      int diff = pre - cur;
      int cntBit = 0;
      while (diff > 0) {
        diff /= 2;
        cntBit++;
      }
      answer = max(answer, cntBit);
    }
    cout << answer << "\n";
  }
}