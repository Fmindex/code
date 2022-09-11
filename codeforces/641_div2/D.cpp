#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  for (int lap = 0; lap < t; lap++) {
    int n, k;
    cin >> n >> k;
    int sum = 0;
    bool isValid = false;
    unordered_map<int, pair<bool, bool> > m;
    int preX = -1;
    m[0] = {false, true };
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      if (n == 1 && x == k) { isValid = true;}
      if (x < k) sum -= 1;
      else if (x > k) sum += 1;
      
      if (m[sum].first && i % 2 == 0 && i >= 3) { isValid = true; }
      if (m[sum].second && i % 2 && i >= 3) { isValid = true; }
      if (m[1 - sum].second && i % 2 == 0) { isValid = true; }
      if (m[1 - sum].first && i % 2) { isValid = true; }
      m[sum] = { m[sum].first || i % 2, m[sum].second || i % 2 == 0 };

      if (isValid) {
        cout << sum << "  " << i << "\n";
      }
    }
    if (isValid) cout << "yes\n";
    else cout << "no\n";
  }
}