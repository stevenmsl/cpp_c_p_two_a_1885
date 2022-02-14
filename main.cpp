#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1885;

string toString(vector<string> input)
{
  string result = "[";
  for (auto e : input)
  {
    result += e;
    result += ",";
  }
  /* remove the last comma */
  if (result.size() > 1)
    result.pop_back();
  result += "]";
  return result;
}

/*
Input: nums1 = [2,1,2,1], nums2 = [1,2,1,2]
Output: 1
*/
tuple<vector<int>, vector<int>, int> testFixture1()
{
  return make_tuple(
      vector<int>{2, 1, 2, 1},
      vector<int>{1, 2, 1, 2},
      1);
}

/*
Input: nums1 = [1,10,6,2], nums2 = [1,4,1,5]
Output: 5
*/

tuple<vector<int>, vector<int>, int> testFixture2()
{
  return make_tuple(
      vector<int>{1, 10, 6, 2},
      vector<int>{1, 4, 1, 5},
      5);
}

void test1()
{
  auto f = testFixture1();
  auto result = Solution::countPairs(get<0>(f), get<1>(f));
  cout << "Test 1 - exepct to see " << to_string(get<2>(f)) << endl;
  cout << "result: " << to_string(result) << endl;
}

void test2()
{
  auto f = testFixture2();
  auto result = Solution::countPairs(get<0>(f), get<1>(f));
  cout << "Test 2 - exepct to see " << to_string(get<2>(f)) << endl;
  cout << "result: " << to_string(result) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}