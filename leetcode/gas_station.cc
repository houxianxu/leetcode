/* this version's time complexity is O(n^2) --> TLE*/

#include <vector>
#include <cstdlib>
#include <stdio.h>
using std::vector;


// whether can complete from station fromStation to station toStation
int canCompleteCircuitFromTo(int *gas, int *cost, int N, int fromStation) {
  int i = 0;
  int hasGas = 0;
  int pass_total_station = 0;
  int indexStation = 0;
  while (hasGas >= 0 && i < N) { // N loop
    indexStation = (fromStation + i) % N;
    hasGas += (gas[indexStation] - cost[indexStation]);
    i += 1;
  }

  pass_total_station = i;

  return pass_total_station;
 
}

int canCompleteCircuitC(int *gas, size_t gas_size, int *cost, size_t cost_size) {
  int i = 0;
  int N = gas_size;
  for(i = 0; i < N; i++) {
    int pass_total_station = 0;
    pass_total_station = canCompleteCircuitFromTo(gas, cost, N, i);
    if (pass_total_station == N) {
      return i;
    }
  }
  return -1;
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