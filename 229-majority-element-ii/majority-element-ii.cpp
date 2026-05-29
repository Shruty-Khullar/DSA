class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0;
        int cnt2=0;
        int elem1 = INT_MIN;
        int elem2 = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(cnt1==0 && nums[i]!=elem2){
                cnt1=1;
                elem1=nums[i];
            } else if(cnt2==0 && nums[i]!=elem1){
                cnt2=1;
                elem2=nums[i];
            } else if(elem1==nums[i]) cnt1++;
            else if(elem2==nums[i]) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0,cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==elem1) cnt1++;
            if(nums[i]==elem2) cnt2++;
        }
        int mini = nums.size()/3 + 1;
        vector<int> ans;
        if(cnt1>=mini) ans.push_back(elem1);
        if(cnt2>=mini) ans.push_back(elem2);
        return ans;
        
        
    }
};