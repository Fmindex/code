#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

pair<int, int> findCircle(int x1, int y1, int x2, int y2, int x3, int y3)
{
  int x12 = x1 - x2;
  int x13 = x1 - x3;

  int y12 = y1 - y2;
  int y13 = y1 - y3;

  int y31 = y3 - y1;
  int y21 = y2 - y1;

  int x31 = x3 - x1;
  int x21 = x2 - x1;

  // x1^2 - x3^2
  int sx13 = pow(x1, 2) - pow(x3, 2);

  // y1^2 - y3^2
  int sy13 = pow(y1, 2) - pow(y3, 2);

  int sx21 = pow(x2, 2) - pow(x1, 2);
  int sy21 = pow(y2, 2) - pow(y1, 2);

  int f = ((sx13) * (x12) + (sy13) * (x12) + (sx21) * (x13) + (sy21) * (x13)) / (2 * ((y31) * (x12) - (y21) * (x13)));
  int g = ((sx13) * (y12) + (sy13) * (y12) + (sx21) * (y13) + (sy21) * (y13)) / (2 * ((x31) * (y12) - (x21) * (y13)));

  int c = -pow(x1, 2) - pow(y1, 2) - 2 * g * x1 - 2 * f * y1;

  // eqn of circle be x^2 + y^2 + 2*g*x + 2*f*y + c = 0
  // where centre is (h = -g, k = -f) and radius r
  // as r^2 = h^2 + k^2 - c
  int h = -g;
  int k = -f;

  return make_pair(h, k);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, a, b;
  cin >> t >> a >> b;
  for (int lap = 1; lap <= t; lap++)
  {
    bool end = false, exit = false, hit = false;
    int initX[3] = {-500000000, 0, 500000000};
    int initY[3] = {-500000000, 0, 500000000};
    int ix, iy;
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        int x = initX[i];
        int y = initY[j];
        cout << x << " " << y << endl;
        string res;
        cin >> res;
        if (res == "WRONG")
        {
          exit = true;
          break;
        }
        if (res == "CENTER")
        {
          end = true;
          break;
        }
        else if (res == "HIT")
        {
          hit = true;
          ix = x;
          iy = y;
        }
        if (hit)
          break;
      }
      if (end || exit || hit)
        break;
    }
    if (end)
      continue;
    if (exit)
      break;

    // find left x
    int left = -1e9, right = ix;
    int mostLeft = ix;
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      cout << mid << " " << iy << endl;
      string res;
      cin >> res;
      if (res == "WRONG")
      {
        exit = true;
        break;
      }
      if (res == "CENTER")
      {
        end = true;
        break;
      }
      else if (res == "HIT")
      {
        mostLeft = min(mostLeft, mid);
        right = mid - 1;
      }
      else
      {
        left = mid + 1;
      }
    }
    if (end)
      continue;
    if (exit)
      break;

    // find right x
    left = ix, right = 1e9;
    int mostRight = ix;
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      cout << mid << " " << iy << endl;
      string res;
      cin >> res;
      if (res == "WRONG")
      {
        exit = true;
        break;
      }
      if (res == "CENTER")
      {
        end = true;
        break;
      }
      else if (res == "HIT")
      {
        mostRight = max(mostRight, mid);
        left = mid + 1;
      }
      else
      {
        right = mid - 1;
      }
    }
    if (end)
      continue;
    if (exit)
      break;

    // find top y
    left = -1e9, right = iy;
    int mostTop = iy;
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      cout << ix << " " << mid << endl;
      string res;
      cin >> res;
      if (res == "WRONG")
      {
        exit = true;
        break;
      }
      if (res == "CENTER")
      {
        end = true;
        break;
      }
      else if (res == "HIT")
      {
        mostTop = min(mostTop, mid);
        right = mid - 1;
      }
      else
      {
        left = mid + 1;
      }
    }
    if (end)
      continue;
    if (exit)
      break;

    // find bottom y
    left = iy, right = 1e9;
    int mostBottom = iy;
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      cout << ix << " " << mid << endl;
      string res;
      cin >> res;
      if (res == "WRONG")
      {
        exit = true;
        break;
      }
      if (res == "CENTER")
      {
        end = true;
        break;
      }
      else if (res == "HIT")
      {
        mostBottom = max(mostBottom, mid);
        left = mid + 1;
      }
      else
      {
        right = mid - 1;
      }
    }
    if (end)
      continue;
    if (exit)
      break;

    cout << (mostLeft + mostRight) / 2 << " " << (mostTop + mostBottom) / 2 << endl;
    string res;
    cin >> res;
    if (res != "CENTER")
    {
      break;
    }
  }
}