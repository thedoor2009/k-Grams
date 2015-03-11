#include <iostream>
#include <fstream> 
#include <unordered_map>

#include "KGrams.h"
#include "SetHelper.h"
#include "MinHash.h"

int main(void){

	
	
	/*std::unordered_map<std::string, int> a;
	std::unordered_map<std::string, int> b;

	std::pair< std::string, int> a1("wo", 1);
	std::pair< std::string, int> a2("or", 2);
	std::pair< std::string, int> a3("rl", 3);
	std::pair< std::string, int> a4("ld", 4);

	a.insert(a1);
	a.insert(a2);
	a.insert(a3);
	a.insert(a4);

	std::pair< std::string, int> b1("ld", 1);
	std::pair< std::string, int> b2("co", 2);
	std::pair< std::string, int> b3("ou", 3);
	std::pair< std::string, int> b4("ul", 4);

	b.insert(b1);
	b.insert(b2);
	b.insert(b3);
	b.insert(b4);
	*/
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

	Hui::MinHash minhash(50);
	minhash.getRepresentColDocument(document_1.getDocumentSet(), document_2.getDocumentSet(), 
									Hui::SetUnion(document_1.getDocumentSet(), document_2.getDocumentSet()));
	minhash.getMinHashRepresentColDocument();
	float similarity = minhash.getSimilarity();
	
	float similarity_12 = Hui::SetJaccard(document_1.getDocumentSet(), document_2.getDocumentSet());
	float similarity_13 = Hui::SetJaccard(document_1.getDocumentSet(), document_3.getDocumentSet());
	float similarity_14 = Hui::SetJaccard(document_1.getDocumentSet(), document_4.getDocumentSet());
	float similarity_23 = Hui::SetJaccard(document_2.getDocumentSet(), document_3.getDocumentSet());
	float similarity_24 = Hui::SetJaccard(document_2.getDocumentSet(), document_4.getDocumentSet());
	float similarity_34 = Hui::SetJaccard(document_3.getDocumentSet(), document_4.getDocumentSet());
	
	int hehe;
	std::cin >> hehe;

	return 0;
}
