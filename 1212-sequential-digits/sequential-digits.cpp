class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        vector<int> numb={1,2,3,4,5,6,7,8,9};
        string l=to_string(low);
        int n = l.length();
        string num;
        for(int i=1;i<=n;i++) num.push_back('0'+i);
        string orig=num;
        int end=n-1;
        while(end<9){
            int i=0;
            int j=end;
            while(j<9){
                if(stoi(num)>=low && stoi(num)<=high) ans.push_back(stoi(num));
                i++;
                j++;
                num.erase(0,1);
                if(j<9) num.push_back('0'+numb[j]);
               
            }
            end++;
            num=orig;
            if(end<9) num.push_back('0'+numb[end]);
            orig=num;
        }
        return ans;
    }
    
};