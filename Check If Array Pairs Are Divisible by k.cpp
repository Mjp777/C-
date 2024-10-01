class Solution {
public:
    // This function checks if it's possible to rearrange 'arr' such that the sum of every pair of elements is divisible by 'k'.
    bool canArrange(vector<int>& arr, int k) {
        // Create a count array to store frequencies of mod values
        vector<int> count(k, 0);
      
        // Increment the count for each element's mod value with 'k', properly handling negative numbers
        for (int number : arr) {
            int modValue = ((number % k) + k) % k;
            ++count[modValue];
        }
      
        // Check pairs from 1 to k-1. For every 'i', there must be equal number of elements with 'k-i' as mod.
        for (int i = 1; i < k; ++i) {
            if (count[i] != count[k - i]) {
                // If counts are not equal, pairs cannot be formed to satisfy the condition.
                return false;
            }
        }
      
        // The count of elements evenly divisible by 'k' must be even for them to be paired.
        return count[0] % 2 == 0;
    }
};
