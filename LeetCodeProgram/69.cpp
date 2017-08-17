#include<iostream>
using namespace std;
//本题的解题思路：（二分法）
//如果用一般的操作，运行时间会TIE 所以要用二分法，其实这是一个很简单的二分法啊，需要注意的是要用longlong型数据
//
//超时的作法
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
//		if(mid*mid == x){     //用注意mid*mid有可能会溢出，所以数据类型要设为longlong类型
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