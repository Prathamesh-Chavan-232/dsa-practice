#include <bits/stdc++.h>
using namespace std;

// Varidiac Variable debugger
#ifndef ONLINE_JUDGE
#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#endif
template <typename... Args>
void logger(string varname,
            Args &&...values) // logger for varadiac debugging print statements
{
  cerr << varname << " =";
  string delim = " ";
  (..., (cerr << delim << values, delim = ", "));
  cerr << "\n";
}

/**
 * @brief - binary search templates, works on array or vector of any datatype
 * */

/*
   This implementation is cleaner in terms of code readability & is easier to
   remember.It runs one more time than the 2nd one, until mid is equal to target
*/

// For vectors
template <typename T> int binSearch(vector<T> const &arr, T const target) {
  int mid, res = -1, low = 0, high = arr.size() - 1;
  while (low <= high) {
    mid = low + (high - low) / 2;
    debug(low, high, mid, arr[mid]);
    if (arr[mid] == target) {
      res = mid;
      break;
    } else if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return res;
}

// For arrays
template <typename T> int binSearch(T arr[], int n, T const target) {
  int mid, res = -1, low = 0, high = n - 1;
  while (low <= high) {
    mid = low + (high - low) / 2;
    debug(low, high, mid, arr[mid]);
    if (arr[mid] == target) {
      res = mid;
      break;
    } else if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return res;
}

/**
 * This implementation only runs until its logically required,i.e. until there
 * aren't any elements between l & r, so at the end either l or r is equal to
 * target -> This is useful in some questions
 * */

// For vectors
template <typename T> int bin_search(vector<T> const &arr, T const target) {
  int l = 0, r = arr.size() - 1, res = -1, m = -1;
  while (r - l > 1) {
    m = l + (r - l) / 2;
    debug(l, r, m, arr[m]);
    if (arr[m] < target) {
      l = m + 1;
    } else {
      r = m; // keep mid included in the search, since the condn arr[mid] ==
             // target is still possible
    }
  }
  if (arr[l] == target)
    res = l;
  else if (arr[r] == target)
    res = r;
  return res;
}

// For arrays
template <typename T> int bin_search(T arr[], int n, T const target) {
  int l = 0, r = n - 1, res = -1, m = -1;
  while (r - l > 1) {
    m = l + (r - l) / 2;
    debug(l, r, m, arr[m]);
    if (arr[m] < target) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  if (arr[l] == target) {
    res = l;
  } else if (arr[r] == target) {
    res = r;
  }
  return res;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("/home/falconcodes/keep-coding/coding-practice/input.txt", "r",
          stdin);
  freopen("/home/falconcodes/keep-coding/coding-practice/output.txt", "w",
          stdout);
  freopen("/home/falconcodes/keep-coding/coding-practice/err.txt", "w", stderr);
#endif

  // Start
  int n, target;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  cin >> target;
  int res = binSearch(arr, n, target);
  cout << "Target found at index: " << res << "\n";
  return 0;
}
