class Solution {
public:
    int countSubarrays(string s, int k){
        
        int left = 0, right = 0, odds = 0, count = 0;
        unordered_map<char, int> freq;
        for(int right = 0; right<s.size(); right++){
            freq[s[right]]++;
            while(freq.size()>k){
                freq[s[left]]--;
                if(freq[s[left]]==0)
                    freq.erase(s[left]);
                left++;
            }
            count = count + right - left + 1;
        }
        return count;
    }
    int numberOfSubstrings(string s) {
        int a = countSubarrays(s,3);
        int b = countSubarrays(s, 2);
        return a-b;
        
    }
};