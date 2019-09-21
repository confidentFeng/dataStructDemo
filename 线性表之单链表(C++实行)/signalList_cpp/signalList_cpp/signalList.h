#ifndef SIGNALLIST_H
#define SIGNALLIST_H

typedef int  ElemType; /* "ElemType���͸���ʵ����������� �������Ϊint */

/* ���Ա�ĵ�����洢�ṹ */
typedef struct node
{
	ElemType data; // ������
	struct node *next; // ָ����
}Node, LinkList;

class SignalList
{
public:
	SignalList(int size = 0); // ���캯��
	~SignalList(); // ��������

	void clearList(); // ����������
	bool isEmpty(); // �ж��Ƿ�Ϊ�ղ���	
	int getLength(); // ��ȡ�����Ȳ���
	bool insertList(int i, const ElemType e); // ����Ԫ�ز���
	bool deleteList(int i, ElemType *e); // ɾ��Ԫ�ز���
	bool getElem(int i, ElemType *e); // ��ȡԪ�ز���
	bool insertListHead(const ElemType e); // ͷ�������Ԫ�ز���
	bool insertListTail(const ElemType e); // β�������Ԫ�ز���
	void traverseList(); // ��������	
	int locateElem(const ElemType e); // ����Ԫ��λ�ò���

private:
	LinkList *m_pList; // ������ָ��
};

#endif