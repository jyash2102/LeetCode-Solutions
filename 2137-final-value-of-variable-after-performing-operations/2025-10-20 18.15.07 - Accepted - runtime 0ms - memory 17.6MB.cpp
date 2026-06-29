class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
       int n = operations.size();
        int value=0;
        for(int i=0;i<n;i++){
            if(operations[i]=="--X" || operations[i]=="X--") value--;
            else value++;
        } 
        return value;
    }
};