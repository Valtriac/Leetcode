#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size());
        int size = nums.size();
        int i =0, j=size-1;
        int skip=-1;
        int product=1;
        int a=0;
        while(a<=j)
        {
            i=0;
            product=1;
            skip=skip+1;
            while(i<=j)
            {
                if(i!=skip)
                {
                    product=product*nums[i];
                }
                i++;
            }
            answer[a]=product;
            a++;
        }
        return answer;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    int num_elements;
    cout << "Enter the number of elements: ";
    cin >> num_elements;

    cout << "Enter " << num_elements << " elements separated by space: ";
    for (int i = 0; i < num_elements; ++i) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    vector<int> result = sol.productExceptSelf(nums);

    cout << "Resultant array: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
