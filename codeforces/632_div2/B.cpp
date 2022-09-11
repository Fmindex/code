#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int arr[200010];
int target[200010];
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
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) cin >> target[i];
    bool foundNegative = false, foundPositive = false, canDo = true;
    for (int i = 0; i < n; i++) {
      if (arr[i] > target[i]) {
        if (!foundNegative) canDo = false;
      } else if (arr[i] < target[i]) {
        if (!foundPositive) canDo = false;
      }
      if (arr[i] < 0) foundNegative = true;
      if (arr[i] > 0) foundPositive = true;
    }
    if (canDo) cout << "YES\n";
    else cout << "NO\n";
  }
}