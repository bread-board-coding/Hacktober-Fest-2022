int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        
        int maxArea=0;
        while(i<j)
        {
            int minheight=min(height[i],height[j]);
            int width=j-i;
            int area=minheight*width;
            if(maxArea<area)
                maxArea=area;
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        
        return maxArea;
    }