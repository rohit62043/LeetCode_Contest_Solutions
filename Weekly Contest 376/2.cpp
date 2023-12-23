// 2966. Divide Array Into Arrays With Max Difference
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n%3!=0){
             vector<vector<int>> an;
                    return an;
        }
        vector<vector<int>> ans;
        int i=0;
        while(i<n){
            int a=2;
            vector<int> temp;
            while(a>=0){
                temp.push_back(nums[i++]);
                a--;
            }
            ans.push_back(temp);
        }
        
        for(int j=0;j<ans.size();j++){
           if((abs(ans[j][0]-ans[j][1])<=k) && (abs(ans[j][0]-ans[j][2])<=k) && (abs(ans[j][1]-ans[j][2])<=k)){
               continue;
           }
            else{
                vector<vector<int>> an;
                    return an;
            }
        }
        
        return ans;
    }
};