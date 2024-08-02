#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int> arr, int pages){
    int n = arr.size(); //size of array.
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            //add pages to current student
            pagesStudent += arr[i];
        }
        else {
            //add pages to next student
            students++;
            pagesStudent = arr[i];
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

    while(low <= high){
        int mid = (low + high) / 2;
        int students = countStudents(a, mid);
        if (students > m) {
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
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