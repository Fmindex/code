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
    int n;
    cin >> n;
    int x = n, bit = 0;
    while (x > 0)
    {
      x /= 2;
      bit++;
    }
    int pre = 1;
    cout << bit - 1 << "\n";
    for (int i = 1; i <= bit; i++)
    {
      int x = n / (bit - i + 1);
      int maxB = i == 1 ? 1 : (1 << (i - 2));
      if (i != 1)
        cout << min(maxB, x) << " ";
      n -= min(maxB, x) * (bit - i + 1);
    }
    cout << "\n";
  }
}