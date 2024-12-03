#include <bits/stdc++.h>
using namespace std;

// Leetcode - 13 Roman To Integer

int romanToInt(string s) {
      // store all symbols in a hashmap
      unordered_map<char, int> hash;
      hash['I'] = 1;
      hash['V'] = 5;
      hash['X'] = 10;
      hash['L'] = 50;
      hash['C'] = 100;
      hash['D'] = 500;
      hash['M'] = 1000;

      int sum = 0;
      int size = s.size();
      for(int i = 0; i < size; i++){
          // subtract from sum if current roman is smaller than the next
          if(hash[s[i]] < hash[s[i+1]]){
              sum -= hash[s[i]];
          } else{
              // add to the sum if current roman is greater than the next
              sum += hash[s[i]];
          }
      }

      return sum;
  }