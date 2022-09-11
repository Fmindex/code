#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;
int arr[200010];
map<long long, long long> isFound;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  long long answer = 0LL, sum = 0LL;
  long long lastFound = 0;
  cin >> n;
  isFound[0LL] = 1;
  for (long long i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    sum += x;
    lastFound = max(lastFound, isFound[sum]);
    answer += i - lastFound;
    isFound[sum] = i + 1;
  }
  cout << answer;
}