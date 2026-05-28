class Solution {
public:
    // void rotate(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     k = k%n;
    //     vector<int> temp(k);
    //     int index=0;
    //     // for(int i=n-k;i<n;i++){
    //     //     temp[index] = nums[i];
    //     //     index++;
    //     // }
    //     for(int i=0; i<k;i++){
    //         temp[i] = nums[n-k+i];
    //     }
    //     for(int i=n-1; i>=k;i--){
    //         nums[i] = nums[i-k];
    //     }
    //     for(int i=0;i<temp.size();i++){
    //         nums[i] = temp[i];
    //     }
        
    // }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        // reverse(nums.begin(), nums.begin()+n-k);
        // reverse(nums.begin()+n-k, nums.end());
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end()-n+k);
        reverse(nums.begin()+k, nums.end());
        
    }
};