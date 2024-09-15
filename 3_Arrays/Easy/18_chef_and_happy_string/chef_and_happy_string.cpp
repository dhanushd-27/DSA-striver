#include <bits/stdc++.h>
using namespace std;

string happyOrNot(string str){
    int count = 0;
    int n = str.length();

    for(int i = 0;i < n; i++){
        char curChar = tolower(str[i]);
        if(curChar == 'a' || curChar == 'e' || curChar == 'i' || curChar == 'o' || curChar == 'u'){
            count++;

            if(count > 2) return "Happy";
        }
    }

    return "Sad";
}

int main(){
    string str = "AeI";
    cout<< "Chef is "<< happyOrNot(str)<< endl;
    return 0;
}