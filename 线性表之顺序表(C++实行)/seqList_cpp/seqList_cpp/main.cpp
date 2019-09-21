#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "seqListCpp.h"

using namespace std;

int main()
{
	// ��ʼ��˳���
	SeqList seqList(20);

	// ����Ԫ��0-2��˳���
	cout << "����Ԫ��0-2��˳���!" << endl;
	for (int i = 0; i<3; i++)
	{
		seqList.appendList(i);
	}
	cout << endl;

	// ��λ��2����Ԫ�ص�9˳���
	cout << "��λ��2����Ԫ��9��˳���!" << endl << endl;
	seqList.insertList(2, 9);

	// ��λ��3ɾ��Ԫ��
	int value1;
	if (seqList.deleteList(3, &value1) == false)
	{
		cout << "delete error!" << endl;
		return -1;
	}
	else
	{
		cout << "��λ��3ɾ��Ԫ�أ�ɾ����Ԫ��Ϊ��" << value1 << endl << endl;
	}

	// ����Ԫ��λ��
	int index = seqList.locateElem(0);
	if (index == -1)
	{
		cout << "locate error!" << endl;
		return -1;
	}
	else
	{
		cout << "���ҵ�Ԫ��0��λ��Ϊ��" << index << endl << endl;
	}

	// ����˳���
	cout << "����˳��� ";
	seqList.traverseList();
	cout << endl;

	// ���˳���
	cout << "���˳���!" << endl << endl;
	seqList.clearList();

	return 0;
}

