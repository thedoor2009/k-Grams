#include "MinHash.h"
#include "MinHashFunction.h"

namespace Hui{
	void MinHash::getRepresentColDocument(std::unordered_map< std::string, int> i_document_a,
		std::unordered_map< std::string, int> i_document_b,
		std::unordered_map< std::string, int> i_document_union){

		for (auto it = i_document_union.begin(); it != i_document_union.end(); ++it){
			if (i_document_a.find(it->first) != i_document_a.end()){
				m_represent_col_a.push_back(1);
			}
			else{
				m_represent_col_a.push_back(0);
			}
			if (i_document_b.find(it->first) != i_document_b.end()){
				m_represent_col_b.push_back(1);
			}
			else{
				m_represent_col_b.push_back(0);
			}
		}
		return;
	}

	void  MinHash::getMinHashRepresentColDocument(){

		unsigned int length_a = m_represent_col_a.size();
		for (int i = 0; i < m_k; i++){
			m_minhash_col_a.push_back(INT_MAX);
		}

		for (int i = 0; i < m_k; i++){
			int hashindex = 0;
			for (unsigned int j = 0; j < length_a; j++){
				int g = j;
				int *h = &g;
				int seed = i + 1;
				MurmurHash3_x86_32(h, sizeof(int), seed, &hashindex);
				i = seed - 1;
				//hashindex = MinHashFunction(j, i);
				if (m_represent_col_a[j] != 0 && hashindex < m_minhash_col_a[i]){
					m_minhash_col_a[i] = hashindex;
				}
			}
		}

		unsigned int length_b = m_represent_col_b.size();
		for (int i = 0; i < m_k; i++){
			m_minhash_col_b.push_back(INT_MAX);
		}

		for (int i = 0; i < m_k; i++){
			int hashindex = 0;
			for (unsigned int j = 0; j < length_b; j++){
				int g = j;
				int *h = &g;
				int seed = i + 1;
				MurmurHash3_x86_32(h, sizeof(int), seed, &hashindex);
				i = seed - 1;
				//hashindex = MinHashFunction(j, i);
				if (m_represent_col_b[j] != 0 && hashindex < m_minhash_col_b[i]){
					m_minhash_col_b[i] = hashindex;
				}
			}
		}
		return;
	}

	float MinHash::getSimilarity(void){
		float sum = 0;
		float k = (float)m_k;
		for (int i = 0; i < m_k; i++){
			if (m_minhash_col_a[i] == m_minhash_col_b[i]){
				sum++;
			}
		}
		return sum / k;
	}
}