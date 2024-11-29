#include <bits/stdc++.h>
using namespace std;
// Leetcode 11 - Container with most water

int maxArea(vector<int>& height) {
    // TC - O(n)
    // SC - O(1)

    int size = height.size();

    int i = 0;
    int j = size - 1;
    long long maxArea = LLONG_MIN;

    while(i < j){
        int h1 = height[i], h2 = height[j];

                    // width * height
        long long area = (j - i) * min(h1, h2);

        // maxArea
        maxArea = max(area, maxArea);

        h1 > h2 ? j-- : i++;
    }

    return maxArea;
}