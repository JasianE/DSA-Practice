class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> entryLookupTable;

        // 1. sort all the entries in the array
        for(int i{0}; i< strs.size(); i++){
            string copy = strs[i];
            sort(copy.begin(), copy.end());
            
            vector<int> referenceToEntry = entryLookupTable[copy];
            referenceToEntry.push_back(i);
            entryLookupTable[copy] = referenceToEntry;
            
        }

        // 2. Add entries that correspond to anagrams to string array

        vector<vector<string>> anagrams; 

        for( auto key : entryLookupTable){
            vector<string> entry;
            
            for(int i {0}; i < key.second.size(); i++){
                entry.push_back(strs[key.second[i]]);
            }
            anagrams.push_back(entry);
        }

        return anagrams;
    }
};
