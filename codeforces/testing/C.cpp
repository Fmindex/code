#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    string s;
    int answer = 0;
    cin >> s;
    unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, int>>>> M;
    int x = 0, y = 0;
    for (char c : s)
    {
      int oldx = x, oldy = y;
      if (c == 'S')
        y--;
      if (c == 'N')
        y++;
      if (c == 'W')
        x--;
      if (c == 'E')
        x++;
      if (M[oldx][oldy][x][y])
        answer += 1;
      else
        answer += 5;
      M[oldx][oldy][x][y] = 1;
      M[x][y][oldx][oldy] = 1;
    }
    cout << answer << "\n";
  }
}