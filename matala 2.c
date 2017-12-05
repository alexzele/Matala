#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>

void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex5();

int *getArr(int *);
void printArr(int *, int);

void sumArray(int *, int);

int difOfSums(int, int);

void print_space(int, int);
void print_pascal_line(int); 
void print_pascal_triangle(int); 

int dividorsSum(int); 

void printBetrothedNumbers(int);

double Newton_Raphson(double, double); 

int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf_s("%d", &all_Ex_in_loop) == 1)
	{
		do
		{
			for (i = 1; i <= 5; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-5 : ");
				scanf_s("%d", &select);
			} while ((select < 0) || (select > 5));
			switch (select) {
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;
			case 5: Ex5(); break;
			}
		} while (all_Ex_in_loop && select);
		
	}
	return 0;
}

/*Mission 1*/

void Ex1()
{
	int size, *arr;
	arr = getArr(&size);
	sumArray(arr, size);
	printArr(arr, size); 
	free(arr); 
}

int *getArr(int *size) 
{
	int i, *arr; 
	printf("Enter size of array:\n");
	scanf("%d", size);
	arr = (int *)malloc((*size) * sizeof(int)); 
	printf("Enter elements of the array:\n");
	for (i = 0; i < *size; i++)
		scanf("%d", arr + i);
	
	return arr;
}


void printArr(int *arr, int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void sumArray(int *arr, int size) 
{
	int i; 
	for (i = 1; i < size; i++)
		arr[i] += arr[i - 1];
} 

/*Mission 2*/

void Ex2()
{
	int a, b; 
	printf("Enter a<b:\n");
	scanf("%d%d", &a, &b);
	while (a >= b) 
	{
		printf(" Enter a < b:\n");
		scanf("%d%d", &a, &b);
	}
	printf("%d\n", difOfSums(a, b)); 
}


int difOfSums(int a, int b)
{
	int  num, sum = 0;
    double mid = (a + b) / 2.; 
	printf("Enter series of integers, until -1:\n");
	scanf("%d", &num);
	while (num != -1)
	{
		if (a< num && num <mid) 
			sum-= num;
		else if (mid< num && num< b)
			sum+= num;
		scanf("%d", &num);
	} 
	return sum;
}

/*Mission 3*/

void Ex3()
{
	int n; 
	printf("Enter number of pascal line:\n");
	scanf("%d", &n);
	print_pascal_triangle(n);
}

void print_pascal_triangle(int n)

{
	int i;
	for (i = 0; i <= n; i++)
	{
		print_space(i, n);
		print_pascal_line(i);
	}
}

void print_space(int i, int n)

{
	for (; i < n; i++)
		printf(" ");
}

void print_pascal_line(int k)

{
	int bin=1,i;
	printf("1 ");
	for(i=1;i<=k;i++)
	{
		bin=(bin*(k-i+1))/i;
		printf("%d ",bin);
	}
	printf ("\n");
}


/*Mission 4*/
void Ex4()
{
	int num;
	printf("Enter upper bound of betrothed numbers :\n");
	scanf("%d", &num);
	printBetrothedNumbers(num);
	printf("\n");
}

int dividorsSum(int num)
{
	int sum = 0, i;
	for (i = 2; i * i < num; i++) 
		if (num % i == 0)
			sum += i + num / i;
	if (i * i == num)
		sum += i;
	return sum;
}

void printBetrothedNumbers(int n) 
{
	int i; 
	for (i = 2; i < n; i++) 
	{
		int sum = dividorsSum(i);
		if (i < sum && dividorsSum(sum) == i)
			printf("( %d - %d ) ", i, sum);
	}
}

/*Mission 5*/

void Ex5()
{
	double n; 
	printf("Enter n to find sqrt(n):\n");
	scanf("%lf", &n);
	if (n<0)
		printf("sqrt is defined only for n >= 0\n");
	else
	    printf("sqrt(%.2lf) = %.3lf\n", n, Newton_Raphson(1, n)); 
}

double Newton_Raphson(double x, double n)

{
	double x1 = x - (x * x - n) / (2 * x);
	if (fabs(x1 - x) < 0.00001) 
		return x1; 
	return Newton_Raphson(x1, n);
}