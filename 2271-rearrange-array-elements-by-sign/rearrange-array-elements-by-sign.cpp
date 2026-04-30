class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums2;
        vector<int> nums3;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                nums2.push_back(nums[i]);
            }
            else {
                nums3.push_back(nums[i]);
            }
        }
        int j=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                nums[i]=nums2[j];
                j++;
            }
        }
        j=0;
        for(int i=0;i<n;i++){
            if(i%2!=0){
                nums[i]=nums3[j];
                j++;
            }
        }

        return nums;
    }
};