// 2961. Double Modular Exponentiation'
class Solution {
public:
    int myPow(int n, int exp,int x)
{
    int result = 1;
    for (; exp > 0; exp--)
        result =((result%x)*(n%x))%x;

    return result;
}
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        for(int i=0;i< variables.size();i++){
            int ai=variables[i][0];
            int bi=variables[i][1];
            int ci=variables[i][2];
            int mi=variables[i][3];
            int temp1=(myPow(ai,bi,10))%10;
            int t=myPow(temp1,ci,mi)%mi;
            if(t==target){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};