class Solution {
public:
    int bestClosingTime(string customers){
        int n=customers.length();
        int pen=0;
        for(int i=0;i<n;i++){
            if(customers[i]=='Y') pen+=1;
        }
        int minpen=pen;
        int idx=0;
        for(int j=0;j<n;j++){
            if(customers[j]=='Y') pen-=1;
            else pen+=1;
            if(pen<minpen){
                minpen=pen;
                idx=j+1;
            }
        }
        return idx;
    }
};