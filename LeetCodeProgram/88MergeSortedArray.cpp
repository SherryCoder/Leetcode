#include<iostream>
#include<vector>
using namespace std;

//void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//	vector<int>::iterator start = nums2.begin();
//	vector<int>::iterator oldstart;
//	for(vector<int>::iterator it = nums1.begin();it!=nums1.end();){
//		int val = *it;
//		vector<int>::iterator j;
//		oldstart = start;
//		for(j = start;j!= nums2.end();){
//			if(*j <= val){
//				if(j+1 < nums2.end()){
//					j++;
//				}else{
//					nums1.insert(it,start,nums2.end());
//					break;
//				}
//			}else{
//				//nums1.insert(i,nums2.begin()+start,nums2.begin()+j);
//				nums1.insert(it,start,j);
//				start = j;
//				break;
//			}
//		}
//		//int t= it +(start - oldstart);
//		
//		if(it + (start-oldstart) !=nums1.end()){
//			it += (start-oldstart);
//		}else{
//			break;
//		}
//	}
//}
//因为nums1是有足够的空间的，所有从空空间开始计算，比较好（参考网上）
//这题是easy难度。。。
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int i = m-1,j = n-1;
	int k = m+n-1;
	while(i>=0&&j>=0){
		if(nums1[i] > nums2[j]){
			nums1[k--]= nums1[i--];
		}else{
			nums1[k--] = nums2[j--];
		}
	}
	while(j>=0){
		nums1[k--] = nums2[j--];
	}
	return;
}
//int main(){
//	int num1[] = {1,8,10,30,50};
//	int num2[] = {1,2,3,9,22,40,60};
//	vector<int>nums1(12,0);
//	vector<int>nums2(7,0);
//	for(int i = 0;i < 5;i++){
//		nums1[i] = num1[i];
//	}
//	for(int i = 0;i < 7;i++){
//		nums2[i] = num2[i];
//	}
//	merge(nums1,5, nums2, 7) ;
//	for(int i = 0;i < 12;i++){
//		cout<<nums1[i]<<" ";
//	}
//	cout<<endl;
//	return 0;
//}