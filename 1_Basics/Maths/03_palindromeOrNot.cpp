#include <bits/stdc++.h>
using namespace std;

int reverse(int x){
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

bool isPalindrome(int x) {

    if(x < 0) return false;
    int rev = reverse(x);

    if(rev == x) return true;
    return false;
}

int main(){
    int x;
    bool ans;

    cout<< "Enter a number: "<< endl;
    cin>> x;
    
    ans = isPalindrome(x);

    if(ans) cout<< "Given number is a palindrome" << endl;
    else cout<< "Given number is not a palindrome"<< endl;
    return 0;
}