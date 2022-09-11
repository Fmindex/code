#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;
int a[10005];
vector<pair<int, int>> edge[100005];
int ban = -1;
int visit[100005];
int bfs(int start) {
  queue<pair<int, long long>> q;
  long long answer = 0LL;
  int maxNode = 0;
  q.push({ start, 0LL });
  while(!q.empty()) {
    long long dis = q.front().second;
    int cur = q.front().first;
    q.pop();
    if (cur == ban) continue;
    visit[cur] = true;
    // answer = max(answer, dis);
    if (answer < dis) {
      answer = dis;
      maxNode = cur;
    }
    for(auto to : edge[cur]){
      if (to.first == ban) continue;
      if (visit[to.first]) continue;
      visit[to.first] = true;
      q.push({ to.first, (long long)(to.second) + dis });
    }
  }
  return maxNode;
}
pair<long long, long long> bfs2(int start) {
  queue<pair<int, long long>> q;
  long long first = 0LL, second = 0LL;
  q.push({ start, 0LL });
  while(!q.empty()) {
    long long dis = q.front().second;
    int cur = q.front().first;
    q.pop();
    if (cur == ban) continue;
    visit[cur] = true;
    // answer = max(answer, dis);
    if (first < dis) {
      second = first;
      first = dis;
    } else if (second < dis) {
      second = dis;
    }
    // cout << cur << " " << dis << " " << first << " " << second  << "\n";
    for(auto to : edge[cur]){
      if (to.first == ban) continue;
      if (visit[to.first]) continue;
      visit[to.first] = true;
      q.push({ to.first, (long long)(to.second) + dis });
    }
  }
  return { first, second };
}

void reset() {
  for (int i = 0; i <= 1e5; i++) visit[i] = 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n, a, b, c;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b >> c;
    edge[a].push_back({ b, c });
    edge[b].push_back({ a, c });
  }
  int t = bfs(1);
  reset();
  long long answer = bfs2(t).second;
  reset();
  ban = t;
  int t2 = bfs(1);
  reset();
  answer = max(answer, bfs2(t2).first);
  // cout << t2 << " " << answer << "\n";
  cout << answer;


  
}