int longestSubarray(vector<int>& nums, int limit) {
        int l=0,n=nums.size(),min;
        deque<int> dq_max,dq_min;
        int  ans=0;
        for(int i=0;i<n;i++)
        {
            while(!dq_max.empty()&&nums[dq_max.back()]<nums[i])
            {
                dq_max.pop_back();
            }
             while(!dq_min.empty()&&nums[dq_min.back()]>nums[i])
            {
                dq_min.pop_back();
            }
            dq_max.push_back(i);
            dq_min.push_back(i);
            while(l<i&&!dq_max.empty()&&!dq_min.empty()&&nums[dq_max.front()]-nums[dq_min.front()]>limit)
             {
                 // th them vao lam thay doi min thi phai pop deque max ra 
                 if(dq_max.front()==l)
                 {
                     dq_max.pop_front();
                 }

		 // th them vao lam thay doi max thi phai pop deque min ra 
		if(dq_min.front()==l)
                 {
                     dq_min.pop_front();
                 }
		
		l++;
             }
	     ans=max(ans,i-l+1);
        }return ans;
    }