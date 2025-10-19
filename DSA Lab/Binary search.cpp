#include<iostream>
#include<vector>
using namespace std;

// itteratie binary search
int bs(vector<int> &a, int tar) {
    int st = 0, end = a.size() - 1;
    
    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (a[mid] < tar) {
            st = mid + 1;
        } else if (a[mid] > tar) {
            end = mid - 1;
        } else return mid;
    } 
    return -1;
}

// recursive binary search
int rbs(vector<int> &a, int st, int end, int tar) {
    if (st > end) return -1;

    int mid = st + (end - st) /2;
    if (a[mid] == tar) return mid;
    else if (a[mid] > tar) return rbs(a, st, mid - 1, tar);
    else return rbs(a, mid + 1, end, tar);
}

int main(){
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tar;
    cin >> tar;
    cout << bs(a, tar) << endl;
    cout << rbs(a, 0, a.size() - 1, tar) << endl;
    return 0;
}
