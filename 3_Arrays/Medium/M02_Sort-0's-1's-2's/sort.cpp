#include <bits/stdc++.h>
using namespace std;

void better_approach(vector<int> arr){
    int size = arr.size();
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] == 0){
            cnt0++;
        }
        else if(arr[i] == 1){
            cnt1++;
        }
        else
            cnt2++;
    }

    for(int i = 0; i < cnt0; i++)
        arr[i] = 0;
    
    for(int i = cnt0; i < cnt1; i++)
        arr[i] = 1;

    for(int i = cnt1; i < cnt2; i++)
        arr[i] = 2;

    for(int i = 0; i < size; i++){
        cout<<arr[i] <<" ";
    }
}

void optimal_approach(vector<int> arr){
    int size = arr.size();

    int mid = 0;
    int low = 0;
    int high = size - 1;

    while(mid < high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++, mid++;
        }

        else if(arr[mid] == 1)
            mid++;
        
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }

    for(int i = 0; i < size; i++){
        cout<<arr[i] <<" ";
    }
}

int main(){
    vector<int> arr = {1, 2, 0, 2, 1, 1, 0, 2};
    int size = arr.size();

    cout<<"\nOriginal Array:\n";
    for(int i = 0; i < size; i++){
        cout<<arr[i]<< " ";
    }

    cout<<"\n\nBRUTE APPROACH\n";
    cout<<"--------------------------------------------------\n";
    cout<<"Use any of the sorting algo's\n\n";

    cout<<"BETTER APPROACH\n";
    cout<<"--------------------------------------------------\n";
    better_approach(arr);

    cout<<"\n\nOriginal Array:\n";
    for(int i = 0; i < size; i++){
        cout<<arr[i]<< " ";
    }

    cout<<"\n\nOPTIMAL APPROACH";
    cout<<"\nDutch National Flag Approach!\n";
    cout<<"--------------------------------------------------\n";
    optimal_approach(arr);
    
    return 0;
}