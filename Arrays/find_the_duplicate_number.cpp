/* Approach 1 : Sorting -> Sort the array. If there is any duplicate element they will be adjacent. 
So we simply check if arr[i]= arr[i+1]. If it is true , then  we return  arr[i].
Time Complexity:O(Nlogn + N)

Reason: NlogN for sorting the array and O(N) for traversing through the array and checking if adjacent elements are equal or not.
But this will distort the array.

Space Complexity:O(1) */

#include <bits/stdc++.h>

using namespace std;

int findDuplicate( vector<int> arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for(int i=0; i<n-1; i++)
    {
        if(arr[i]= arr[i+1])
        {
            return arr[i];
        }
    }
    
}

int main()
{
    vector<int> arr;
    arr = {1,3,4,2,2};
  cout << "The duplicate element is " << findDuplicate(arr) << endl;

    return 0;
}


/*Approach 2: Using two ptr.
Time complexity: O(N). Since we traversed through the array only once.
Space complexity: O(1). */

#include <bits/stdc++.h>

using namespace std;

int findDuplicate( vector<int> &nums)
{
    int slow = nums[0];
  int fast = nums[0];
  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow != fast);
  fast = nums[0];
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }
  return slow;
    
}

int main()
{
    vector<int> arr;
    arr = {1,3,4,2,2};
  cout << "The duplicate element is " << findDuplicate(arr) << endl;

    return 0;
}
