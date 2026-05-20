class Solution {
public:
    int countSubarrays(vector<int>& nums, int k){
        int left = 0, right = 0, odds = 0, count = 0;
        for(int right = 0; right<nums.size(); right++){
            if(nums[right]%2!=0)
                odds++;
            while(odds>k){
                if(nums[left]%2!=0)
                    odds--;
                left++;
            }
            count = count + right - left + 1;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int sum = 0;
        int lessThanK = countSubarrays(nums, k);
        int lessThanKMinusOne = countSubarrays(nums, k-1);
        return lessThanK - lessThanKMinusOne;
     
    }
};