#ifndef HUI_KGRAMS_HEADER
#define HUI_KGRAMS_HEADER

#include<iostream>
#include <unordered_map>

namespace Hui{
	class KGrams{
	public:
		KGrams(int i_k = 1, bool i_word_type = true, bool i_character_type = false, const std::string &i_doc_path = "Data/doc1.txt"){
			m_k = i_k;
			m_word_type = i_word_type;
			m_character_type = i_character_type;
			m_doc_path = i_doc_path;
		}

		std::unordered_map< std::string, int> getDocumentSet(void);

		void readDocumentData();
		void showDocumentSet();
		bool processDocumentToSet();
			

	private:
		std::string								m_doc_data;
		std::string								m_doc_path;
		std::unordered_map< std::string, int>	m_doc_set;
		
		int			m_k;
		bool		m_word_type;
		bool		m_character_type;
	};
}


#endif