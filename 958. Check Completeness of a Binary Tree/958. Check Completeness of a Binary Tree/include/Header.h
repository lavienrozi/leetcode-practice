#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

template<typename T> void LOG(T x) { std::cout << x << std::endl; }

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void dfs(TreeNode* root) {
	if (root) {
		std::cout << root->val << ',';
		dfs(root->left);
		dfs(root->right);
	}
}

class Solution {
public:
	bool isCompleteTree(TreeNode* root) {
		std::queue<TreeNode*> q;
		q.push(root);
		int flag = 0;
		while (!q.empty()) {
			TreeNode* node = q.front();
			q.pop();
			if (flag && node != NULL) return false;
			if (node == NULL) {
				flag = 1;
				continue;
			}
			q.push(node->left);
			q.push(node->right);
		}
		return true;

	}
};