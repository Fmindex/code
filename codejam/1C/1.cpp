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
    int x, y;
    cin >> x >> y;
    string s;
    cin >> s;
    vector<pair<int, int>> path;
    path.push_back({x, y});
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'S') y--;
      if (s[i] == 'N') y++;
      if (s[i] == 'E') x++;
      if (s[i] == 'W') x--;
      path.push_back({x, y});
    }
    int answer = 2e9;
    for (int i = 0; i < path.size(); i++) {
      int tx = path[i].first, ty = path[i].second;
      if (abs(tx) + abs(ty) <= i) {
        answer = min(answer, i);
      }
    }
    cout << "Case #" << lap << ": "; 
    if (answer == 2e9) cout << "IMPOSSIBLE\n";
    else cout << answer << "\n";
  }
}