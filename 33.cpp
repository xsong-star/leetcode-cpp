#include <vector>
#include <iostream>
using namespace std;

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0,r = n-1;
    while(l<=r)
    {
        int mid = l + (r-l)/2;
        if(nums[l] == target)
            return l;
        if(nums[r] == target)
            return r;
        if(nums[mid] == target)
            return mid;
        if(nums[0]<nums[mid])
        {
            if(nums[0]<=target && target < nums[mid])
            {
                r = mid-1;
            } 
            else
            {
                l = mid+1;
            }
        }
        else
        {
            if(target<=nums[n-1]&&nums[mid]<target)
            {
                l = mid+1;
            }
            else
            {
                r = mid - 1;
            }
        }
        
    }
    return -1;
}
int main()
{
    vector<int> nums{4,5,6,7,0,1,2};
    cout << search(nums,6) << endl;
    return 0;
}