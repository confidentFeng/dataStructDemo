#include <iostream>
#include "seqListCpp.h"

using namespace std;

// ���캯��
SeqList::SeqList(int size)
{
	// ��ʼ��˳�����������
	m_maxSize = size; 
	// ��ʼ�����˳���Ԫ�ص�����
	m_pDataArr = new ElemType[m_maxSize];
	// ��ʼ��˳���ĵ�ǰ����
	m_length = 0;
}

// ��������
SeqList::~SeqList()
{
	delete[] m_pDataArr;
	m_pDataArr = NULL;
}

// �ж��Ƿ�Ϊ�ղ���
bool SeqList::isEmpty()
{
	return m_length == 0 ? true : false;
}

// ��ȡ˳����Ȳ���
int SeqList::getLength() 
{
	return m_length;
}

// ���˳������
void SeqList::clearList()
{
	m_length = 0;
}

// ��ȡԪ�ز���
bool SeqList::getElem(int i, ElemType *e)
{
	// ǰ������: ˳����Ѵ��ڣ���i�ں���Χ�ڣ�0 <= i <= m_length
	if (m_length == 0 || i < 0 || i > m_length) // ��m_length==0����˵��˳�������
		return false;

	*e = m_pDataArr[i];

	return true;
}

// ����Ԫ��λ�ò���
int SeqList::locateElem(const ElemType e)
{
	// ��������ʾ˳���Ԫ��
	for (int i = 0; i < m_length; i++)
	{
		if (m_pDataArr[i] == e)
			return i;
	}

	return -1;
}

// ����Ԫ�ز���
bool SeqList::appendList(const ElemType e)
{
	// �ж�˳������Ƿ���ڵ������鳤�ȣ������׳��쳣��̬��������
	if (m_length >= m_maxSize)
		return false;

	// �ڱ�β�������Ԫ��e
	m_pDataArr[m_length] = e;

	// ����1
	m_length++;

	return true;
}

// ����Ԫ�ز���
bool SeqList::insertList(int i, const ElemType e)
{
	// �ж�˳����Ƿ�δ�� �� i�Ƿ��ںϷ���Χ��
	if (m_length >= m_maxSize || i < 0 || i > m_length) // ����i�ڱ�β��һ��λ�ò���
		return false;

	// �����һ��Ԫ�ؿ�ʼ��ǰ��������i��λ�ã��ֱ����Ƕ�����ƶ�һ��λ��
	if (i <= m_length - 1) // �ڱ�β��һ��λ�ò����������������ú���
	{
		for (int k = m_length - 1; k >= i; k--)
		{
			m_pDataArr[k + 1] = m_pDataArr[k];
		}
	}

	// ��Ҫ����Ԫ������λ��i��
	m_pDataArr[i] = e;
	// ��+1
	m_length++;

	return true;
}

// ɾ��Ԫ�ز���
bool SeqList::deleteList(int i, ElemType *e)
{
	// �ж�˳����Ƿ�δ�� �� i�Ƿ��ںϷ���Χ��
	if (m_length == 0 || i<0 || i > m_length - 1)
		return false;

	// ȡ��ɾ��Ԫ��
	*e = m_pDataArr[i];

	// ��ɾ��Ԫ�ص���һ��λ�ÿ�ʼ���������һ��Ԫ��λ�ã��ֱ����Ƕ���ǰ�ƶ�һ��λ��
	if (i != m_length - 1) // ����ɾ��λ���ڱ�β������Ҫǰ�ơ�
	{
		// ��ɾ��Ԫ�ص���һ��λ�ü�����Ԫ����ǰ�ƶ�һλ
		for (int k = i; k < m_length - 1; k++)
			m_pDataArr[k] = m_pDataArr[k + 1];
	}

	// ����1
	m_length--;

	return true;
}

// ����˳���
void SeqList::traverseList()
{	
	// �ж�˳����Ƿ���ڣ��Լ��Ƿ�Ϊ�ձ�
	if (m_pDataArr == NULL || m_length == 0)
		return;

	for (int i = 0; i < m_length; i++)
	{
		cout << m_pDataArr[i] << " ";
	}
	cout << endl;
}

