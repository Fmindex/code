#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
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
    cin >> n >> k;
    vector<int> a;
    unordered_map<int, int> M;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      a.push_back(x);
      M[x] = 1;
    }
    vector<int> unique, answer;
    for (auto p : M)
    {
      unique.push_back(p.first);
    }
    if (unique.size() > k)
    {
      cout << "-1\n";
      continue;
    }
    cout << k * (int)a.size() << "\n";
    for (int x : a)
    {
      for (int y : unique)
      {
        cout << y << " ";
      }
      for (int i = 0; i < k - (int)unique.size(); i++)
      {
        cout << "1 ";
      }
    }
    cout << "\n";
  }
}