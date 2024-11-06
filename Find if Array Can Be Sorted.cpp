#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int previousMax = -300; // Initial value considering the constraints for possible integer values
        int currentIndex = 0, numSize = nums.size();
      
        // Loop through all elements in the array
        while (currentIndex < numSize) {
            int nextIndex = currentIndex + 1;
            int currentPopCount = __builtin_popcount(nums[currentIndex]);
            int currentMin = nums[currentIndex], currentMax = nums[currentIndex];
          
            // Find subsequence where all elements have the same number of set bits (1s)
            while (nextIndex < numSize && __builtin_popcount(nums[nextIndex]) == currentPopCount) {
                currentMin = min(currentMin, nums[nextIndex]);
                currentMax = max(currentMax, nums[nextIndex]);
                nextIndex++;
            }
          
            // If the maximum value from previous segment is greater than minimum of the current,
            // then the array can't be sorted based on the rules given
            if (previousMax > currentMin) {
                return false;
            }
            previousMax = currentMax; // Update previousMax to the max of the current segment
            currentIndex = nextIndex; // Move to the next segment
        }
      
        // If the loop completes without returning false, it means the array can be sorted
        return true;
    }
};
