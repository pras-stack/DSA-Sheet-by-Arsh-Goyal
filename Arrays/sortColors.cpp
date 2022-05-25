/* Approach (Using counting sort)
Use three counter variables to keep track of the count of total 0’s , 1’s and 2’s which will take a time complexity of O(n).
Now again traverse the array and put the array elements in order by using the counter variable , so again time complexity is O(n)
So total time complexity - O(2n) which means it is done in two passes.
Space Complexity - O(1)  */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 =0, count1=0, count2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                count0++;
            else if(nums[i]==1)
                count1++;
            else
                count2++;
        }
        
        int i=0;
        while(count0>0)
        {
            nums[i++]=0;
            count0--;
        } 
        
        while(count1>0)
        {
            nums[i++]=1;
            count1--;
        }
        
        while(count2>0)
        {
            nums[i++]=2;
            count2--;
        }
        
    }
};


/* Approach 2 (Using the concept of “The Dutch National Flag” problem)

Now this approach is basically based on the concept of The Dutch National Flag Problem.
This is basically an approach where we divide our array into partitions which are :
1. array[0 to low-1] = 0 is present
2. array[low to mid-1] = 1 is present
3. array[mid to high-1] = unknown
4. array[high to n(size of array)] = 2 is present
I have attached a few links and resources for your better understanding. */
Code :
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
                mid++;
            
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
Whenever I see 0, I swap it with element present at low position.
When I get 1, I just let it be and when i encounter 2 I swap it with element at high position. 
Similarly I keep incrementing and decrementig the variables - high, low and mid. 
