#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int lap = 1; lap <= t; lap++)
  {
    int a, b, c, ans = 0;
    cin >> a >> b >> c;
    if (a) ans++,a--;
	  if (b) ans++,b--;
	  if (c) ans++,c--;
	  if (b < c) swap(b, c);
    if (a < b) swap(a,b);
	  if (a && c) a--, c--, ans++;
	  if (a && b) a--, b--, ans++;
	  if (b && c) b--, c--, ans++;
	  if (a && b && c) ans++;
    cout << ans << "\n";
  }
}
