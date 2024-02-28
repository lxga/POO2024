#include <iostream>
using namespace std;

bool isPrime(int n)
{
	if(n==1 || n==0)
		return false; 
    for (int tr = 2; tr <= n / 2; tr++)// sau tr*tr<=n pt complexitate O(sqrt(n))
        if ((n % tr ) == 0)
            return false;
    return true;
}
int main()
{
    int n;
    std::cout << "Enter a number:";
    std::cin >> n;
    if (isPrime(n))
        std::cout << n << " is prime !";
    else 
        std::cout << n << " is NOT prime !";
    return 0;
}