/*
Assigned by:
Student_alex _zelentsov #ID 321233256
Student_Mike_Rozen #ID 312691207
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
void swap(int *v, int *u);
int *input_array_dyn(int n);
void remove_char(char *str, char ch);
void quick_sort(int *a, int first, int last);
int sum_add_sub(int num);
void *same_same(int *ar1, int *ar2, int n, int m);
int partition(int *a, int left, int right);

void swap(int *v, int *u)  //function aid for ex3
{
	int temp;
	temp = *v;
	*v = *u;
	*u = temp;
}
int sum_add_sub(int num)////function aid for ex2
{

	if (num != 0)
	{
		return (num % 10 + sum_add_sub(num / -10));
	}
	else
	{
		return 0;
	}
}
int divi_11(int num)//ex 2
{
	int nnum;
	nnum = sum_add_sub(num);
	while (nnum>9)
		nnum = sum_add_sub(nnum);
	if (nnum == 0)
		return 1;//("The number you insert can be divisible by 11");
	else return 0;//("The number you insert can't be divisible by 11");


}
void Ex1()
{
	int first = 0, last, i;
	int *a, size;
	printf("Input size");
	scanf_s("%d", &size);
	a = input_array_dyn(size);
	last = size - 1;
	while (first <= last)
	{
		if (a[first] % 2 == 0 && a[last] % 2 == 1)
		{
			swap(&a[first], &a[last]);
			first++;
			last--;
		}
		else if (a[first] % 2 == 0 && a[last] % 2 == 0)
			last--;
		else if (a[first] % 2 == 1 && a[last] % 2 == 1)
			first++;
		else
		{
			first++;
			last--;
		}
	}
	for (i = 0;i<size;i++)
		printf("%d ", a[i]);
	printf("\n");
	free(a);
}
void Ex2()
{
	int  num; // input for Ex 2
	printf_s("Please Insert Positive Number:\n");
	scanf_s("%d", &num);
	while (num <0)
	{
		printf_s("Wrong Input, Please Insert again:\n");
		scanf_s("%d", &num);
	}

	if (divi_11(num) == 1)
		printf_s("The number you insert can be divisible by 11\n");
	else printf_s("The number you insert can't be divisible by 11\n");

}
int *input_array_dyn(int n)
{
	int i;
	int *a;
	a = (int *)calloc(n, sizeof(int));
	assert(a);
	printf("enter the array of length %d\n", n);
	for (i = 0;i<n;i++)
		scanf_s("%d", a + i);
	return a;
}
void *same_same(int *ar1, int *ar2, int n, int m) // 
{
	int *c;
	int i = 0, j = 0, k = 0, co = 0;
	int min = n;
	if (n>m)
		min = m;
	c = (int *)calloc(min, sizeof(int));
	quick_sort(ar1, 0, n - 1);
	quick_sort(ar2, 0, m - 1);

	while (i<n  &&  j<m)
	{
		if (ar1[i] == ar2[j])
		{
			c[k++] = ar1[i++];
			j++;
		}
		else if (ar1[i] < ar2[j])
			i++;
		else j++;

	}
	c = (int *)realloc(c, k * sizeof(int));
	for (;co<k;co++)
		printf_s(" %d ", c[co]);
	printf_s("\n");
}
void Ex3()
{
	int  *arr1, *arr2, n, m; // input for Ex 3
	printf_s("Please Insert Size of array one :\n");
	scanf_s("%d", &n);
	printf_s("Please Insert Size of array two :\n");
	scanf_s("%d", &m);
	printf_s("Please Insert numbers of array one :\n");
	arr1 = input_array_dyn(n);
	printf_s("Please Insert numbers of array two :\n");
	arr2 = input_array_dyn(m);

	same_same(arr1, arr2, n, m);
	free(arr1);
	free(arr2);


}
int partition(int *a, int left, int right)
{

	int first = left;
	int pivot;
	int pos;
	srand((unsigned)time(NULL));
	pos = rand() % (right - left + 1) + left;
	swap(a + first, a + pos);
	pivot = a[first];

	while (left<right)
	{
		while (a[right] > pivot) right--;
		while ((left < right) && (a[left] <= pivot)) left++;
		if (left < right)
			swap(a + left, a + right);
	}
	pos = right;
	a[first] = a[pos];
	a[pos] = pivot;
	return pos;
}
void quick_sort(int *a, int first, int last)// quick sort nlogn
{
	int pos;
	if (first<last)
	{
		pos = partition(a, first, last);
		quick_sort(a, first, pos - 1);
		quick_sort(a, pos + 1, last);
	}
}
int part1_excute(int *a, int *b, int n) // part one of Ex 4
{
	int index;
	int ans = 1;
	quick_sort(a, 0, n - 1);
	quick_sort(b, 0, n - 1);
	for (index = 0;index<n;index++)
	{
		if (a[index] != b[index])
			ans = 0;
	}
	if (ans == 0) return 0;
	else return 1; 
	
}
void Part1()//EX 4.1
{
	int *a, *b;
	int ans = 1;
	int size;
	printf("Please input the size of array\n");
	scanf_s("%d", &size);
	printf("First array:\n");
	a = input_array_dyn(size);
	printf("Second array:\n");
	b = input_array_dyn(size);
	printf("If the output is 1, the arrays are the same.\n");
	printf("If the output is 0, the arrays are the not same.\n");
	printf(" The ans is:   %d\n", part1_excute(a,b,size));
	free(a);
	free(b);
}
int Ex4()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once -enter 0, cyclically -enter other number) ");
	if (scanf_s("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 3; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do
			{
				select = 0;
				printf("please select 0-3 : ");
				scanf_s("%d", &select);
			} while ((select<0) || (select>3));
			switch (select)
			{
			case 1: Part1();
				break;
			case 2: 
				break;
			case 3: 
				break;
			}
		} 
	while (all_Ex_in_loop && select);
		return 0;
}
void remove_char(char *str, char ch)//aid for EX 5
{

	char *p1, *p2;
	for (p1 = p2 = str; *p1 != '\0'; p1++)
	{
		*p2 = *p1;
		if (*p2 != ch)
			p2++;
	}
	*p2 = '\0';
}
char Ex5()
{
	
	char *stri; 
	int size; 
	char remove;
	printf("enter size of array\n");
	scanf_s("%d",&size);
	stri = (char*) malloc(size*sizeof(char));
	printf("Please enter your string\n");
	scanf_s("%s", stri);
	printf("Now enter the char you would like to remove\n");
	scanf_s("%s",&remove);
	remove_char(stri,remove);
	printf("Your answer is %s",stri) ;
	printf("/n") ;
	free(stri);
	return 0;

}

int main(void)
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu one or cyclically?\n (once- enter 0, cyclically-enter any other number )\n");
	if (scanf_s("%d", &all_Ex_in_loop) == 1)
		do {
			for (i = 1; i <= 5; i++)
				printf("Ex %d--->%d\n", i, i);
			printf("Exit--->0\n");
			do {
				select = 0;
				printf("please select 0-5: \n");
				scanf_s("%d", &select);
			} while ((select < 0) || (select > 5));
			switch (select) {
			case 1:
				Ex1();
				break;
			case 2:
				Ex2();
				break;
			case 3:
				Ex3();
				break;

			case 4:
				Ex4();
				break;

			case 5:
				Ex5();
				break;
			}
		} while (all_Ex_in_loop && select);
		return 0;

}
