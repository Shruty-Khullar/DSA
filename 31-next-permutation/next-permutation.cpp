class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int max_num = nums[0];
        int n = nums.size();
        int permutation_index=-1;
        for(int i=n-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                permutation_index=i;
                break;
            }
        }
        if(permutation_index==-1)
             reverse(nums.begin(), nums.end());
        else {
            // int min_largest=permutation_index;
            // for(int i=permutation_index-1; i<n; i++){
            //     if(nums[i]>nums[permutation_index-1] && nums[i]<nums[permutation_index])
            //         min_largest = i;
                    
            // }
            // swap(nums[min_largest], nums[permutation_index-1]);
            // reverse(nums.begin()+permutation_index, nums.end());

            for (int i = nums.size() - 1; i > permutation_index-1; i--) {
            // Swap the two
            if (nums[i] > nums[permutation_index-1]) {
                swap(nums[i], nums[permutation_index-1]);
                break;
            }
        }

        // Reverse the part after index
        reverse(nums.begin() + permutation_index, nums.end());
    
        }
        
    }
};