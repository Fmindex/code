#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
int N, Q;
int arr[200001];
pii cycle[200001];
int main()
{
  ios_base::sync_with_stdio(0);
  scanf("%d%d", &N, &Q);
  for (int i = 1; i <= N; i++)
    scanf("%d", &arr[i]);
  int pp = 1;
  for (int i = 1; i <= N; i++)
  {
    if (cycle[i].x != 0)
      continue;
    int V = i;
    for (int k = 1;; k++)
    {
      if (cycle[V].x != 0)
        break;
      cycle[V] = make_pair(pp, k);
      V = arr[V];
    }
    pp++;
  }
  while (Q--)
  {
    int U, V, a, b;
    scanf("%d%d%d%d", &U, &V, &a, &b);
    if (cycle[a].x != cycle[b].x)
    {
      if ((cycle[U].x == cycle[a].x || cycle[U].x == cycle[b].x) &&
          (cycle[V].x == cycle[a].x || cycle[V].x == cycle[b].x))
      {
        printf("DEAD\n");
      }
      else if (cycle[U].x == cycle[V].x)
        printf("DEAD\n");
      else
        printf("SURVIVE\n");
    }
    else
    {
      if (cycle[U].x != cycle[V].x)
      {
        printf("SURVIVE\n");
      }
      else if (cycle[U].x == cycle[V].x && cycle[U].x != cycle[a].x)
        printf("DEAD\n");
      else
      {
        a = cycle[a].y;
        b = cycle[b].y;
        if (a > b)
          swap(a, b);
        bool ok1 = (cycle[U].y > a && cycle[U].y <= b ? true : false);
        bool ok2 = (cycle[V].y > a && cycle[V].y <= b ? true : false);
        if (ok1 == ok2)
          printf("DEAD\n");
        else
          printf("SURVIVE\n");
      }
    }
  }
  return 0;
}
/*
5 2
1 4 2 3 5
1 2 3 4
2 3 4 5
*/