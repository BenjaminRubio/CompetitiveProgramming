#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

typedef long long ll;
typedef ll Key;
typedef struct node *pnode;

struct node
{
    Key key;
    int prior, size;
    ll sum;
    pnode l, r;
    node(Key key = 0) : key(key), prior(rand()), size(1), sum(key), l(0), r(0) {}
};
static int size(pnode p) { return p ? p->size : 0; }
static Key key(pnode p) { return p ? p->key : 0; }
static ll sum(pnode p) { return p ? p->sum : 0; }
void push(pnode p)
{
}
void pull(pnode p)
{
    p->size = 1 + size(p->l) + size(p->r);
    p->sum = sum(p->l) + key(p) + sum(p->r);
}

pnode merge(pnode l, pnode r)
{
    if (!l || !r)
        return l ? l : r;
    push(l), push(r);
    pnode t;
    if (l->prior < r->prior)
        l->r = merge(l->r, r), t = l;
    else
        r->l = merge(l, r->l), t = r;
    pull(t);
    return t;
}

void split(pnode t, Key key, pnode &l, pnode &r)
{
    if (!t)
        return void(l = r = 0);
    push(t);
    if (key < t->key)
        split(t->l, key, l, t->l), r = t;
    else
        split(t->r, key, t->r, r), l = t;
    pull(t);
}

void erase(pnode &t, Key key)
{
    if (!t)
        return;
    push(t);
    if (key == t->key)
        t = merge(t->l, t->r);
    else if (key < t->key)
        erase(t->l, key);
    else
        erase(t->r, key);
    if (t)
        pull(t);
}

pnode find(pnode t, Key key)
{
    if (!t)
        return 0;
    if (key == t->key)
        return t;
    if (key < t->key)
        return find(t->l, key);
    return find(t->r, key);
}

pnode find_first(pnode t, Key key)
{
    if (!t)
        return 0;
    if (key <= t->key)
    {
        pnode res = find_first(t->l, key);
        if (res)
            return res;
        return t;
    }
    return find_first(t->r, key);
}

ll upper_sum(pnode t, Key k)
{
    if (!t)
        return 0;
    if (k < t->key)
        return upper_sum(t->l, k);
    return key(t) + sum(t->l) + upper_sum(t->r, k);
}

ll lower_sum(pnode t, Key k)
{
    if (!t)
        return 0;
    if (k <= t->key)
        return lower_sum(t->l, k);
    return key(t) + sum(t->l) + lower_sum(t->r, k);
}

struct treap
{
    pnode root;
    treap(pnode root = 0) : root(root) {}
    int size() { return ::size(root); }
    void insert(Key key)
    {
        pnode t1, t2;
        pnode t_new = new node(key);
        split(root, key, t1, t2);
        t1 = ::merge(t1, t_new);
        root = ::merge(t1, t2);
    }
    void erase(Key key1, Key key2)
    {
        pnode t1, t2, t3;
        split(root, key1, t1, t2);
        split(t2, key2, t2, t3);
        root = merge(t1, t3);
    }
    void erase(Key key) { ::erase(root, key); }
    pnode find(Key key) { return ::find(root, key); }
    pnode find_first(Key key) { return ::find_first(root, key); }
    ll upper_sum(Key key) { return ::upper_sum(root, key); }
    ll lower_sum(Key key) { return ::lower_sum(root, key); }
    Key &operator[](int pos) { return find(pos)->key; }
};
treap merge(treap a, treap b) { return treap(merge(a.root, b.root)); }

int N, M, k;
ll f;
multiset<ll> s;
vector<ll> nums;

int count_winners(treap &t)
{
    int ans = 0;
    ll last = 0;
    pnode t_ = t.find_first(last);
    while (t_)
    {
        if (t.lower_sum(key(t_)) <= key(t_))
            ans++;
        last = t.upper_sum(key(t_));
        if (last == key(t_))
            last++;
        t_ = t.find_first(last);
    }
    return ans + (*s.begin() == *(++s.begin())); // checkeo caso borde
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    treap t;

    cin >> N;
    rep(i, N)
    {
        cin >> f;
        t.insert(f);
        s.insert(f);
        nums.push_back(f);
    }

    cout << count_winners(t) << '\n';

    cin >> M;
    rep(i, M)
    {
        cin >> k >> f;
        t.erase(nums[k - 1]);
        t.insert(f);
        s.erase(s.lower_bound(nums[k - 1]));
        s.insert(f);
        nums[k - 1] = f;

        cout << count_winners(t) << '\n';
    }
}