#include <iostream>
#include <string>
#include <cmath>
#define endl "\n"
#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);}

using namespace std; 

int main() {
	fastio;

	int t;
	cin>>t;

	while(t--) {
		unsigned int x, y;
		cin>>x>>y;

		unsigned long long int current_grid = max(x, y);
		unsigned long long int start = (current_grid*current_grid);

		if(start%2==0) {

			if(x == current_grid) {
				cout<<start-(y-1)<<endl;
			}
			else {
				cout<<start-(2*current_grid-x-1)<<endl;
			}
		}
		else {

			if(y == current_grid) {
				cout<<start-(x-1)<<endl;
			}
			else {
				cout<<start-(2*current_grid-y-1)<<endl;
			}
		}
	}

	return 0;
}