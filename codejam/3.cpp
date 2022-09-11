#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int lap = 1; lap <= t; lap++) {
    int n;
    cin >> n;
    vector<pair<int, pair<int, int> > > V;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      V.push_back(make_pair(y, make_pair(x, i)));
    }
    sort(V.begin(), V.end());
    int lastC = 0, lastJ = 0;
    bool imp = false;
    char ans[2000];
    for (int i = 0; i < n; i++) {
      int order = V[i].second.second;
      int x = V[i].second.first;
      int y = V[i].first;
      if (lastC <= x) {
        ans[order] = 'C';
        lastC = y;
      } else if (lastJ <= x) {
        ans[order] = 'J';
        lastJ = y;
      } else {
        imp = true;
        break;
      }
    }
    if (imp) {
      cout << "Case #" << lap << ": " << "IMPOSSIBLE" << "\n";
    } else {
      cout << "Case #" << lap << ": ";
      for (int j = 0; j < n; j++) {
        cout << ans[j];
      }
      cout << "\n";
    }
  }
}