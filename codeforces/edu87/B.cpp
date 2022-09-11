#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

vector<char> v[100];
bool done[100], visit[100];
vector<char> answer;

void reset() {
  for (char i = 'A'; i <= 'Z'; i++) {
    done[i] = false;
    visit[i] = false;
  }
  answer.clear();
}

bool dfs(char cur) {
  if (visit[cur] && !done[cur]) return false;
  if (visit[cur] && done[cur]) return true;
  bool can = true;
  visit[cur] = true;
  // cout << cur << " requires: ";
  for(char to : v[cur]) {
    // cout << to << " ";
    can &= dfs(to);
  }
  // cout << "\n" << cur << " " << can << "\n";
  if (can) {
    done[cur] = true;
    answer.push_back(cur);
  }
  return can;

}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int lap = 1; lap <= t; lap++)
  {
    reset();
    int r, c;
    cin >> r >> c;
    string s[31];
    bool m[100][100] = {false}; 
    for (int i = 0; i < r; i++) {
      cin >> s[i];
    }
    for (int i = 0; i < r - 1; i++) {
      for (int j = 0; j < c; j++) {
        if (s[i + 1][j] != s[i][j]) m[s[i][j]][s[i + 1][j]] = 1;
      }
    }
    for (char i = 'A'; i <= 'Z'; i++) {
      v[i].clear();
      for (char j = 'A'; j <= 'Z'; j++)
      if (i != j && m[i][j])
        v[i].push_back(j);
    }
    bool isDone = true;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        isDone &= dfs(s[i][j]);
      }
    }
    cout << "Case #" << lap << ": ";
    if (isDone) {
      for (char c : answer) cout << c;
    } else {
      cout << "-1";
    }
    cout << "\n";
  }
}
