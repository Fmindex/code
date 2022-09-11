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


  int n, m;
  int a[200010];
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    a[x] = 1;
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) {
      cnt++;
    } 
  }
  if (cnt == n) cout << "-1";
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) {
      cout << "E";
    } else {
      cout << "A";
    }
  }

}