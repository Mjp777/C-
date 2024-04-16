Jump Game II

You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

class Solution {
 public:
  int jump(vector<int>& nums) {
    int ans = 0;
    int end = 0;
    int farthest = 0;

    // Start an implicit BFS.
    for (int i = 0; i < nums.size() - 1; ++i) {
      farthest = max(farthest, i + nums[i]);
      if (farthest >= nums.size() - 1) {
        ++ans;
        break;
      }
      if (i == end) {    // Visited all the items on the current level.
        ++ans;           // Increment the level.
        end = farthest;  // Make the queue size for the next level.
      }
    }

    return ans;
  }
};
