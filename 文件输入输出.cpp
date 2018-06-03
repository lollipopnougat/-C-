#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ifstream f("1.txt");
	ofstream p("2.txt");
	string line;
	getline(f,line);
	cout<<line<<endl;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		p<<line<<endl;
	p.close();
	f.close();
    return 0;
}

