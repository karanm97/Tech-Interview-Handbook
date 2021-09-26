// url - https://leetcode.com/problems/two-sum/

#include <bits/stdc++.h>

using namespace std;

// O(n^2) approach
vector<int> twosum0(vector<int> &nums, int target)
{
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result.push_back(i);
                result.push_back(j);
            }
        }
    }
    return result;
}

//O(n) approach
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++)
    {
        auto element = hash.find(target - nums[i]);
        if (element != hash.end())
        {
            return {element->second, i};
        }
        hash[nums[i]] = i;
    }
    return {};
}

int main()
{
    // vector<int> nums = {2, 7, 11, 15};
    // int target = 9;
    // vector<int> nums = {3, 2, 4};
    // int target = 6;
    // vector<int> nums = {3, 3};
    // int target = 6;
    vector<int> nums = {3, 3, 2, 7, 11, 15};
    int target = 9;
    vector<int> op = twoSum(nums, target);
    printf("%d %d\n", op[0], op[1]);
    return 0;
}