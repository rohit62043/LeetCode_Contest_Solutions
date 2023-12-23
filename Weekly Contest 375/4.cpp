// 2963. Count the Number of Good Partitions

class Solution {
public:
    int mod=1000000007;
    int numberOfGoodPartitions(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }

        int i=0;
        int j=0;
        j=max(j,mp[nums[i]]);
        int ans=1;
        while(i<nums.size()){
            if(i>j){
                ans=(ans*2)%mod;
            }
            j=max(j,mp[nums[i]]);
            i++;
        }
        return ans;
    }
};