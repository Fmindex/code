#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;
int PR[15], PS[15], RS[15];
string answer = "";
int dfs(int index, int dep, char target) {
  if (dep == 0) {
    answer[index] = target;
    return index;
  }
  char left = 'P', right = 'R';
  if (target == 'R') {
    left = 'S';
    right = 'R';
  } 
  if (target == 'S') {
    left = 'P';
    right = 'S';
  } 
  int r = dfs(index * 2, dep - 1, left);
  int l = dfs(index * 2 + 1, dep - 1, right);
  bool isLess = false;
  int diff = l - r;
  for (int i = r; i < l; i++) {
    if (answer[i] < answer[i + diff]) {
      isLess = true;
      break;
    } else if (answer[i] > answer[i + diff]) {
      break;
    }
  }
  if (!isLess) {
    for (int i = r; i < l; i++) {
      char temp = answer[i];
      answer[i] = answer[i + diff];
      answer[i + diff] = temp;
    }
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int lap = 1; lap <= t; lap++) {
    int n, r, p, s;
    cin >> n >> r >> p >> s;
    int dep = 0;
    answer = "";
    while (r + p + s > 1) {
      int x = (r + p - s) / 2;
      int pr = x;
      int ps = p - x;
      int rs = r - x;
      if (pr < 0 || ps < 0 || rs < 0) {
        break;
      }
      PR[dep] = pr;
      PS[dep] = ps;
      RS[dep] = rs;
      p = pr;
      r = rs;
      s = ps;
      dep++;
    }
    cout << "Case #" << lap << ": ";
    if (r + p + s > 1) {
      cout << "IMPOSSIBLE\n";
      continue;
    }
    // cout << r << " " << p << " " << s;

    int cnt = 1<<n;
    for (int i = 0; i < cnt; i++) answer += ' ';
    if (p > 0)
      dfs(0, dep, 'P');
    if (s > 0)
      dfs(0, dep, 'S');
    if (r > 0)
      dfs(0, dep, 'R');
    cout << answer;
    cout << "\n";
  }
}