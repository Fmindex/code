#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
string mapper[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int needMore(string x, string y) {
  int answer = 0;
  for (int i = 0; i < 7; i++) {
    if (x[i] == '1' && y[i] == '0') return -1;
    if (x[i] == '0' && y[i] == '1') answer++;
  }
  return answer;
}

int n, k;
int mem[2020][2020];
int arr[11][2020] = {0};
int ans[2020];
bool isAnswer = false;
void dp(int i, int j) {
  if (isAnswer) return;
  if (j < 0) return;
  if (i == n && j != 0) return;
  if (mem[i][j] != 0) return;
  mem[i][j] = 1;
  if (i == n && j == 0) {
    for (int h = 0; h < n; h++) cout << ans[h];
    isAnswer = true;
    return;
  }

  int answer = -1;
  for (int x = 9; x >= 0; x--) {
    if (arr[x][i] == -1) continue;
    ans[i] = x;
    dp(i + 1, j - arr[x][i]);
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<string> S;

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    for (int j = 0; j <= 9; j++) {
      int more = needMore(temp, mapper[j]);
      arr[j][i] = more;
    }
  }
  dp(0, k);
  if (!isAnswer) cout << "-1";
}