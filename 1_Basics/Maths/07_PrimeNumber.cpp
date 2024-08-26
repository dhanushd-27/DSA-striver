#include <bits/stdc++.h>
using namespace std;

bool isPrimeNumber(int num){
    if(num == 1) return false;
    if(num == 2) return true;

    int range = sqrt(num);

    for(int i = 2; i <= range; i++){
        if(num % i == 0){
            return false;
        }
    }

    return true;
}

int main(){
    int num;

    cout<< "Enter a number: ";
    cin >> num;

    if(isPrimeNumber(num)){
        cout<< num<< " is a Prime Number";
    }
    else{
        cout<< num<< " is not a Prime Number";
    }
}