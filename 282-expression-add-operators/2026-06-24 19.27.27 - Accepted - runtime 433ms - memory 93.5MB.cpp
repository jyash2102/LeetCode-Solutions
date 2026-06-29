class Solution {
public:
    void recur(int idx,long currval,long prevnum,string s,vector<string>& ans,string num, int target){
        if(idx==num.length()){
            if(currval==target) ans.push_back(s);
            return;
        }
        for(int i=idx;i<num.length();i++){
            if(i!=idx && num[idx]=='0') break;
            string str=num.substr(idx,i-idx+1);
            long curr=stol(str);
            if(idx==0) recur(i+1,curr,curr,s+str,ans,num,target);
            else{
                recur(i+1,currval+curr,curr,s+"+"+str,ans,num,target);
                recur(i+1,currval-curr,-curr,s+"-"+str,ans,num,target);
                recur(i+1,(currval-prevnum)+(prevnum*curr),prevnum*curr,s+"*"+str,ans,num,target);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        recur(0,0,0,"",ans,num,target);
        return ans;
    }
};