#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int gcd(int x, int y) {
  if (y == 0) return x;
  else return gcd(y, x % y);
}

int lcm(int x, int y) {
  return x / gcd(x, y) * y;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);


  int n, m, c = 0;
  int arr[200010];
  int mem1[200010], mem2[200010];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int gcd1 = arr[0];
  for (int i = 0; i < n; i++) {
    gcd1 = gcd(gcd1, arr[i]);
    mem1[i] = gcd1;
  }
  gcd1 = arr[n - 1];
  for (int i = n - 1; i >= 0; i--) {
    gcd1 = gcd(gcd1, arr[i]);
    mem2[i] = gcd1;
  }
  int answer = mem2[1];
  for (int i = 0; i < n; i++) {
    if (i == 0) answer = lcm(answer, mem2[1]);
    else if (i == n - 1) answer = lcm(answer, mem1[n - 2]);
    else answer = lcm(answer, gcd(mem1[i - 1], mem2[i + 1]));
  }
  cout << answer;
}