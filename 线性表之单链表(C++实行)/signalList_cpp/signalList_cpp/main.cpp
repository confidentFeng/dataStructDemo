#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "signalList.h"

using namespace std;

int main()
{
	// ��ʼ������
	SignalList signleList(20);

	cout << "����Ԫ��0-2������!" << endl;
	for (int i = 0; i<3; i++)
	{
		signleList.insertList(i+1, i);
	}
	cout << endl;

	// ��λ��2����Ԫ��9������
	cout << "��λ��2����Ԫ��9������!" << endl << endl;
	signleList.insertList(2, 9);

	// ��λ��3ɾ��Ԫ��
	int value1;
	if (signleList.deleteList(3, &value1) == false)
	{
		cout << "delete error!" << endl;
		return -1;
	}
	else
	{
		cout << "��λ��3ɾ��Ԫ�أ�ɾ����Ԫ��Ϊ��" << value1 << endl << endl;
	}

	// ����Ԫ��λ��
	int index = signleList.locateElem(9);
	if (index == -1)
	{
		cout << "locate error!" << endl;
		return -1;
	}
	else
	{
		cout << "���ҵ�Ԫ��9��λ��Ϊ��" << index << endl << endl;
	}

	// ��������
	cout << "�������� ";
	signleList.traverseList();
	cout << endl << endl;

	// �������
	cout << "�������!" << endl << endl;
	signleList.clearList();

	return 0;
}

