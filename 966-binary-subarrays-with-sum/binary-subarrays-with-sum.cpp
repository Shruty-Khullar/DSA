class Solution {
public:
    int countWays(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int count = 0;
        int left = 0;
        int right = 0;
        int sum = 0;
        for(int right=0;right<nums.size();right++){
            sum += nums[right];
            while(sum>goal ){
                sum = sum - nums[left];
                left++;
            }
            count = count + right - left + 1; 
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sumLessEqualToGoal = countWays(nums, goal);
        int sumLessEqualGoalMinOne = countWays(nums, goal-1);
        return sumLessEqualToGoal - sumLessEqualGoalMinOne;
    }
};