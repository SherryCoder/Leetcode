//��ʾͼ���ļ�
//#include <opencv2/opencv.hpp>
//using namespace std;
//#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
//int main()
//{
//    const char *pstrImageName = "curry.jpg";
//    const char *pstrWindowsTitle = "OpenCV��һ������";
//    //���ļ��ж�ȡͼ��
//    IplImage *pImage = cvLoadImage(pstrImageName, CV_LOAD_IMAGE_UNCHANGED);
//    //��������
//    cvNamedWindow(pstrWindowsTitle, 0);
//    //��ָ����������ʾͼ��
//    cvShowImage(pstrWindowsTitle, pImage);
//    //�ȴ������¼�
//    cvWaitKey();
//    cvDestroyWindow(pstrWindowsTitle);
//    cvReleaseImage(&pImage);
//    return 0;
//}

#include<iostream>
#include<vector>
#include<sstream>
#include<string>

using namespace std;

int main(){
	stringstream stream;
	string a,b;
	int t = 5;
	a ="->" + to_string(t);
	//a += b;
	cout<<a<<endl;
	return 0;
}
