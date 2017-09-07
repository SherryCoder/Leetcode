#include<iostream>
#include<vector>
using namespace std;
//这题是将原链表分成小于X和大于X的两部分，是简单的链表操作，比较简单
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode* partition(ListNode* head, int x) {
	ListNode*smaller = new ListNode(-1);
	ListNode*shead = smaller;
	ListNode*bigger = new ListNode(-1);
	ListNode*bhead = bigger;
	ListNode*T = head;
	while(T){
		if(T->val >= x){
			bigger->next = T;
			bigger = bigger->next;
		}else{
			smaller->next = T;
			smaller = smaller->next;
		}
		T = T->next;
	}
	smaller->next = bhead->next;
	bigger->next = NULL;
	return shead->next;
}

//int main(){
//	int test[] = {1,4,3,2,5,2};  //10
//	ListNode*head = new ListNode(-1);
//	ListNode*p = head;
//	for(int i = 0;i < sizeof(test)/sizeof(int);i++){
//		ListNode*tmp = new ListNode(test[i]);
//		p->next = tmp;
//		p = p->next;
//	}
//	ListNode*result = partition(head->next,3);
//	while(result){
//		cout<<result->val<<" ";
//		result = result->next;
//	}
//	return 0;
//}
