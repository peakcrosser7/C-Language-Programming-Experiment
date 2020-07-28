#define _CRT_SECURE_NO_WARNINGS		//VS编译器的原因需要添加的宏定义
/* 1、源程序改错题 */
/*
#include<stdio.h>
#define PI 3.14159	//去掉分号；
void main( void )
{
   int f ;
   short p, k ;
   double c , r , s ;
   short newint;	//task3定义变量newint

// for task 1
   printf("Input  Fahrenheit:" ) ;
   scanf("%d", &f ) ;	//scanf形参表需加&
   c = 1.0*5/9*(f-32) ;	//保证5/9结果为浮点数要乘1.0
   printf( " \n %d (F) = %.2f (C)\n\n ", f, c ) ;

// for task 2 
	printf("input the radius r:");
	scanf("%lf", &r);	//double类型格式输出符为%lf
	s = PI*r*r;
	printf("\nThe acreage is %.2f\n\n",s);	//去掉printf形参表中的&

// for task 3 
	printf("input hex int k, p :");
	scanf("%hx %hx", &k, &p );
	newint = (p&0xff00)|(k&0xff00)>>8;	//将<<改为>> 作为低字节
	printf("new int = %hx\n\n",newint);

}


/* 2、源程序修改替换题 */
/*
#include<stdio.h>

void main( )
{
   int a, b;
   printf("Input two integers:");
   scanf("%d %d",&a,&b);
   //a=a+b;	//方法一
   //b=a-b;
   //a=a-b;
   a=a^b; //方法二
   b=a^b;
   a=a^b;
   printf("\na=%d,b=%d",a,b);
}


/* 3、编程设计题 */
/* (1)  */
/*
#include<stdio.h>

int main()
{
	char c;
	printf("Input a char:\n");
	c=getchar();
	c=(c>='A'&&c<='Z')?c+32:c;		//若为大写字母变换为小写字母，否则不变
	printf("%c\n",c);
	return 0;
}

/* (2) */
/*
#include<stdio.h>
#include<math.h>

int main()
{
	unsigned short x, m, n;
	printf("输入x（16进制）、m（0~15）和n（1~16-m）:\n");
	scanf("%hx%hd%hd", &x, &m, &n);
	if(m>=0&&m<=15 && n>=1&& m<=16-m)	//判断m、n的值是否在合理范围内
	{
		x = x >> m;
		x = x << (16 - n);
		printf("result=%hx\n",x);	//输出结果
	}
	else
		printf("输入错误！\n");		//输出错误则提示并退出
	return 0;
}


/* (3) */
/*
#include<stdio.h>
int main()
{
	char temp;	//临时储存输入字符
	int i,flag=1;
	unsigned long bin;	//临时储存输入的1或0
	unsigned long savenum=0;	//机器储存的IP地址
	unsigned long byte[4] = { 0xff000000,0x00ff0000,0x0000ff00,0x000000ff };
	printf("请输入32位IP地址: ");
	for(i=0;i<32&&flag;i++)	//输入32位IP地址
	{
		temp=getchar();		//输入32位IP地址
		if(temp=='1'||temp=='0')	//合法性判断
		{
			bin=temp=='1'?1:0;	//储存输入的1或0
			savenum|=bin<<(31-i);		//计算IP每一部分的数字
		}
		else
		{
			flag = 0;	//输入非法字符则退出循环
			printf("\n输入错误！\n");	//有非法输入则提示输入错误
		}
	}
	if (flag)
	{
		printf("\nIP Adress:");
		for (i = 0; i < 4; i++)
			printf("%lu.", (byte[i] & savenum) >> (3 - i) * 8);
			//输出IP地址每一部分的数字
		printf("\b \n");
	}		
	return 0;
}
/**/