#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
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
    long long l, r;
    cin >> l >> r;
    long long diff = abs(l - r);
    long long left = 0, right = 2e9, x, tar = 0;
    while (left <= right) {
      long long mid = left + (right - left) / 2;
      x = ((mid + 1) * mid / 2);
      if (x <= diff) {
        left = mid + 1;
        tar = max(tar, mid);
      }
      else right = mid - 1;
    }
    x = (tar + 1) * tar / 2;
    long long start = tar + 1;
    long long answer = tar;
    if (l < r) r -= x;
    else l -= x;
    if (r > l) {
      left = 0;
      right = 2e9;
      tar = 0;
      if (start <= r) {
        while (left <= right) {
          long long mid = left + (right - left) / 2;
          long long x = (start + (mid - 1)) * mid;
          if (x <= r)  {
            left = mid + 1;
            tar = max(tar, mid);
          }
          else right = mid - 1;
        }
        answer += tar;
        r -= ((start + (tar - 1)) * tar);
      }
      if (start + 1 <= l) {
        tar = 0;
        left = 0;
        right = 2e9;
        while (left <= right) {
          long long mid = left + (right - left) / 2;
          long long x = (start + 1 + (mid - 1)) * mid;
          if (x <= l)  {
            left = mid + 1;
            tar = max(tar, mid);
          }
          else right = mid - 1;
        }
        l -= ((start + 1 + (tar - 1)) * tar);
        answer += tar;
      }
    } else {
      tar = 0;
      left = 0;
      right = 2e9;
      if (start <= l) {
        while (left <= right) {
          long long mid = left + (right - left) / 2;
          long long x = (start + (mid - 1)) * mid;
          if (x <= l)  {
            left = mid + 1;
            tar = max(tar, mid);
          }
          else right = mid - 1;
        }
        answer += tar;
        l -= ((start + (tar - 1)) * tar);
      }
      if (start + 1 <= r) {
        left = 0;
        right = 2e9;
        tar = 0;
        while (left <= right) {
          long long mid = left + (right - left) / 2;
          long long x = (start + 1 + (mid - 1)) * mid;
          if (x <= r)  {
            left = mid + 1;
            tar = max(tar, mid);
          }
          else right = mid - 1;
        }
        r -= ((start + 1 + (tar - 1)) * tar);
        answer += tar;
      }
    }
    cout << "Case #" << lap << ": ";
    cout << answer << " " << l << " " << r << "\n";
  }
}