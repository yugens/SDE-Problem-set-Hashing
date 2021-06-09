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


//
