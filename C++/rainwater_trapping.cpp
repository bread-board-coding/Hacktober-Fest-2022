#include<iostream>

using namespace std;

int main() {

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	// time : o(n) space : o(1)
	
	int i = 0;
	int j = n-1;

	int l = 0; // denotes the height of the talleset building from 0 to i
	int r = 0; // denotes the height of the tallest building from j to n-1

	int total = 0;

	while(i <= j) {
		l = max(l, h[i]);
		r = max(r, h[j]);

		if(l < r) {
			// you can now compute the water trapped on top of the ith building
			int w_i = l - h[i];
			total += w_i;
			i++;
		} else {
			// you can now compute the water trapped on top of the jth building 
			int w_j = r - h[j];
			total += w_j;
			j--;
		}

	}

	cout << total << endl;


	return 0;
}