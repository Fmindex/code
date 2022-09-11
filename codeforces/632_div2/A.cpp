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
    int cnt = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (j == m - 1 && i == n - 1) cout << "B";
        else if (cnt % 2) cout << "B";
        else cout << "W";
        cnt++;
      }
      cout << "\n";
    }
  }
}

