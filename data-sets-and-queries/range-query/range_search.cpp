#include <bits/stdc++.h>
using namespace std;

const int ST_SIZE = (1 << 18) - 1;
const int MAX_N = 500001;
const int MAX_Q = 20001;
const int MAX = 1000000001;


int n, q;

struct pt {
  int x, y, id;
} pts[MAX_N];

struct node {
  int mid, l, r;
  node *ln, *rn;
} root;

void debug() {
  printf("Start pts: \n");
  for (int i=0; i<=n; i++) {
    printf("Point: (%d, %d; %d), ", pts[i].x, pts[i].y, pts[i].id);
  }
  printf("End pts \n");
}

void debug(node *n) {
  if (!n) {printf("Node NULL\n"); return;}
  printf("Node, range: %d ~ %d mid: (%d, %d; %d)", n->l, n->r, pts[n->mid].x, pts[n->mid].y, pts[n->mid].id);
  printf("pts:");
  for (int i=n->l; i<n->r; i++) {
    printf("(%d, %d; %d), ", pts[i].x, pts[i].y, pts[i].id);
  }
  printf("\nL\n");
  debug(n->ln);
  printf("R\n");
  debug(n->rn);
}

void build (int st, int en, int dep, node *n) {
  if (en - st == 0) {
    return;
  } else if (en - st == 1) {
    n->l = st;
    n->r = en;
    n->mid = st;
    return;
  }

  sort(pts + st, pts + en, [dep](const pt& a, const pt& b) {
      return dep%2 == 0 ? a.x < b.x : a.y < b.y;
    });

  int mid = (st + en) / 2;
  n->l = st;
  n->r = en;
  n->ln = new node;
  n->rn = new node;
  n->mid = mid;

  build(st, mid, (dep + 1), n->ln);
  build(mid, en, (dep + 1), n->rn);
}

set<int> ans;
void query(int stx, int enx, int sty, int eny, int dep, node *n) {
  if (!n) return;

  if (pts[n->l].x <= stx && enx <= pts[n->r].x && pts[n->l].y <= sty && eny <= pts[n->r].y) {
    for (int i = n->l; i <= n->r; i++) {
      ans.insert(i);
    }
    return;
  }

  if (dep%2 == 0) {
    query(stx, enx, sty, eny, dep+1, n->ln);
    query(stx, enx, sty, eny, dep+1, n->rn);
  } else {
    query(stx, enx, sty, eny, dep+1, n->ln);
    query(stx, enx, sty, eny, dep+1, n->rn);
  }
}

int main() {
  scanf("%d", &n);
  for (int i=1; i<=n; i++) {
    scanf("%d %d", &pts[i].x, &pts[i].y);
    pts[i].id = i;
  }

  debug();
  build(1, n, 0, &root);
  debug(&root);

  scanf("%d", &q);
  for (int i=0; i<q; i++) {
    int stx, enx, sty, eny;
    scanf("%d %d %d %d", &stx, &enx, &sty, &eny);
    ans.clear();
    query(stx, enx, sty, eny, 0, &root);
    for (int i: ans) printf("%d\n", i-1);
    printf("\n");
  }
  return 0;
}
