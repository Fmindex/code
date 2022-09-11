#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;
int answer[105][105];
int visit[105], ex[105];

queue<pair<int, pair<int, int> > > q; 
void reVisit() {
  for (int i = 0; i < 105; i++) visit[i] = 0, ex[i] = 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int lap = 1; lap <= t; lap++) {
    int n, m;
    cin >> n >> m;
    reVisit();
    pair<int, int> query[1005];
    int require[200];
    for (int i = 0; i < 105; i++)
      for (int j = 0; j < 105; j++)
        answer[i][j] = 0;
    vector<int> v[200];
    for (int i = 2; i <= n; i++) {
      int x;
      cin >> x;
      require[i] = -x;
    }
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      v[x].push_back(y);
      v[y].push_back(x);
      query[i] = {x, y};
    }
      int cnt = 0;
      // cout << require[i].first << " " << require[i].second << " " << cnt << "\n";
      // dfs(v, 1, 0, require[i].second, cnt, 1);
      while(!q.empty()) q.pop();
      q.push({ 1, { 0, 0 } });
      int maxPath = 0;
      while (!q.empty()) {
        int cur = q.front().first;
        int t = q.front().second.first;
        int pre = q.front().second.second;
        maxPath = max(maxPath, t);
        q.pop();
        if(visit[cur] && !ex[cur]) continue;
        if (ex[cur]) {
          ex[cur] = 0;
        } else {
          cnt++;
          visit[cur] = 1;
        }
        bool isPush = false;
        for (int to : v[cur]) {
          if (visit[to]) continue;
          if (answer[cur][to] > 0) continue;
          if (require[to] > cnt && !isPush) {
            isPush = true;
            ex[cur] = 1;
            q.push({cur, { t, pre }});
            
          } else {
            answer[cur][to] = maxPath + 1 - t;
            answer[to][cur] = maxPath + 1 - t;
            q.push({to, { maxPath + 1, cur }});
          }
        }
      }

    
    cout << "Case #" << lap << ": ";
    for (int i = 0; i < m; i++) {
      int ans = answer[query[i].first][query[i].second];
      if (ans == 0) ans = 1;
      cout << ans << " ";
    }
    cout << "\n";
  }
}