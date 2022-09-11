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
    int x, n, m;
    cin >> x >> n >> m;
    while (x / 2 + 10 < x && n > 0) {
      x = x / 2 + 10;
      n--;
    }
    while (m > 0) {
      x -= 10;
      m--;
    }
    if (x <= 0) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
}