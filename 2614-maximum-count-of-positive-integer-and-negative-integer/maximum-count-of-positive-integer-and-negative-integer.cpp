class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int x=0;
        int y=0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]>0){
        //         x++;
        //     }else if(nums[i]<0){
        //         y++;
        //     }
        // }

        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]<=0){
                low = mid+1;
            }else{
                if(mid>0 && nums[mid-1]>0){
                    high = mid - 1;
                }else{
                    x = nums.size()-mid;
                    break;
                }
            }
        }

         low = 0;
         high = nums.size()-1;

        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]>=0){
                high = mid-1;
            }else{
                if(mid + 1 < nums.size()  && nums[mid+1]<0){
                    low = mid + 1;
                }else{
                    y = mid+1;
                    break;
                }
            }
        }

        return max(x,y);
    }
};