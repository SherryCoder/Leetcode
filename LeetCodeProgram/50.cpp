#include <iostream>
#include <vector>
using namespace std;

//����һ��ģ����pow����Ŀ����Ŀ��ʵҲ���Ǻ��ѣ���Ҫ���ǵļ��㣺1��n�����Ǹ�������ôINT_MINת�������ᳬ��һ��������Ҫ���ô�ʩ�����о���ʱ�临�Ӷȵ�����
//�����ö��ַ�������ʱ�临�Ӷ�

//������
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