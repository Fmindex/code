#include <bits/stdc++.h>

#define long long long

using namespace std;

const int N = 1e5 + 5;
const int M = 1e9 + 7;

struct Query
{
  int l, r, k, i;
  Query(int l, int r, int k, int i) : l(l), r(r), k(k), i(i) {}
};

int n, m, A[N];
long ans[N];

long dp1[N][105], dp2[N][105];

void compute_l(int l, int r)
{
  for (int i = l; i <= r + 1; i++)
    for (int j = 0; j <= 100; j++)
      dp1[i][j] = 0;
  dp1[r + 1][0] = 1;
  for (int i = r; i >= l; i--)
    for (int j = 0; j <= 100; j++)
    {
      dp1[i][j] += dp1[i + 1][j];
      if (j >= A[i])
        dp1[i][j] += dp1[i + 1][j - A[i]];
      dp1[i][j] %= M;
    }
}

void compute_r(int l, int r)
{
  for (int i = l - 1; i <= r; i++)
    for (int j = 0; j <= 100; j++)
      dp2[i][j] = 0;
  dp2[l - 1][0] = 1;
  for (int i = l; i <= r; i++)
    for (int j = 0; j <= 100; j++)
    {
      dp2[i][j] += dp2[i - 1][j];
      if (j >= A[i])
        dp2[i][j] += dp2[i - 1][j - A[i]];
      dp2[i][j] %= M;
    }
}

void solve(int l, int r, vector<Query> &vec)
{
  if (vec.empty())
    return;
  if (l == r)
  {
    for (Query q : vec)
      ans[q.i] = (A[l] == q.k);
    return;
  }
  int mid = (l + r) >> 1;
  compute_l(l, mid), compute_r(mid + 1, r);

  vector<Query> L, R;
  for (Query q : vec)
  {
    if (q.r <= mid)
      L.emplace_back(q);
    else if (q.l > mid)
      R.emplace_back(q);
    else
      for (int j = 0; j <= q.k; j++)
      {
        ans[q.i] += dp1[q.l][j] * dp2[q.r][q.k - j] % M;
        ans[q.i] %= M;
      }
  }
  vec.clear();
  solve(l, mid, L), solve(mid + 1, r, R);
}

int main()
{
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%d", A + i);
  vector<Query> vec;
  for (int i = 1, a, b, c; i <= m; i++)
  {
    scanf("%d %d %d", &a, &b, &c);
    vec.emplace_back(a, b, c, i);
  }
  solve(1, n, vec);
  for (int i = 1; i <= m; i++)
    printf("%lld\n", ans[i]);

  return 0;
}