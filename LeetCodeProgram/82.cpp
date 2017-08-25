#include<iostream>
using namespace std;
//删除链表中重复的元素，只留下只有一个元素的元素
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

////ListNode* deleteDuplicates(ListNode* head) {
////	if(!head || !head->next){
////		return head;
////	}
////
////	ListNode*headDup = head;
////	ListNode*newhead = new ListNode(-1);
////	ListNode*newheadDup = newhead;
////	ListNode*p = head;
////	ListNode*q;
////	while(p){
////		if(!p->next){
////			newheadDup->next = p;
////			break;
////		}
////		q = p->next;
////		int Cnt = 1;
////		while(q->val == p->val){
////			if(q->next){
////				q = q->next;
////				Cnt++;
////			}else{
////				p= NULL;
////				q = NULL;
////				break;
////			}
////		}
////		if(Cnt == 1 && p ){
////			newheadDup->next = p;
////			newheadDup = newheadDup->next;
////			newheadDup->next = NULL;
////		}
////		p = q;
////	}
////	return newhead->next;
////}
//网上另一种写法，值得学习，用了双指针
//ListNode* deleteDuplicates(ListNode* head) {
//	if(!head || !head->next){
//		return head;
//	}
//
//	ListNode**headDup = &head;            //headDup指向了head指针的地址
//	while(*headDup){
//		if((*headDup)->next && (*headDup)->val == (*headDup)->next->val){
//			ListNode*temp = (*headDup);
//			while(temp && (*headDup)->val == temp->val){
//				temp = temp->next;
//			}
//			(*headDup) = temp;
//		}else{
//			headDup = &((*headDup)->next);
//		}
//	}
//	return head;
//}

//如果是ListNode*headDup = head 那么headDup的指针仅仅是指向了head的所指向的元素，并不拥有改变这个元素的能力
//但是ListNode**headDup = &head就可以让headDup用有改变head链表的能力，所以下面这样子是不可能达到删除的目的
//需要像上面的代码那样书写
ListNode* deleteDuplicates(ListNode* head) {
	if(!head || !head->next){
		return head;
	}

	ListNode*headDup = head;            //headDup指向了head指针的地址
	ListNode*p = headDup;
	while(headDup){
		if(headDup->next && headDup->val == headDup->next->val){
			ListNode*temp = (headDup);
			while(temp && headDup->val == temp->val){
				temp = temp->next;
			}
			headDup = temp;
		}else{
			headDup = headDup->next;
		}
	}
	return p;
}
////递归的方法（网上）
////ListNode*deleteDuplicates(ListNode*head){
////	if(!head || !head->next) return head;
////	int val = head->val;
////	ListNode*p = head->next;
////	if(p->val!=val){
////		head->next = deleteDuplicates(p);
////		return head;
////	}else{
////		while(p && p->val == val) p = p->next;
////		return deleteDuplicates(p);
////	}
////}
//
int main(){
	int test[] = {1,1,2,2,2,3,3,4};  //10
	ListNode*head = new ListNode(-1);
	ListNode*p = head;
	for(int i = 0;i < sizeof(test)/sizeof(int);i++){
		ListNode*tmp = new ListNode(test[i]);
		p->next = tmp;
		p = p->next;
	}
	ListNode*result = deleteDuplicates(head->next);
	while(result){
		cout<<result->val<<" ";
		result = result->next;
	}
	return 0;
}

