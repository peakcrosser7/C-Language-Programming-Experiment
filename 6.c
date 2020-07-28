#define _CRT_SECURE_NO_WARNINGS	

/* 1.源程序改错题 */
/*
#include "stdio.h"
void main(void)
{
	float f;		//定义一个float变量
	float* p=&f;	//让指针指向先前的变量
	scanf("%f", p);
	printf("%f\n", *p);
}


/* 2.源程序完善、修改、替换题 */
/*
#include "stdio.h"
#include "string.h"
void main(void)
{
	char* (*p)(char* dest,char* src)=NULL;		//添加函数指针p的定义（填空）
	char a[80], b[80], c[160], * result = c;
	int choice, i;
	do {
		printf("\t\t1 copy string.\n");
		printf("\t\t2 connect string.\n");
		printf("\t\t3 exit.\n");
		printf("\t\tinput a number (1-3) please!\n");
		scanf("%d", &choice);
	} while (choice < 1 || choice>3);		//改错choice>5改为>3
	switch (choice) {
	case 1:
		p = strcpy;
		break;
	case 2:
		p = strcat;
		break;
	case 3:
		goto down;
	}
	getchar();
	printf("input the first string please!\n");
	i = 0;
	gets(a);	//输入字符串a（填空）
	printf("input the second string please!\n");
	i = 0;
	gets(b);	//输入字符串b（填空）
	result = p(a, b);	//调用函数指针（填空）
	printf("the result is %s\n", result);
down:
	;
}


/* 3.跟踪调试题 */
/* (1) */
/*
#include "stdio.h"
char* strcpy(char*, char*);
void main(void)
{
	char a[20], b[60] = "there is a boat on the lake.";
	printf("%s\n", strcpy(a, b));

}
char* strcpy(char* s, char* t)
{
	while (*s++ = *t++)
		;
	return (s);
}


/* (2) */
/*
#include "stdio.h"
char* strcpy(char*, char*);
void main(void)
{
	char a[60], b[60] = "there is a boat on the lake.";		//将字符数组a的容量加大
	printf("%s\n", strcpy(a, b));

}
char* strcpy(char* s, char* t)
{
	char* p = s;	//添加新的指针p，使发生变动的指针为p而不为s
	while (*p++ = *t++)
		;
	return (s);
}


/* 4.编程设计题 */
/* （1） */
/*
#include<stdio.h>

char changec(char c)
{
	if (c < 10)
		return c | '0';
	else
		return c - 10 + 'A';
}

int main()
{
	long a=0x1234ABCD;
	char* pc = (char*)&a,c;
	int i = 0;
	printf("请输入一长整型数：");
	scanf("%lx", &a);
	printf("输出结果：\n字节  高四位  低四位\n");
	for (i = 0; i < 4; i++)
	{
		printf("No.%d  ", i+1);
		c = changec((*pc>>4) & 0xf);
		printf("%6c  ", c);
		c = changec(*pc & 0xf);
		printf("%6c\n", c);
		pc++;
	}
	return 0;
}


/* (2) */
/*
#include<stdio.h>
#define N 5

void changestr(char *p)
{
	int j,flag;
	if (p[0])
	{
		for (flag = 1, j = 0; p[j]; j++)
		{
			if (p[j] == ' ' && flag)
				flag = 0;
			else if (p[j] == ' ' && !flag)
				continue;
			else
				flag = 1;
			putchar(p[j]);
		}
		putchar('\n');
	}
}

int main()
{
	int i;
	char s[N][80];
	char* p[N];
	printf("请输入文本：\n");
	for (i = 0; i < N; i++)
	{
		p[i] = s[i];
		gets(p[i]);
	}
	printf("调整后结果：\n");
	for(i=0;i<N;i++)
		changestr(p[i]);
	return 0;
}



/* (4) */
/*
#include<stdio.h>
#define N 3		//学生数
#define M 2		//课程门数

void inputscorenames(char(*s)[10])
{
	int i;
	printf("请输入%d门课程的名称：\n", M);
	for (i = 0; i < M; i++)
		scanf("%s",*(s+i));
}

void inputscores(float(*p)[M],char (*s)[10])
{
	int i, j;
	printf("请分别输入%d名学生的%d门成绩：\n",N,M);
	for (i = 0; i < N; i++)
	{
		printf("第%d名学生：\n", i+1);
		for (j = 0; j < M; j++)
		{
			printf("%s:", *(s + j));
			scanf("%f", *(p + i) + j);
		}
	}		
}

void putstuave(float(*p)[M])
{
	int i, j;
	float sum;
	for (i = 0; i < N; i++)
	{
		for (sum = 0, j = 0; j < M; j++)
			sum += *(*(p + i) + j);
		printf("第%d名同学的平均成绩为：%.2f\n", i+1, sum/M);
	}	
}

void putscoave(float(*p)[M],char (*s)[10],float* scoave)
{
	int i, j;
	float sum;
	for (i = 0; i < M; i++)
	{
		for (sum = 0, j = 0; j < N; j++)
			sum += *(*(p + j) + i);
		*(scoave + i) = sum/N;
		printf("%s课程平均成绩为：%.2f\n", *(s+i), *(scoave+i));
	}
}

void underavenum(float(*p)[M], char(*s)[10], float* scoave)
{
	int num;
	int i, j;
	for (i = 0; i < M; i++)
	{
		for (num = 0, j = 0; j < N; j++)
			if (*(*(p + j) + i) < *(scoave + i))
				num++;
		printf("低于%s平均成绩人数：%d\n", *(s + i), num);
	}
}

void highlownum(float(*p)[M], char(*s)[10], float* score)
{
	int high, low;
	int i, j;
	for (i = 0;i < M; i++)
	{
		for (high = low = 0, j = 0; j < N; j++)
			if (*(*(p + j) + i) < 60)
				low++;
			else if (*(*(p + j) + i) > 90)
				high++;
		printf("%s不及格人数：%d\t90分以上人数：%d\n", *(s + i), low,high);
	}
}

int main()
{
	char scorenames[M][10];
	float scores[N][M];
	float scoave[M];
	inputscorenames(scorenames);
	inputscores(scores, scorenames);
	putchar('\n');
	putstuave(scores);		//输出每个学生平均成绩
	putchar('\n');
	putscoave(scores, scorenames, scoave);	//输出每门平均成绩
	putchar('\n');
	underavenum(scores, scorenames, scoave);	//每门低于平均分的人数
	putchar('\n');
	highlownum(scores, scorenames, scoave);	//不及格及过90人数
	return 0;
}


/* 5.选做题 */
/* （1） */
/*
#include<stdio.h>

int main()
{
	char num[2][32];
	char result[32];
	int i,j;
	int temp;

	for (i = 0; i < 31; i++)
		result[i] = '0';
	result[i] = 0;

	for (i = 0; i < 2; i++)
	{
		printf("第%d个数：",i+1);
		num[i][0] = '0';
		for (j = 1; j < 21; j++)
			num[i][j] = getchar();
		if (getchar() != '.')
		{
			printf("Input Eorror!");
			exit(1);
		}
		for (j = 21; j < 31; j++)
			num[i][j] = getchar();
		num[i][j] = 0;
		getchar();
	}

	for (j = 31; j >= 0; j--)
	{
		temp =result[j]+ num[0][j] + num[1][j] - 3 * '0';
		if (temp >= 10)
			result[j - 1]++;
		result[j] = temp % 10+'0';	
	}

	printf("a+b=");
	if (result[0] != '0')
		putchar(result[0]);
	for (i = 1; i < 21; i++)
		putchar(result[i]);
	putchar('.');
	for (; i < 31; i++)
		putchar(result[i]);
	return 0;

}


/* (2) */
/*
#include<stdio.h>
#include<string.h>

int main()
{
	char* (*p[2])(char*, const char*) = { strstr,strcat };
	char s1[40], s2[20];
	char* temp;
	printf("请输入第一个字符串：");
	gets(s1);
	printf("请输入第二个字符串：");
	gets(s2);
	
	printf("\n执行p[0]后（strstr）:\n");
	if ((temp = p[0](s1, s2)))
		printf("s2是s1子串:%s\n", temp);
	else
		printf("s2不是s1子串\n");

	printf("\n执行p[1]后（strcat）:\n");
	printf("%s\n", p[1](s1, s2));
	
	return 0;
}


/* (3) */
/*
#include<stdio.h>

int main(int argc, char* argv[])
{
	int i;
	printf("命令行参数个数:%d\n分别为:\n", argc);
	for (i = 0; i < argc; i++)
		puts(*(argv + i));
	return 0;
	
}

/**/