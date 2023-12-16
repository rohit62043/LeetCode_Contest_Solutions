// 2956_FindCommonElementsBetweenTwoArrays
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1;
        unordered_set<int> st2;
        
        for(auto x: nums1){
            st1.insert(x);
        }
        for(auto x: nums2){
            st2.insert(x);
        }
        
        int count1=0;
        for(auto x:nums1){
            if(st2.find(x)!=st2.end()){
                count1++;
            }
        }
        int count2=0;
        for(auto x:nums2){
            if(st1.find(x)!=st1.end()){
                count2++;
            }
        }
        
        return {count1,count2};
    }
};