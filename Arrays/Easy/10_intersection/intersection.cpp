#include <bits/stdc++.h>
using namespace std;

vector<int> brute_approach(vector<int> arr1, int arr1_size, vector<int> arr2, int arr2_size){
    vector<int> vis(arr2_size);
    vector<int> ans;

    for(int i =0; i< arr1_size; i++){
        // Iterate through arr2 i times
        for(int j = 0; j< arr2_size; j++){
        // Check for common elements in both the arrays
            if(arr1[i] == arr2[j] && vis[j] != 1){
                ans.push_back(arr1[i]);
                vis[j] = 1;
                break;
            }
            // If arr1 element is smaller than arr2 element break because it means arr1 ele doesn't exist in arr2
            if(arr1[i] < arr2[j])
                break;
        }
    } 
    return ans;

    // TC: O(n1 x n2)
    // SC: O(n2)
    // We are not considering ans[] size as it is not used for calculation
}

vector<int> optimal_approach(vector<int> arr1, int arr1_size, vector<int> arr2, int arr2_size){
    int i = 0;
    int j = 0;

    vector<int> ans;

    while(i < arr1_size && j < arr2_size){
        if(arr1[i] < arr2[j]){
            i++;
        } 
        
        else if(arr1[i] > arr2[j]){
            j++;
        }

        else{
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    return ans;
}
int main(){
    vector<int> arr1 = {1, 1, 2, 3, 4, 4, 6};
    vector<int> arr2 = {1, 2, 3, 4, 4, 5};

    vector<int> ans = brute_approach(arr1, arr1.size(), arr2, arr2.size());

    vector<int> ans1 = optimal_approach(arr1, arr1.size(), arr2, arr2.size());

    for(int i: ans)
        cout<<i<< " ";
    
    cout<<endl;

    for(int i: ans1)
        cout<<i<< " ";
}