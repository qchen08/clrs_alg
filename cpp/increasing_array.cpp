#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int get_reg_size(vector<int> &IN, int N, int i){
	int j;
	for(j = 1; j+i < N; j++){
		if(j+i == N-1 || IN[i+j] >= IN[i])
			return j;
	}
	return j;
}

int get_reg_cost(vector<int> &IN, int i, int M){
	int base = IN[i];
	int cost = 0;
	for(int j = i; j <= M; j++){
		int curr = IN[j];
		if(IN[j] < base){
			if(curr > base-curr){
				// add
				cost += base-curr;
				IN[j] = base;
			}else{
				// delete
				cost += IN[j];
				IN[j] = -1;
			}
		}
	}
	return cost;
}

void compute_cost(vector<int> &IN, int N){
	for(int i = 0; i < N; i++){
		int reg_size = 0;
		int reg_cost = 0;
		if(i != N-1 && IN[i] > IN[i+1]){
			reg_size = get_reg_size(IN, N, i);
			reg_cost = get_reg_cost(IN, i, i+reg_size);
			cout << "[" << i << "," << i+reg_size << "] : " << reg_cost << endl;
		}
		if(reg_size != 0){
			i+= reg_size-1;
		}
	}
}

int main(int argc, char *argv[]){
	int N = argc-1;
	cout << "array size = " << N << endl;

	vector<int> IN;
	IN.resize(N);
	for(int i = 0; i < N; i++){
		IN[i] = atoi(argv[i+1]);	
	}
	for(int i = 0; i < N; i++){
		cout << "IN[" << i << "] = " << IN[i] << endl;
	}


	compute_cost(IN, N);

	for(int i = 0; i < N; i++){
		cout << "Result[" << i << "] = " << IN[i] << endl;
	}



	return 0;
}
