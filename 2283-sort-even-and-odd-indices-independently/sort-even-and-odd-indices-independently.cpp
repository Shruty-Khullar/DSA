class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        vector<int> even;
        vector<int> odd;
        for(int i=0;i<n;i++){
            if(i%2==0){
                even.push_back(nums[i]);
            } else {
                odd.push_back(nums[i]);
            }
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        reverse(odd.begin(), odd.end());
        int index1=0, index2=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                nums[i] = even[index1];
                index1++;
            } else {
                nums[i] = odd[index2];
                index2++;
            }
        }
        return nums;
    }
};