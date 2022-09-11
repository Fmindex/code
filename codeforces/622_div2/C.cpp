#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;
int arr[1000005];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  bool isValid = true;
  int lowest = 2e9;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    // if (i == 1) lowest = arr[i];
    // lowest = min(lowest, arr[i]);
  }
  int left = 0, right = n;
  for (int i = 2; i <= n; i++) {
    left = i;
    if (arr[i] < arr[i - 1]) break;
  }
  for (int i = n - 1; i >= 1; i--) {
    right = i;
    if (arr[i] < arr[i + 1]) break;
  }

  int leftMin = left, rightMin = left;
  for (int i = left; i <= right; i++) {
    if (arr[i] < arr[leftMin]) leftMin = i;
    if (arr[i] <= arr[rightMin]) rightMin = i;
  }

  int ansLeft = 0, ansRight = 0;
  cout << leftMin << " " << rightMin << "\n";
  for (int i = leftMin; i <= n; i++) {
    if (arr[i] <= arr[leftMin]) continue;
    ansLeft += arr[i] - arr[leftMin];
  }
  for (int i = rightMin; i >= 1; i--) {
    if (arr[i] <= arr[rightMin]) continue;
    ansRight += arr[i] - arr[rightMin];
  }
  cout << ansLeft << " " << ansRight << "\n";
  if (ansLeft <= ansRight) {
    for (int i = leftMin; i <= n; i++) {
      if (arr[i] <= arr[leftMin]) continue;
      arr[i] = arr[leftMin];
    }
  } else {
    for (int i = rightMin; i >= 1; i--) {
      if (arr[i] <= arr[rightMin]) continue;
      arr[i] = arr[rightMin];
    }
  }
  for (int i = 1; i <= n; i++) cout << arr[i] << " ";
}