#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>

using namespace std;
int a[2000][2000];
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
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cin >> a[i][j];
      }
    }
    long long answer = 0LL;
    for (int i = 0; i < n; i++)
    {
      long long sum = 0LL;
      for (int j = 0; i + j < n; j++)
      {
        sum += (long long)a[i + j][j];
      }
      answer = max(answer, sum);
      sum = 0LL;
      for (int j = 0; i + j < n; j++)
      {
        sum += (long long)a[j][i + j];
      }
      answer = max(answer, sum);
    }
    cout << answer << "\n";
  }
}