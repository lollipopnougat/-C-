#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int main(void)
{
	string s1,s2="0123456789";
	int f[10],t;
	cin>>s1;
	for(int i=0;i<10;i++)
	{
		if(s1.find(s2[i])!=s1.npos) 
		{
			t=s1.find(s2[i]);
			cout<<"ËÑË÷×Ö·û"<<s2[i]<<"\tÔÚ×Ö·û´®Î»ÖÃ"<<t<<endl;
			if(t>=s1.size()) break;
			while(s1.find(s2[i])!=string::npos)
			{
				if(t>=s1.size()) break;
				t=s1.find(s2[i],t+1);
				cout<<"ËÑË÷×Ö·û"<<s2[i]<<"\tÔÚ×Ö·û´®Î»ÖÃ"<<t<<endl;
			
			}
		}
	}
	system("pause");
	return 0;
}
