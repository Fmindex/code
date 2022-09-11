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
    int r, c, ans = 0;
    cin >> r >> c;
    vector<float> V[100010];
    vector<bool> isEli[100010];
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        float x;
        cin >> x;
        V[i].push_back(x);
        isEli[i].push_back(false);
      }
    }
    bool isContinue = true;
    while (isContinue) {
      isContinue = false;
      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
          int dx[] = {-1, 0, 1, 0};
          int dy[] = {0, -1, 0, 1};
          float sum = 0;
          int count = 0;
          for (int di = 0; di < 4; di++) {
            int x = j + dx[di];
            int y = i + dy[di];
            if (x >= 0 && x < c && y >= 0 && y < r) {
              sum += V[y][x];
              count++;
            }
          }
            // cout << V[i][j] << " " << isEli[i][j] << "\n";
          if (!isEli[i][j]) {
            ans += V[i][j];
          }
          if (!isEli[i][j] && count != 0 && sum / count > V[i][j]) {
            isContinue = true;
            isEli[i][j] = true;
          }
        }
        cout << ans << "\n";
      }
    }
    
    cout << "Case #" << lap << ": ";
    cout << ans << "\n";
    
  }
}