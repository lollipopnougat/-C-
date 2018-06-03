#include<iostream>
#include<string>
#include<sstream>
#include<cstdlib> 
#include<vector>
using namespace std;
struct NumData
{
	double num1;
	char my3rd;
	double num2;
};
class Calculator
{
public:
	double Methods(NumData sy);
private:
	double solution;
};
class ProcessStr
{
public:
	double ExportToVec(string strin);
	//int debug();
private:
	int add = 0, sub = 0, mul = 0, div = 0;
	vector<double> num;
	vector<char> sym;
	string temp;
	stringstream ss;
	double ex;
	bool IsNum(char ty);
	bool LIS = false;
	void Str2Vec();
	void Counter(char symbol);
	double Send2Cal(double n1, char s1, double n2);
	void Counter2(char d);
	double SearchProcess();
};
/*int ProcessStr::debug()
{
	string str;
	cin >> str;
	cout << "字符串是：" << str << "\n长度为：" << str.size() << endl;
	ExportToVec(str);
	vector<double>::iterator it;
	for (it = num.begin(); it != num.end(); it++)
		cout << *it << endl;
	//it迭代器 
	cout << endl;
	vector<char>::iterator ite;
	for (ite = sym.begin(); ite != sym.end(); ite++)
		cout << *ite << endl;
	//迭代器 
	cout << "+ - * /\n" << add << " " << sub << " " << mul << " " << div << endl;
	system("pause");
	return 0;
}*/
int main()
{
	ProcessStr p1;
	/*if (p1.debug() != 0)
		cout << "Error!" << endl;
	else return 0;*/
	string str;
	cin>>str;
	cout<<p1.ExportToVec(str)<<endl;
	return 0;

}
bool ProcessStr::IsNum(char ty)
{
	if (ty >= '0'&&ty <= '9') return true;
	else return false;
}
void ProcessStr::Str2Vec()
{

	if (temp == "-" || temp == "")
	{
		cout << "Error!请重新输入：" << endl;
		main();
	}
	else
	{
		ss << temp;
		ss >> ex;
		ss.clear();
		ss.str("");
		temp = "";
		num.push_back(ex);
	}
}
void ProcessStr::Counter(char symbol)
{
	switch (symbol)

	{
	case '+':add++; break;
	case '-':sub++; break;
	case '*':mul++; break;
	case '/':div++; break;
	default:cout << "错误数据！" << endl;
	}
}
double ProcessStr::ExportToVec(string strin)
{
	if (!strin.empty())
	{
		for (int i = 0; i<strin.size(); i++)
		{
			if (IsNum(strin[i]) || (i == 0 & strin[i] == '-') || (i != 0 && strin[i] == '.'))
			{
				temp += strin[i];
				LIS = false;
			}
			else
			{
				if (LIS&&strin[i] == '-')
				{
					temp += strin[i];
					LIS = false;
				}
				else
				{
					Str2Vec();
					sym.push_back(strin[i]);
					Counter(strin[i]);
					LIS = true;
				}

			}
		}
		if (!temp.empty()) Str2Vec();
	}
	else cout << "空的..." << endl;
	return SearchProcess();
}
void ProcessStr::Counter2(char d)
{
	switch (d)
	{
	case '+':add--; break;
	case '-':sub--; break;
	case '*':mul--; break;
	case '/':div--; break;
	default:cout << "错误数据！" << endl;
	}
}
double ProcessStr::SearchProcess()
{
	string exam = "*/+-";
	for (int j = 0; j<4; j++)
	{
		int symn[4] = { mul,div,add,sub };
		for (int i = 0; i<= symn [j]; i++)
		{
			if (sym.at(i) == exam[j])
			{
				Counter2(exam[j]);
				num.at(i + 1) = Send2Cal(num.at(i), exam[j], num.at(i + 1));

				if (add == 0 && sub == 0 && mul == 0 && div == 0)
					ex = num.at(i + 1);
			}
		}
	}
	return ex;
}
double ProcessStr::Send2Cal(double n1, char s1, double n2)
{
	Calculator c1;
	NumData sy1 = { n1,s1,n2 };
	return c1.Methods(sy1);
}
double Calculator::Methods(NumData sy)
{
	switch (sy.my3rd)
	{
	case '+':solution = sy.num1 + sy.num2; break;
	case '-':solution = sy.num1 - sy.num2; break;
	case '*':solution = sy.num1*sy.num2; break;
	case '/':
	{
		try
		{
			if (sy.num2 == 0) throw "错误！除数不能为零!";
			solution = sy.num1 / sy.num2;
		}
		catch (char *str)
		{
			cout << str << endl;
			cout << "请重新输入计算式：" << endl;

		}
	}break;
	default:
	{
		cout << "错误！输入了无效字符！" << endl;
		cout << "请重新输入计算式：" << endl;
	}
	}
	return solution;
}
