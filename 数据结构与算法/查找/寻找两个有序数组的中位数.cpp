using namespace std;
class Solution {
public:
    //先用lowerbound找左侧的中位数，在用upper找右侧的中位数，加起来求均值即可
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       // for(auto &i:nums1) i*=2;
       // for(auto &i:nums2) i*=2;
        int n=nums1.size();
        int m=nums2.size();
        int l,r;
        if(n){ 
			l=nums1[0],r=nums1[n-1]; 
			if(m) l=min(nums1[0],nums2[0]),r=max(nums1[n-1],nums2[m-1]);
		}
		else l=nums2[0],r=nums2[m-1];
		int p1=l,p2=r;
        while(l<r){
            int mid=l+r+1>>1;
            int cnt1=(lower_bound(nums1.begin(),nums1.end(),mid)-nums1.begin())+(lower_bound(nums2.begin(),nums2.end(),mid)-nums2.begin());
            //int cnt2=(nums1.end()-upper_bound(nums1.begin(),nums1.end(),mid))+(nums2.end()-upper_bound(nums2.begin(),nums2.end(),mid));
            if(cnt1>(n+m)/2) r=mid-1;
            else l=mid;
        }
        double jk=l;
        l=p1,r=p2;
        while(l<r){
            int mid=l+r>>1;
            //int cnt1=(lower_bound(nums1.begin(),nums1.end(),mid)-nums1.begin())+(lower_bound(nums2.begin(),nums2.end(),mid)-nums2.begin());
            int cnt2=(nums1.end()-upper_bound(nums1.begin(),nums1.end(),mid))+(nums2.end()-upper_bound(nums2.begin(),nums2.end(),mid));
            if(cnt2>(n+m)/2) l=mid+1;
            else r=mid;
        }
        jk+=l;
        return jk/2;
    }
}x;
int main(){
	vector<int>a={};
	vector<int> b={2,3};
	cout<<x.findMedianSortedArrays(a,b);
}