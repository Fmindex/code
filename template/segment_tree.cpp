// max

int seg[400005];

void update(int v, int tl, int tr, int pos, int x) {
    if (tl == tr) seg[v] = max(seg[v], x);
    else {
        int tm = (tl+tr) >> 1;
        if (pos <= tm) update(v<<1, tl, tm, pos, x);
        else update(v<<1|1, tm+1, tr, pos, x);
        seg[v] = max(seg[v<<1], seg[v<<1|1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) return seg[v];
    int tm = (tl+tr) >> 1;
    return max(query(v<<1, tl, tm, l, min(r, tm)), query(v<<1|1, tm+1, tr, max(l, tm+1), r));
}

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        for (int i=1; i<=400000; i++) seg[i] = 0;
        for (int i=1; i<=n; i++) {
            int cur = nums[i-1];
            int x = query(1, 1, 100000, max(1, cur-k), cur-1)+1;
            res = max(res, x);
            update(1, 1, 100000, cur, x);
        }
        return res;
    }
};


// sum

class NumArray {
    int seg[400005] = {0}, N = 0;

void updateUtil(int v, int tl, int tr, int pos, int x) {
    if (tl == tr) seg[v] = x;
    else {
        int tm = (tl+tr) >> 1;
        if (pos <= tm) updateUtil(v<<1, tl, tm, pos, x);
        else updateUtil(v<<1|1, tm+1, tr, pos, x);
        seg[v] = seg[v<<1] + seg[v<<1|1];
    }
}

int queryUtil(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) return seg[v];
    int tm = (tl+tr) >> 1;
    return queryUtil(v<<1, tl, tm, l, min(r, tm)) + queryUtil(v<<1|1, tm+1, tr, max(l, tm+1), r);
}

public:
    NumArray(vector<int>& nums) {
        N = (int)nums.size();
        for (int i = 0; i < nums.size(); i++) {
            updateUtil(1, 0, N - 1, i, nums[i]);
        }
    }
    
    void update(int index, int val) {
        updateUtil(1, 0, N - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return queryUtil(1, 0, N - 1, left, right);
    }
};
