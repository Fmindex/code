#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>

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
    cout << "Case #" << lap << ": ";
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    deque<int> q;
    a -= c;
    b -= c;
    if (a + b + c > n) {
      cout << "IMPOSSIBLE\n";
      continue;
    }
    for (int i = 0; i < c; i++) q.push_back(n);
    if (a + b + c < n) {
      int diff = n - (a + b + c);
      if (a != 0) {
        while (diff--) {
          q.push_front(1);
        }
      } else if (b != 0) {
        while (diff--) {
          q.push_back(1);
        }
      } else {
        if (c == 1) {
          cout << "IMPOSSIBLE\n";
          continue;
        } else {
          q.pop_front();
          while (diff--) q.push_front(1);
          q.push_front(n);
        }
      }
    }
    int temp = n - 1;
    while (a--) q.push_front(temp--);    
    temp = n - 1;
    while (b--) q.push_back(temp--);    
    while (!q.empty()) {
      cout << q.front() << " ";
      q.pop_front();
    }
    cout << "\n";
  }
}