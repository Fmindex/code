#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
vector<int> edgeOf[200000];
bool isVisited[200000];
bool isTour[200000];
int memChild[200000];
int memParent[200000];
int ans = 0;
int countAnswer(int node) {
  if (isVisited[node]) return 0;
  isVisited[node] = true;
  int child = 0;
  for (auto to : edgeOf[node]) {
    child += countAnswer(to);
  }
  if (isTour[node]) {
    ans += child;
    return child;
  } else {
    return child + 1;
  }

}

void countParent(int node, int parent) {
  if (isVisited[node]) return;
  isVisited[node] = true;
  memParent[node] = parent;
  for (auto to : edgeOf[node]) {
    countParent(to, parent + 1);
  }
}

int countChild(int node) {
  if (isVisited[node]) return 0;
  isVisited[node] = true;
  int child = 0;
  for (auto to : edgeOf[node]) {
    child += countChild(to);
  }
  return memChild[node] = child + 1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    edgeOf[x].push_back(y);
    edgeOf[y].push_back(x);
  }
  countChild(1);
  for (int i = 0; i <= 100010; i++) isVisited[i] = false;
  countParent(1, 0);

  // isTour[1] = true;
  vector<pair<int, int> > V;
  for (int i = 1; i <= n; i++) {
    V.push_back({memParent[i] - memChild[i], i});
  }
  sort(V.begin(), V.end());
  for (int i = 0; i < n - k; i++) {
    isTour[V[i].second] = true;
  }
  for (int i = 0; i <= 100010; i++) isVisited[i] = false;
  countAnswer(1);
  cout << ans;
}