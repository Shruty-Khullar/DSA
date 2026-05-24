class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int idx = -1;
        while(low<=high){
            int mid = (high+low)/2;
            if(nums[mid]==target){
                idx = mid;
                break;
            } else if (nums[mid]>target){
                high = mid-1;
            } else 
                low = mid+1;
        }
        return idx!=-1 ? idx : low;
    }
};