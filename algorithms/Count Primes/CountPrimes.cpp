/*Count Primes
Description:
Count the number of prime numbers less than a non-negative number, n.
*/
class Solution {
public:
    int countPrimes(int n) {
        vector<int>isPrime(n+1,1);
        isPrime[1] = 0;
        for(int i = 2;(i*i) < n;i++){
            if(!isPrime[i])continue;
            for(int j = i*i;j < n; j += i)
                 isPrime[j] = 0;
        }
        int count = 0;
        for(int i = 1;i < n;i++)
          count += isPrime[i];  
          
        return count;
    }
};