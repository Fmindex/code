#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int arr[100010] = {0}, check[100010] = {0};
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int lap = 1; lap <= t; lap++) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      arr[x] = i;
      check[i] = 0;
    }
    int cur = arr[1];
    bool isValid = true;
    for (int i = 1; i <= n; i++) {
      if (arr[i] == cur) {
        check[cur] = 1;
        cur++;
      } else {
        if (cur > n || check[cur]) cur = arr[i];
        else isValid = false;
        check[cur] = 1;
        cur++;
      }
    }
    if (isValid) cout << "Yes\n";
    else cout << "No\n";
  }
}