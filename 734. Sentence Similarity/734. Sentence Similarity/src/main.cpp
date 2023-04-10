// 734. Sentence Similarity.cpp : Defines the entry point for the application.
//

#include "header.h"

// using namespace std;

int main()
{
	std::vector<std::string> sentence1 = { "great", "acting", "skills" };
	std::vector<std::string> sentence2 = { "fine","drama","talent" };
	std::vector<std::vector<std::string>> similarPairs = { {"great", "fine"},{"drama", "acting"},{"skills", "talent"} };

	Solution1 sol;
	LOG(sol.areSentencesSimilar(sentence1, sentence2, similarPairs));

	return 0;
}
