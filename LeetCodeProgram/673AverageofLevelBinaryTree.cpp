//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
////求二叉树每层的平均数
////待测试
////层序遍历就是树的广度优先遍历
//struct TreeNode{
//	int val;
//	TreeNode*left;
//	TreeNode*right;
//	TreeNode(int x):val(x),left(NULL),right(NULL){}
//};
//
//vector<double> averageofLevels(TreeNode*root){
//	vector<double> result;
//	if(root==NULL) return result;
//	vector<TreeNode*> levelV;
//	levelV.push_back(root);
//	while(levelV.size()>0){
//		vector<TreeNode*> level_next;
//		int sum_t=0;
//		for(int i = 0;i < levelV.size();i++){
//			TreeNode*node_t = levelV[i];
//			if(node_t->left){
//				level_next.push_back(node_t->left);
//			}
//			if(node_t->right){	
//				level_next.push_back(node_t->right);	
//			}
//			sum_t += node_t->val;
//		}
//		result.push_back(sum_t/level_next.size());
//		levelV.clear();
//		for(int i = 0;i < level_next.size();i++){
//			levelV.push_back(level_next[i]);
//		}
//		
//	}
//	return result;
//}
//
////使用队列
//vector<double> averageofLevels(TreeNode*root){
//	vector<double> result;
//	if(root == NULL){
//		return result;
//	}
//	queue<TreeNode*> tree;
//	tree.push(root);
//	while(!tree.empty()){
//		int sum_t = 0;
//		int cnt = tree.size();
//		for(int i = 0;i < cnt;i++){
//			TreeNode*node_t = tree.front();
//			sum_t += node_t->val;
//			if(node_t->left){
//				tree.push(node_t->left);
//			}
//			if(node_t->right){
//				tree.push(node_t->right);
//			}
//			tree.pop();
//		}
//		result.push_back(sum_t/cnt);
//	}
//	return result;
//	
//}