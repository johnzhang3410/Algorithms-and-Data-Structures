class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int size{};
        
        //size of (in bits) of the entire array over bits of a single element results in how many elements there are in the array
        size = sizeof(nums)/sizeof(nums[0]);
        
        //double for loop that go through all possible index combinations to see if sum of elements of 2 index == target
        for (int k{}; k < size; k++){
            for (int i{1}; i < size; i++){
                if (nums[k] + nums[i] == target){
                    return {k, i};
                }
            }
        }
        return {};
    }
};
