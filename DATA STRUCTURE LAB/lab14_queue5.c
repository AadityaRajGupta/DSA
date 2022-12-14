class Solution {
public:
    int recursion(vector<int>& nums,int a,vector<int>& dat)
    {
        if (a>=nums.size())
            return 0;
        if (dat[a]!=-1)
            return dat[a];
        int p=recursion(nums,a+2,dat)+nums[a];
        int n=recursion(nums,a+1,dat);

        dat[a]=max(p,n);

        return dat[a];
    }
    int rob(vector<int>& nums) {
        vector<int> dat(nums.size(),-1);
        return recursion(nums,0,dat);
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int c=0,p=0,n=0;
        for(int i=0;i<nums.size();i++)
        {
            n=max(c,p+nums[i]);
            p=c;
            c=n;
        }
        return c;
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int N=nums.size();
        int dat[N+1];

        dat[0]=0;
        dat[1]=nums[0];

        for (int i=2;i<=N;i++)
            dat[i]=max(dat[i-1],dat[i-2]+nums[i-1]);
        return dat[N];
    }
};