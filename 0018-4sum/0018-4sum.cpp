//Handled duplicates inside the two-pointer while loop.
//O(n^3)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();

        if (n < 4) return result;

        for (int i = 0; i < n - 3; ++i) {
            // Avoid duplicate numbers in the 1st position
            if (i > 0 && nums[i] == nums[i-1]) continue;

            for (int j = i + 1; j < n - 2; ++j) {
                // Avoid duplicate numbers in the 2nd position
                if (j > i + 1 && nums[j] == nums[j-1]) continue;

                int left = j + 1, right = n - 1;
                while (left < right) {
                    long long int sum = static_cast<long long int>(nums[i]) + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});//directly added to the result once a quadruplet is found. (Better than using set)
                        // Avoid duplicate numbers in the 3rd and 4th positions
                        while (left < right && nums[left] == nums[left + 1]) ++left;
                        while (left < right && nums[right] == nums[right - 1]) --right;
                        ++left; --right;
                    } else if (sum < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }
        return result;
    }
};
