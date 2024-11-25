#include <bits/stdc++.h>
using namespace std;

// Interview doesn't usually ask time complexity of recursion problems
// TC - 2^t * k
// SC - k * x

void findCombination(int index, int target, vector<int> &candidates, vector<int> &combinations, vector<vector<int>> res){
        // the recursion has reached to last index
        if(index == candidates.size()){
            // if the combination elements sum == target, push it to the res
            if(target == 0){
                res.push_back(combinations);
            }

            return;
        }

        // if current element is less than target, add it to the combination
        if(candidates[index] <= target){
            combinations.push_back(candidates[index]);
            // reduce it target by candidates[index];
            findCombination(index, target - candidates[index], candidates, combinations, res);
            combinations.pop_back();
        }
        // don't select the current index
        findCombination(index + 1, target, candidates, combinations, res);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> combinations;

    findCombination(0, target, candidates, combinations, res);
    return res;
}