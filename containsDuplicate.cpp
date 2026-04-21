class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Create a hashmap, then check the hashmap each time,
        unordered_map<int, int> Occurences;

        // Iterate through the array, and adding to the hash map frequency for each element
        // If it already exists, then we exit
        // otherwise return false.

        for(int i{0}; i < nums.size(); i++){
            if(Occurences.contains(nums[i])){
                return true;
            }
            Occurences[nums[i]] = 1;
        }

        //O(n) time, O(n) memory

        return false;
    }
};
