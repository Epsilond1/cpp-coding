#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using std::cout;
using std::cin;
using std::endl;
using std::sort;
using std::vector;
using std::priority_queue;

int main() {
  std::ios_base::sync_with_stdio(0);
  int count, k_number;
  cin >> count >> k_number;

  vector<long long> sequence(count + 2);
  priority_queue<long long> quy;

  long long x0, x1, cA, cB, cC;
  cin >> x0 >> x1 >> cA >> cB >> cC;

  long long cnst = pow(2, 31);
  sequence[0] = x0;
  sequence[1] = x1;

  if (count == 1) {
    cout << x1;
  }
  else if (count == 2) {
    cout << std::max(x0, x1) << std::min(x0, x1);
  }
  else if (count > 2) {
    for (int index = 2; index < count + 2; ++index) {
      sequence[index]= (((cA * sequence[index - 2]) + (cB * sequence[index - 1]) + cC) % cnst);
      quy.push(sequence[index]);
    }

    for (int index = count; index >= k_number; --index) {
      cout << quy.top() << " ";
      quy.pop();
    }
  }

  cout << "\n";

  return 0;
}
