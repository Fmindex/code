#include <iostream>

using namespace std;

char x[11];
char ans[11];
int order = 1;
void dfs(int n, int k, int index, char pre)
{
  if (index == n)
  {
    if (order == k)
    {
      for (int i = 0; i < n; i++)
      {
        ans[i] = x[i];
      }
    }
    order++;
    return;
  }

  if (pre != 'a')
  {
    x[index] = 'a';
    dfs(n, k, index + 1, 'a');
  }
  if (pre != 'b')
  {
    x[index] = 'b';
    dfs(n, k, index + 1, 'b');
  }
  if (pre != 'c')
  {
    x[index] = 'c';
    dfs(n, k, index + 1, 'c');
  }
}

int main()
{
  int n = 1, k = 4;
  dfs(n, k, 0, 'x');
  string answer = "";
  cout << order;
  if (order <= k)
    cout << "";
  else
  {
    for (int i = 0; i < n; i++)
    {
      answer += ans[i];
    }
    cout << answer;
  }
}