class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int max_ele = arr[n-1];
        int temp;
        for(int i=n-2;i>=0;i--){
            temp=arr[i];
            arr[i]=max_ele;
            max_ele=max(max_ele, temp);
        }
        arr[n-1]=-1;
        return arr;
    }
};