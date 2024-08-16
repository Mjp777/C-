#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int maxDistance(std::vector<std::vector<int>>& arrays) {
        // Initialize global minimum and maximum values
        int globalMin = arrays[0][0];
        int globalMax = arrays[0][arrays[0].size() - 1];
        int maxDistance = 0;

        // Iterate through the arrays
        for (size_t i = 1; i < arrays.size(); ++i) {
            int currentMin = arrays[i][0];
            int currentMax = arrays[i][arrays[i].size() - 1];

            // Calculate distance using global min and current max
            maxDistance = std::max(maxDistance, std::abs(currentMax - globalMin));
            // Calculate distance using global max and current min
            maxDistance = std::max(maxDistance, std::abs(currentMin - globalMax));

            // Update global min and max values
            globalMin = std::min(globalMin, currentMin);
            globalMax = std::max(globalMax, currentMax);
        }

        return maxDistance;
    }
};
