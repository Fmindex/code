#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
#include <math.h>

using namespace std;

unordered_map<int, int> m;
bool isPerfectSquare(int x) 
{ 
    double sr = sqrt(x); 
    return ((sr - floor(sr)) == 0); 
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int lap = 1; lap <= t; lap++)
  {
    int n, x;
    cin >> n;
    int sum = 0;
    int maxEle = 0;
    long long answer = 0;
    m.clear();
    m[0] = 1;
    int minSum = 0;
      for (int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
        minSum = min(minSum, sum);
        // if (m.size() < sqrt(maxEle - minSum)) {
        //   for (auto mm : m) {
        //     if (isPerfectSquare(sum - mm.first)) answer += mm.second;
        //   }
        // } else {
          for (int j = 0; j * j <= sum - minSum; j++) {
            if (m.find(sum - j * j) != m.end())
              answer += (long long)m[sum - j * j];
          }
        // }
        m[sum]++;
      } 
    
    cout << "Case #" << lap << ": ";
    cout << answer << "\n";
  }
}
