int BinSearch(vector <int> a, int n, int x) {
	int l = 0, r = n - 1;
	while (l < r) {
		int mid = (l + r) / 2;
		if (a[mid] < x) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	if (a[l] == x) {
		return l;
	}
	return -1;
}

int binarySearch(vector<int> arr, int value) {
	int l = 0, r = arr.size() - 1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (arr[mid] == value)
			return mid;
		if (arr[mid] < value)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return -1;
}