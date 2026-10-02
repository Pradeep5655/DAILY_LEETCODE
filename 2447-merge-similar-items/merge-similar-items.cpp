class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        int n1 = items1.size();
        int n2 = items2.size();
        map<int,int> mp;
        
        vector<vector<int>> ans;
        // for(int i=0;i<n2;i++){
        //     for(int j=0;j<n1;j++){
        //         if(items1[i][0]==items2[j][0]){
        //             vector<vector<int>> temp = {{items2[i][0],items2[i][1]+items1[j][1]}};
        //             ans.push_back(temp[0]);
        //             temp.clear();
        //         }else{
        //             ans.push_back(items1[i]);
        //         }
        //     }
        // }

        for(auto x:items1){
            mp[x[0]] += x[1];
        }

        for(auto x:items2){
            mp[x[0]] += x[1];
        }

        for (auto it = mp.begin(); it != mp.end(); it++) {
    ans.push_back({it->first, it->second});
}
        return ans;
    }
};