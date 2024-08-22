// Write an optimal approach to find HCF and LCM of two numbers
#include <bits/stdc++.h>
using namespace std;

int HCF(int a, int b){
    while(a > 0 && b > 0){
        
        if(a > b){
            a = a % b;
        }
        else{
            b = b % a;
        }

        if(a == 0) return b;
    }

    return a;
}

int LCM(int a, int b, int HCF){
    return (a * b) / HCF;
}

int main(){
    int n1 = 9, n2 = 12;
    int gcd = HCF(n1, n2);

    int lcm = LCM(n1, n2, gcd);

    cout<< "Greatest Common factor of "<< n1<< " and "<< n2<< " are: "<< gcd<< endl;
    cout<< "Least Common Multiple of "<< n1<< " and "<< n2<< " are: "<< lcm;
}