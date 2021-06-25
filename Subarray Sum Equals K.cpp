class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    int sum=0,ans=0;
    int n=nums.size();
    unordered_map<int,int> mp;
    mp.insert({0,1});
   for(int i=1;i<=n;i++)
   {
       sum+=nums[i-1];
      if(mp.find(sum-k)!=mp.end())
       {
           ans+=mp[sum-k];
       }
       mp[sum]++;
   }
   return ans;  
    }
};
