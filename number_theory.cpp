#include "data_structure.h"

// Prime sieve
static const int N = 1000000;
static bool is_prime[N];
vector<int> primes;

// Eratosthenes法 (埃氏筛法)
// O(NloglogN)
void Eratosthenes(long long n) {
  is_prime[0] = is_prime[1] = false;
  for (long long i = 2; i <= n; i++)
    is_prime[i] = true;
  for (long long i = 2; i * i <= n; i++) {
    // i <= n if storing primes is needed
    if (is_prime[i]) {
      for (long long j = i * i; j <= n; j += i) // i * i may overflow
        // 从 2 到 i - 1 的倍数之前筛过了
        is_prime[j] = false;
    }
  }
}

// 线性筛法
// O(N)




// 2521. 数组乘积中的不同质因数数目
int distinctPrimeFactors(vector<int> &nums) {
  int n = nums.size();
  unordered_set<int> primes;

  for (int i = 0; i < n; i++) {
    int num = nums[i];
    int x = 2;
    while (x * x <= num) { // x must be prime number
      if (num % x == 0)
        primes.insert(x);
      while (num % x == 0)
        num /= x;
      x++;
    }
    if (num != 1)
      primes.insert(num);
  }
  return primes.size();
}
