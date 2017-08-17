#include <iostream>
#include <vector>
using namespace std;

//这是一道模拟求pow的题目。题目其实也不是很难，需要考虑的几点：1、n可能是负数，那么INT_MIN转成整数会超过一个，所以要做好措施，还有就是时间复杂度的问题
//可以用二分法来降低时间复杂度

//待测试
double myPow(double x, int n) {
	if(n == 0){
		return 1.0;
	}
	if(n>0){
		double half = (double)myPow(x,n/2);
		if(n%2 == 0){
			return half*half;
		}else{
			return half*half*x;
		}
	}else {
		if(n == INT_MIN){
			return 1.0/myPow(x,INT_MAX)*x;
		}
		return 1.0/myPow(x,-n);
	}
}

//double myPow(double x,int n){
//	if(n == 0){
//		return 1.0;
//	}
//	else{
//		if(n < 0){
//			if(n == INT_MIN){
//				return 1.0/(myPow(x,INT_MAX)*x);
//			}
//			return 1.0/myPow(x,-n);
//		}else{
//			if(n%2 == 0){
//				double half = myPow(x,n>>1);
//				return half*half;
//			}else{
//				double half = myPow(x,(n-1)>>1);
//				return half*half*x;
//			}
//		}
//	}
//}


//int main(){
//	double result = myPow(34.00515,-3);
//	//cout<<fixed<<<<endl;
//}