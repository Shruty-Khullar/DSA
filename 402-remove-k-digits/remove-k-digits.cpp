class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> s;
        for(int i=0;i<num.size();i++){
            while(!s.empty() && num[i]<s.top() && k>0){
                s.pop();
                k--;
                if(k==0)
                    break;
            }
            s.push(num[i]);
        }
        while(!s.empty() && k>0){
            s.pop();
            k--;
        }
        string new1 = "";
        while(!s.empty()){
            new1+= s.top();
            s.pop();
        }
         
        reverse(new1.begin(), new1.end());
        int i =0;
        while(!new1.empty() && new1[i]=='0'){
            i++;
        }
        new1 = new1.substr(i);
        if(new1=="")
            return "0";
        return new1;
    }
};

    