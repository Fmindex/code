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
    int n, k, answer = 0, indexAnswer = 1, peak = 0;
    int arr[200010];
    int qs[200010] = {0};
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    for (int i = 3; i <= n; i++) {
      if (arr[i - 1] > arr[i] && arr[i - 1] > arr[i - 2]) {
        qs[i - 2] = 1;
        peak++;
      } else qs[i - 2] = 0;
      if (i > k) {
        if (qs[i - k] == 1) peak--;
      }
      if (i - k >= 0 && peak > answer) {
        answer = peak;
        indexAnswer = i - k + 1;
      }
    }
    cout << answer + 1 << " " << indexAnswer << "\n";
  }
}