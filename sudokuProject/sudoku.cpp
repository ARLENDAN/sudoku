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
int result=0; //�����
int Num;
fstream Out_Put("sudoku.txt", ios::out);

//������еĽ�
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

//�ж��Ƿ���Խ���i�С���j�е�����Ϊk
bool check(int a[9][9],int i,int j,int k)
{
 int m,n;
 //�ж���
 for(n=0;n<9;n++)
 {
  if(a[i][n] == k)
   return false;
 }
 //�ж���
 for(m=0;m<9;m++)
 {
  if(a[m][j] == k)
   return false;
 }
 //�ж�����С�Ź���
 int t1=(i/3)*3,t2=(j/3)*3;
 for(m=t1;m<t1+3;m++)
 {
  for(n=t2;n<t2+3;n++)
  {
   if(a[m][n] == k)
    return false;
  }
 }
 //���У�����true
 return true;
}
//������⺯��
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
 i=n/9; j=n%9; //�����n����������������
 if(a[i][j] != 0) //�Ѿ���ԭʼ����
 {
  if(n == 80)   //�����һ�����ӣ�������н�
   {result++;print(t);}
   
  else    //�������һ�����ӣ�����һ������
   Shudu(t,n+1);
 }
 else    //û������
 {
  for(int k=1;k<=9;k++)
  {
   bool flag=check(t,i,j,k);
   if(flag) //��i�С���j�п�����k
   {
    t[i][j]=k; //��Ϊk
    if(n == 80)
      {result++;print(t);}
    else
     Shudu(t,n+1);
    t[i][j]=0; //�ָ�Ϊ0���ж���һ��k
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
		cout << "������������Ŀ����������ִ�б�����������ȷ��������Ŀ��" << endl;
		return 0;
	}
	else if(strcmp(argv[1],"-c") != 0)
	{
		cout<<"�����ʽ����"<<endl;
		return 0;
	}
	else
	{
		for(int i = 0;i < strlen(argv[2]);i++)
				if (argv[2][i] <'0'|| argv[2][i]>'9')
				{
					cout<<"������Ŀ����" << endl;
					return 0;
				}
	}
	Num = Input(argv[2]);
 	int a[9][9]={0};
 	Shudu(a,0);
 	Out_Put.close();

 return 0;
}

