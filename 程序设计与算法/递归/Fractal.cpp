#include <iostream>
#include <cmath>
using namespace std;
char matrix[2000][2000];//输出用的矩阵 
void draw(int n,int x,int y)//n为输出的degree，x,y为开始输出的左上角坐标 
{
	if(n==1)
	{
		matrix[x][y]='X';
		return ;
	}
	else
	{
		draw(n-1,x,y);//打印左上角
		draw(n-1,x+2*pow(3,n-2),y);//打印左下角
		draw(n-1,x,y+2*pow(3,n-2)) ;//打印右上角
		draw(n-1,x+2*pow(3,n-2),y+2*pow(3,n-2));//打印右下角 
		draw(n-1,x+pow(3,n-2),y+pow(3,n-2));//打印中间 
	}
	
}
void print(int wid)
{
	for(int i=0;i<wid;i++)
	{
		for(int j=0;j<wid;j++)
		{
			cout<<matrix[i][j];
		}
		cout<<endl;
	}
	cout<<"-"<<endl;
}
int main()
{
	int degree;
	cin>>degree;
	while(degree!=-1)
	{
		int wid=pow(3,degree-1);//degree为i的时候输出矩阵的宽度 
		for(int i=0;i<wid;i++)//初始化矩阵为空白 
		{
			for(int j=0;j<wid;j++)
			{
				matrix[i][j]=' ' ;
			}
		} 
		draw(degree,0,0); 
		print(wid);
		cin>>degree;
	}
} 
