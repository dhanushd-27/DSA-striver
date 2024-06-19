#include <bits/stdc++.h>
using namespace std;

int linear_search(vector<int> arr,int num, int size){
    for(int i = 0 ;i < size; i++){
        if(arr[i] == num){
            return i;
        }
    }
    return -1;
}
int main(){
    int num, size, index = -1;

    cout<<"Enter the number of elements:    ";
    cin>> size;

    vector<int> arr(size);
    cout<< arr.size();
    for(int i = 0; i < size; i++){
        cout<<"Enter an element:   ";
        cin>> arr[i];
    }

    cout<<"Enter the element to be found:   ";
    cin>> num;

    index = linear_search(arr, num, size);

    if(index == -1){
        cout<< "\nElement not found!";
    }
    else{
        printf("Element found at %d index!", index);
    }
}