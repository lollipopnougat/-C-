#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
 	
    system("adb shell screencap -p /sdcard/фад╩╫ьм╪.png");
    system("adb pull /sdcard/фад╩╫ьм╪.png ");
    system("adb shell rm -r /sdcard/фад╩╫ьм╪.png ");
	
    return 0;
}

