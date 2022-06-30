#define _CRT_SECURE_NO_DEPRECATE
#include<cstdio>
#include<iostream>
#include <algorithm>

using namespace std;

struct Stu {
	char name;
	int marks;
}student[100];

void Fast_Sort(int* a, char *b,int first, int last) {
	if (first < last) {
		//如果区间不只一个数
		int temp = a[first];//将区间的第一个数作为基准数
		char tempc = b[first];//将区间的第一个数作为基准数
		int i = first;//从左到右进行查找时的“指针”，指示当前左位置
		int j = last;//从右到左进行查找时的“指针”，指示当前右位置

		while (i < j) {
			//当右边的数大于基准数时，略过，继续向左查找
			//不满足条件时跳出循环，此时的j对应的元素是小于基准元素的
			while (i<j && a[j] > temp)
				j--;
			//将右边小于等于基准元素的数填入右边相应位置
			a[i] = a[j];
			b[i] = b[j];
			//当左边的数小于等于基准数时，略过，继续向右查找
			//(重复的基准元素集合到左区间)
			//不满足条件时跳出循环，此时的i对应的元素是大于等于基准元素的
			while (i < j && a[i] <= temp)
				i++;
			//将左边大于基准元素的数填入左边相应位置
			a[j] = a[i];
			b[j] = b[i];
		}
		//将基准元素填入相应位置
		a[i] = temp;
		b[i] = tempc;
		//此时的i即为基准元素的位置
		//对基准元素的左边子区间进行相似的快速排序
		Fast_Sort(a, b, first, i - 1);
		//对基准元素的右边子区间进行相似的快速排序
		Fast_Sort(a, b, i + 1, last);
	}
	//如果区间只有一个数，则返回
	else return;
}

int Delet_Re(int a[], int number,int b[]) {
	int n = unique(a, a + number) - a;//取得去重的参数

	for (int i = 0; i < n; i++) {//去重并保存
		b[i] = a[i];
	}
	return n;
}


int main() {
	FILE* fp = NULL;
		fp = fopen("C:\\Users\\lx\\Desktop\\wendang\\C++\\group_work\\final_work\\c（i\\c（i\\test.xls", "r");//C:\\Users\\lx\\Desktop\\wendang\\C++\\group_work\\final_work\\c（i\c\（i\\test.xls
	//char test1[6] = { 'a','b','c','d','e','f'};
	//int test2[6] = { 1,2,3,4,5,6 };
		char test1[13];
		int test2[13]={0},test3[13]={0},test4[13]={0};
	int k,student_number;
	printf("请输入参加考试的人数：");
	scanf("%d", &student_number);
	k = 2 * student_number;
	for(int i = 0;i<=k;i++)
		//for (int j = 0; j <= 6; j++) 
	{
			fscanf(fp, "%d", &test2[i]);
			
			fseek(fp, 2L, SEEK_CUR);
		}	

	fclose(fp);

	for (int i = 1, j = 0; i <= k; i += 2, j++) {
		test3[j] = test2[i];
		test1[j] = 'A' + j; 
		//printf("%c ", test1[j]);
		//printf("%d ", student[j].marks);
	}

	Fast_Sort(test3,test1,0,student_number - 1);//test3存储排序数列


	for (int i = 0; i < student_number; i ++) {
		student[i].marks = test3[i];
		student[i].name = test1[i];
		//printf("%c %d\n ", student[i].name,student[i].marks);
	}//将排好序的数列和人物命存储入结构体

	for (int i = 0; i < Delet_Re(test3, student_number, test4); i++); //printf("%d ", test4[i]);test4存储去重排序数列

	fp = fopen("C:\\Users\\lx\\Desktop\\wendang\\C++\\group_work\\final_work\\c（i\\c（i\\test.xls", "w");//D:\\test\\test.xls

	for (int i = 0; i < student_number; i++) {
		fprintf(fp, "%c\t%d\n", student[i].name, student[i].marks);
	}
	fprintf(fp, "去重序列为:\n");
	for (int i = 0; i < student_number; i++) {
		if (test4[i] != 0) fprintf(fp, "%d ", test4[i]);
		else continue;
	}
	fclose(fp);
	return 0;
}