#include <bits/stdc++.h>
using namespace std;

const int ST_SIZE = (1 << 18) - 1;
const int MAX_N = 500001;
const int MAX_Q = 20001;
const int MAX = 1000000001;
int n, q;
int size;
int a[MAX_N];
int i[MAX], j[MAX], k[MAX];

int nums[MAX_N];
vector<int> data[ST_SIZE];


void init(int k, int l, int r) {
  if (r - l == 1) {
    data[k].push_back(a[l]);
  } else {
    int lch = k * 2 + 1;
    int rch = k * 2 + 2;
    init(lch, l, (l + r) / 2);
    init(rch, (l + r) / 2, r);
    data[k].resize(r - l);

    merge(data[lch].begin(), data[lch].end(), data[rch].begin(), data[rch].end(),
          data[k].begin());
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int x, y;
  p = new Point[n];
  for (int i=0; i<n; i++) {
    cin >> x >> y;
    p[i] = {i, x, y};
  }

  size = 1;
  while(size < n) size *= 2;
  tree = new Node[2*size -1];
  
  int sx, tx, sy, ty;  
  for (int i=0; i<q; i++) {
    cin >> sx >> tx >> sy >> ty;
  }
  
  
  return 0;
}
