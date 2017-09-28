//显示图像文件
//#include <opencv2/opencv.hpp>
//using namespace std;
//#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
//int main()
//{
//    const char *pstrImageName = "curry.jpg";
//    const char *pstrWindowsTitle = "OpenCV第一个程序";
//    //从文件中读取图像
//    IplImage *pImage = cvLoadImage(pstrImageName, CV_LOAD_IMAGE_UNCHANGED);
//    //创建窗口
//    cvNamedWindow(pstrWindowsTitle, 0);
//    //在指定窗口中显示图像
//    cvShowImage(pstrWindowsTitle, pImage);
//    //等待按键事件
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
