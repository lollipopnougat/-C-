#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
 	
    system("adb shell screencap -p /sdcard/��Ļ��ͼ.png");
    system("adb pull /sdcard/��Ļ��ͼ.png ");
    system("adb shell rm -r /sdcard/��Ļ��ͼ.png ");
	
    return 0;
}

