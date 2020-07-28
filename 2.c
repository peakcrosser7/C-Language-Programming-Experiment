#define _CRT_SECURE_NO_WARNINGS		//VS编译器的原因需要添加的宏定义

/* 1.源程序改错题 */
/*
#include <stdio.h>
void main(void)
{
	int i, n;
	long long s = 1;
	printf("Please enter n:");
	scanf("%d", &n);	//改为&n
	for (i = 1; i <= n; i++)	//逗号改为分号
		s = s * i;
	printf("%d! = %lld", n, s);
}


/* 2.源程序修改替换题 */
/* （1）*/
/* while替换 */
/*
#include<stdio.h>
int main()
{
	int i = 1, n;
	long long s = 1;
	printf("Please enter n:");
	scanf("%d", &n);
	while (i <= n)
	{
		s *= i;
		i++;
	}
	printf("while替换:\n%d!=%lld\n", n, s);
	return 0;
}

/* do-while替换 */
/*
#include<stdio.h>
int main()
{
	int i = 1, n;
	long long s = 1;
	printf("Please enter n:");
	scanf("%d", &n);
	do
	{
		s *= i;
		i++;
	}while(i<=n);
	printf("do-while替换:\n%d!=%lld", n, s);
	return 0;
}

/* (2) */
/*
#include<stdio.h>
int main()
{
	int S, n=0,factorial=1;		//factorial为阶乘值
	printf("Please enter int S:");
	scanf("%d", &S);
	while (factorial < S)
	{
		n++;
		factorial *= n;
	}
	printf("n=%d\n", n);
	return 0;
}

/* 3.编程设计题 */
/* （1） */
/* if实现 */
/*
#include<stdio.h>
int main()
{
	float x, tax1;		//tax1为if得出税额
	printf("输入工资金额：");
	scanf("%f", &x);
	if (x < 1000)		//根据工资分类收取税额（if实现）
		tax1 = 0;
	else if (x >= 1000 && x < 2000)
		tax1 = x * 0.05;
	else if (x >= 2000 && x < 3000)
		tax1 = x * 0.1;
	else if (x >= 3000 && x < 4000)
		tax1 = x * 0.15;
	else if (x >= 4000 && x < 5000)
		tax1 = x * 0.2;
	else
		tax1 = x * 0.25;
	printf("\n收取税金额度(if)：%g\n", tax1);
	return 0;
}

/* switch 实现 */
/*
#include<stdio.h>
int main()
{
	float x, tax2;		//tax2为switch得出税额
	printf("输入工资金额：");
	scanf("%f", &x);
	switch ((int)x / 1000)	//根据工资分类收取税额（switch实现）
	{
	case 0:tax2 = 0;
		break;
	case 1:tax2 = x * 0.05;
		break;
	case 2:tax2 = x * 0.1;
		break;
	case 3:tax2 = x * 0.15;
		break;
	case 4:tax2 = x * 0.2;
		break;
	default:tax2 = x * 0.25;
	}
	printf("\n收取税金额度(switch)：%g\n", tax2);
	return 0;
}


/* (2) */
/* 有数组 */
/*
#include<stdio.h>
int main()
{
	char s[100];
	int i=0;
	printf("请输入一行字符：");
	gets(s,99);
	printf("\n处理后字符：");
	while(s[i])
	{
		putchar(s[i]);		//输出当前下标字符
		if (s[i] == ' ')	//若当前字符为空格
			for (; s[i] == ' '; i++);	//则继续判读之后字符，一直到非空格字符为止
		else
			i++;
	}
	return 0;
}

/* 无数组 */
/*
#include<stdio.h>
int main()
{
	char c;
	int flag = 1;
	printf("请输入一行字符：");
	while ((c=getchar())!='\n')
	{
		if (c == ' ' && !flag)		
		//若当前字符为空格且flag为0则跳过本次循环
			continue;
		else if (c == ' ')	//若输入的数为空格则flag置零
			flag = 0;
		else
			flag = 1;		//若不为空格flag置1
		putchar(c);
	}
	putchar('\n');
	return 0;
}


/* (3) */
/*
#include<stdio.h>
int main()
{
	int i, j,num;
	for (i = 0; i < 10; i++)
	{
		putchar('\t');
		for (j = 0; j < (9 - i) * 2; j++)
			putchar(' ');		//输出前面空格
		for (j = 0,num=1; j <= i; j++)
		{
			if (j)		//若数值不为第一个
				num =num* (i - j + 1) / j;	//按照公式C(i,j)=C(i,j-1)*（i-j+1)/j
			printf("%-4d",num);	//若数值为第一个则直接输出1
		}
		putchar('\n');
	}
	return 0;
}


/* (4) */
/*
#include<stdio.h>
int main()
{
	int num,temp,flag=0;	//flag用于去除前导0
	printf("请输入一个正整数:");
	scanf("%d", &num);
	if (num > 0)
	{
		printf("逆转后结果为：");
		while(num)
		{
			temp = num % 10;
			if (temp!= 0 && !flag)
				flag = 1;	//遇到第一个不为0的数则flag置1
			if(flag)	//当flag=1时输出数字
				printf("%d", temp);
			num /= 10;
		}
		printf("\n");
	}
	else
		printf("输入错误!\n");
	return 0;
}

/* 4.选做题 */
/*
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	double x1,x2;
	srand((unsigned)time(NULL));
	x2 = rand();	//生成一个随机数作为近似根迭代初值
	do
	{
		x1 = x2;
		x2 = x1 - (3 * x1 * x1 * x1 - 4 * x1 * x1 - 5 * x1 + 13) / (9 * x1 * x1 - 8 * x1 - 5);
		//按公式操作
	} while (fabs(x2 - x1) > 1e-6);		//当两数值差值大于精度值则继续循环
	printf("近似根：%lf\n", x2);
	return 0;
}

/**/
