// url - https://leetcode.com/problems/contains-duplicate/

#include <bits/stdc++.h>

using namespace std;

// Time: O(n) AND Space: O(n) approach
bool containsDuplicate0(vector<int> &nums)
{
    unordered_map<long long int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        map[nums[i]]++;
        if (map[nums[i]] >= 2)
            return true;
    }
    return false;
}

// Time: O(nlogn) AND Space: O(1) approach
bool containsDuplicate(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    // vector<int> nums = {1, 2, 3, 1};
    // vector<int> nums = {1, 2, 3, 4};
    vector<int> nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    printf(containsDuplicate(nums) ? "true\n" : "false\n");
    return 0;
}