#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int Status; // Status�Ǻ������״̬���ɹ�����TRUE,ʧ�ܷ���FALSE

#define MAX_SIZE 100  /* ���鳤�� */
typedef int  ElemType; /* "ElemType���͸���ʵ����������� �������Ϊint */
// ˳���ṹ����
typedef struct
{
	ElemType  data[MAX_SIZE];  /* ���˳���Ԫ�ص����飬���ֵΪMAXSIZE */
	int length; /* ˳���ĵ�ǰ���� */
}SeqList;

SeqList *initList(); // ��ʼ������
Status appendList(SeqList *pSeqList, const ElemType e); // ����Ԫ�ز���
Status insertList(SeqList *pSeqList, int i, const ElemType e); // ����Ԫ�ز���
Status deleteList(SeqList *pSeqList, int i, ElemType *e); // ɾ��Ԫ�ز���
Status getElem(SeqList *pSeqList, int i, ElemType *e); // ��ȡԪ�ز���
int locateElem(SeqList *pSeqList, const ElemType e); // ����Ԫ��λ�ò���
void traverseList(SeqList *pSeqList); // ����˳���
Status isEmpty(SeqList *pSeqList); // ����Ƿ�Ϊ�ղ���
int getLength(SeqList *pSeqList); // ��ȡԪ�ظ�������
void clearList(SeqList *pSeqList); // ���˳������
void destroyList(SeqList *pSeqList); // ����˳������

// ��ʼ������
SeqList *initList()
{
	SeqList *pSeqList = (SeqList *)malloc(sizeof(SeqList));
	if (pSeqList == NULL)
	{
		printf("initList malloc error!\n");
		exit(-1);
	}

	pSeqList->length = 0;
	return pSeqList;
}

// ����Ԫ�ز���
Status appendList(SeqList *pSeqList, const ElemType e)
{
	// �ж�˳������Ƿ���ڵ������鳤�ȣ������׳��쳣��̬��������
	if (pSeqList->length >= MAX_SIZE)
		return FALSE;

	// �ڱ�β�������Ԫ��e
	pSeqList->data[pSeqList->length] = e;

	// ����1
	pSeqList->length++;

	return TRUE;
}

// ����Ԫ�ز���
Status insertList(SeqList *pSeqList, int i, const ElemType e)
{
	// �ж�˳����Ƿ��������Ҳ���λ���Ƿ����
	if (pSeqList->length >= MAX_SIZE || i < 0 || i > pSeqList->length) // �����ڱ�β����һ��λ�ò���Ԫ��
		return FALSE;

	// �����һ��Ԫ�ؿ�ʼ��ǰ��������i��λ�ã��ֱ����Ƕ�����ƶ�һ��λ��
	// ��������������ú��ƣ��ڱ�β����һ��λ�ò���Ԫ��(������һ����λ��0����Ԫ�ص����)
	if (i != pSeqList->length)
	{
		// ������λ�ü�����Ԫ������ƶ�һλ
		for (int k = pSeqList->length - 1; k >= i; k--)
			pSeqList->data[k + 1] = pSeqList->data[k];
	}

	// ��Ҫ����Ԫ������λ��i��
	pSeqList->data[i] = e;
	// ����1
	pSeqList->length++;

	return TRUE;
}

// ɾ��Ԫ�ز���
Status deleteList(SeqList *pSeqList, int i, ElemType *e)
{
	// �ж�˳����Ƿ�Ϊ�գ���ɾ��λ���Ƿ����
	if (pSeqList->length == 0 || i < 0 || i > pSeqList->length - 1)
		return FALSE;

	// ȡ��ɾ��Ԫ��
	*e = pSeqList->data[i];

	// ��ɾ��Ԫ�ص���һ��λ�ÿ�ʼ���������һ��Ԫ��λ�ã��ֱ����Ƕ���ǰ�ƶ�һ��λ��
	// ���������������ǰ�ƣ�ɾ��λ���ڱ�β
	if (i != pSeqList->length - 1)
	{
		// ��ɾ��Ԫ�ص���һ��λ�ü�����Ԫ����ǰ�ƶ�һλ
		for (int k = i; k < pSeqList->length - 1; k++)
			pSeqList->data[k] = pSeqList->data[k + 1];
	}

	// ����1
	pSeqList->length--;

	return TRUE;
}

// ��ȡԪ�ز���
Status getElem(SeqList *pSeqList, int i, ElemType *e)
{
	// �ж�˳����Ƿ���ڣ���ɾ��λ���Ƿ����
	if (pSeqList == NULL || i < 0 || i > pSeqList->length - 1)
		return FALSE;

	*e = pSeqList->data[i];

	return TRUE;
}

// ����Ԫ��λ�ò���
int locateElem(SeqList *pSeqList, const ElemType e)
{
	// ��������ʾ˳���Ԫ��
	for (int i = 0; i < pSeqList->length; i++)
	{
		if (pSeqList->data[i] == e)
			return i;
	}

	return -1;
}


// ��������
void traverseList(SeqList *pSeqList)
{
	for (int i = 0; i < pSeqList->length; i++)
		printf("%d ", pSeqList->data[i]);
	printf("\n");
}

// ����Ƿ�Ϊ�ղ���
Status isEmpty(SeqList *pSeqList)
{
	return pSeqList->length == 0 ? TRUE : FALSE;
}

// ��ȡԪ�ظ�������
int getLength(SeqList *pSeqList)
{
	return pSeqList->length;
}

// ���˳������
void clearList(SeqList *pSeqList)
{
	pSeqList->length = 0;
}

// ����˳������
void destroyList(SeqList *pSeqList)
{
	free(pSeqList);
	pSeqList = NULL;
}

int main()
{
	// ��ʼ��˳���
	SeqList *pSeqList = initList();

	// ���˳����Ƿ�Ϊ��
	if (isEmpty(pSeqList))
		printf("˳���Ϊ�գ�\n\n");
	else
		printf("˳���Ϊ�գ�\n\n");

	// ����Ԫ��0-2��˳���
	printf("����Ԫ��0-2��˳���!\n\n");
	for (int i = 0; i<3; i++)
	{
		appendList(pSeqList, i);
	}
	printf("\n");

	// ��λ��2����Ԫ�ص�˳���
	printf("��λ��2����Ԫ��9��˳���!\n\n");
	insertList(pSeqList, 2, 9);

	// ��˳�����ɾ��Ԫ��
	int value1;
	if (deleteList(pSeqList, 3, &value1) == FALSE)
	{
		printf("delete error!\n\n");
		return -1;
	}
	printf("��λ��3ɾ��Ԫ�أ�ɾ����Ԫ��Ϊ��%d\n\n", value1);

	// ��ȡԪ�ظ���
	printf("��ǰԪ�ظ���Ϊ%d��\n\n", getLength(pSeqList));

	// ����Ԫ��λ��
	printf("���ҵ�Ԫ��0��λ��Ϊ��%d\n\n", locateElem(pSeqList, 0));

	// ��������ʾ˳���Ԫ��
	printf("����˳��� ");
	traverseList(pSeqList);
	printf("\n");

	// ���˳���
	clearList(pSeqList);
	printf("���˳���!\n");

	// ����˳���
	destroyList(pSeqList);
	printf("\n");

	return 0;
}