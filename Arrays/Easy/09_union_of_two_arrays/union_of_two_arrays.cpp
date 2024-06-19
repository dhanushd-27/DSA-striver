#include <bits/stdc++.h>
using namespace std;

vector<int> union_of_two(vector<int> arr1, vector<int> arr2){
    // Brute Approach
    set<int> union_set;
    vector<int> union_arr;


    // Pushing all values of array 1 into the set
    // O(n1.logn)
    for(int i = 0; i < arr1.size(); i++){
        union_set.emplace(arr1[i]);
    }

    // Pushing all values of array 2 into the set
    // O(n2.logn)    
    for(int i : arr2){
        union_set.emplace(i);
    }

    // Pushing all unique values of set into a new array named union_arr
    // TC: O(n1 + n2)

    int j = 0;
    for(auto ele: union_set){
        union_arr.push_back(ele);
    }

    // Return the union array
    return union_arr;

    //TC: O(n1.logn) + O(n2.logn) + O(n1 + n2)
    //SC: O(n1+n2) + O(n1+n2)
}

vector<int> optimal_approach(vector<int> arr1, vector<int> arr2){
    // Optimal_approach
    vector<int> union_arr;

    // arr1 = {1,1,2,3,4,5};
    // arr2 = {2,3,4,4,5,6,7};

    int i = 0, j = 0;
    int arr1_size = arr1.size();
    int arr2_size = arr2.size();


    while(i < arr1_size && j < arr2_size){
        if(arr1[i] <= arr2[j]){
            if(union_arr.size() == 0 || union_arr.back() != arr1[i]){
                union_arr.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if(union_arr.size() == 0 || union_arr.back() != arr2[j]){
                union_arr.push_back(arr2[j]);
            }
            j++;
        }
    }

    while(i < arr1_size){
        if(union_arr.back() != arr1[i])
            union_arr.push_back(arr1[i]);
        i++;
    }

    while(j < arr2_size){
        if(union_arr.back() != arr2[j])
            union_arr.push_back(arr2[j]);
        j++;
    }
    
    return union_arr;
}


int main(){
    vector<int> union_arr;

    vector<int> arr2 = {2,3,4,4,5,6,7};
    vector<int> arr1 = {1,1,2,3,4,5};

    cout<<"BRUTE APPROACH\n";
    cout<<"--------------\n";
    union_arr = union_of_two(arr1, arr2);
    cout<<"Union of Two Array using Brute Approach\n";
    for(int i: union_arr){
        cout<<i<< " ";
    }

    cout<<"\n\n";

    cout<<"Optimal Approach\n";
    cout<< "---------------"<<endl;
    union_arr = optimal_approach(arr1, arr2);
    cout<<"Union of Two Array using Optimal Approach\n";
    for(int i: union_arr){
        cout<<i<< " ";
    }
}
