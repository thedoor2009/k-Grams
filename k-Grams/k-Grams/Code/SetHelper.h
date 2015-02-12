#include<iostream>
#include<string>
#include <unordered_map>

namespace Hui{
	std::unordered_map< std::string, int> SetInsection(std::unordered_map< std::string, int> i_a, std::unordered_map< std::string, int> i_b){
		std::unordered_map< std::string, int> set_insection;

		for (auto it = i_a.begin(); it != i_a.end(); ++it){
			std::pair< std::string, int> a_element(it->first, it->second);
			set_insection.insert(a_element);
		}

		for (auto it = i_a.begin(); it != i_a.end(); ++it){
			if (i_b.find(it->first) == i_b.end()){
				set_insection.erase(it->first);
			}
		}

		return set_insection;
	}

	std::unordered_map< std::string, int> SetUnion(std::unordered_map< std::string, int> i_a, std::unordered_map< std::string, int> i_b){
		std::unordered_map< std::string, int> set_union;

		for (auto it = i_a.begin(); it != i_a.end(); ++it){
			std::pair< std::string, int> a_element(it->first, it->second);
			set_union.insert(a_element);
		}

		for (auto it = i_b.begin(); it != i_b.end(); ++it){
			std::pair< std::string, int> b_element(it->first, it->second + i_a.size() - 1);
			if (i_a.find(it->first) == i_a.end()){
				set_union.insert(b_element);
			}
		}

		return set_union;
	}

	float SetJaccard(std::unordered_map< std::string, int> i_a, std::unordered_map< std::string, int> i_b){
		std::unordered_map<std::string, int> test_union = Hui::SetUnion(i_a, i_b);
		std::unordered_map<std::string, int> test_insection = Hui::SetInsection(i_a, i_b);

		float x = (float)test_insection.size();
		float y = (float)test_union.size();

		return x / y;
	}

}