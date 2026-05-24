class Solution {
public:
    int lowerBound(vector<int>& nums, int target){
        int low =0, high = nums.size()-1;
        int idx = high;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>=target){
                idx = mid;
                high = mid-1;
            } else {
                low=mid+1;
            }
        }
        return idx;
    }
    int upperBound(vector<int>& nums, int target){
        int low =0, high = nums.size()-1;
        int idx = high+1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>target){
                idx = mid;
                high = mid-1;
            } else {
                low=mid+1;
            }
        }
        return idx;
    }
    vector<int> searchRange(vector<int>& nums, int target) { 
        vector<int> ans(2,-1);
        if(nums.size()==0)
            return ans;
        int first = lowerBound(nums, target);
        if(nums[first]!=target)
            return ans;
        ans[0] = first;
        ans[1] = upperBound(nums, target) - 1;
        return ans;
        
    }
};