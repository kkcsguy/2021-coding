#include "bits/stdc++.h"

using namespace std;

//挖坑版的快排
void quick_sort(vector<int> &nums, int l, int r) {
    if (l >= r) return;
    int cur = nums[r];
    int i = l, j = r;
    while (i < j) {
        while (i < j && nums[i] < cur) i++;
        if (i < j) {
            nums[j--] = nums[i];
        }
        while (i < j && nums[j] > cur) j--;
        if (i < j) {
            nums[i++] = nums[j];
        }
    }
    nums[i] = cur;
//    for (auto k:nums)
//        cout << k << ' ';
//    cout << endl;
    quick_sort(nums, l, i - 1);
    quick_sort(nums, i + 1, r);


}


int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    quick_sort(nums, 0, n - 1);
    for (auto i:nums)
        cout << i << ' ';
    return 0;
}