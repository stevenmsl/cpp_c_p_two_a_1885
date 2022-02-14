#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <string>
#include <sstream>
using namespace sol1885;
using namespace std;

/*takeaways
  - this is the best solution IMO
  - look at this carefully as it is the key:
    - i < j and nums1[i] + nums1[j] > nums2[i] + nums2[j]
    - try (1,3)
      nums1[1] + nums1[3] > nums2[1] + nums2[3]
    - try (3,1)
      nums1[3] + nums1[1] > nums2[3] + nums2[1]
    - they are identical so you can just
      ignore requirement that i < j
  - combine two arrays into one by calculating the diff
    - (nums1[i]-nums2[i]) + (nums1[j]- nums2[i]) > 0
    - this is just to rearrange the formula but now
      we only have to deal with one vector instead of
      two
*/
int Solution::countPairs(vector<int> &nums1, vector<int> &nums2)
{
  const int n = nums1.size();
  auto diff = vector<int>(n);
  for (auto i = 0; i < n; i++)
    diff[i] = nums1[i] - nums2[i];

  /*
    - at this point the question
      has been simplified - Given
      a vector, count the pairs of
      (i,j) where diff[i] + diff[j] > 0
    - sorting would change the index
      of the numbers for sure. But we
      don't care as we can ignore i < j
      requirements as mentioned aboved
  */
  sort(diff.begin(), diff.end());

  auto pairs = 0;

  int i = 0, j = n - 1;
  while (i < j)
  {
    if (diff[i] + diff[j] <= 0)
      /*
        - diff[i] to small; move on
          to a large one
      */
      i++;
    else
    {
      /*
        - ok whatever after this should
          all qualify as they afre bigger
      */
      pairs += (j - i);
      /*
        - try a smaller number to see if
          it still works
      */
      j--;
    }
  }

  return pairs;
}