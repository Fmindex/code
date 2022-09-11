#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int head[600010], power[600010], cnt;

int _find(int x) {
  if (head[x] == x) return x;
  return head[x] = _find(head[x]);
}

void _union(int x, int y) {
  int headX = _find(x);
  int headY = _find(y);
  if (headX != headY) {
    cnt--;
    head[headX] = headY;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k, M = 1e9 + 7;
  bool impossible = true;
  cin >> n >> k;
  cnt = n * 2;
  for (int i = 1; i <= 2 * n; i++) head[i] = i;
  power[0] = 1;
  for (int i = 1; i <= n; i++) power[i] = (power[i - 1] * 2) % M;
  for (int i = 0; i < k; i++) {
    int command, x, y;
    cin >> command >> x >> y;
    if (!impossible) {
      cout << "0\n";
      continue;
    }
    if (command == 1) {
      _union(x, y);
      _union(x + n, y + n);
    } else {
      _union(x, y + n);
      _union(y, x + n);
    }
    if (_find(x) == _find(x + n) || _find(y) == _find(y + n)) {
      cout << "0\n";
      impossible = false;
    } else cout << power[cnt / 2] << "\n";
  }
}