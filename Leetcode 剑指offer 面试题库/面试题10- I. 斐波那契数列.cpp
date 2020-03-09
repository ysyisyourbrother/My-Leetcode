class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int* contain = new int[n+1];
        contain[0] = 0;
        contain[1] = 1;
        for(int i = 2;i<n;i++)
        {
            contain[i]=(contain[i-1]+contain[i-2])%int(1e9+7);
        }
        return contain[n-1];
    }
};