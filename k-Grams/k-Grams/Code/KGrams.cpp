#include "KGrams.h"

#include<string>
#include<iostream>
#include<fstream>
#include <unordered_map>

namespace Hui{
	std::unordered_map< std::string, int> KGrams::getDocumentSet(void){
		return m_doc_set;
	}

	void KGrams::readDocumentData(void){
		std::ifstream in(m_doc_path, std::ios::in);
		std::istreambuf_iterator<char> beg(in), end;
		std::string strdata(beg, end);
		m_doc_data = strdata;
		in.close();
	}

	void KGrams::showDocumentSet(void){

		for (auto it = m_doc_set.begin(); it != m_doc_set.end(); ++it){
			std::cout << it->first << ":" << it->second << std::endl;
		}
		//if (m_doc_set.find("space between galaxies") != m_doc_set.end()){
		//	int hehe = 0;
		//}
	}

	bool KGrams::processDocumentToSet(void){
		if (m_character_type){
			unsigned int document_size = m_doc_data.size();
			
			if (document_size == 0){
				return false;
			}
			else{
				for (unsigned int i = 0; i < document_size - m_k + 1; i++){
					if (m_doc_data.at(i) == ' '){
						continue;
					}
					else{
						char *newSeq = new char[10];
						char character;
						int count = 0;
						int index = 0;

						while (count < m_k && i + index < document_size){
							character = m_doc_data.at(i + index);
							if (character == ' '){
								index++;
							}
							else{
								newSeq[count] = character;
								count++;
								index++;
							}
						}
						newSeq[count] = '\0';

						std::string str(newSeq);
						int n = m_doc_set.size();
						std::pair< std::string, int> set(str, n);
						
						if (m_doc_set.find(str) == m_doc_set.end() && str.size() == m_k){
							m_doc_set.insert(set);
						}
					}
				}
			}
		}
		else if (m_word_type){
			unsigned int document_size = m_doc_data.size();

			if (document_size == 0){
				return false;
			}
			else{
				int space_num = 0;
				for (unsigned int i = 0; i < document_size; i++){
					if (m_doc_data.at(i) == ' '){
						space_num++;
					}
				}

				int space_count = 0;
				int count = 0;
				for (unsigned int i = 0; i < document_size - m_k + 1; i++){
					if (space_count == space_num){
						break;
					}
					
					if (m_doc_data.at(i) == ' '){
						continue;
					}
					else{
						char *newSeq = new char[50];
						char character;
						int count = 0;
						int index = 0;
						int i_offset = 0;
						while (count < m_k && i + index < document_size){
							character = m_doc_data.at(i + index);
							newSeq[index] = character;
							if (character == ' '){
								index++;
								count++;
								if (count == 1){
									i_offset = index - 1;
								}
							}
							else{
								index++;
							}
						}
						i += i_offset;
						space_count++;

						if (newSeq[index - 1] == ' '){
							newSeq[index - 1] = '\0';
						}
						else{
							newSeq[index] = '\0';
						}

						std::string str(newSeq);
						int n = m_doc_set.size();
						std::pair< std::string, int> set(str, n);

						if (m_doc_set.find(str) == m_doc_set.end() && count >= m_k - 1){
							m_doc_set.insert(set);
						}
					}
				}
			}
		}
		else{
			std::cout << " Document Process Type Error";
			return false;
		}
		return true;
	}
}