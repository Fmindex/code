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
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    if (((a + b) * n >= c - d) && ((a - b) * n <= c + d)) cout << "Yes\n";
    else cout << "No\n";
  }
}