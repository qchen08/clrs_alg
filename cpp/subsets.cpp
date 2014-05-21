#include <iostream>
#include <map>
#include <vector>
using namespace std;

class BITSET{
	typedef unsigned long long BITNUM;
	private:
		std::vector<BITNUM> bitset;
		int bits;
		int unitSize;
	public:
		BITSET(int size){
			unitSize = sizeof(BITNUM)*8;
			int i;
			for(i = 0; i < size / unitSize+1; i++){
				bitset.push_back(0);
			}
			bits = size;
		}

		bool operator[](int i) const{
			int index = i/sizeof(BITNUM)/8;
			BITNUM num = bitset[index];
			int reminder = i - i * index;
			return (num >> reminder) & 0x1;
		}

		bool empty() const{
			int i = 0;
			for(i = 0; i < bits / unitSize; i++){
				if(!bitset[i]){
					return false;
				}
			}
			BITNUM num = bitset[i];
			BITNUM mask = (0x1 << (bits - bits * i)) - 1;
			num &= mask;
			if(num)
				return false;

			return true;
		}

		BITSET& inc() {
			BITNUM max_num = -1;
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

void print_set(vector<vector<int> > &ret, const BITSET &bitset, const std::vector<int>& keyVec, const std::vector<int>& cntVec){
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
		bool output = false;

		vector<int> retVec;
		for(j = 0; j < cntVec.size(); j++){
			if(bitset[j]){
				output = true;
				retVec.push_back(keyVec[j]);
				for(i = 0; i < cntTmp[j]; i++){
					retVec.push_back(keyVec[j]);
				}
			}
		}

		ret.push_back(retVec);
		if(!dec(bitset, cntVec, cntTmp))
			break;
	}
}

class Solution {
	public:
		vector<vector<int> > subsetsWithDup(vector<int> &S) {
			vector<vector<int> > ret;
			int i, j;
			std::map<int, int> cntMap;
			std::vector<int> keyVec;
			std::vector<int> cntVec;
			std::map<int, int>::iterator iter;
			for(i = 0; i < S.size(); i++){
				if((iter = cntMap.find(S[i])) != cntMap.end()){
					iter->second ++;
				}else{
					cntMap.insert(std::make_pair(S[i], 1));
				}
			}

			// create cntVec & keyVec
			for(auto &cnt : cntMap){
				keyVec.push_back(cnt.first);
				cntVec.push_back(cnt.second);
			}

			int N = cntMap.size();
			BITSET mybitset(N);

			while(1){
				mybitset.inc();
				print_set(ret, mybitset, keyVec, cntVec);
				if(mybitset.empty()){
					break;
				}
			}
			return ret;	
		}
};


int main(){
	int myints[] = {1, 1};
	int i, j;
	std::vector<int>  array(myints, myints + sizeof(myints) / sizeof(int) );
	Solution s;
	vector<vector<int> > result = s.subsetsWithDup(array);

	cout << "[\n";
	for(i = 0; i < result.size(); i ++){
		cout << "  [";
		for(j = 0; j < result[i].size(); j++){
			cout << result[i][j];
			if(j != result[i].size()-1)
				cout << ",";
		}
		cout << "]";
		if(i != result.size()-1)
			cout << ",";
		cout << "\n";
	}
	cout << "]\n";

	return 0;
}
