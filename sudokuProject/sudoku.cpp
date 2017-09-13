#include <stdio.h>
#include <tchar.h>
#include<iostream>
#include<string>
#include<cstring>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include<algorithm>
#include<sstream>
using namespace std;
int result=0; //结果数
int Num;
fstream Out_Put("sudoku.txt", ios::out);

//输出可行的解
void print(int a[9][9])
{
	if (Out_Put.is_open())
	{
		for (int i = 0;i < 9;i++)
		{
			for (int j = 0;j < 9;j++)
			{
				Out_Put << a[i][j] << " ";
				
			}
			Out_Put << endl;
		}
		Out_Put << endl;
	}

}

//判断是否可以将第i行、第j列的数设为k
bool check(int a[9][9],int i,int j,int k)
{
 int m,n;
 //判断行
 for(n=0;n<9;n++)
 {
  if(a[i][n] == k)
   return false;
 }
 //判断列
 for(m=0;m<9;m++)
 {
  if(a[m][j] == k)
   return false;
 }
 //判断所在小九宫格
 int t1=(i/3)*3,t2=(j/3)*3;
 for(m=t1;m<t1+3;m++)
 {
  for(n=t2;n<t2+3;n++)
  {
   if(a[m][n] == k)
    return false;
  }
 }
 //可行，返回true
 return true;
}
//数独求解函数
void Shudu(int a[9][9],int n)
{
	if(Num==result) return;
 int t[9][9];
 int i,j;
 for(i=0;i<9;i++)
 {
  for(j=0;j<9;j++)
   t[i][j]=a[i][j];
 }
 i=n/9; j=n%9; //求出第n个数的行数和列数
 if(a[i][j] != 0) //已经有原始数据
 {
  if(n == 80)   //是最后一个格子，输出可行解
   {result++;print(t);}
   
  else    //不是最后一个格子，求下一个格子
   Shudu(t,n+1);
 }
 else    //没有数据
 {
  for(int k=1;k<=9;k++)
  {
   bool flag=check(t,i,j,k);
   if(flag) //第i行、第j列可以是k
   {
    t[i][j]=k; //设为k
    if(n == 80)
      {result++;print(t);}
    else
     Shudu(t,n+1);
    t[i][j]=0; //恢复为0，判断下一个k
   }
  }
 }
}

int  Input(string input)
{
	int n;
	stringstream ss;
	ss.clear();
	ss << input;
	ss >> n;
	return n;
}

int main(int argc, char* argv[])
{
	if(argc!=3)
	{
		cout << "您输入生成数目错误，请重新执行本程序，输入正确的生成数目！" << endl;
		return 0;
	}
	else if(strcmp(argv[1],"-c") != 0)
	{
		cout<<"输入格式有误"<<endl;
		return 0;
	}
	else
	{
		for(int i = 0;i < strlen(argv[2]);i++)
				if (argv[2][i] <'0'|| argv[2][i]>'9')
				{
					cout<<"生成数目错误" << endl;
					return 0;
				}
	}
	Num = Input(argv[2]);
 	int a[9][9]={0};
 	Shudu(a,0);
 	Out_Put.close();

 return 0;
}

