#define _CRT_SECURE_NO_WARNINGS	
/* 1.源程序改错题 */
/*
#include "stdio.h"
long sum_fac(int n);	//函数声明
void main(void)
{
	int k;
	for (k = 1; k < 6; k++)
		printf("k=%d\tthe sum is %ld\n", k, sum_fac(k));
}
long sum_fac(int n)
{
	long s = 0;
	int i;
	long fac=1;	//fac赋初值
	for (i = 1; i <= n; i++)
	{
		fac *= i;
		s += fac;
	}	//复合语句
	return s;
}


/* 2.源程序修改替换题 */
/* （1） */
/*
#include "stdio.h"
long sum_fac(int n);	//函数声明
void main(void)
{
	int k;
	for (k = 1; k < 6; k++)
		printf("k=%d\tthe sum is %ld\n", k, sum_fac(k));
}

long sum_fac(int n)
{
	static long s = 0;
	static long fac = 1;
	fac *= n;	//求n!
	s += fac;	// s=s+n!
	return s;
}


/* (2) */
/*
#include "stdio.h"
double sum_fac(int n);	//函数声明
void main(void)
{
	int k;
	for (k = 1; k < 6; k++)
		printf("k=%d\tthe sum is %lf\n", k, sum_fac(k));
}

double sum_fac(int n)
{
	static double s = 0;
	static double fac = 1;
	fac *= n;	//求n!
	s += 1/ fac;	// s=s+1/n!
	return s;
}


/* 3.跟踪调试题 */
/*
#include<stdio.h>
void main(void)
{
	int i, k;
	long sum = 0, * p = &sum;
	scanf("%d", &k);
	for (i = 1; i <= k; i++) {
		sum += fabonacci(i);
		printf("i=%d\tthe sum is %ld\n", i, *p);
	}
}
long fabonacci(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return fabonacci(n - 1) + fabonacci(n - 2);
}


/* 4.编程设计题 */
/* （1） */
/*
#include<stdio.h>
MaxDiv(int a, int b)
{
	if (a % b != 0)	//若余数不为0则除数作为被除数，余数作为除数辗转相除
		return MaxDiv(b, a % b);
	else	//若余数为0则除数为最大公约数
		return  b;
}

int main()
{
	int a, b,result;
	printf("请输入两个整数：");
	scanf("%d %d", &a, &b);
	if (a <= 0 || b <= 0)
		printf("输入错误！\n");
	else
	{
		result=MaxDiv(a, b);
		printf("最大公约数为：%d\n", result);
	}
	return 0;
}


/* (2) */
/*
#include<stdio.h>
#include<math.h>
IsPrime(int n)	//判断n是否为素数
{
	int i;
	double temp=sqrt(n);
	for (i = 2; i <= temp; i++)
		if (n % i == 0)		//若余数为0则不为素数
			return 0;
	return 1;	//若一直有余数则为素数
}

void Goldbach(int n)	//验证n满足哥德巴赫猜想猜想
{
	int temp,a;
	for (temp = n / 2, a = 2; a <= temp; a++)
		if (IsPrime(a) && IsPrime(n - a))	//判断a和n-a是否为素数
		{
			printf("%d=%d+%d\n", n, a, n - a);	//都为素数则满足条件输出
			return;
		}
	printf("不满足哥德巴赫猜想!\n");
}

int main()
{
	int n;
	printf("请输入一个大于等于4的偶数：");
	scanf("%d", &n);
	if (n % 2 || n < 4)
			printf("输入错误！\n");
	else
		Goldbach(n);
	return 0;
}


/* (3) */
/*
#include<stdio.h>
#include<math.h>
#define BEGIN 10
#define END 20
IsPrime(int n)	//判断n是否为素数
{
	int i;
	double temp = sqrt(n);
	for (i = 2; i <= temp; i++)
		if (n % i == 0)
			return 0;
	return 1;
}

void Goldbach(int n)	//验证n满足哥德巴赫猜想猜想
{
	int temp, a;
	for (temp = n / 2, a = 2; a <= temp; a++)
		if (IsPrime(a) && IsPrime(n - a))
		{
			printf("%d=%d+%d\n", n, a, n - a);
			return;
		}
	printf("不满足哥德巴赫猜想!\n");
}

int main()
{
	int i;
	printf("GOLDBACH'S CONJECTURE:\n");
	printf("Every even number n>=4 is the sum of two primes.\n");
	for (i = BEGIN; i <= END; i+=2)
		Goldbach(i);	//验证BEGIN到END的偶数的哥德巴赫猜想
	return 0;
}

/**/