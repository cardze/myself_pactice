#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> v = {1,2,3,4,5};
	const int n = v.size();

	vector<vector<int>> d;
	d.resize(n+1);
	for(int i=1; i<=n; i++){
		d[i].resize(n+1);
	}

	for(int i=1; i<=n; i++){
		d[i][i] = v[i-1];
	}

	for(int i=2; i<=n; i++){
		d[1][i] = d[1][i-1] + v[i-1];
	}

	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			d[i][j] = d[1][j] - d[1][i-1];
		}
	}

	for(int a=1; a<=n; a++){
		for(int b=1; b<=n; b++){
			cout<<d[a][b]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	return 0;
}
