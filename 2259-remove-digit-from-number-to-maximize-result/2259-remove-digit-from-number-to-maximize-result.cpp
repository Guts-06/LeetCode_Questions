class Solution {
public:
    string removeDigit(string number, char digit) {
        int k=0;
        for(int i=0;i<number.size();i++){
            if(number[i]==digit){
                k=i;
                if(number[i+1]>number[i]){
                    break;
                }
            }
            }
            number.erase(k,1);
            return number;
        }
    
};