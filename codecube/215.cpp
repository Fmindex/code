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
  int arr[100010];
  cin >> n >> m;
  int cur = 0, cntCur = 0;
  int answer = 1;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (i == 0) {
      cur = arr[i];
      cntCur = 1;
      continue;
    }
    // cout << cur << " " << answer << "\n";
    if (arr[i] <= m / 2) {
      if (cur + arr[i] > (cntCur + 1) * m / 2) {
        cur += arr[i];
        cntCur++;
      } else {
        answer++;
        cur = arr[i];
        cntCur = 1;
      }
    } else {
      if (cur < cntCur * m / 2) {
        cur += arr[i];
        cntCur++;
      } else {
        answer++;
        cur = arr[i];
        cntCur = 1;
      }
    }
  }
  cout << answer;
}