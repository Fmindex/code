#include <iostream>

using namespace std;

int main()
{
  int k = 7;
  int a[100];
  a[0] = a[1] = 1;
  int c = 2;
  for (; a[c - 1] <= k; c++)
  {
    a[c] = a[c - 1] + a[c - 2];
  }
  c -= 2;
  int ans = 0;
  cout << c << "\n";
  while (k > 0)
  {
    cout << a[c] << " " << k << "\n";
    if (a[c] <= k)
    {
      k -= a[c--];
      ans++;
    }
    else
      c--;
  }
  string x = "123";
  x[2] = 'f';
  cout << x;
  return ans;
}
