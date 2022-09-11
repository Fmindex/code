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
    int n, m;
    cin >> n >> m;
    if (n == 1 || m == 1) {
      cout << "YES\n";
    } else if (n == 2 && m == 2) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}