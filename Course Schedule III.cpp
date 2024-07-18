class Solution {
 public:
  int scheduleCourse(vector<vector<int>>& courses) {
    int time = 0;
    priority_queue<int> maxHeap;

    ranges::sort(courses,
                 [](const auto& a, const auto& b) { return a[1] < b[1]; });

    for (const vector<int>& course : courses) {
      const int duration = course[0];
      const int lastDay = course[1];
      maxHeap.push(duration);
      time += duration;
     
      if (time > lastDay)
        time -= maxHeap.top(), maxHeap.pop();
    }

    return maxHeap.size();
  }
};
