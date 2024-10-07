#include <bits/stdc++.h>
using namespace std;

bool findX(string word, char x){
    for(char it: word){
        if(it == x) return true;
    }

    return false;
}

void findWordsContaining(vector<string>& words, char x) {
    int size = words.size();
    vector<int> res;

    for(int i = 0; i < size; i++){
        if(findX(words[i], x)){
            res.push_back(i);
        }
    }

    for(int it: res){
        cout<< it<< " ";
    }
}

int main(){
    vector<string> words = {"abc","bcd","aaaa","cbc"};

    findWordsContaining(words, 'a');
}