#include <Header.h>

void removeEle(std::vector<std::vector<int>>& pos) {
	std::vector < std::vector<int>>::iterator iter; 
	iter = pos.begin();
	while (iter != (pos.end() - 1)) {
		pos.erase(iter);
		for (const auto& vec : pos) {
			std::cout << '[';
			for (const auto& val : vec)
				std::cout << val << ',';
			std::cout << "], ";
		}
		
		iter = pos.begin();
	}
	
}

int main() {
	std::vector<std::vector<int>> lands_pos = { {0, 0},{0, 1},{1,0},{1, 2},{2, 1} };
	Solution1 sol;
	//int num = sol.numIslands2(3, 3,lands_pos);
	// removeEle(lands_pos);
	//LOG(num);

	return 0;
}