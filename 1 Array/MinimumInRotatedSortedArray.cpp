// url - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <bits/stdc++.h>

using namespace std;

// Modified Binary Search
int findMin(vector<int> &nums)
{
    int l = 0, r = nums.size() - 1;
    while (l < r)
    {
        if (nums[l] < nums[r])
        {
            return nums[l];
        }
        int mid = l + (r - l) / 2;
        if (nums[l] > nums[mid])
        {
            r = mid;
        }
        else
        {
            l = ++mid;
        }
    }
    return nums[l];
}

int main()
{
    // vector<int> nums = {3, 4, 5, 1, 2};
    // vector<int> nums = {4,5,6,7,0,1,2};
    vector<int> nums = {11, 13, 15, 17};
    printf("%d\n", findMin(nums));
    return 0;
}