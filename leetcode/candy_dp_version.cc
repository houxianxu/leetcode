#include <vector>
#include <cstdlib>

using std::vector;


void change_dp_num(int *ratings, int *dp_num, int n) { // change the dp_num
  while (n >= 1 && ratings[n - 1] > ratings[n]) {
    dp_num[n-1] += 1;
  }
}

int candyC(int *ratings, size_t rating_size) {
  if (rating_size == 0 || rating_size == 1) {
    return rating_size;
  } else {
    int dp_num[rating_size];
    int i = 0;
    dp_num[0] = 1;
    for (i = 1; i < rating_size; i++) {
      if (ratings[i] > ratings[i-1]) {
        dp_num[i] += dp_num[i-1] + 1;
      } else if (ratings[i] == ratings[i-1]) {
        dp_num[i] = 1;
      } else {
        if (dp_num[i-1] > 1) {
          dp_num[i] = 1;
        } else {
          dp_num[i] = 1;
          change_dp_num(ratings, dp_num, i);
        }
      }
    }

    int res = 0;
    for (i = 0; i < rating_size; i++) {
      res += dp_num[i];
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