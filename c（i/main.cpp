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
		//������䲻ֻһ����
		int temp = a[first];//������ĵ�һ������Ϊ��׼��
		char tempc = b[first];//������ĵ�һ������Ϊ��׼��
		int i = first;//�����ҽ��в���ʱ�ġ�ָ�롱��ָʾ��ǰ��λ��
		int j = last;//���ҵ�����в���ʱ�ġ�ָ�롱��ָʾ��ǰ��λ��

		while (i < j) {
			//���ұߵ������ڻ�׼��ʱ���Թ��������������
			//����������ʱ����ѭ������ʱ��j��Ӧ��Ԫ����С�ڻ�׼Ԫ�ص�
			while (i<j && a[j] > temp)
				j--;
			//���ұ�С�ڵ��ڻ�׼Ԫ�ص��������ұ���Ӧλ��
			a[i] = a[j];
			b[i] = b[j];
			//����ߵ���С�ڵ��ڻ�׼��ʱ���Թ����������Ҳ���
			//(�ظ��Ļ�׼Ԫ�ؼ��ϵ�������)
			//����������ʱ����ѭ������ʱ��i��Ӧ��Ԫ���Ǵ��ڵ��ڻ�׼Ԫ�ص�
			while (i < j && a[i] <= temp)
				i++;
			//����ߴ��ڻ�׼Ԫ�ص������������Ӧλ��
			a[j] = a[i];
			b[j] = b[i];
		}
		//����׼Ԫ��������Ӧλ��
		a[i] = temp;
		b[i] = tempc;
		//��ʱ��i��Ϊ��׼Ԫ�ص�λ��
		//�Ի�׼Ԫ�ص����������������ƵĿ�������
		Fast_Sort(a, b, first, i - 1);
		//�Ի�׼Ԫ�ص��ұ�������������ƵĿ�������
		Fast_Sort(a, b, i + 1, last);
	}
	//�������ֻ��һ�������򷵻�
	else return;
}

int Delet_Re(int a[], int number,int b[]) {
	int n = unique(a, a + number) - a;//ȡ��ȥ�صĲ���

	for (int i = 0; i < n; i++) {//ȥ�ز�����
		b[i] = a[i];
	}
	return n;
}


int main() {
	FILE* fp = NULL;
		fp = fopen("C:\\Users\\lx\\Desktop\\wendang\\C++\\group_work\\final_work\\c��i\\c��i\\test.xls", "r");//C:\\Users\\lx\\Desktop\\wendang\\C++\\group_work\\final_work\\c��i\c\��i\\test.xls
	//char test1[6] = { 'a','b','c','d','e','f'};
	//int test2[6] = { 1,2,3,4,5,6 };
		char test1[13];
		int test2[13]={0},test3[13]={0},test4[13]={0};
	int k,student_number;
	printf("������μӿ��Ե�������");
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

	Fast_Sort(test3,test1,0,student_number - 1);//test3�洢��������


	for (int i = 0; i < student_number; i ++) {
		student[i].marks = test3[i];
		student[i].name = test1[i];
		//printf("%c %d\n ", student[i].name,student[i].marks);
	}//���ź�������к��������洢��ṹ��

	for (int i = 0; i < Delet_Re(test3, student_number, test4); i++); //printf("%d ", test4[i]);test4�洢ȥ����������

	fp = fopen("C:\\Users\\lx\\Desktop\\wendang\\C++\\group_work\\final_work\\c��i\\c��i\\test.xls", "w");//D:\\test\\test.xls

	for (int i = 0; i < student_number; i++) {
		fprintf(fp, "%c\t%d\n", student[i].name, student[i].marks);
	}
	fprintf(fp, "ȥ������Ϊ:\n");
	for (int i = 0; i < student_number; i++) {
		if (test4[i] != 0) fprintf(fp, "%d ", test4[i]);
		else continue;
	}
	fclose(fp);
	return 0;
}