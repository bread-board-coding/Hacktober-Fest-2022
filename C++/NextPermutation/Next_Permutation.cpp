//The next permutation of an array of integers is the next lexicographically greater permutation of its integer
// Input: nums = [1,2,3]
// Output: [1,3,2]


#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{

  int n = nums.size();

  int idx = -1;

  for (int i = n - 1; i > 0; i--)

  {

    if (nums[i] > nums[i - 1])

    {

      idx = i;

      break;
    }
  }

  if (idx == -1)

  {

    reverse(nums.begin(), nums.end());
  }

  else
  {

    int prev = idx;

    for (int i = idx + 1; i < n; i++)

    {

      if (nums[i] > nums[idx - 1] && nums[i] <= nums[prev])

      {

        prev = i;
      }
    }

    swap(nums[idx - 1], nums[prev]);

    reverse(nums.begin() + idx, nums.end());
  }
}
int main()
{
  int n;
  cout << "Enter size of the array : ";
  cin >> n;
  vector<int> v;
  cout << "Enter elements of the array :" << endl;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    v.push_back(x);
  }
  nextPermutation(v);
  for (int i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
}
