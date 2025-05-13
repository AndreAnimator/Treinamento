class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int mindex = m - 1;
        int nindex = n - 1;
        int right = m + n - 1;

        while(nindex >= 0){
            if(mindex >= 0 && nums1[mindex] > nums2[nindex]){
                nums1[right] = nums1[mindex];
                mindex -= 1;
            } else{
                nums1[right] = nums2[nindex];
                nindex -= 1;
            }
            right -= 1;
        }
    }
};