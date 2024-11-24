#include <bits/stdc++.h>
using namespace std;

stack<long long> st;
long long mini;

// MinStack() {
//     mini = LLONG_MAX;
// }

// Key formulae 
// top = 2*val - mini; for new mini when pushing a element

// mini = 2*mini - top for when poping element

// 2nd Way - is to use 2 stack 
// 3rd Way - store a pair of elements in the stack
void push(int val) {
    if(st.empty()){
        st.push(val);
        mini = val;
    }
    else if(val < mini){
        long long top = (long long) 2*val - mini;
        mini = val;
        st.push(top);
    }
    else{
        st.push(val);
    }
}

void pop() {
    if(st.empty()) return;

    long long x = st.top();
    st.pop();
    if(x < mini){
        mini = (2*mini) - x;
    }
}

int top() {
    long long top = st.top();

    if(top < mini) return mini;
    return top;
}

int getMin() {
    return mini;
}