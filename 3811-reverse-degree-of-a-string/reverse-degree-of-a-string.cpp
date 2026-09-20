class Solution {
public:
    int reverseDegree(string s) {
        int n = 0;
        for(int i=0;i<s.size();i++){
            if((s[i]-123)<0){
            n += (s[i]-123)*(i+1)*(-1);
            }else{
               n+= (s[i]-123)*(i+1);
            }
        }
        return n;
    }
};