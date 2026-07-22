// Problem Link: https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/description/

// Solution: This problem is solved using the meet-in-the-middle approach. 

// Time Complexity: O(2^(n/2) * n)

// Space Complexity: O(2^(n/2))


class Solution {
public:
    int sum=0,n,ans;
    vector<vector<int>>left,right;
    void rec(vector<int>& nums,int cnt,int i,int end,int s,vector<vector<int>>& temp)
    {
        if(i==end)
        {
            temp[cnt].push_back(s);
            return ;
        }
        if(cnt<end)
        {
            rec(nums,cnt+1,i+1,end,s+nums[i],temp);
        }
        rec(nums,cnt,i+1,end,s,temp);
    }



    int minimumDifference(vector<int>& nums) {
        n=nums.size()/2;
        ans=INT_MAX;
        for(auto i:nums)
            sum+=i;
        left.assign(n+1,{});
        right.assign(n+1,{});
        rec(nums,0,0,n,0,left);
        rec(nums,0,n,2*n,0,right);
        
        for(auto &i:left)
            sort(i.begin(),i.end());
        for(auto &i:right)
            sort(i.begin(),i.end());
        
        for(int i=0;i<=n;i++)
        {
            int rem=n-i;
            for(int k=0;k<left[i].size();k++){
                int target = sum/2-left[i][k];
                int j=lower_bound(right[rem].begin(),right[rem].end(),target)-right[rem].begin();
                if(j==right[rem].size())
                {
                    j--;
                }
                int fsum=left[i][k]+right[rem][j];
                int ssum=sum-fsum;
                ans=min(ans,abs(ssum-fsum));
            }
        }
        return ans;
    }
};