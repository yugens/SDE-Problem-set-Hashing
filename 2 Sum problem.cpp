//Brute force approach having time complexity o(n^2) and space complexity o(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        int n= nums.size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]==(target-nums[i]))
                {
                    v.push_back(i);
                    v.push_back(j);
                }
            }
        }
        return v;
        
    }
};

//Optimsed solution having time complexity o(n) and space complexity o(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(mp.find(target-nums[i])!=mp.end())
            {
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]]=i;
        }
        
        return ans;
    }
};
