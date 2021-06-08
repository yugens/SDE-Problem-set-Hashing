//Brute force approach having time complexity o(nlogn)+o(n) and space complexity o(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==0 or n==1)
            return n;
       int count=0,ans=0;
       for(int i=1;i<n;i++)
       {
           if(nums[i]==nums[i-1]+1)
               count++;
           else if(nums[i]==nums[i-1])
               continue;
           else
               count=0;
           ans=max(ans,count);
       }
            return ans+1;
    }
};

//Optimised approach using Hash set having time complexity o(n)+o(n)+o(n) and space complexity o(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int n=nums.size();
        int ans=0;
       set<int> st;
       for(int i=0;i<n;i++)
       {
           st.insert(nums[i]);
       }
       for(int i=0;i<n;i++)
       {
           int ele=nums[i]-1;
          if(st.find(ele)==st.end())
          {
              int currele=nums[i];
              int count=0;
              while(st.find(currele)!=st.end())
              {
                  currele+=1;
                  count+=1;
              }
          ans=max(ans,count);
          }
       }
        return ans;
    }
};
