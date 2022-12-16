int interpolationSearch(int a[], int n, int x) {
    int l = 0, r = n - 1;
    while (a[r] != a[l] && x >= a[l] && x <= a[r]) {
        int mid = l + (r - l) * (x - a[l]) / (a[r] - a[l]);
        if (a[mid] < x) {
            l = mid + 1;
        }
        else if (a[mid] > x) {
            r = mid - 1;
        }
        else {
            if (mid > 0 && a[mid - 1] == x) {
                r = mid - 1;
            }
            else {
                return mid;
            }
        }
    }
    if (a[l] == x) {
        return l;
    }
    return -1;
}