#include<iostream>
#include<vector>
using namespace std;
int main(void)
{
	vector<int> vec;
	vec.begin()//指向迭代器中第一个元素。   
	vec.end()//指向迭代器中末端元素的下一个，指向一个不存在元素。          
	vec.push_back(elem)     //在尾部加入一个数据。  
	vec.pop_back()          //删除最后一个数据。  
	vec.capacity()  //vector可用空间的大小。  
	vec.size()//返回容器中数据个数。  
	vec.empty() //判断容器是否为空。  
	vec.front()     //传回第一个数据。  
	vec.back()  //传回最后一个数据，不检查这个数据是否存在。  
	vec.at(index)   //传回索引idx所指的数据，如果idx越界，抛出out_of_range。  
	vec.clear() //移除容器中所有数据。  
	vec.erase(iterator) //删除pos位置的数据，传回下一个数据的位置。  
	vec.erase(begin,end)    //删除[beg,end)区间的数据，传回下一个数据的位置。注意：begin和end为iterator  
	vec.insert(position,elem)   //在pos位置插入一个elem拷贝，传回新数据位置。  
	vec.insert(position,n,elem) //在pos位置插入n个elem数据，无返回值。  
	vec.insert(position,begin,end)  //在pos位置插入在[beg,end)区间的数据，无返回值。
}  