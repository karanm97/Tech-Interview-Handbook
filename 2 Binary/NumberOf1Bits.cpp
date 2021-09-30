// url - https://leetcode.com/problems/number-of-1-bits/

#include <bits/stdc++.h>

using namespace std;

// O(n) approach
int hammingWeight(uint32_t n)
{
    int count = 0;
    while (n > 0)
    {
        if (n & 1)
        {
            count++;
        }
        n >>= 1;
    }
    return count;
}

int main()
{
    // uint32_t n = 00000000000000000000000000001011;
    uint32_t n = 00000000000000000000000010000000;
    printf("%d\n", hammingWeight(n));
    return 0;
}