#pragma once
#include <iostream>

template<typename T> void LOG(T x) { std::cout << x << std::endl; }

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void climbTree(TreeNode* root) {
	if (root) {
		std::cout << root->val << ',';
		climbTree(root->left);
		climbTree(root->right);
	}
}

class Solution {
public:
	bool isSymmetric(TreeNode* root) {

	}
};
