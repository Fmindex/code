#include <bits/stdc++.h>
using namespace std;
struct edge
{
  long long node;
  long long cost;
  long long cop = 0;
  bool operator<(const edge &o) const
  {
    return cost > o.cost;
  }
};

priority_queue<edge> pq;
vector<edge> g[200005];
bool ch[200005][2];
int main()
{
  long long n, m, k, t, u, v, w, ans;
  bool can = false;
  edge ne, ce;
  scanf("%lld %lld %lld %lld", &n, &m, &k, &t);
  for (long long i = 0; i < m; i++)
  {
    scanf("%lld %lld %lld", &u, &v, &w);
    ne.cop = 0;
    ne.cost = w;
    ne.node = v;
    g[u].push_back(ne);
    ne.node = u;
    g[v].push_back(ne);
  }
  ne.cost = 0;
  ne.node = 1;
  ne.cop = 0;
  pq.push(ne);
  while (!pq.empty() && !can)
  {
    ce = pq.top();
    if (!ch[ce.node][ce.cop])
    {
      for (const auto &i : g[ce.node])
      {
        ne.cop = ce.cop;
        ne.node = i.node;
        ne.cost = ce.cost + i.cost;
        if (ne.cost <= t && !ch[ne.node][ne.cop])
        {
          pq.push(ne);
        }
        if (ce.cop == 0 && k < i.cost)
        {
          ne.cost = ce.cost + k;
          ne.cop = 1;
          if (ne.cost <= t && !ch[ne.node][ne.cop])
          {
            pq.push(ne);
          }
        }
      }
      ch[ce.node][ce.cop] = true;
      if (ce.node == n)
      {
        can = true;
        ans = ce.cost;
        break;
      }
    }
    pq.pop();
  }
  if (can)
  {
    printf("Happy Winnie the Pooh :3\n");
    printf("%lld\n", ans);
  }
  else
  {
    printf("No Honey TT\n");
  }
}