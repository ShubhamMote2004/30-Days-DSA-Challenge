#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> findZeroSumSubarrays(const vector<int>& arr) {
    unordered_map<int, vector<int>> sumIndices; // Stores indices where each cumulative sum occurs
    vector<vector<int>> result; // Stores the result subarrays
    int cumulativeSum = 0;
    
    // Initialize with cumulative sum 0 at index -1
    sumIndices[0].push_back(-1);
    
    for (int i = 0; i < arr.size(); ++i) {
        cumulativeSum += arr[i];
        
        // If the cumulative sum has been seen before
        if (sumIndices.find(cumulativeSum) != sumIndices.end()) {
            // Retrieve the list of previous indices with this cumulative sum
            const vector<int>& startIndices = sumIndices[cumulativeSum];
            
            // For each previous index, generate subarrays
            for (int startIndex : startIndices) {
                result.push_back(vector<int>(arr.begin() + startIndex + 1, arr.begin() + i + 1));
            }
        }
        
        // Add the current index to the list of indices for this cumulative sum
        sumIndices[cumulativeSum].push_back(i);
    }
    
    return result;
}

int main() {
    vector<int> arr = {1, -1, 2, -2, 3, -3};
    
    vector<vector<int>> subarrays = findZeroSumSubarrays(arr);
    
    for (const auto& subarray : subarrays) {
        for (int num : subarray) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
