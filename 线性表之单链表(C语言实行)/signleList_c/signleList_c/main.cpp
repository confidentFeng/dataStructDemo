#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int Status; // Status�Ǻ������״̬���ɹ�����TRUE,ʧ�ܷ���FALSE

typedef int ElemType;
/* ���Ա�ĵ�����洢�ṹ */
typedef struct node
{
	ElemType data;
	struct node *next;
}Node, LinkList;

void initList(LinkList **pList); // ��ʼ�����������
Status insertList(LinkList *pList, int i, const ElemType e); // ����Ԫ�ز���
Status deleteList(LinkList *pList, int i, ElemType *e); // ɾ��Ԫ�ز���
Status getElem(LinkList *pList, int i, ElemType *e); // ��ȡԪ�ز���
Status insertListHead(LinkList *pList, const ElemType e); // ͷ�������Ԫ�ز���
Status insertListTail(LinkList *pList, const ElemType e); // β�������Ԫ�ز���
Status clearList(LinkList *pList); // ����������
void traverseList(LinkList *pList); // �����������

// ��ʼ�����������
void initList(LinkList **pList) // ����ʹ��˫��ָ�룬һ��ָ����������
{
	*pList = (LinkList *)malloc(sizeof(Node));
	if (!pList)
	{
		printf("malloc error!\n");
		return;
	}

	(*pList)->data = 0;
	(*pList)->next = NULL;
}

// ����Ԫ�ز���
Status insertList(LinkList *pList, int i, const ElemType e)
{
	Node *front; // ָ��λ��i���ڵ�ǰһ�����
	int j; // ������

	// �ж������Ƿ����
	if (!pList)
	{
		printf("list not exist!\n");
		return FALSE;
	}
	// ֻ����λ��1�Լ�������룬����i����Ϊ1
	if (i < 1)
	{
		printf("i is invalid!\n");
		return FALSE;
	}

	// �ҵ�iλ�����ڵ�ǰһ�����
	front = pList; // ��������frontָ������ĵ�0�����-ͷ���
	j = 1; // jΪ����������ֵΪ1����Ӧfrontָ�����һ����㣬������λ�ý��
	while (front != NULL && j < i)
	{
		front = front->next;
		j++;
	}
	// δ�ҵ�iλ�����ڵ�ǰһ�����
	if (front == NULL)
	{
		printf("dont find front!\n");
		return FALSE;
	}
		
	// ����һ���սڵ㣬���Ҫ�������Ԫ��
	Node *temp = (Node *)malloc(sizeof(Node));
	if (!temp)
	{
		printf("malloc error!\n");
		return FALSE;
	}
	temp->data = e;

	// ������
	temp->next = front->next;
	front->next = temp;

	return TRUE;
}

// ɾ��Ԫ�ز���
Status deleteList(LinkList *pList, int i, ElemType *e)
{
	Node *front; // ָ��λ��i���ڵ�ǰһ�����
	int j; // ������

	// �ж������Ƿ����
	if (!pList)
	{
		printf("list not exist!\n");
		return FALSE;
	}
	// ֻ��ɾ��λ��1�Լ��Ժ�Ľ��
	if (i < 1)
	{
		printf("i is invalid!\n");
		return FALSE;
	}

	// �ҵ�iλ�����ڵĽ��
	front = pList; // ��������frontָ������ĵ�0�����-ͷ���
	j = 1; // jΪ����������ֵΪ1����Ӧfrontָ�����һ����㣬������λ�ý��
	while (front != NULL && j < i)
	{
		front = front->next;
		j++;
	}
	// δ�ҵ�iλ�����ڵ�ǰһ�����
	if (front == NULL)
	{
		printf("dont find front!\n");
		return FALSE;
	}

	// ��ǰ����Ҫɾ���Ľ��
	Node *temp = front->next;
	*e = temp->data; // ��Ҫɾ���������ݸ���e

	// ɾ�����
	front->next = front->next->next;

	// ���ٽ��	
	free(temp);
	temp = NULL;

	return TRUE;
}

// ��ȡԪ�ز���
Status getElem(LinkList *pList, int i, ElemType *e)
{
	Node *cur;

	// �ж������Ƿ����
	if (!pList)
	{
		printf("list not exist!\n");
		return FALSE;
	}
	// ֻ�ܻ�ȡλ��1�Լ��Ժ��Ԫ��
	if (i < 1)
	{
		printf("i is invalid!\n");
		return FALSE;
	}

	// �ҵ�iλ�����ڵĽ��
	cur = pList->next; // ��������curָ������ĵ�1�����
	int j = 1; // jΪ����������ֵΪ1����Ӧcurָ����
	while (cur != NULL && j < i)
	{
		cur = cur->next;
		j++;
	}
	// δ�ҵ�iλ�����ڵ�ǰһ�����
	if (cur == NULL)
	{
		printf("dont find front!\n");
		return FALSE;
	}

	// ȡ��i����������
	*e = cur->data;

	return TRUE;
}

// ͷ�������Ԫ�ز���
Status insertListHead(LinkList *pList, const ElemType e)
{
	Node *head;
	Node *temp;

	// �ж������Ƿ����
	if (!pList)
	{
		printf("list not exist!\n");
		return FALSE;
	}

	// ��headָ�������ͷ���
	head = pList;

	// ������Ų���Ԫ�صĽ��
	temp = (Node *)malloc(sizeof(Node));
	if (!temp)
	{
		printf("malloc error!\n");
		return FALSE;
	}
	temp->data = e;
	
	// ͷ���������
	temp->next = head->next;
	head->next = temp;

	return TRUE;
}

// β�������Ԫ�ز���
Status insertListTail(LinkList *pList, const ElemType e)
{
	Node *cur;
	Node *temp;

	// �ж������Ƿ����
	if (!pList)
	{
		printf("list not exist!\n");
		return FALSE;
	}

	// �ҵ�����β�ڵ�
	cur = pList;
	while (cur->next)
	{
		cur = cur->next;
	}

	// ������Ų���Ԫ�صĽ��
	temp = (Node *)malloc(sizeof(Node));
	if (!temp)
	{
		printf("malloc error!\n");
		return -1;
	}
	temp->data = e;

	// β���������
	temp->next = cur->next;
	cur->next = temp;

	return TRUE;
}

// ����������
Status clearList(LinkList *pList)
{
	Node *cur; // ��ǰ���
	Node *temp; // ���ȱ�����һ��㣬��ֹ�ͷŵ�ǰ�����¡�������

	// �ж������Ƿ����
	if (!pList)
	{
		printf("list not exist!\n");
		return FALSE;
	}

	cur = pList; // ָ��ͷ���
	while (cur)
	{
		temp = cur->next; // ���ȱ�����һ��㣬��ֹ�ͷŵ�ǰ�����¡�������
		free(cur); // �ͷŵ�ǰ���
		cur = temp; // ����һ��㸳����ǰ���p
	}
	pList->next = NULL; // ͷ���ָ����ָ���

	return TRUE;
}

// �����������
void traverseList(LinkList *pList)
{
	// �ж������Ƿ����
	if (!pList)
	{
		printf("list not exist!\n");
		return;
	}

	Node *cur = pList->next;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

int main()
{
	LinkList *pList;

	// ��ʼ������
	initList(&pList);
	printf("��ʼ������!\n\n");

	// ������
	insertList(pList, 1, 0);
	printf("��λ��1����Ԫ��0\n");
	insertList(pList, 2, 1);
	printf("��λ��2����Ԫ��1\n");
	insertList(pList, 1, 2);
	printf("��λ��3����Ԫ��2\n\n");

	// ɾ�����
	int val;
	deleteList(pList, 2, &val);
	printf("ɾ��λ��2�Ľ�㣬ɾ����������Ϊ�� %d\n", val);
	printf("\n");

	// ͷ�������Ԫ��
	insertListHead(pList, 5);
	printf("ͷ�������Ԫ��5\n\n");

	// β�������Ԫ��
	insertListTail(pList, 8);
	printf("β�������Ԫ��8\n\n");

	// ����������ʾԪ�ز���
	printf("��������");
	traverseList(pList);
	printf("\n");

	// ��������
	clearList(pList);
	printf("��������\n\n");

	return 0;
}