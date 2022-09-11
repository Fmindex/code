#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int arr[200010];
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
    vector<int> answer;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    for (int i = 0; i < (n + 1) / 2; i++) {
      if (i == (n - i - 1)) {
        answer.push_back(arr[i]);
      } else {
        answer.push_back(arr[n - i -1]);
        answer.push_back(arr[i]);
      }
    }
    reverse(answer.begin(), answer.end());
    for (int x : answer) cout << x << " ";
    cout << "\n";
  }
}