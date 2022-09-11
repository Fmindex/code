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
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    sort(s.begin(), s.end());
    char first = s[0];
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] == first)
        cnt++;
    }
    if (cnt < k)
    {
      cout << s[k - 1] << "\n";
      continue;
    }
    cnt = 0;
    first = s[k];
    for (int i = k; i < s.size(); i++)
      if (s[i] != first)
        cnt++;
    if (cnt == 0)
    {
      int sz = (int)s.size() - k;
      cout << s[0];
      int ceiled = sz / k;
      if (ceiled * k != sz)
        ceiled++;
      for (int i = 0; i < ceiled; i++)
        cout << s[k];
      cout << "\n";
      continue;
    }

    cout << s[0];
    for (int i = k; i < s.size(); i++)
      cout << s[i];
    cout << "\n";
  }
}