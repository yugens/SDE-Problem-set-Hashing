// Brute force approach using Kadane's Algorithm having time complexity o(n^2) and space complexity o(1)
int maxLen(int A[], int n)
{
    // Your code here
    int sum=0,ans=0;
    for(int i=0;i<n;i++)
    {
        sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=A[j];
            if(sum==0)
            ans=max(ans,j-i+1);
        }
    }
    return ans;
}

//Optimsed Approach using Hash map having time complexity o(nlog n) and space complexity o(n)
int maxLen(int A[], int n)
{
    // Your code here
   int sum=0,ans=0;
   unordered_map<int,int> mp;
   for(int i=1;i<=n;i++)
   {
       sum+=A[i-1];
       if(sum==0)
       ans=max(ans,i);
       else if(mp.count(sum)==0)
       mp[sum]=i;
       else
       {
           int it=mp[sum];
           ans=max(ans,i-it);
       }
   }
   return ans;
}
