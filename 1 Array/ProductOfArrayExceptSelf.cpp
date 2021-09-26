// url - https://leetcode.com/problems/product-of-array-except-self/

#include <bits/stdc++.h>

using namespace std;

// Time: O(n) AND Space: O(n) approach
vector<int> productExceptSelf0(vector<int> &nums)
{
    int n = nums.size();
    int prefix[n], suffix[n];
    vector<int> result = {};
    prefix[0] = nums[0];
    suffix[n - 1] = nums[n - 1];
    for (int i = 1, j = n - 2; i < n && j >= 0; i++, j--)
    {
        prefix[i] = nums[i] * prefix[i - 1];
        suffix[j] = nums[j] * suffix[j + 1];
    }
    result.push_back(suffix[1]);
    for (int i = 1; i < n - 1; i++)
    {
        result.push_back(prefix[i - 1] * suffix[i + 1]);
    }
    result.push_back(prefix[n - 2]);
    return result;
}

// Time: O(n) AND Space: O(1) approach
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result = {};
    result.push_back(1);
    for (int i = 1; i < n; i++)
    {
        result.push_back(nums[i - 1] * result[i - 1]);
    }
    int right = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        result[i] = result[i] * right;
        right *= nums[i];
    }
    return result;
}

int main()
{
    vector<int> input = {1, 2, 3, 4};
    // vector<int> input = {-1, 1, 0, -3, 3};
    vector<int> result = productExceptSelf(input);
    for (int i = 0; i < result.size(); i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}