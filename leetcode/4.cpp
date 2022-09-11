#include <iostream>

using namespace std;

int main()
{
  int k = 703;
  string s = "600342244431311113256628376226052681059918526204";
  int dp[100010] = {0};

  dp[0] = 1;
  //int myint1 = stoi(str1);
  for (int i = 1; i <= s.length(); i++)
  {
    string x = "";
    for (int j = i; j >= max(i - 8, 1); j--)
    {
      x = s[j - 1] + x;
      if (x[0] == '0')
        continue;
      int val = stoi(x);
      if (val >= 1 && val <= k)
      {
        cout << val << "\n";
        dp[i] += dp[i - x.length()];
      }
    }
    // cout << dp[i] << " ";
  }
  // return dp[s.length()];
  cout << dp[s.length()];
}
