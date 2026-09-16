class Solution {
public:

    bool check(vector<int>& bloomDay, int m, int k, int days){
            int n = bloomDay.size();
            int ct = 0;
            int bqt = 0;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=days){
                    ct++;
                    if(ct==k){
                        bqt++;
                        ct = 0;
                    }
                }else{
                        ct = 0;
                    }
            }
            return bqt>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n =1LL * m*k;
        if(n>bloomDay.size()) return -1;

        int maxi = *max_element(bloomDay.begin(),bloomDay.end());
        int mini = *min_element(bloomDay.begin(),bloomDay.end());

        int low  = mini;
        int high = maxi;
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(bloomDay,m,k,mid)){
                ans = mid;
                high = mid-1;
            } else{
                low = mid +1;
            } 
        }

        return ans;
    }
};