// Allocate all books to given m students such that the max number of pages assigned to a student is minimum

#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int> a, int pages){
    int n = a.size();
    int students = 1;
    long long pagesStudent = 0;

    for(int i = 0; i < n; i++){
        if(a[i] + pagesStudent <= pages) pagesStudent += a[i];

        else{
            students++;
            pagesStudent=a[i];
        }
    }

    return students;
}

int findPages(vector<int> a, int n, int m){
    // impossible case
    if(m > n) return -1;

    // The minimum possible answer, i.e The minimum no of pages that can be assigned to a student m = n
    int low = *max_element(a.begin(), a.end());

    // The max possible answer, i.e n = 1 and ans = sum of all values in a
    int high = accumulate(a.begin(), a.end(), 0);

    for(int i = low; i <= high; i++){
        if(countStudents(a, i) == m) return i;
    }

    return low;
}

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
