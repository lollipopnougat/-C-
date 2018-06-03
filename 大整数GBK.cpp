#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

class BigInteger
{
public:
	BigInteger() {}
	~BigInteger() {}
	void input();
	bool empty();
	void print();
	void operator=(const BigInteger &rhs);
	friend bool operator>(const BigInteger &lhs, const BigInteger &rhs);
	friend BigInteger operator+(const BigInteger &lhs, const BigInteger &rhs);
	friend BigInteger operator-(BigInteger &lhs, BigInteger &rhs);
private:
	int arry[100] = {0};
	string str;
	int len = 0;
};
bool operator>(const BigInteger &lhs, const BigInteger &rhs)
{
	if(lhs.len>rhs.len) return true;
	else if(rhs.len>lhs.len) return false;
	else
	{
		for(int i=0;i<lhs.len;i++)
		{
			if(lhs.arry[i]>rhs.arry[i]) 
				return true;	
			else if(rhs.arry[i]>lhs.arry[i]) return false;
		}
		return false;
	}
}

void BigInteger::operator=(const BigInteger &rhs)
{
	for (int i = 0; i < rhs.len; i++)
		this->arry[i] = rhs.arry[i];
	this->len = rhs.len;
}

BigInteger operator+(const BigInteger &lhs, const BigInteger &rhs)
{
	BigInteger result;
	int flag = 0, i = 0;
	while (i < lhs.len && i < rhs.len)
	{
		result.arry[i] = (lhs.arry[i] + rhs.arry[i] + flag) % 10;
		flag = (lhs.arry[i] + rhs.arry[i] + flag) / 10;
		i++;
	}
	for (; i < lhs.len; i++)
	{
		result.arry[i] = (lhs.arry[i] + flag) % 10;
		flag = (lhs.arry[i] + flag) / 10;
	}
	for (; i < rhs.len; i++)
	{
		result.arry[i] = (rhs.arry[i] + flag) % 10;
		flag = (rhs.arry[i] + flag) / 10;
	}
	result.len = max(lhs.len, rhs.len) + flag;
	if (flag == 1) result.arry[result.len] = 1;
	return result;
}

BigInteger operator-(BigInteger &lhs, BigInteger &rhs)
{
	BigInteger result;
	int i = 0;
	bool flag = false;
	if (rhs > lhs) return rhs - lhs;
	else
	{
		while (i < lhs.len)
		{
			if (flag) lhs.arry[i]--;
			flag = false;
			if (lhs.arry[i] >= rhs.arry[i]) result.arry[i] = lhs.arry[i] - rhs.arry[i];
			else
			{
				flag = true;
				lhs.arry[i] += 10;
				result.arry[i] = lhs.arry[i] - rhs.arry[i];
			}
			i++;
		}
		for (; i < lhs.len; i++)
		{
			if (flag) lhs.arry[i]--;
			flag = false;
			if (lhs.arry[i] < 0)
			{
				flag = true;
				lhs.arry[i] += 10;
			}
			result.arry[i] = lhs.arry[i];
		}
		for(i=lhs.len-1;i>=0;i--)
		{
			if(result.arry[i]!=0) break;
		}
		result.len = i+1;
		return result;	
	}
}


void BigInteger::input()
{
	cin >> str;
	len = str.size();
	for (int i = 0; i < len; i++)
	{
		if (str[len - i - 1] >= '0' && str[len - i - 1] <= '9')
			arry[i] = int(str[len - i - 1] - '0');
		else throw "输入的不是合法的数!";
	}
}

bool BigInteger::empty()
{
	if (len == 0) return true;
	else return false;
}

void BigInteger::print()
{
	if (len != 0)
	{
		for (int i = len - 1; i >= 0; i--)
			cout << arry[i];
		cout << endl;
	}
	else cout << "数字是空的！" << endl;

}



int main(int argc, char const *argv[])
{
	BigInteger num1, num2, resu;
	cout << "输入第一个大整数（大于0,小于10^100）" << endl;
	num1.input();
	cout << "输入第二个大整数" << endl;
	num2.input();
	resu = num1 + num2;
	cout<<"相加结果是:";
	resu.print();
	resu = num1 - num2;
	cout<<"相减结果是:";
	resu.print();
	system("pause");
	return 0;
}
