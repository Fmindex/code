#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int x = 0, y = 0;
  for (int i = 0; i < 10000; i++)
  {
    string X;
    int Y;
    cin >> X >> Y;
    if (X == "NORTH")
    {
      y += Y;
    }
    if (X == "SOUTH")
    {
      y -= Y;
    }
    if (X == "EAST")
    {
      x += Y;
    }
    if (X == "WEST")
    {
      x -= Y;
    }
  }
  cout << x << " " << y;
  return 0;
}