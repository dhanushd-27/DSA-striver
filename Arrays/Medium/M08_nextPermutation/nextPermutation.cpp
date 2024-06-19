#include <bits/stdc++.h>
using namespace std;


// *Algorithm / Intuition
// *Brute Force: Finding all possible permutations. 

// *Approach :

// *Step 1: Find all possible permutations of elements present and store them.

// *Step 2: Search input from all possible permutations.

// *Step 3: Print the next permutation present right after it.

void inbuilt_func(){
    vector<int> arr = {1,3,2};

    next_permutation(arr.begin(), arr.end());

    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
}

void optimal_approach(vector<int> A){
    int n = A.size();
    int breakPoint = -1;

    //* Find the break point of the array i. e arr[i] > arr[i + 1]
    // * vector<int> A = {2, 1, 5, 4, 3, 0, 0};
    
    for(int i = n - 2; i >= 0; i--){
        if(A[i] < A[i + 1]){
            breakPoint = i;
            break;
        }
    }

    //* Find the element which immediate greater than arr[i] i. e element at break point
    if(breakPoint != -1){
        int index = n - 1;
        while(A[breakPoint] > A[index]){
            index--;
        }
        swap(A[breakPoint], A[index]);

        reverse(A.begin() + breakPoint + 1, A.end());
    }

    else reverse(A.begin(), A.end());

    cout<<"The Next Possible iteration is: [ ";
    for(int i = 0; i < n; i++){
        cout<<A[i]<< " ";
    }
    cout<<"]";
}

int main(){
    inbuilt_func();
    cout<<"\n\nOPTIMAL APPROACH\n\n";

    vector<int> A = {2, 1, 5, 4, 3, 0, 0};
    optimal_approach(A);
}