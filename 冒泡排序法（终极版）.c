#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int cmp_int(const void* e1, const void* e2)//自定义比较函数
{
	return *(int*)e1 - *(int*)e2;
}
void my_swap(char* buf1, char* buf2, size_t width)
{
	int i;
	for (i = 0; i < width; i++)
	{
		char* tmp =*buf1;
		*buf1++ = *buf2;
		*buf2++ = tmp;
	}
}

void bubble_sort(void* base, size_t sz, size_t width, int (*cmp)(const void* e1,const void* e2))
{
	int i, j;
	for (i = 0; i < sz-1; i++)
	{
		for (j = 0; j < sz -1 - i; j++)
		{
			if (cmp_int((char*)base + j * width,(char*)base + (j + 1) * width)>0)
			{
				my_swap((char*)base + j * width, (char*)base + (j + 1) * width,width);
			}
		}
	}
}
int main(int argc, char *argv[]) 
{
	int i = 0;
	int arr[] = { 3,11,2,5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}
