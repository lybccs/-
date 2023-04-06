#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 50
typedef struct A{
	//���Ա�ͨ��˳��洢ʵ��
	int data[MaxSize];
	int length;  //��ǰ����
}Sqlist;
void initialize_L(Sqlist* L)
{
	//��ʼ�����Ա�
	(*L).length = 0;//��ʼ����Ϊ0
	for (int i = 1; i < 50; i++)
	{
		(*L).data[i] = 0;//ÿ��Ԫ�ض���ֵΪ��
	}
}
bool Sqlist_insert(Sqlist* L, int i, int j)
{
	//�����Ա�λ��Ϊi��λ�ò���һ��Ԫ��
	if (i<1 || i>(*L).length + 1)
	{
		//ֻ���ڱ��ںͱ����һλ�ĺ�һλ����Ԫ��
		return false;
	}
	for (int k = (*L).length; k >= i; k--)
	{
		//����λ�ú����Ԫ�ض�����һλ
		(*L).data[k] = (*L).data[k - 1];
	}
	(*L).data[i - 1] = j;//����Ԫ��
	(*L).length++;//������1
	return true;
}
bool Sqlist_delete(Sqlist* L, int i)
{
	//ɾ��λ��Ϊi��Ԫ��
	if (i<1 || i>(*L).length)
	{
		//λ��ֻ����1������ȡ
		return false;
	}
	for (int j = i; j < (*L).length; j++)
	{
		//ɾ��λ�ú����Ԫ�ض���ǰ��һλ
		(*L).data[j - 1] = (*L).data[j];
	}
	(*L).length--;
	return true;
}
void search_Sqlist_location(Sqlist L, int i)
{
	//��λ����
	if (i<1 || i>L.length)
	{
		printf("û�����λ��\n");
	}
	else
		printf("��%dλԪ���ǣ�%d\n", i, L.data[i - 1]);
}
int serch_Sqlist_value(Sqlist L, int i)
{
	//��ֵ����
	for (int j = 0; j < L.length; j++)
	{
		if (L.data[j] == i)
		{
			return j + 1;//����λ��
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
	//��λ��Ϊi��Ԫ�ظ�Ϊj
	(*L).data[i - 1] = j;
	return true;
}
int main()
{
	Sqlist L;//����һ�����Ա�
	initialize_L(&L);//��ʼ��
	for (int i = 1; i <= 9; i++)
	{
		bool a = Sqlist_insert(&L, i, i);//����Ԫ��
			if (a)
			{
				printf("��%dλ����ɹ�\n", i);
			}
	}
	bool a = Sqlist_insert(&L, 1, 2);//����Ԫ��
	bool b = Sqlist_delete(&L, 10);
	if (b)
	{
		printf("ɾ���ɹ���Ŀǰ��ĳ��ȣ�%d\n", L.length);
		for (int i = 0; i < L.length; i++)
		{
			printf("%d ", L.data[i]);
		}
		printf("\n");
	}
	a = alter_Sqlist(&L, 2, 10);
	if (a)
	{
		printf("�޸ĳɹ����ĺ�ı�:\n");
		for (int i = 0; i < L.length; i++)
		{
			printf("%d ", L.data[i]);
		}
		printf("\n");
	}
	a = alter_Sqlist(&L, 10, 2);
	if(!a)
	{
		printf("�޸�ʧ��\n");
	}
	search_Sqlist_location(L, 100);
	search_Sqlist_location(L, 9);
	int c = serch_Sqlist_value(L, 100);
	if (!c)
		printf("û��\n");
	c = serch_Sqlist_value(L, 2);
	if (c)
		printf("��һ��ֵΪ2��Ԫ�ص�λ����%d", c);
	return 0;
}