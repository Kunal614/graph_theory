#include <bits/stdc++.h>
#define EPOCHS 40
#define even(a) (!(a&1))
typedef long long ll;

using namespace std;

/**
 * Exponentiation function rewritten using
 * binary exponenetiation for computations in 
 * log(n) time
 */
ll power(ll a, ll b, ll p) {
	ll result = 1;

	while(b!=0) {

		if(!even(b)) {
			result = ((result%p) * (a%p))%p;
		}
		a = ((a%p)*(a%p))%p;
		b = b>>1;
	}

	return result;
}


bool primality_test(ll a, ll n, ll p) {
	
	if(even(n)) {
		ll x = power(a, (ll)n/2, p)-1;
		ll y = power(a, (ll)n/2, p)+1;
		
		if(x%p==0 || y%p==0) {
			return true;
		}
		
		if(even((ll)n/2)) {
			return primality_test(a, (ll)n/2, p);
		}
		else {
			return false;
		}
	}
	return true;
}

bool miller_rabin(ll n) {
	
	for(int epochs=0; epochs<EPOCHS; ++epochs) {
		ll a=(rand()%(n-1))+1;
		
		if(power(a, n-1, n)-1 != 0) {
			return false;
		}
		else if(!primality_test(a, n-1, n)){
			return false;
		}
	}
	return true;
}

int main() {
	srand(time(0));
	
	ll n;
	
	printf("Enter the number: ");
	scanf("%lld", &n);
	
	(miller_rabin(n))?printf("%lld is prime!\n", n):printf("%lld is composite.\n", n);
	
	return 0;
}
