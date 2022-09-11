#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
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
    int n;
    cin >> n;
    queue<int> remain, want;
    int arr[105] = {0}, require[105] = {0};
    vector<string> answer;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x == 0) {
        if (!want.empty()) {
          require[want.front()]--;
          arr[i] = want.front();
        } else {
          remain.push(i);
        }
        while (!want.empty() && require[want.front()] == 0) want.pop();
      } else {
        while (!remain.empty() && x > 0) {
          arr[remain.front()] = i;
          remain.pop();
          x--;
        }
        bool canAdd = true;
        if (!want.empty()) {
          require[want.front()]--;
          arr[i] = want.front();
          canAdd = false;
        }
        while (!want.empty() && require[want.front()] == 0) want.pop();

        if (x == 0) {
          if (canAdd) remain.push(i);
        } else if (x == 1) {
          if (canAdd) arr[i] = i;
          else {
            want.push(i);
            require[i] = 1;
          }
        } else {
          if (canAdd) arr[i] = i;
          want.push(i);
          require[i] = x - canAdd;
        }
      }
    }
    cout << "Case #" << lap << ": "; 
    if (arr[0] != 0 || arr[n - 1] != n - 1 || want.size() > 0 || remain.size() > 0) {
      cout << "IMPOSSIBLE\n";
    } else {
      int row = 1;
      for (int i = 0; i < n; i++) row = max(row, abs(i - arr[i]) + 1);
      for (int i = 0; i < row; i++) {
        string temp = "";
        for (int j = 0; j < n; j++) temp += '.';
        answer.push_back(temp);
      }

      for (int i = 0; i < n; i++) {
        int cur = i;
        int row = 0;
        while (cur != arr[i]) {
          if (cur < arr[i]) {
            answer[row][cur] = '\\';
            cur++;
          } else {
            answer[row][cur] = '/';
            cur--;
          }
          row++;
        }
      }
      cout << row << "\n";  
      for (int i = 0; i < row; i++) {
        cout << answer[i] << "\n";
      }
    }
      // for (int i = 0; i < n; i++) cout << arr[i] << " ";
  }
}