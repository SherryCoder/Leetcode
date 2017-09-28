#include<iostream>
#include<vector>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// 这个解法不断改变的是left的下一个节点
ListNode* reverseBetween(ListNode* head, int m, int n) {
	ListNode*ht = new ListNode(-1);
	ht->next = head;
	//ListNode*ht  = head;
	ListNode*left = ht;
	ListNode*right = ht;
	for(int i = 1;i < m;i++){
		left = left->next;
	}
	ListNode*cur = left->next;

	for(int i = 0;i < n-m;i ++){

		ListNode*move = cur->next;    //move表示的是要反转的元素
		cur->next = move->next;      //这边保证了最终cur->next会指向最后一个需要翻转的元素的next元素
		move->next = left->next;
		left->next = move;
	}

	return ht->next;
}

//
//int main(){
//	int test[] = {3,5,1};  //10
//	ListNode*head = new ListNode(-1);
//	ListNode*p = head;
//	for(int i = 0;i < sizeof(test)/sizeof(int);i++){
//		ListNode*tmp = new ListNode(test[i]);
//		p->next = tmp;
//		p = p->next;
//	}
//	ListNode*result =reverseBetween(head->next,1,3);
//	while(result){
//		cout<<result->val<<" ";
//		result = result->next;
//	}
//	return 0;
//}
