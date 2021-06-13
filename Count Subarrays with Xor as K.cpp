//Brute force approach using Kadane's Algorithm having time complexity O(n^2) and space complexity o(1)
int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    int count=0;
    for(int i=0;i<n;i++)
    {
        int xorsum=0;
        for(int j=i;j<n;j++)
        {
            xorsum=xorsum^A[j];
            if(xorsum==B)
            count++;
        }
    }
    return count;
}


//Optimised approach having time complexity o(nlog(n)) and space complexity o(n)
int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    int count=0;
    int Xor=0;
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        Xor=A[i]^Xor;
        if(Xor==B)
        count++;
        int y=Xor^B;
        if(mp.find(y)!=mp.end())
        count+=mp[y];
        mp[Xor]+=1;
    }
    return count;
}

