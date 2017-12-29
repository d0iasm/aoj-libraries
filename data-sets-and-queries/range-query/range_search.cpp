#include <bits/stdc++.h>
using namespace std;


struct Node {
  int l, r;
  // node *l, *r;
};

struct Point {
  int id, x, y;
};

class KdTree {
private:
  Node* root;
  int* tree;
public:
  int size;
  KdTree (int n) {
    
  }
  void insert(int l, int r, int depth);
  vector<int> query();
};

void KdTree::insert(int l, int r, int depth) {

}

int n, q;
int size;
Point* p;
Node* tree;

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
