#include <vector>
#include <iostream>
#include <unordered_map>

class Solution1 {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int,int> ump;
        std::vector<int> res;
        for (int i=0;i<nums2.size();i++) ump[nums2[i]]=i;
        for (int i=0;i<nums1.size();i++) {
            auto it = ump.find(nums1[i]);
            if (it!=ump.end()) res.push_back(it->second);
        }
        return res;
    }
};