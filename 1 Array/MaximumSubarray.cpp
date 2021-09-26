// url - https://leetcode.com/problems/maximum-subarray/

#include <bits/stdc++.h>

using namespace std;

// O(n^2) approach
int maxSubArray0(vector<int> &nums)
{
    int max_sum = INT_MIN, sum = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            max_sum = max(max_sum, sum);
        }
    }
    return max_sum;
}

//O(n) approach
int maxSubArray(vector<int> &nums)
{
    int max_sum = INT_MIN, sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        max_sum = max(max_sum, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return max_sum;
}

int main()
{
    // vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // vector<int> nums = {1};
    vector<int> nums = {5, 4, -1, 7, 8};
    printf("%d\n", maxSubArray(nums));
    return 0;
}