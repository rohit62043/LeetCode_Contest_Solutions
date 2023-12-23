// // 2967. Minimum Cost to Make Array Equalindromic-->Mean VS Median(sorted me median se diffrence kam hota hai)
// Approach
// We have to take median first and then check for the nearest possible palindrom of the median

// To find the possible palindrom, nearest to the median there are five cases need to check :

// case 1: one digit less nearest palindrom
// case 2: one digit more nearest palindrom
// case 3: simply take the mirror image of the left half
// case 4: take mirror image of the (left half + 1)
// case 5: take mirror image of the (left half - 1)
// You may check this : find-the-closest-palindrome
// finally just check the cost with all three palindrom and then take the minimum cost.

 long long minimumCost(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int median = (n %2 )?nums[n/2]: (nums[n/2] + nums[n/2 - 1])/2;
        //Find out possible palindroms
        vector<long long> pal;
        string t = to_string(median);

        pal.push_back(pow(10, t.size()-1) - 1); //case 1 : next palindrom with one digit less
        pal.push_back(pow(10, t.size()) + 1);   //case 2: next palindrom with one digit more
        
        //case 3: palidrom with just mirror image of the left half
        for(int i = 0; i < t.size()/2; ++i) t[t.size() - i - 1] = t[i];
        pal.push_back(stoll(t));
        
        //case 4: palidrom with mirror image of the left half with left half + 1 
        string pal_next = to_string(stoi(t.substr(0,(t.size()+1)/2)) + 1);
        string temp = pal_next;
        if(t.size()%2) pal_next = pal_next.substr(0, pal_next.size() - 1);
        reverse(pal_next.begin(), pal_next.end());
        pal.push_back(stoll(temp + pal_next));
        
        //case 5: palidrom with mirror image of the left half with left half - 1 
        string pal_prev = to_string(stoi(t.substr(0,(t.size()+1)/2)) - 1);
        temp = pal_prev;
        if(t.size()%2)  pal_prev = pal_prev.substr(0, pal_prev.size() - 1);
        reverse(pal_prev.begin(), pal_prev.end());
        pal.push_back(stoll(temp + pal_prev));
        
        //find the closest;
        long long cost=LLONG_MAX;
        for(auto p:pal){
            long long sum=0;
            for(auto v:nums){
                sum+=abs(p-v);
            }
            cost=min(cost,sum);
        }
        
        return cost;
    }

// Similar Question-->564. Find the Closest Palindrome
 string nearestPalindromic(string n) {
    //Find out possible palindroms
    vector<long long> pal;
    string t = n;

    pal.push_back(pow(10, t.size()-1) - 1); //case 1 : next palindrom with one digit less
    pal.push_back(pow(10, t.size()) + 1);   //case 2: next palindrom with one digit more
    
    //case 3: palidrom with just mirror image of the left half
    for(int i = 0; i < t.size()/2; ++i) t[t.size() - i - 1] = t[i];
    pal.push_back(stoll(t));
    
    //case 4: palidrom with mirror image of the left half with left half + 1 
    string pal_next = to_string(stoi(t.substr(0,(t.size()+1)/2)) + 1);
    string temp = pal_next;
    if(t.size()%2) pal_next = pal_next.substr(0, pal_next.size() - 1);
    reverse(pal_next.begin(), pal_next.end());
    pal.push_back(stoll(temp + pal_next));
    
    //case 5: palidrom with mirror image of the left half with left half - 1 
    string pal_prev = to_string(stoi(t.substr(0,(t.size()+1)/2)) - 1);
    temp = pal_prev;
    if(t.size()%2)  pal_prev = pal_prev.substr(0, pal_prev.size() - 1);
    reverse(pal_prev.begin(), pal_prev.end());
    pal.push_back(stoll(temp + pal_prev));
    
    sort(pal.begin(),pal.end());
    //find the closest;
    long long ans;
    long long num=stoll(n);
    long long diff=LLONG_MAX;
    for(auto p: pal){
        long long sum =p;
        if(abs(sum-num)<diff && abs(sum-num)!=0){
            diff=abs(sum-num);
            ans=sum;
        }
        
    }

    return to_string(ans);
    }