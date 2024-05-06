#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//生成一个固定长度的随机数组
int* RandomBuffer() {

	srand((unsigned int)time(NULL));//让rand()函数真正生成随机数-以时间戳（因为在不停变）来实现
	int randBuffer[10];
	for (int i = 0; i < (sizeof(randBuffer) / sizeof(randBuffer[0])); i++)
	{

		int x = rand() % 100+1;//生成0~100的随机数
		randBuffer[i] = x;//填到数组中，满了即停
	}
	return &randBuffer;

}

//删除数组中最小值
bool Del_Min(int *array,int *MinValue) {

	int length = 10;//记录数组长度
	if (length == 0)
	{

		return false;
	}
	else
	{

		int pos = 0;//辅助变量--记录最小值的下标
		*MinValue = array[0];//默认第一个为最小

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

//测试
void test01() {

	int MinValue = 0;
	bool tag=Del_Min(RandomBuffer(), &MinValue);

	if (tag == true)
	{
		printf("删除成功！最小值为：%d", MinValue);
	}
}

int main()
{

	test01();
	return 0;
}