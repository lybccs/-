#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 50
typedef struct A{
	//线性表通过顺序存储实现
	int data[MaxSize];
	int length;  //当前长度
}Sqlist;
void initialize_L(Sqlist* L)
{
	//初始化线性表
	(*L).length = 0;//初始长度为0
	for (int i = 1; i < 50; i++)
	{
		(*L).data[i] = 0;//每个元素都赋值为零
	}
}
bool Sqlist_insert(Sqlist* L, int i, int j)
{
	//向线性表位序为i的位置插入一个元素
	if (i<1 || i>(*L).length + 1)
	{
		//只能在表内和表最后一位的后一位插入元素
		return false;
	}
	for (int k = (*L).length; k >= i; k--)
	{
		//插入位置后面的元素都后移一位
		(*L).data[k] = (*L).data[k - 1];
	}
	(*L).data[i - 1] = j;//插入元素
	(*L).length++;//表长增加1
	return true;
}
bool Sqlist_delete(Sqlist* L, int i)
{
	//删除位序为i的元素
	if (i<1 || i>(*L).length)
	{
		//位序只能在1到表长中取
		return false;
	}
	for (int j = i; j < (*L).length; j++)
	{
		//删除位置后面的元素都往前移一位
		(*L).data[j - 1] = (*L).data[j];
	}
	(*L).length--;
	return true;
}
void search_Sqlist_location(Sqlist L, int i)
{
	//按位查找
	if (i<1 || i>L.length)
	{
		printf("没有这个位序\n");
	}
	else
		printf("第%d位元素是：%d\n", i, L.data[i - 1]);
}
int serch_Sqlist_value(Sqlist L, int i)
{
	//按值查找
	for (int j = 0; j < L.length; j++)
	{
		if (L.data[j] == i)
		{
			return j + 1;//返回位序
		}
	}
	return 0;
}
bool alter_Sqlist(Sqlist* L, int i, int j)
{
	if (i<1 || i>(*L).length)
	{
		return false;
	}
	//将位序为i的元素改为j
	(*L).data[i - 1] = j;
	return true;
}
int main()
{
	Sqlist L;//创建一个线性表
	initialize_L(&L);//初始化
	for (int i = 1; i <= 9; i++)
	{
		bool a = Sqlist_insert(&L, i, i);//插入元素
			if (a)
			{
				printf("第%d位插入成功\n", i);
			}
	}
	bool a = Sqlist_insert(&L, 1, 2);//插入元素
	bool b = Sqlist_delete(&L, 10);
	if (b)
	{
		printf("删除成功，目前表的长度：%d\n", L.length);
		for (int i = 0; i < L.length; i++)
		{
			printf("%d ", L.data[i]);
		}
		printf("\n");
	}
	a = alter_Sqlist(&L, 2, 10);
	if (a)
	{
		printf("修改成功，改后的表:\n");
		for (int i = 0; i < L.length; i++)
		{
			printf("%d ", L.data[i]);
		}
		printf("\n");
	}
	a = alter_Sqlist(&L, 10, 2);
	if(!a)
	{
		printf("修改失败\n");
	}
	search_Sqlist_location(L, 100);
	search_Sqlist_location(L, 9);
	int c = serch_Sqlist_value(L, 100);
	if (!c)
		printf("没有\n");
	c = serch_Sqlist_value(L, 2);
	if (c)
		printf("第一个值为2的元素的位序是%d", c);
	return 0;
}