#include <bits/stdc++.h>
 
const int MAX_N = 500005;
const int MAX_R = 1000000000;
int N;
 
struct pt {
    int x, y, id;
 
    bool operator<(const pt& b) const { return id < b.id; }
} pts[MAX_N];
 
struct node {
    std::vector<pt> pts;
    pt mid;
    node* l, *r;
} root;
 
std::set<pt> ans;
 
void build(int st, int en, int dep, node* n) {
    if (en - st == 1) {
        n->pts.push_back(pts[st]);
        n->mid = pts[st];
        return;
    } else if (en - st == 0) {
        return;
    }
    int mid = (st + en) / 2;
    std::sort(pts + st, pts + en, [dep](const pt& a, const pt& b) {
        bool typ[2] = {a.x < b.x, a.y < b.y};
        bool qal[2] = {a.x != b.x, a.y != b.y};
        if (qal[dep]) return typ[dep];
        return typ[!dep];
    });
 
    n->pts = std::vector<pt>(pts + st, pts + en);
    n->l = new node;
    n->r = new node;
    n->mid = pts[mid];
 
    build(st, mid, (dep + 1) % 2, n->l);
    build(mid, en, (dep + 1) % 2, n->r);
}
 
bool pis(pt tl, pt br, pt p) {
    return p.x >= tl.x && p.x <= br.x && p.y <= tl.y && p.y >= br.y;
}
 
bool aFullyContainsB(pt tla, pt bra, pt tlb, pt brb) {
    return pis(tla, bra, tlb) && pis(tla, bra, brb);
}
 
bool intersect(pt tla, pt bra, pt tlb, pt brb) {
    return tla.x <= brb.x && bra.x >= tlb.x && tla.y >= brb.y && bra.y <= tlb.y;
}
 
void query(int stx, int enx, int sty, int eny, int nstx, int nenx, int nsty, int neny, node* n, int dep) {
    if (!n) return;
 
    // printf("%d %d %d %d %d %d %d %d\n", stx, enx, sty, eny, nstx, nenx, nsty, neny);
    bool inter = intersect({stx, eny, 0}, {enx, sty, 0}, {nstx, neny, 0}, {nenx, nsty, 0});
    if (!inter) return;
 
    bool fully = aFullyContainsB({stx, eny, 0}, {enx, sty, 0}, {nstx, neny, 0}, {nenx, nsty, 0});
    if (fully) {
        for (pt p : n->pts) {
            ans.insert(p);
        }
        return;
    }
 
    pt m = n->mid;
    if (pis({stx, eny, 0}, {enx, sty, 0}, m)) {
        ans.insert(m);
    }
    if (dep) {
        query(stx, enx, sty, eny, nstx, nenx, nsty, m.y, n->l, (dep + 1) % 2);
        query(stx, enx, sty, eny, nstx, nenx, m.y, neny, n->r, (dep + 1) % 2);
    } else {
        query(stx, enx, sty, eny, nstx, m.x, nsty, neny, n->l, (dep + 1) % 2);
        query(stx, enx, sty, eny, m.x, nenx, nsty, neny, n->r, (dep + 1) % 2);
 
    }
}
 
void debug(node* n) {
    if (!n) {printf("Node NULL\n"); return;}
    printf("Node, mid: (%d, %d; %d) pts: ", n->mid.x, n->mid.y, n->mid.id);
    for (pt p : n->pts) {
        printf("(%d, %d; %d), ", p.x, p.y, p.id);
    }
    printf("\n L\n");
    debug(n->l);
    printf("R\n");
    debug(n->r);
}
 
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &pts[i].x, &pts[i].y);
        pts[i].id = i;
    }
    build(0, N, 0, &root);
    // debug(&root);
    int Q;
    scanf("%d", &Q);
    for (int i = 0; i < Q; ++i) {
        int stx, enx, sty, eny; // inclusive
        scanf("%d %d %d %d", &stx, &enx, &sty, &eny);
        ans.clear();
        query(stx, enx, sty, eny, -MAX_R, MAX_R, -MAX_R, MAX_R, &root, 0);
        for (pt p : ans) {
            printf("%d\n", p.id);
        }
        printf("\n");
    }
}
