#ifndef SEQLIST_H
#define SEQLIST_H

typedef int  ElemType; /* "ElemType���͸���ʵ����������� �������Ϊint */

class SeqList
{
public:
	SeqList(int size = 0); // ���캯��
	~SeqList(); // ��������

	bool isEmpty(); // �ж��Ƿ�Ϊ�ղ���
	void clearList(); // ���˳������
	int getLength(); // ��ȡ˳����Ȳ���
	bool getElem(int i, ElemType *e); // ��ȡԪ�ز���
	int locateElem(const ElemType e); // ����Ԫ��λ�ò���
	bool appendList(const ElemType e); // ����Ԫ�ز���
	bool insertList(int i, const ElemType e); // ����Ԫ�ز���
	bool deleteList(int i, ElemType *e); // ɾ��Ԫ�ز���
	void traverseList(); // ����˳���

private:
	ElemType *m_pDataArr; // ָ����˳���Ԫ�ص�����
	int m_length; // ˳���ĵ�ǰ����
	int m_maxSize; // ˳�����������
};

#endif