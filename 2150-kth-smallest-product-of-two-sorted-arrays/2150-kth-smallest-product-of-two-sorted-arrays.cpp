class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long ans = 0;
        int n = nums1.size(), m = nums2.size();

        long long l = -1e10, r = 1e10;

        while(l <= r) {
            long long mid = (r-l)/2 + l;
            long long sum = 0;

            for(int i=0; i<n; i++) {
                if(nums1[i] == 0) {
                    if(mid >= 0) sum += m;
                }
                else if(nums1[i] > 0) {
                    long long p = mid / nums1[i];
                    if(mid < 0 && mid % nums1[i] != 0) p--;     
                    sum += upper_bound(nums2.begin(), nums2.end(), p) - nums2.begin();
                }
                else { 
                    long long p = mid / nums1[i];
                    if(mid < 0 && mid % nums1[i] != 0) p++;          
                    sum += nums2.end() - lower_bound(nums2.begin(), nums2.end(), p);
                }
            }

            if(sum >= k) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
