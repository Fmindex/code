#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n, m;
vector<string> a;
void dfs(int i, int j) {
  if (i < 0 || i >= n || j < 0 || j >= m) return;
  if (a[i][j] == '.') return;
  a[i][j] = '.';
  dfs(i, j + 1);
  dfs(i, j - 1);
  dfs(i - 1, j);
  dfs(i + 1, j);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);


  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    a.push_back(s);
  }
  int cntEmptyRow = 0, cntEmptyCol = 0;
  bool isValid = true;
  for (int i = 0; i < n; i++) {
    int changeColorCnt = 0;
    bool isEmpty = true;
    int state = 0;
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '#') {
        if (state == 0) {
          state = 1;
          changeColorCnt++;
        }
      } else {
        if (state == 1) {
          state = 0;
        }
      }
      if (a[i][j] == '#') isEmpty = false;
    }
    if (isEmpty)
      cntEmptyRow++;
    if (changeColorCnt > 1) {
      // cout << i << " " << changeColorCnt << "\n";
      isValid = false;
      break;
    } 
  }
  if (!isValid) {
    cout << "-1";
    return 0;
  }

  for (int i = 0; i < m; i++) {
    int changeColorCnt = 0;
    bool isEmpty = true;
    int state = 0;
    for (int j = 0; j < n; j++) {
      if (a[j][i] == '#') {
        if (state == 0) {
          state = 1;
          changeColorCnt++;
        }
      } else {
        if (state == 1) {
          state = 0;
        }
      }
      if (a[j][i] == '#') isEmpty = false;
    }
    if (isEmpty)
      cntEmptyCol++;
    if (changeColorCnt > 1) {
      isValid = false;
      break;
    } 
  }
  if (!isValid) {
    cout << "-1";
    return 0;
  }

  if ((cntEmptyCol > 0 && cntEmptyRow == 0) || (cntEmptyCol == 0 && cntEmptyRow > 0)) {
    cout << "-1";
    return 0;
  }
  int answer = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '#') {
        answer++;
        dfs(i, j);
      }
    }
  }
  cout << answer;
}