// 2965. Find Missing and Repeated Values
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int n=grid.size();
            int m=grid[0].size();
            vector<int> check(n*n,0);
        
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    check[grid[i][j]-1]++;
                }
            }
        vector<int> ans;
        for(int i=0;i<n*n;i++){
            if(check[i]==2){
                ans.push_back(i+1);
            }
        }
        for(int i=0;i<n*n;i++){
            if(check[i]==0){
                ans.push_back(i+1);
            }
        }
             
        return ans;
    }
};