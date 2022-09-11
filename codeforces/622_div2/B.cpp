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
    int n, x, y;
    cin >> n >> x >> y;
    cout << max(1, min(n, x + y - n + 1)) << " " << min(n, x + y - 1) << "\n";
  }
}