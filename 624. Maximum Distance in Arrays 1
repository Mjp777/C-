class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxDistance = 0; // maximum distance found so far
        int minElement = arrays[0][0]; // initialize with the first element of the first array
        int maxElement = arrays[0].back(); // initialize with the last element of the first array

        // Start from the second array
        for (int i = 1; i < arrays.size(); ++i) {
            // Reference to the current array to avoid copying
            auto& currentArray = arrays[i];
          
            // Calculate distance between the smallest element so far and the last element of the current array
            int distanceToMin = abs(currentArray[0] - maxElement);
          
            // Calculate distance between the largest element so far and the first element of the current array
            int distanceToMax = abs(currentArray.back() - minElement);
          
            // Update maxDistance with the largest of the three: itself, distanceToMin, distanceToMax
            maxDistance = max({maxDistance, distanceToMin, distanceToMax});
          
            // Update minElement with the smaller between minElement and the first element of the current array
            minElement = min(minElement, currentArray[0]);
          
            // Update maxElement with the larger between maxElement and the last element of the current array
            maxElement = max(maxElement, currentArray.back());
        }
      
        // Return the maximum distance found
        return maxDistance;
    }
};
