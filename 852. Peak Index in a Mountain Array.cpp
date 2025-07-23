int peakIndexInMountainArray(vector<int>& a) {
        int st = 1, end = a.size()-2;
        
        while(st <= end) {
            int mid = st + (end - st) / 2;
            if (a[mid] > a[mid - 1] and a[mid] > a[mid + 1]) return mid;
            else if (a[mid] > a[mid - 1]) st = mid + 1;
            else end = mid - 1;
        }
        return -1;
    }
