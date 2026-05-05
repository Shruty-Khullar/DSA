class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        sort(nums.begin(), nums.end());
        int max_length=0;
        int currSeq=1;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]==1){
                currSeq++;
            } else if(nums[i]-nums[i-1]==0) {
                continue;
            } else {
                max_length=max(max_length, currSeq);
                currSeq=1;
            }
        }
        max_length=max(max_length, currSeq);
        return max_length;
    }
};