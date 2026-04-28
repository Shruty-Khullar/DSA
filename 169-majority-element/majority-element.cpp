class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // int avg = nums.size()/2;
        // int start=0, end=0;
        // int ans = nums[0];
        // int len=0;
        // for(int i=1;i<nums.size();i++){
        //     if(nums[i]==nums[start]){
        //         end++;
        //         len = max(len, end-start+1);
        //     }
        //     else {
        //         start=i;
        //         end=i;
        //     }
        //     if(len>avg){
        //         ans = nums[i];
        //         break;
        //     }
        // }
        // return ans;

        //Moorey's Voting Algorithm
        int maj_ele = nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==maj_ele){
                count++;
            } else {
                count--;
            }

            if(count==0){
                maj_ele = nums[i];
                count=1;
            }
        }
        return maj_ele;
    }
};