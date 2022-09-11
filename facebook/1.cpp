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
    char answer[51][51];
    cin >> n;
    string I, O;
    cin >> I >> O;
    for (int i = 0; i < n; i++) {
      bool canGo = O[i] == 'Y';
      for (int j = i - 1; j >= 0; j--) {
        if (!canGo) {
          answer[i][j] = 'N';
          continue;
        }
        if (I[j] == 'N') {
          answer[i][j] = 'N';
          canGo = false;
          continue;
        }
        answer[i][j] = 'Y';
        if (O[j] == 'N') canGo = false;
      }
      answer[i][i] = 'Y';
      canGo = O[i] == 'Y';
      for (int j = i + 1; j < n; j++) {
        if (!canGo) {
          answer[i][j] = 'N';
          continue;
        }
        if (I[j] == 'N') {
          answer[i][j] = 'N';
          canGo = false;
          continue;
        }
        answer[i][j] = 'Y';
        if (O[j] == 'N') canGo = false;
      }
    }
    cout << "Case #" << lap << ": \n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << answer[i][j];
      }
      cout << "\n";
    }
    
  }
}