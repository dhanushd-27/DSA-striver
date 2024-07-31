// WAP program to reverse a number
/* Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.*/
#include <bits/stdc++.h>
using namespace std;

int revers(int x){
    // Using long long to verify whether the reverse value crosses Signed INT range
    long long rev = 0;
    long long temp = x;
    bool neg = false;

    // When input value is negative
    if(temp < 0){
        neg = true;
        temp = temp * -1;
    }

    while(temp > 0){
        int rem = temp%10;
        // Check the value is within Signed integer range
        if(rev * 10 > INT_MAX || rev * 10 * -1 < INT_MIN) return 0;
        rev = (rev * 10) + rem;
        temp = temp / 10;
    }

    if(neg){
        return -1 * rev;
    }

    return rev;
}

int main(){
    int x, ans;

    cout<< "Enter a number: "<< endl;
    cin>> x;

    ans = revers(x);
    if(ans == 0){
        cout<< "Reverse of given number "<< x<< " is out of signed integer range";
        return 0;
    }
    cout<<"Reverse of "<< x<< " is "<< ans;
    return 0;
}