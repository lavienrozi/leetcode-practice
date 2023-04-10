// 734. Sentence Similarity.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

// TODO: Reference additional headers your program requires here.

template<typename T>
void LOG(T x) { std::cout << x << std::endl; }

class Solution1 {
public:
	bool areSentencesSimilar(std::vector<std::string>& sentence1, std::vector<std::string>& sentence2, std::vector<std::vector<std::string>>& similarPairs) {
		if (sentence1 == sentence2) return true;
		else if (sentence1.size() == sentence2.size()) {
			for (int i = 0; i < sentence1.size(); i++) {
				if (sentence2[i] == sentence2[i]) continue;
				std::vector<std::vector<std::string>>::iterator iter1;
				std::vector<std::vector<std::string>>::iterator iter2;
				std::vector<std::string> vec1 = { sentence1[i],sentence2[i] };
				std::vector<std::string> vec2 = { sentence2[i],sentence1[i] };
				iter1 = std::find(similarPairs.begin(), similarPairs.end(), vec1);
				iter2 = std::find(similarPairs.begin(), similarPairs.end(), vec2);
				if (iter1 == similarPairs.end() && iter2 == similarPairs.end())
					return false;
			}
			return true;
		}
		LOG("start from here");

		return false;
	}
};

#include <unordered_map>
#include <unordered_set>

class Solution2 {
public:
	auto areSentencesSimilar(const std::vector<std::string>& sentence1,
		const std::vector<std::string>& sentence2,
		const std::vector<std::vector<std::string>>& similarPairs) -> bool {
		if (sentence1.size() != sentence2.size()) return false;

		std::unordered_map<std::string, std::unordered_set<std::string>> umap;
		for (const auto& pp : similarPairs) {
			umap[pp[0]].insert(pp[1]);
			umap[pp[1]].insert(pp[0]);
		}

		for (int i = 0; i < sentence1.size(); ++i) {
			auto word1 = sentence1[i];
			auto word2 = sentence2[i];

			if (word1 != word2 && (umap.find(word1) == umap.end() || umap[word1].find(word2) == umap[word1].end())) {
				return false;
			}
		}

		return true;
	}
};
