#include <iostream>
#include <vector>
using namespace std;

//这是一个循环移位的问题，向右边循环移动k位，需要注意的是，k可能会大于链表的长度len，所以要将移位的step取为k%len 
//这题相对来说并不难，只是后面这个移位k可能大于len需要考虑
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 

 ListNode* rotateRight(ListNode* head, int k) {
	 if(head==NULL){
		return NULL;
	 }
	 if(k == 0){
		return head;
	 }
	 ListNode*headtemp = head;
	 ListNode*tailtemp = head;
	 int len = 1;
	 while(tailtemp->next!=NULL){
		 len++;
		 tailtemp = tailtemp->next;
	 }
	 int step = k%len;
	 if(step == 0){
		 return head;
	 }
	 for(int i = 1;i < len - step;i++){
		 headtemp = headtemp->next;
	 }
	 ListNode* tail = headtemp;
	 headtemp = headtemp->next;
	 tailtemp->next = head;
	 tail->next = NULL;
	 head = headtemp;
	 return head;
 }

 //int main(){
	//ListNode*head = new ListNode(1);
	//ListNode*headtemp = head;
	//for(int i = 1;i < 1;i++){
	//	ListNode*tmp = new ListNode(i+1);
	//	headtemp->next = tmp;
	//	headtemp = tmp;
	//}
	//headtemp = head;
	////while(head!=NULL){
	////	cout<<head->val<<" ";
	////	head = head->next;
	////}
	//ListNode*result = rotateRight(head,2);
	///*while(result!=NULL){
	//	cout<<result->val<<" ";
	//	result = result->next;
	//}*/
	////要注意内存的释放问题
	//ListNode*resulttemp = result;
	//while(resulttemp){
	//	ListNode*tmp = resulttemp;
	//	resulttemp = resulttemp->next;
	//	delete tmp;
	//	tmp = NULL;
	//}

	//return 0;
 //}