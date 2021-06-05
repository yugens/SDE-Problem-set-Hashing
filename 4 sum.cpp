//Brute force approach with time complexity : o(n^3logn + nlogn) and space complexity : o(n)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        vector<int> ret;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    int x=target-(nums[i]+nums[j]+nums[k]);
                    ret.clear();
                    if (binary_search(nums.begin()+k+1,nums.end(), x))
                    {
                        ret.push_back(nums[i]);
                        ret.push_back(nums[j]);
                        ret.push_back(nums[k]);
                        ret.push_back(x);
                        v.push_back(ret);
                    }
                }
            }
        }
        set<vector<int>> s;
        for(auto it:v)
        {
            s.insert(it);
        }
        vector<vector<int>> v1;
        for(auto it:s)
            v1.push_back(it);
        
        return v1;
    }
};

//Optimised solution with time complexity : o(n^3) and space complexity : o(1)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
             int a=nums[i];
            for(int j=i+1;j<n;j++)
            {
                int x = target-(nums[i]+nums[j]);
                int l=j+1;
                int r=n-1;
                int b=nums[j];
                while(l<r)
                {
                    int c=nums[l];
                    int d=nums[r];
                    int twosum=c+d;
                    if(twosum<x)
                        l++;
                    else if(twosum>x)
                        r--;
                    else
                    {
                      ans.push_back({a,b,c,d});
                      while(l<r and nums[l]==c)
                          l++;
                      while(l<r and nums[r]==d)
                          r--;
                    }
                }
                 while (j + 1 < n && nums[j + 1] == b) 
                    j++;
        }
            while(i+1<n && nums[i+1]==a)
                i++;
        }
        return ans;
    }
};
