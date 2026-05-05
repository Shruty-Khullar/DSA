class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // int n = nums.size();
        // if(n==0)
        //     return 0;
        // sort(nums.begin(), nums.end());
        // int max_length=0;
        // int currSeq=1;
        // for(int i=1;i<n;i++){
        //     if(nums[i]-nums[i-1]==1){
        //         currSeq++;
        //     } else if(nums[i]-nums[i-1]==0) {
        //         continue;
        //     } else {
        //         currSeq=1;
        //     }
        //     max_length=max(max_length, currSeq);
        // }
        // max_length=max(max_length, currSeq);
        // return max_length;
        int max_len=0, subseqLen=0;
        unordered_set<int> s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        for(auto itr: s){
            if(s.find(itr-1)!=s.end()){
                continue;
            } else {
                subseqLen++;
                int num = itr;
                while(s.find(num+1)!=s.end()){
                    subseqLen++;
                    num=num+1;
                }
            }
            max_len=max(max_len, subseqLen);
            subseqLen=0;
        }
        return max_len;

    }
};