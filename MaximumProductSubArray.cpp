#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;  // If the array is empty, return 0
        }

        // Initialize variables to track the current max, min, and the overall max product
        int maxProduct = nums[0];
        int currentMax = nums[0];
        int currentMin = nums[0];

        // Loop through the array starting from the second element
        for (int i = 1; i < nums.size(); i++) {
            int currentNum = nums[i];

            // If the current number is negative, swap currentMax and currentMin
            if (currentNum < 0) {
                swap(currentMax, currentMin);
            }

            // Update currentMax and currentMin
            currentMax = max(currentNum, currentMax * currentNum);
            currentMin = min(currentNum, currentMin * currentNum);

            // Update the result with the maximum product found so far
            maxProduct = max(maxProduct, currentMax);
        }

        return maxProduct;  // Return the maximum product found
    }
};

int main() {
    // Create an object of the Solution class
    Solution sol;

    // Example input: array of integers
    vector<int> nums = {2, 3, -2, 4, -1};  // Example with both positive and negative numbers

    // Call the maxProduct function and output the result
    cout << "Maximum Product Subarray: " << sol.maxProduct(nums) << endl;  // Expected Output: 48

    return 0;
}
