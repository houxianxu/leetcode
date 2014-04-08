
#include <vector>
#include <cstdlib>
#include <stdio.h>
using std::vector;




int canCompleteCircuitC(int *gas, size_t gas_size, int *cost, size_t cost_size) {
  int start = 0;
  int N = gas_size;
  int sum = 0;
  int total = 0; // determine whether it can go a loop
  int diff = 0;
  int i = 0;
  for(i = 0; i < N; i++) {
    diff = gas[i] - cost[i];
    total += diff;
    sum += diff;
    if (sum < 0) {
      start = i + 1;
      sum = 0;
    } 
  }
  return total < 0 ? -1 : start;
}


int c_solution(int *gas, size_t gas_size,  int *cost, size_t cost_size) {
  return canCompleteCircuitC(gas, gas_size, cost, cost_size);
}

class Solution {
 public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int *c_gas = new int[gas.size()];
    int *c_cost = new int[cost.size()];
    copy_vec(c_gas, gas);
    copy_vec(c_cost, cost);
    int ret = c_solution(c_gas, gas.size(), c_cost, cost.size());
    delete [] c_gas;
    delete [] c_cost;
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
  int gas[] = {2, 2, 2};
  int cost[] = {3, 1, 2}; 
  printf("%d\n", c_solution(gas, 3, cost, 3));
  return 0;
}