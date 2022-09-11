#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int mem[1000005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for (int i = 1; i <= 1000000; i++)
    for (int j = 2; i * j <= 1000000; j++)
      if (mem[i * j] == 0)
        mem[i * j] = j;
      else
        mem[i * j] = min(mem[i * j], j);
  int t;
  cin >> t;
  for (int lap = 1; lap <= t; lap++) {
    int n, k;
    cin >> n >> k;
    while (k--) {
      if (n % 2 == 0) {
        n += (k + 1) * 2;
        break;
      }
      n += mem[n];
    }
    cout << n << "\n";
  }
}