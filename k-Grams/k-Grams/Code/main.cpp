#include <iostream>
#include <fstream> 
#include <unordered_map>

#include "KGrams.h"
#include "SetHelper.h"
#include "MinHash.h"

int main(void){

	int k = 3;

	Hui::KGrams document_1(k, false, true, "Data/doc1.txt");
	document_1.readDocumentData();
	document_1.processDocumentToSet();
	//document_1.showDocumentSet();

	Hui::KGrams document_2(k, false, true, "Data/doc2.txt");
	document_2.readDocumentData();
	document_2.processDocumentToSet();
	//document_2.showDocumentSet();

	Hui::KGrams document_3(k, false, true, "Data/doc3.txt");
	document_3.readDocumentData();
	document_3.processDocumentToSet();
	//document_3.showDocumentSet();

	Hui::KGrams document_4(k, false, true, "Data/doc4.txt");
	document_4.readDocumentData();
	document_4.processDocumentToSet();
	//document_4.showDocumentSet();

	//Hui::MinHash minhash(50);
	//minhash.getRepresentColDocument(document_1.getDocumentSet(), document_2.getDocumentSet(), 
	//								Hui::SetUnion(document_1.getDocumentSet(), document_2.getDocumentSet()));
	//minhash.getMinHashRepresentColDocument();
	//float similarity = minhash.getSimilarity();

	float similarity_12 = Hui::SetJaccard(document_1.getDocumentSet(), document_2.getDocumentSet());
	float similarity_13 = Hui::SetJaccard(document_1.getDocumentSet(), document_3.getDocumentSet());
	float similarity_14 = Hui::SetJaccard(document_1.getDocumentSet(), document_4.getDocumentSet());
	float similarity_23 = Hui::SetJaccard(document_2.getDocumentSet(), document_3.getDocumentSet());
	float similarity_24 = Hui::SetJaccard(document_2.getDocumentSet(), document_4.getDocumentSet());
	float similarity_34 = Hui::SetJaccard(document_3.getDocumentSet(), document_4.getDocumentSet());

	std::cout << "The Jaccard Similarity of document 1 and document 2 is " << similarity_12 << std::endl;
	std::cout << "The Jaccard Similarity of document 1 and document 3 is " << similarity_13 << std::endl;
	std::cout << "The Jaccard Similarity of document 1 and document 4 is " << similarity_14 << std::endl;
	std::cout << "The Jaccard Similarity of document 2 and document 3 is " << similarity_23 << std::endl;
	std::cout << "The Jaccard Similarity of document 2 and document 4 is " << similarity_24 << std::endl;
	std::cout << "The Jaccard Similarity of document 3 and document 4 is " << similarity_34 << std::endl;


	int hehe;
	std::cin >> hehe;

	return 0;
}
