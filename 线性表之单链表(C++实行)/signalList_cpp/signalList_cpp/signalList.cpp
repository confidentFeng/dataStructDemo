#include <iostream>
#include "signalList.h"

using namespace std;

// ���캯��
SignalList::SignalList(int size)
{
	// ��ʼ��������
	m_pList = new Node;
	m_pList->data = 0;
	m_pList->next = NULL;
}

// ��������
SignalList::~SignalList()
{
	clearList(); // �������
	delete m_pList;
	m_pList = NULL;
}

// ����������
void SignalList::clearList()
{
	Node *cur; // ��ǰ���
	Node *temp; // ���ȱ�����һ��㣬��ֹ�ͷŵ�ǰ�����¡�������

	cur = m_pList->next; //ָ��ͷ���
	while (cur)
	{
		temp = cur->next; // ���ȱ�����һ��㣬��ֹ�ͷŵ�ǰ�����¡�������
		delete cur; // �ͷŵ�ǰ���
		cur = temp; // ����һ��㸳����ǰ���
	}

	cur->next = NULL; // ע�⻹Ҫ��ͷ����ָ����ָ���
}

// �ж��Ƿ�Ϊ�ղ���
bool SignalList::isEmpty()
{
	return m_pList->next == NULL ? true : false;
}

// ��ȡ�����Ȳ���
int SignalList::getLength()
{
	Node *cur = m_pList;
	int length = 0;

	while (cur->next)
	{
		cur = cur->next;
		length++;
	}

	return length;
}

// ����Ԫ�ز���
bool SignalList::insertList(int i, const ElemType e)
{
	// �ж������Ƿ����
	if (!m_pList)
	{
		cout << "list not exist!" << endl;
		return false;
	}
	// ֻ����λ��1�Լ�������룬����i����Ϊ1
	if (i < 1)
	{
		cout << "i is invalid!" << endl;
		return false;
	}

	// �ҵ�λ��i��ǰһ�����
	Node *front = m_pList; // ��������frontָ������ĵ�0�����-ͷ���
	int j = 1; // jΪ����������ֵΪ1����Ӧfrontָ�����һ����㣬������λ�ý��
	while (front != NULL && j < i)
	{
		front = front->next;
		j++;
	}
	// δ�ҵ�iλ�����ڵ�ǰһ�����
	if (front == NULL)
	{
		cout << "dont find front!" << endl;
		return false;
	}		

	// ����һ���սڵ㣬���Ҫ�������Ԫ��
	Node *temp = new Node;
	temp->data = e;
	temp->next = NULL;

	// ������s
	temp->next = front->next;
	front->next = temp;

	return true;
}

// ɾ��Ԫ�ز���
bool SignalList::deleteList(int i, ElemType *e)
{
	// �ж������Ƿ����
	if (!m_pList)
	{
		cout << "list not exist!" << endl;
		return false;
	}
	// ֻ��ɾ��λ��1�Լ�����Ľ��
	if (i < 1)
	{
		cout << "i is invalid!" << endl;
		return false;
	}

	// �ҵ�λ��i��ǰһ�����
	Node *front = m_pList; // ��������frontָ������ĵ�0�����-ͷ���
	int j = 1; // jΪ����������ֵΪ1����Ӧfrontָ�����һ����㣬������λ�ý��
	while (front != NULL && j < i)
	{
		front = front->next;
		j++;
	}
	// δ�ҵ�iλ�����ڵ�ǰһ�����
	if (front == NULL)
	{
		cout << "dont find front!" << endl;
		return false;
	}

	// ��ǰ����Ҫɾ���Ľ��
	Node *temp = front->next;
	*e = temp->data; // ��Ҫɾ���������ݸ���e

	// ɾ�����
	front->next = front->next->next;	

	// ���ٽ��
	delete temp;
	temp = NULL;

	return true;
}

// ��ȡԪ�ز���
bool SignalList::getElem(int i, ElemType *e)
{
	// �ж������Ƿ����
	if (!m_pList)
	{
		cout << "list not exist!" << endl;
		return false;
	}
	// ֻ�ܻ�ȡλ��1�Լ������Ԫ��
	if (i < 1)
	{
		cout << "i is invalid!" << endl;
		return false;
	}

	// �ҵ�iλ�����ڵĽ��
	Node *cur = m_pList->next; // ��������curָ������ĵ�1�����
	int j = 1; // jΪ����������ֵΪ1����Ӧcurָ����
	while (cur != NULL && j<i)
	{
		cur = cur->next;
		j++;
	}
	// δ�ҵ�iλ�����ڵ�ǰһ�����
	if (cur == NULL)
	{
		cout << "dont find front!" << endl;
		return false;
	}

	// ȡ��i��Ԫ�ص�����
	*e = cur->data;
}

// ͷ�������Ԫ�ز���
bool SignalList::insertListHead(const ElemType e)
{
	// �ж������Ƿ����
	if (!m_pList)
	{
		cout << "list not exist!" << endl;
		return false;
	}

	// ��headָ�������ͷ���
	Node *head = m_pList;

	// ������Ų���Ԫ�صĽ��
	Node *temp = new Node;
	if (!temp)
	{
		cout << "malloc error!" << endl;
		return false;
	}
	temp->data = e;

	// ͷ���������
	temp->next = head->next;
	head->next = temp;

	return true;
}

// β�������Ԫ�ز���
bool SignalList::insertListTail(const ElemType e)
{
	// �ж������Ƿ����
	if (!m_pList)
	{
		cout << "list not exist!" << endl;
		return false;
	}

	// �ҵ�β���
	Node *cur = m_pList;
	while (cur->next)
	{
		cur = cur->next;
	}

	// ������Ų���Ԫ�صĽ��
	Node *temp = new Node;
	if (!temp)
	{
		cout << "malloc error!" << endl;
		return false;
	}
	temp->data = e;

	// β���������
	temp->next = cur->next;
	cur->next = temp;

	return true;
}

// ��������
void SignalList::traverseList()
{
	// �ж������Ƿ����
	if (!m_pList)
	{
		cout << "list not exist!" << endl;
		return;
	}

	Node *cur = m_pList->next;
	while (cur)
	{
		cout << cur->data << " ";
		cur = cur->next;
	}
}

// ����Ԫ��λ�ò���
int SignalList::locateElem(const ElemType e)
{
	Node *cur = m_pList; // ��ǰ���
	int i = 0; // λ������

	while (cur->next)
	{
		cur = cur->next;
		i++;
		if (cur->data == e)
			return i;		
	}

	return -1;
}
