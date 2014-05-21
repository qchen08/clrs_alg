#include <iostream>
#include <map>
#include <vector>

class BITSET{
	private:
		std::vector<unsigned long long> bitset;
	public:
		BITSET(int size){
			int i;
			for(i = 0; i < size / sizeof(unsigned long long)+1; i++){
				bitset.push_back(0);
			}
		}

		bool operator[](int i) const{
			int index = i/sizeof(unsigned long long);
			unsigned long long num = bitset[index];
			int reminder = i - i * index;
			return (num >> reminder) & 0x1;
		}


		BITSET& inc() {
			unsigned long long  max_num = -1;
			int i = 0;
			while(1){
				if (bitset[i] == max_num){
					bitset[i] = 0;
					i++;
				}else{
					bitset[i] ++;
					break;
				}
			}
			return *this;
		}
};

// return false when nothing can be done //
bool dec(const BITSET &bitset, const std::vector<int>& cntVec, std::vector<int>& cntTmp){
	int i;
	for(i = 0; i < cntTmp.size(); i ++){
		if(bitset[i]){
			if(cntTmp[i] != 0){
				cntTmp[i] --;
				return true;
			}else{
				cntTmp[i] = cntVec[i] - 1;	
			}
		}
	}
	return false;
}

void print_set(const BITSET &bitset, const std::vector<int>& keyVec, const std::vector<int>& cntVec){
	int i, j;
	std::vector<int> cntTmp;
	cntTmp.resize(cntVec.size());
	for(j = 0; j < cntVec.size(); j++){
		if(bitset[j]){
			if(cntVec[j] != 1){
				cntTmp[j] = (cntVec[j] - 1);
			}else{
				cntTmp[j] = 0;
			}
		}
	}


	while(1){
		std::cout << "{";
		for(j = 0; j < cntVec.size(); j++){
			if(bitset[j]){
				std::cout << keyVec[j] << " ";
				for(i = 0; i < cntTmp[j]; i++)
					std::cout << keyVec[j] << " ";
			}
		}
		std::cout << "\b}" << std::endl;
		if(!dec(bitset, cntVec, cntTmp))
			break;
	}
}

int main(){
	int array[] = {1, 3, 2, 2, 3};
	int i, j;
	std::map<int, int> cntMap;
	std::vector<int> keyVec;
	std::vector<int> cntVec;
	std::map<int, int>::iterator iter;
	for(i = 0; i < sizeof(array)/sizeof(int); i++){
		if((iter = cntMap.find(array[i])) != cntMap.end()){
			iter->second ++;
		}else{
			cntMap.insert(std::make_pair(array[i], 1));
		}
	}

	// create cntVec & keyVec
	for(auto &cnt : cntMap){
		keyVec.push_back(cnt.first);
		cntVec.push_back(cnt.second);
	}

	int N = cntMap.size();
	BITSET mybitset(N);

	std::cout << "{";
	for(i = 0; i < N * N - 1; i ++){
		print_set(mybitset, keyVec, cntVec);
		mybitset.inc();
	}

	return 0;
}
