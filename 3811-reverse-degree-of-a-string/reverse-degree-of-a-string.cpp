class Solution {
public:
    int reverseDegree(string s) {
        vector<int> x;
        for(int i=0;i<s.size();i++){
            if((s[i]-123)<0){
            x.push_back((s[i]-123)*(i+1)*(-1));
            }else{
                x.push_back((s[i]-123)*(i+1));
            }
        }
    // accumulate(x.begin(),x.end(),0)
        return accumulate(x.begin(),x.end(),0);
    }
};