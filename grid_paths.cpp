#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
#define endl "\n"
#define nitro {std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);}
#define even(a) (!(a&1))
#define M 1000000007
#define make_pair mp
#define fori(a, b) for(int i=a; i<b; ++i)
#define forj(a, b) for(int j=a; j<b; ++j)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned long int ul;
typedef std::vector<ll> vi;
typedef std::pair<ll, ll> pairi;

int ans = 0;
bool visited[7][7];
string path;

bool up(int i, int j) {
	
	if(i-1<0) {
		return false;
	}
	
	return (!visited[i-1][j]);
}

bool down(int i, int j) {
	
	if(i+1>6) {
		return false;
	}
	
	return (!visited[i+1][j]);
}

bool left(int i, int j) {
	
	if(j-1<0) {
		return false;
	}
	
	return (!visited[i][j-1]);
}

bool right(int i, int j) {
	
	if(j+1>6) {
		return false;
	}
	
	return (!visited[i][j+1]);
}

bool all_squares_visited() {
	
	bool res = true;
	
	fori(0, 7) {
		forj(0, 7) {
			res &= visited[i][j];	
		}
	}
	
	return res;
}

void reset(int beg, int i, int j, int end) {
	
	for(int x=beg; x<end; x++) {
		switch(path[x]) {
			case 'U':
				visited[--i][j] = false;
			break;
			
			case 'D':
				visited[++i][j] = false;
			break;
			
			case 'L':
				visited[i][--j] = false;
			break;
			
			case 'R':
				visited[i][++j] = false;
			break;
		}
	}
	
}

bool checkForPruning(int i, int j) {
	
	if(i==6 && j==0) {
		if(all_squares_visited()) {
			++ans;
		}
		return true;
	}
	
	if(!up(i, j) && !down(i, j) && left(i, j) && right(i, j)) {
		return true;
	}
	
	if(up(i, j) && down(i, j) && !left(i, j) && !right(i, j)) {
		return true;
	}
	
	if(!up(i, j) && !down(i, j) && !left(i, j) && !right(i, j)) {
		return true;
	}
	
	return false;
}

int solve(int beg, int i, int j) {

	visited[i][j] = true;
	
	//cout<<endl<<"call from "<<"i= "<<i<<", j= "<<j<<" at x= "<<beg<<" saying go "<<path[beg]<<endl;

	for(int x=beg;x<49;x++) {
		
		if(checkForPruning(i, j)) {
			return x;
		}

		switch(path[x]) {

			case'U':
			if(i-1>=0) {
				if(!visited[i-1][j]) {
					visited[--i][j] = true;
				}
				else {
					return x;
				}
			}
			else {
				return x;
			}
			break;

			case'D':
			if(i+1<=6) {
				if(!visited[i+1][j]) {
					visited[++i][j] = true;
				}
				else {
					return x;
				}
			}
			else {
				return x;
			}
			break;

			case'L':
			if(j-1>=0) {
				if(!visited[i][j-1]) {
					visited[i][--j] = true;
				}
				else {
					return x;
				}
					
			}
			else {
				return x;
			}
			break;

			case'R':
			if(j+1<=6) {
				if(!visited[i][j+1]) {
					visited[i][++j] = true;
				}
				else {
					return x;
				}
			}
			else {
				return x;
			}
			break;

			case'?':
			if(i-1>=0) { //up
				if(!visited[i-1][j]) {
					
					path[x] = 'U';
					int y=solve(x, i, j);
					reset(x, i, j, y);
					path[x] = '?';
					visited[i][j] = false;
				}
			}
			if(i+1<=6) { //down
				if(!visited[i+1][j]) {
					
					path[x] = 'D';
					int y=solve(x, i, j);
					reset(x, i, j, y);
					path[x] = '?';
					visited[i][j] = false;
				}
			}
			if(j-1>=0) { //left
				if(!visited[i][j-1]) {
					
					path[x] = 'L';
					int y=solve(x, i, j);
					reset(x, i, j, y);
					path[x] = '?';
					visited[i][j] = false;
				}
			}
			if(j+1<=6) { //right
				if(!visited[i][j+1]) {
					
					path[x] = 'R';
					int y=solve(x, i, j);
					reset(x, i, j, y);
					path[x] = '?';
					visited[i][j] = false;
				}
			}
			return x;
			break;
		}
		//cout<<"i: "<<i<<", j: "<<j<<endl;
	}
	return 49;	
}

int main() {
	nitro

	getline(cin, path);

	fori(0, 7) {
		forj(0, 7) {
			visited[i][j] = false;
		}
	}

	solve(0, 0, 0);

	cout<<ans<<endl;

	return 0;
}
