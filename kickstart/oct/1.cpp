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
    string x;
    long long answer = 0LL, kicks = 0LL;
    cin >> x;
    for (int i = 0; i < x.length(); i++)
    {
      string temp1 = x.substr(i, 4);
      string temp2 = x.substr(i, 5);
      if (temp1 == "KICK")
      {
        kicks++;
      }
      else if (temp2 == "START")
      {
        answer += kicks;
      }
    }
    cout << "Case #" << lap << ": ";
    cout << answer << "\n";
  }
}