#define _CRT_SECURE_NO_WARNINGS		//VS编译器的原因需要添加的宏定义

/*1.源程序改错 */
/*
#include<stdio.h>
int main(void)
{
	int a[10] = { 27, 13, 5, 32, 23, 3, 17, 43, 55, 39 };
	void sort(int[], int);
	int i;
	sort(a, 10);	//a[0]改为a
	for (i = 0; i < 10; i++)
		printf("%6d", a[i]);
	printf("\n");
	return 0;
}
 void sort(int b[], int n)
 {
	 int i, j, t;
	 for (i = 0; i < n - 1; i++)	
		 for (j = 0; j < n - i - 1; j++)
			 if (b[j] > b[j + 1])	//改为大于号
				t = b[j], b[j] = b[j + 1], b[j + 1] = t;
}


 /* 2.源程序完善、修改、替换 */
 /* （1） */
 /*
#include<stdio.h>
#define M 10	//总人数
#define N 3		//出圈的数字
int main(void)
{
	int a[M], b[M];	// 数组a存放圈中人的编号，数组b存放出圈人的编号
	int i, j, k;
	for (i = 0; i < M; i++)			//对圈中人按顺序编号1—M
		a[i] = i + 1;
	for (i = M, j = 0; i > 1; i--) 
	{
		// i表示圈中人个数，初始为M个，剩1个人时结束循环；j表示当前报数人的位置
		for (k = 1; k <= N; k++)			// 1至N报数
			if (++j > i - 1) 
				j = 0;// 最后一个人报数后第一个人接着报，形成一个圈
		b[M - i] = j ? a[j - 1] : a[i - 1];	// 将报数为N的人的编号存入数组b（填空）
		if (j)
			for (k = --j; k < i; k++)	// 压缩数组a，使报数为N的人出圈 
				a[k]=a[k+1];	//后面的人补前面人的空位（填空）
	}
	for (i = 0; i < M - 1; i++)		// 按次序输出出圈人的编号
		printf("%6d", b[i]);
	printf("%6d\n", a[0]);			// 输出圈中最后一个人的编号
	return 0;
}


/* (2) */
/*
#include<stdio.h>
#define M 10	//总人数
#define N 3		//出圈的数字
int main(void)
{
	int a[M];	// 数组a存放圈中人的编号，数组b存放出圈人的编号
	int i, j, k;
	for (i = 0; i < M; i++)			//对圈中人按顺序编号1—M
		a[i] = i + 1;
	for (i = M, j = 0, k=1; i > 1; k++,j++)
	{	// i表示圈中人个数，初始为M个，剩1个人时结束循环；j表示当前报数人的位置
			if (j > M-1)	//若报数至结尾则从头报数
				j = 0;
			while(a[j] == 0)	//当当前宝树的人已报过数（已做标记）
				j++;	//则直到未报过数的人报数
			if (k == N)		//若报的数为N
			{
				printf("%6d", a[j]);	//输出该数（出圈）
				a[j] = 0;	//对报数的人做标记
				i--;	//剩余人数-1
				k = 0;	//重新报数
			}
	}
	for (i = 0; i < M - 1; i++)
		if(a[i])
			printf("\n%6d\n", a[i]);			// 输出圈中最后一个人的编号
	return 0;
}


/* 3.跟踪调试题 */
/* 源程序 */
/*
#include<stdio.h>
void strncat(char[], char[], int);
int main(void)
{
	char a[50] = "The adopted symbol is ", b[27] = "abcdefghijklmnopqrstuvwxyz";
	strncat(a, b, 4);
	printf("%s\n", a);
	return 0;
}
void strncat(char s[], char t[], int n)
{
	int i = 0, j;
	while (s[i++]);
	for (j = 0; j < n && t[j];)
		s[i++] = t[j++];
	s[i] = '\0';
}


/* 修改后 */
/*
#include<stdio.h>
void strncat(char[], char[], int);
int main(void)
{
	char a[50] = "The adopted symbol is ", b[27] = "abcdefghijklmnopqrstuvwxyz";
	strncat(a, b, 4);
	printf("%s\n", a);
	return 0;
}
void strncat(char s[], char t[], int n)
{
	int i = 0, j;
	while (s[i])
		i++;
	for (j = 0; j < n && t[j];)
		s[i++] = t[j++];
	s[i] = '\0';
}


/* 4.程序设计 */
/* (1) */
/*
#include<stdio.h>
int main()
{
	int src[3][4], res[4][3];
	int i, j;
	printf("请输入一个3×4的矩阵：\n");
	for (i = 0; i < 3; i++)
		for (j = 0; j < 4; j++)
			scanf("%d", &src[i][j]);
	printf("原矩阵：\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d\t", src[i][j]);	//输出原矩阵
			res[j][i] = src[i][j];		//元素转置
		}
		putchar('\n');
	}
	printf("转置矩阵：\n");
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
			printf("%d\t", res[i][j]);	//输出转置矩阵
		putchar('\n');
	}
	return 0;
}


/* (2) */
/*
#include<stdio.h>
int main()
{
	int num,bits;
	char bin[40];
	int i;
	bits = sizeof(int) * 8;	//计算整型占用位数
	printf("请输入一个整数：");
	scanf("%d", &num);
	for (i = 0; i < bits; i++)
		bin[i] = (num & (1 << (bits - i - 1))) ? '1' : '0';	
		//将二进制数字每位以字符形式储存
	bin[i] = 0;	//添加字符串结束符
	puts(bin);
	return 0;
}


/* (3) */
/*
#include<stdio.h>
#include<stdlib.h>
typedef struct stu
{
	char name[10];
	int score;
}stu;

void QuickSort(stu a[],int left,int right)	//快速排序（降序）
{
	int i = left, j = right;
	stu key = a[left];	//关键值
	if (left < right)
	{
		while (i < j)
		{
			while (i<j && a[j].score<=key.score)	//右侧找一个大于关键值的放到前面
				j--;
			a[i] = a[j];
			while (i < j && a[i].score >= key.score)	//左侧找一个小于关键值的放到后面
				i++;
			a[j] = a[i];
		}
		a[i] = key;	//放置关键值
		QuickSort(a, left, i - 1);	//左边部分快排
		QuickSort(a, i + 1, right);		//右边部分快排
	}
}

stu* Dich(stu a[], int key, int n)	//二分法搜索成绩
{	//key为待查找值
	int left = 0, right = n - 1,mid;	//定义左右中间值
	stu *temp;
	for (mid = (left + right) / 2; left < right && a[mid].score != key;mid=(left+right)/2 )
	{	//判断中间值是否与待查找值相等
		if (a[mid].score < key)		//若查找值大于中间值，则在左侧
			right = mid - 1;	//折去右边
		else	//若查找值小于中间值，则在右侧
			left = mid + 1;		//折去左边
	}
	if (a[mid].score == key)	//若找到
	{
		temp = a + mid;
		return  temp;	//返回找到的数据地址
	}
	else	//未找到返回空指针
		return NULL;
}

int main()
{
	int n,key;
	stu* head,*dest;
	int i;
	printf("请输入需要输入的学生数量n：");
	scanf("%d", &n);
	getchar();
	head = (stu*)malloc(sizeof(stu) * n);
	for (i = 0; i < n; i++)
	{
		printf("姓名：");
		gets(head[i].name);
		printf("成绩：");
		scanf("%d", &head[i].score);
		getchar();
	}

	QuickSort(head, 0, n - 1);	//成绩排序
	printf("按成绩从高到低排序：\n");
	printf("姓名    成绩\n");
	for (i = 0; i < n; i++)
		printf("%-8s%d\n", head[i].name, head[i].score);

	printf("请输入查找的成绩：");	//查找成绩
	scanf("%d", &key);
	dest=Dich(head, key,n);
	if (dest)	//若返回指针不为空则找到，输出姓名和成绩
		printf("%-8s%d\n", dest->name, dest->score);
	else	//若为空指针则未找到，输出未找到
		printf("未找到！\n");

	free(head);
	return 0;
}


/* 5.选做程序设计 */
/* （1） */
/*
#include<stdio.h>
#include<string.h>
int strnins(char* s, char* t, int n)
{	//s为被插入字符串，t为插入字符串，n为插入位置
	int len = strlen(s);
	int i, j;
	char temp[10];
	if (n > len)
	{
		printf("输入n过大，无法插入！");
		return 0;
	}
	else if (n < 0)
	{
		printf("输入n不能为负数，无法插入！");
		return 0;
	}
	for (i = n, j = 0; s[i];j++,i++)		//将s插入点后元素存入临时数组
		temp[j] = s[i];
	temp[j] = 0;
	for (i = n, j = 0; t[j];i++,j++)	//插入t字符串到s
		s[i] = t[j];
	for (j = 0; temp[j]; i++,j++)	//将临时数组中的元素放回原字符串
		s[i] = temp[j];
	s[i] = 0;
	return 1;	//操作成功返回1
}

int main()
{
	char s[30], t[10];
	int n,flag;
	printf("请输入字符串s：");
	gets(s);
	printf("请输入字符串t：");
	gets(t);
	printf("请输入n：");
	scanf("%d", &n);
	flag=strnins(s, t, n);
	if(flag)	//若操作成功输出插入后字符串
		puts(s);
	return 0;
}


/* （2） */
/*
#include<stdio.h>
#define N 8
int chess[N][N];	//棋盘
int times = 0;	//解的数量
void QueenSet(int x, int y)	//放置皇后函数
{
	if (QueenCheck(x, y) == 1)	//如果能放
	{
		chess[x][y] = 1;	//放置棋子
		if (x + 1 == N)		//若为最后一行
		{
			printf("解法%d:\n",++times);	//次数加1
			for (int i = 0; i < N; i++)		//输出当前解
			{
				for (int j = 0; j < N; j++)
				{
					if (chess[i][j])
						printf("■");
					else
						printf("□");
				}
				putchar('\n');
			}
			putchar('\n');
		}
		else	//若不为最后一行
			QueenSet(x+1, 0);	//判断下一行如何放置
	}
	chess[x][y] = 0;	//若不能放，则不放皇后，
						//若已经输出一种解，则撤去最后的皇后
	if (y + 1 < N)		//当前位置右边能放
		QueenSet(x, y + 1);	//尝试在其右边放置皇后
	else
		return;		//若右边不能放置则返回
}

int QueenCheck(int x, int y)	//检查（x，y）处是否能放皇后
{
	int i;
	for (i = 0; i < N; i++)		//直线
		if (chess[i][y] == 1 || chess[x][i] == 1)
			return 0;
	for (i = -N; i < N; i++)	//对角线
	{
		if (x + i >= 0 && x + i < N && y + i >= 0 && y + i < N)
			if (chess[x + i][y + i] == 1)
				return 0;
		if (x + i >= 0 && x + i < N && y - i >= 0 && y - i < N)
			if (chess[x + i][y - i] == 1)
				return 0;
	}
	return 1;	//能放返回1，反之返回0
}

int main()
{
	QueenSet(0, 0);	//从（0,0）处开始放皇后
	return 0;	
}

/**/
