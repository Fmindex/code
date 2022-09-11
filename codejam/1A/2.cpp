#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int pascalTable[510][510];
int isVisited[510][510];
pair<int, int> path[150];
bool isEnd = false;

void reset() {
  for(int i = 1; i <= 500; i++) {
    for (int j = 1; j <= 500; j++) {
      isVisited[i][j] = 0;
    }
  }
}

void dfs(int X, int Y, int sum, int depth) {
  if (isEnd) return;
  isVisited[Y][X] = 1;
  path[depth] = make_pair(X, Y);
  // cout << Y << " " << X << " " << sum << " " << pascalTable[Y][X] << "\n";
  if (sum - pascalTable[Y][X] == 0) {
    // cout<<"ans\n";
    isEnd = true;
    for (int i = 0; i <= depth; i++) {
      cout << path[i].second << " " << path[i].first << "\n";
    }
    return;
  }

  int directionX[6] = {0, 1, 1, 1, 0, -1};
  int directionY[6] = {-1, -1, 0, 1, 1, -1};

  for (int i = 0; i < 6; i++) {
    int x = X + directionX[i];
    int y = Y + directionY[i];
    if (y >= 1 && y <= 500 && x >= 1 && x <= y) {
      if (!isVisited[y][x] && pascalTable[y][x] <= sum - pascalTable[Y][X]) {
        dfs(x, y, sum - pascalTable[Y][X], depth + 1);
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for(int i = 1; i <= 500; i++) {
    for (int j = 1; j <= i; j++) {
      if (i == 1) pascalTable[i][j] = 1;
      else if (j == 1 || j == i) pascalTable[i][j] = 1;
      else pascalTable[i][j] = pascalTable[i - 1][j - 1] + pascalTable[i - 1][j];
    }
  }

  int t;
  cin >> t;
  for (int lap = 1; lap <= t; lap++)
  {
    int n;
    cin >> n;
    cout << "Case #" << lap << ": \n";
    isEnd = false;
    dfs(1, 1, n, 0);
    reset();
  }
}