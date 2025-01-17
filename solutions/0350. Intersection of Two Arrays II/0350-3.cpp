class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size())
      return intersect(nums2, nums1);

    vector<int> ans;
    int lowerBound = 0;  // Lower bound for the binary search

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    for (const int num : nums1) {
      const int i = binarySearch(nums2, lowerBound, num);
      if (i < nums2.size() && nums2[i] == num) {
        ans.push_back(num);
        lowerBound = i + 1;
      }
    }

    return ans;
  }

 private:
  // Performs binary search on the bigger array.
  // Finds the first index l s.t nums2[l] >= target.
  int binarySearch(vector<int>& nums2, int lo, int target) {
    int l = lo;
    int r = nums2.size();

    while (l < r) {
      const int m = (l + r) / 2;
      if (nums2[m] >= target)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }
};
