#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> merged;
        int i = 0;

        cout << "Enter the intervals: ";
        for (int j = 0; j < intervals.size(); j++) {
            int start, end;
            cin >> start >> end;
            intervals.push_back({start, end});
        }

        cout << "Enter the new interval: ";
        int newStart, newEnd;
        cin >> newStart >> newEnd;
        newInterval = {newStart, newEnd};

        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            merged.push_back(intervals[i]);
            i++;
        }

        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval = {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};
            i++;
        }
        merged.push_back(newInterval);

        while (i < intervals.size()) {
            merged.push_back(intervals[i]);
            i++;
        }

        return merged;
    }
};

int main() {
    Solution s;
    vector<vector<int>> intervals;
    vector<int> newInterval;
    vector<vector<int>> result = s.insert(intervals, newInterval);
    cout << "Merged intervals: ";
    for (auto interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}
