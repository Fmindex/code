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

  int x = 3;
  int *p;
  p = &x;
  *p = 5;
  cout << x << endl;
  cout << *p << endl;
  cout << p << endl;

  int t;
  cin >> t;
  for (int lap = 1; lap <= t; lap++)
  {
    int n;
    cin >> n;
    int small = (1 << (n / 2)) - 2 + (1 << n);
    int big = ((1 << (n + 1)) - 2) - small;
    cout << small - big << "\n";
  }
}