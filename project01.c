#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//����һ���̶����ȵ��������
int* RandomBuffer() {

	srand((unsigned int)time(NULL));//��rand()�����������������-��ʱ�������Ϊ�ڲ�ͣ�䣩��ʵ��
	int randBuffer[10];
	for (int i = 0; i < (sizeof(randBuffer) / sizeof(randBuffer[0])); i++)
	{

		int x = rand() % 100+1;//����0~100�������
		randBuffer[i] = x;//������У����˼�ͣ
	}
	return &randBuffer;

}

//ɾ����������Сֵ
bool Del_Min(int *array,int *MinValue) {

	int length = 10;//��¼���鳤��
	if (length == 0)
	{

		return false;
	}
	else
	{

		int pos = 0;//��������--��¼��Сֵ���±�
		*MinValue = array[0];//Ĭ�ϵ�һ��Ϊ��С

		for (int i = 1; i < length; i++)
		{
			if (array[i] < MinValue)
			{
				*MinValue = array[i];
				pos = i;
			}
		}
		array[pos] = array[length - 1];
		length--;
		return true;
	}
}

//����
void test01() {

	int MinValue = 0;
	bool tag=Del_Min(RandomBuffer(), &MinValue);

	if (tag == true)
	{
		printf("ɾ���ɹ�����СֵΪ��%d", MinValue);
	}
}

int main()
{

	test01();
	return 0;
}