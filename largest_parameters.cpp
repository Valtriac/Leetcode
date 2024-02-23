#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long sum = 0;
        sort(nums.begin(),nums.end());
        for(auto i : nums) sum += i;
        int n = nums.size();
        for(int i = n - 1; i >= 2; i--){
            sum -= nums[i];
            if(sum > nums[i]){
                return sum + nums[i];
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 1, 2};
    cout << "Largest perimeter: " << solution.largestPerimeter(nums) << endl;
    return 0;
}
