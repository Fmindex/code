#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <utility>
#include <math.h>

#define FOR(i, x, y) for (int i = x; i <= y; i++)
#define ROF(i, x, y) for (int i = x; i >= y; i--)
#define mp make_pair
#define X first
#define Y second
#define pb push_back
#define sz(X) ((int)(X).size())
#define MAX_int (1 << 31) - 1
#define MIN_int -(1 << 31) + 1

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

int main()
{
  int n, pos, l, r;
  int sum = 0;
  cin >> n >> pos >> l >> r;
  if (pos < l)
  {
    if (l != 1)
      sum += (l - pos) + 1;
    if (r != n)
      sum += (r - l) + 1;
  }
  else if (pos > r)
  {
    if (r != n)
      sum += (pos - r) + 1;
    if (l != 1)
      sum += (r - l) + 1;
  }
  else
  {
    if (l != 1)
      sum += (pos - l) + 1;
    if (r != n)
      sum += (r - pos) + 1;
    if (l != 1 && r != n)
      sum += min(pos - l, r - pos);
  }
  cout << sum;
  return 0;
}