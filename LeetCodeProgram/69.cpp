#include<iostream>
using namespace std;
//����Ľ���˼·�������ַ���
//�����һ��Ĳ���������ʱ���TIE ����Ҫ�ö��ַ�����ʵ����һ���ܼ򵥵Ķ��ַ�������Ҫע�����Ҫ��longlong������
//
//��ʱ������
//int mySqrt(int x) {
//	for(int i = 0;i <=x ;i++){
//		if(i*i == x){
//			return i;
//		}
//		if(i*i > x){
//			return i-1;
//		}
//	}
//}

//int mySqrt(int x){
//	long long left = 1;
//	long long right = x/2+1;
//	long long mid;
//	while(left<=right){
//		mid = left + (right - left)/2;
//		if(mid*mid == x){     //��ע��mid*mid�п��ܻ������������������Ҫ��Ϊlonglong����
//			return mid;
//		}
//		if(mid*mid < x){
//			left = mid + 1;
//		}
//		if(mid*mid > x){
//			right = mid - 1;
//		}
//	}
//	return (left+right)/2;
//}

int mySqrt(int x){
	long long left = 0,right = x,mid;
	mid = (left + right)/2;
	while(left <= right){
		if(mid*mid <= x && (mid+1)*(mid+1) > x){
			return mid;
		}
		if(mid*mid < x){
			left = mid + 1;
			mid = (left+right) / 2;
		}
		if(mid*mid > x){
			right = mid - 1;
			mid = (left+right)/2;
		}
	}
} 

//int main(){
//	int res = mySqrt(2);
//	cout<<res<<endl;
//	cout<<9/2<<endl;
//	return 0;
//}