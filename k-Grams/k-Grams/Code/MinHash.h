#ifndef HUI_MINHASH_HEADER
#define HUI_MINHASH_HEADER

#include<vector>
#include<iostream>
#include<string>
#include <unordered_map>



namespace Hui{
	class MinHash{

	public:
		MinHash(int i_k = 10){
			m_k = i_k;
		}

		void getRepresentColDocument(std::unordered_map< std::string, int> i_document_a,
			std::unordered_map< std::string, int> i_document_b,
			std::unordered_map< std::string, int> i_document_union);

		void getMinHashRepresentColDocument();

		float getSimilarity(void);

	private:
		std::vector<int> m_represent_col_a;
		std::vector<int> m_represent_col_b;
		std::vector<int> m_minhash_col_a;
		std::vector<int> m_minhash_col_b;
		int m_k;
	};
}

#endif