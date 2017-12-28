#include <bits/stdc++.h>
using namespace std;


int n, q;

class RangeMinimumQuery {
private:
  int* tree;
public:
  int size;
  RangeMinimumQuery(int n) {
    size = 1; while(size < n) size *= 2;
    tree = new int[2*size - 1];
    for (int i=0; i < 2*size - 1; i++) tree[i] = INT_MAX;
  }
  void update(int i, int x);
  int find(int s, int t, int i, int l, int r);
};

void RangeMinimumQuery::update(int i, int x) {
  i += size - 1;

  tree[i] = x;
  while (i > 0) {
    i = (i - 1) / 2;
    tree[i] = min(tree[2*i+1], tree[2*i+2]);
  }
}

int RangeMinimumQuery::find(int s, int t, int i, int l, int r) {
  if (r < s || t < l) return INT_MAX;
  if (s <= l && r <= t) return tree[i];

  int vl = RangeMinimumQuery::find(s, t, 2*i+1, l, (l+r)/2);
  int vr = RangeMinimumQuery::find(s, t, 2*i+2, (l+r)/2+1, r);
  return min(vl, vr);
}

int main () {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> n >> q;

  RangeMinimumQuery* RmQ = new RangeMinimumQuery(n);
  
  int com, x, y;
  for (int i=0; i < q; i++) {    cin >> com >> x >> y;
    if (com == 0) {
      RmQ -> update(x ,y);
    } else {
      cout << RmQ -> find(x, y, 0, 0, n-1) << '\n';
    }
  }
  return 0;
} 

