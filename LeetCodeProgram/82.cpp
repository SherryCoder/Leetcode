#include<iostream>
using namespace std;
//ɾ���������ظ���Ԫ�أ�ֻ����ֻ��һ��Ԫ�ص�Ԫ��
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
//������һ��д����ֵ��ѧϰ������˫ָ��
//ListNode* deleteDuplicates(ListNode* head) {
//	if(!head || !head->next){
//		return head;
//	}
//
//	ListNode**headDup = &head;            //headDupָ����headָ��ĵ�ַ
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

//�����ListNode*headDup = head ��ôheadDup��ָ�������ָ����head����ָ���Ԫ�أ�����ӵ�иı����Ԫ�ص�����
//����ListNode**headDup = &head�Ϳ�����headDup���иı�head��������������������������ǲ����ܴﵽɾ����Ŀ��
//��Ҫ������Ĵ���������д
ListNode* deleteDuplicates(ListNode* head) {
	if(!head || !head->next){
		return head;
	}

	ListNode*headDup = head;            //headDupָ����headָ��ĵ�ַ
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
////�ݹ�ķ��������ϣ�
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

