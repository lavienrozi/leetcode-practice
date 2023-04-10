#include "Header.h"


int main() {

	//LOG(tNode.val);
	TreeNode* nSub0_0 = new TreeNode(3, nullptr, nullptr);
	TreeNode* nSub0_1 = new TreeNode(4, nullptr, nullptr);
	TreeNode* nSub1_0 = nullptr;
	//TreeNode* nSub1_0 = new TreeNode(5, nullptr, nullptr);
	// TreeNode* nSub1_1 = nullptr;
	TreeNode* nSub1_1 = new TreeNode(6, nullptr, nullptr);
	TreeNode* nSub0 = new TreeNode(7, nSub0_0, nSub0_1);
	TreeNode* nSub1 = new TreeNode(8, nSub1_0, nSub1_1);
	TreeNode* nRoot = new TreeNode(16, nSub0, nSub1);

	// dfs(nRoot);
	Solution sol;
	std::cout<<sol.isCompleteTree(nRoot);
	// std::cout << (nRoot || nullptr);

	return 0;
}