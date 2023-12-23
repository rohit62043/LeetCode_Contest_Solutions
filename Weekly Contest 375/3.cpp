// 2962. Count Subarrays Where Max Element Appears at Least K Times
 long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int s=0;
        int e=0;
        int count=0;
        int maxi=INT_MIN;
        for(auto x:nums){
            maxi=max(maxi,x);
        }
        
        long long ans=0;
        int tempS=0;
        while(e<nums.size()){
            if(nums[e]==maxi){
                count++;
                if(count>=k){
                    ans+=n-e;
                }
            }
            while(count>=k && s<=e){
                if(nums[s]==maxi){
                    count--;
                }
                if(count>=k){
                    ans+=n-e;
                }
                s++;
            }
            e++;
        }
       
        return ans;
    }