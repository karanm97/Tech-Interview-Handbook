// url - https://leetcode.com/problems/maximum-product-subarray/

#include <bits/stdc++.h>

using namespace std;

// O(n^2) approach
int maxProduct0(vector<int> &nums)
{
    int product = nums[0], max_product = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        product = 1;
        for (int j = i; j < nums.size(); j++)
        {
            product *= nums[j];
            max_product = max(max_product, product);
        }
    }
    return max_product;
}

// O(n) approach, 2 passes
int maxProduct1(vector<int> &nums)
{
    int max_prod = INT_MIN, prod = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        max_prod = max(max_prod, prod *= nums[i]);
        if (nums[i] == 0)
        {
            prod = 1;
        }
    }
    prod = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        max_prod = max(max_prod, prod *= nums[i]);
        if (nums[i] == 0)
        {
            prod = 1;
        }
    }
    return max_prod;
}

// O(n) approach, 1 pass
int maxProduct(vector<int> &nums)
{
    int max_val = nums[0], min_val = nums[0], max_prod = nums[0], temp_max;
    for (int i = 1; i < nums.size(); i++)
    {
        temp_max = max_val;
        max_val = max(temp_max * nums[i], max(min_val * nums[i], nums[i]));
        min_val = min(temp_max * nums[i], min(min_val * nums[i], nums[i]));
        max_prod = max(max_prod, max_val);
    }
    return max_prod;
}

int main()
{
    // vector<int> nums = {2, 3, -2, 4};
    // vector<int> nums = {-2, 0, -1};
    // vector<int> nums = {0, -1};
    // vector<int> nums = {-2};
    vector<int> nums = {-2, -10, 0, 9, 10};
    printf("%d\n", maxProduct(nums));
    return 0;
}