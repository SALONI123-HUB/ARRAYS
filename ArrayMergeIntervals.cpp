#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort intervals based on the start value
        sort(intervals.begin(), intervals.end());
        
        // Initialize an empty vector to store merged intervals
        vector<vector<int>> merged;

        // Iterate through the sorted intervals
        for (int i = 0; i < intervals.size(); i++) {
            int current_start = intervals[i][0];
            int current_end = intervals[i][1];
            
            // If merged is empty or there is no overlap, add the current interval
            if (merged.empty() || merged.back()[1] < current_start) {
                merged.push_back({current_start, current_end});
            } else {
                // If there is overlap, merge the intervals by updating the end value
                merged.back()[1] = max(merged.back()[1], current_end);
            }
        }

        return merged;
    }
};

int main() {
    // Create an object of the Solution class
    Solution sol;

    // Example input intervals
    vector<vector<int>> intervals = {{1, 4}, {2, 5}, {7, 9}, {8, 10}, {12, 15}};

    // Output the original intervals
    cout << "Original intervals: ";
    for (const auto& interval : intervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    // Call the merge function and store the result
    vector<vector<int>> result = sol.merge(intervals);

    // Output the merged intervals
    cout << "Merged intervals: ";
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
