#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int deg[100005], n, odd, even, mx;
vector<int> e[100005];
 
void dfs(int now, int pre, int dep) {
    if (deg[now] == 1) {
      if(dep % 2 == 1) odd++; 
      else even++;
    }

    int cnt = 0;
    for(auto to : e[now]) {
        if(to == pre) continue;
        dfs(to, now, dep + 1);
        if(deg[to] == 1) cnt++;
    }
    mx -= max(0, cnt - 1);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for(int i = 1; i < n; i++) {
      int x, y;
      cin >> x >> y;
      e[x].push_back(y);
      e[y].push_back(x);
      deg[x]++;
      deg[y]++;
  }
  for(int i = 1; i <= n; i++)
    if (deg[i] != 1) {
        dfs(i, i, 0);
        break;
    }
  cout << ((even && odd) ? 3 : 1) << " " << mx + n - 1;
}