#include <iostream>
#include <fstream> 
#include <unordered_map>

#include "KGrams.h"
#include "SetHelper.h"

int main(void){

	int k = 3;
	
	Hui::KGrams document_1(k, true, false, "Data/doc1.txt");
	document_1.readDocumentData();
	document_1.processDocumentToSet();
	//document_1.showDocumentSet();

	Hui::KGrams document_2(k, true, false, "Data/doc2.txt");
	document_2.readDocumentData();
	document_2.processDocumentToSet();
	//document_2.showDocumentSet();

	Hui::KGrams document_3(k, true, false, "Data/doc3.txt");
	document_3.readDocumentData();
	document_3.processDocumentToSet();
	//document_3.showDocumentSet();

	Hui::KGrams document_4(k, true, false, "Data/doc4.txt");
	document_4.readDocumentData();
	document_4.processDocumentToSet();
	//document_4.showDocumentSet();

	
	float similarity_12 = Hui::SetJaccard(document_1.getDocumentSet(), document_2.getDocumentSet());
	float similarity_13 = Hui::SetJaccard(document_1.getDocumentSet(), document_3.getDocumentSet());
	float similarity_14 = Hui::SetJaccard(document_1.getDocumentSet(), document_4.getDocumentSet());
	float similarity_23 = Hui::SetJaccard(document_2.getDocumentSet(), document_3.getDocumentSet());
	float similarity_24 = Hui::SetJaccard(document_2.getDocumentSet(), document_4.getDocumentSet());
	float similarity_34 = Hui::SetJaccard(document_3.getDocumentSet(), document_4.getDocumentSet());
	
	
	Hui::KGrams test1(3, true, false, "Data/doct3.txt");
	test1.readDocumentData();
	test1.processDocumentToSet();
	test1.showDocumentSet();
	/*
	
	Hui::KGrams test2(3, false, true, "Data/doct2.txt");
	test2.readDocumentData();
	test2.processDocumentToSet();
	test2.showDocumentSet();


	std::unordered_map<std::string, int> test_union = Hui::SetUnion(test1.getDocumentSet(), test2.getDocumentSet());
	std::unordered_map<std::string, int> test_insection = Hui::SetInsection(test1.getDocumentSet(), test2.getDocumentSet());
	*/

	std::cout << "Hello World" << std::endl;
	return 0;
}
