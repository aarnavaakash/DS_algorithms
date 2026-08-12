void updateRange(int start, int end, int i, int l, int r, int val) {
    if (lazyTree[i] != 0) {
        segTree[i] += (r - l + 1) * lazyTree[i];

        if (l != r) {
            lazyTree[i * 2 + 1] += lazyTree[i];
            lazyTree[i * 2 + 2] += lazyTree[i];
        }
        lazyTree[i] = 0;
    }

    if (l > end || r < start || l > r)
        return;

    if (l >= start && r <= end) {
        segTree[i] += (r - l + 1) * val;
        if (l != r) {
            lazyTree[i * 2 + 1] += val;
            lazyTree[i * 2 + 2] += val;
        }
        return;
    }

    int mid = (l + r) / 2;
    updateRange(start, end, 2*i+1, l, mid, val);
    updateRange(start, end, 2*i+2, mid+1, r, val);
    segTree[i] = segTree[i * 2 + 1] + segTree[i * 2 + 2];
}
