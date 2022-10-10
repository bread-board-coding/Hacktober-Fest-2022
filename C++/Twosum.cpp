vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mymap;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            mymap[nums[i]]=i;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            int x=target-nums[i];
             
            if(mymap.count(x)>0)
            {
                if(i!=mymap[x])
                {
                    ans.push_back(i);
                    ans.push_back(mymap[x]);
                    return ans;
                }
            }
        }
        
        return ans;
    }