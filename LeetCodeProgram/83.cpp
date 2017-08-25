//#include<iostream>
//using namespace std;
////删除链表中的重复元素,注释掉的是另一种解法，不是错误
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//
//ListNode* deleteDuplicates(ListNode* head) {
//	if(!head || !head->next) return head;
//	ListNode**runner = &head;
//	while(*runner){
//		if((*runner)->next && (*runner)->val == (*runner)->next->val){
//			(*runner)->next = (*runner)->next->next;
//		}else{
//			runner = &((*runner)->next);
//		}
//	}
//	return head;
//}
//
////ListNode* deleteDuplicates(ListNode* head) {
////	if(!head || !head->next) return head;
////	ListNode*newhead = head;
////	while(newhead){
////		if(newhead->next && newhead->next->val == newhead->val){
////			newhead->next = newhead->next->next;
////		}else{
////			newhead = newhead->next;
////		}
////	}
////	return head;
////}
//
////int main(){
////	int test[] = {1,1,1};  //10
////	ListNode*head = new ListNode(-1);
////	ListNode*p = head;
////	for(int i = 0;i < sizeof(test)/sizeof(int);i++){
////		ListNode*tmp = new ListNode(test[i]);
////		p->next = tmp;
////		p = p->next;
////	}
////	ListNode*result = deleteDuplicates(head->next);
////	while(result){
////		cout<<result->val<<" ";
////		result = result->next;
////	}
////	return 0;
////}