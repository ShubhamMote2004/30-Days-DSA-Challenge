#include<iostream>
#include<vector>
using namespace std;

int findMissingNumber(vector<int> arr, int n){
    int sum1 = 0;
    for(int i=0; i<n; i++){         //calculating the sum of all the array elements.
        sum1 = sum1 + arr[i];
    }

    int sum2 = 0;
    for(int i=1; i<=n+1; i++){      //calculating the sum from 1 to n.
        sum2 = sum2 + i;
    }

    return sum2 - sum1;             //difference is the missing number.
}

int main()
{
    vector<int> arr = {1,2,4,5};
    int n = arr.size();
    cout<<findMissingNumber(arr, n);
}