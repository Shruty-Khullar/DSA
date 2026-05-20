class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left_sum = 0;
        for(int i=0;i<=k-1;i++){
            left_sum += cardPoints[i];
        }
        int max_sum = left_sum;
        int rightptr = cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
            left_sum = left_sum - cardPoints[i] + cardPoints[rightptr];
            rightptr--;
            max_sum = max(max_sum, left_sum);
        }
        return max_sum;
    }
};