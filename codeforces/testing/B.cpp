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
  for (int i = 0; i < t; i++)
  {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (((a + c == b) && (a + c == d)) || ((a + d == b) && (a + d == c)))
    {
      cout << "Yes\n";
    }
    else if (((b + c == a) && (b + c == d)) || ((b + d == a) && (b + d == c)))
    {
      cout << "Yes\n";
    }
    else
    {
      cout << "No\n";
    }
  }
}