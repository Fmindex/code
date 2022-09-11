#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int mem[30000];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int i = 2, j = 0;
  int result = 0, cnt = 0;
  while (result <= 1000000000)
  {
    result += i + j;
    i += 2;
    j += 1;
    mem[cnt] = result;
    cnt++;
    if (result >= 1000000000)
      break;
  }

  int t;
  cin >> t;
  for (int lap = 1; lap <= t; lap++)
  {
    int n, answer = 0;
    cin >> n;
    while (n >= 2) {
      for (int i = 0; i < cnt; i++) {
        if (mem[i] >= n) {
          if (i == 0) {
            n = 0;
          } else {
            if (mem[i] == n) n -= mem[i];
            else n -= mem[i - 1];
          }
          answer++;
          break;
        } 
      }
    }
    cout << answer << "\n";
  }
}