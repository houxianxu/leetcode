#include <vector>
#include <cstdlib>

using std::vector;


int candyC(int *ratings, size_t rating_size) {
  if (rating_size == 0 || rating_size == 1) {
    return rating_size;
  } else {
    int i = 0;
    int candyNumber[rating_size];

    // initilaize to 1
    for (i = 0; i < rating_size; i++) {
      candyNumber[i] = 1;
    }

    // scan from left to right, and add 1 when ratings[right] > ratings[left]
    for (i = 1; i < rating_size; i++) {
      if (ratings[i] > ratings[i-1]) {
        candyNumber[i] = candyNumber[i-1] + 1;
      }
    }
    // scan from right to left, and 1 when ratings[right] < ratings[left]
    for (i = rating_size - 2; i >= 0; i--) {
      if (ratings[i] > ratings[i+1] && candyNumber[i] <= candyNumber[i+1]) {
        candyNumber[i] = candyNumber[i+1] + 1;
      }
    }

    // sum the total candy
    int res = 0; // return the result
    for (i = 0; i < rating_size; i++) {
      res += candyNumber[i];
    }

    return res;
  }
}

int c_solution(int *ratings, size_t rating_size)  {
  return candyC(ratings, rating_size);
}

class Solution {
 public:
  int candy(vector<int> &ratings) {
    int *c_ratings = new int[ratings.size()];
    copy_vec(c_ratings, ratings);
    int ret = c_solution(c_ratings, ratings.size());
    delete [] c_ratings;
    return ret;
  }
  void copy_vec(int *c_vec, const vector<int> &vec) {
    for(int i = 0; i < vec.size(); i++) {
      c_vec[i] = vec[i];
    }
  }
};

int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}