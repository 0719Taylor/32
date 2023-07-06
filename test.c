#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>



//数组参数 指针参数


//1.数组传参

//void test(int arr[3][5])
//{}
//void test1(int arr[][5])
//{}
//void test2(int arr[3][]) //error - 列标不可以省略
//{}
//void test3(int arr[][]) //error - 必须要有列标
//{}
//void test4(int* arr) //error
//{}
//void test5(int** arr) //error
//{} 
//void test6(int(*arr)[5])
//{}
//int main()
//{
//	int arr[3][5] = { 0 };
//	//test(arr);//二维数组传参
//	//test1(arr);
//	//test2(arr);
//	//test3(arr);
//	//test4(arr);
//	//test5(arr);
//	test6(arr);
//	return 0;
//}


//2.指针传参

//(1)一级指针传参
//void test1(int* p)
//{}
//void test2(char* p)
//{}
//int main()
//{
//	int a = 10;
//	int* p1 = &a;
//	test1(&a);//ok
//	test1(p1);//ok
//	char ch = 'w';
//	char* pc = &ch;
//	test2(&ch); 
//	test2(pc);
//	return 0;
//}



//(2)二级指针传参
//void test(int** p)
//{}
//int main()
//{
//	int* ptr;
//	int** pp = &ptr;
//	test(&ptr);
//	test(pp);
//	int* arr[10];
//	test(arr);//指针数组也可以
//	return 0;
//}







//函数指针


//数组指针 - 是指向数组的指针
//函数指针 - 是指向函数的指针 - 存放函数地址的一个指针

//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//printf("%d\n",Add(a,b));
//	//&函数名 和 函数名 都是函数的地址
//	/*printf("%p\n",&Add);
//	printf("%p\n",Add);*/
//	int (*pa)(int, int) = Add;
//	printf("%d\n", (*pa)(2, 3)); 
//	return 0;
//}

//void Print(char* str)
//{
//	printf("%s\n",str);
//}
//int main()
//{
//	void (*p)(char*) = Print;
//	(*p)("hello bit");
//	return 0;
//}











//(*(void(*)())0)()     -  把0强制类型转换成：void(*)()函数指针类型 - 0就是一个函数的地址    然后调用0地址处的函数

//singal是一个函数声明     
//signal函数的参数有2个,第一个是int,第二个是函数指针,该函数指针指向的函数参数是int,返回类型是void
//signal函数的返回类型也是一个函数指针,该函数指针指向的函数的参数是int,返回类型是void
//void(*       singal(int, void(*)(int))    )(int);   
//
//typedef void(* pfun_t)(int);	
//pfun_t signal(int, pfun_t);  //简洁版本
//
//
//typedef unsigned int uint;







//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int (*pa)(int, int) = Add;
//	printf("%d\n", (pa)(2, 3)); 
//	printf("%d\n", pa(2, 3));
//	printf("%d\n", *pa(2, 3));  //error
//	printf("%d\n", (*pa)(2, 3));
//	return 0;
//}










//函数指针数组


//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//	//指针数组
//	//int* arr[5];
//	//需要一个数组,这个数组可以存放4个函数的地址 - 函数指针的数组
//	int (*pa)(int, int) = Add; // Sub/Mul/Div
//	int (*parr[4])(int, int) = { Add,Sub,Mul,Div }; //函数指针的数组
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d\n", parr[i](2, 3));
//	}
//	return 0;
//}










/*char* my_strcpy(char* dest, const char* src);
1.写一个函数指针pf,能够指向my_strcpy
char* (*pf)(char*, const char*) = my_strcpy;

2.写一个函数指针数组pfArr,能够存放4个my_strcpy函数的地址
char* (*pfArr[4])(char*, const char*) = { my_strcpy,my_strcpy,my_strcpy,my_strcpy };*/ 


//函数指针数组的用途：转移表

//计算器
//void menu()
//{
//	printf("*********************************\n");
//	printf("***     1.add           2.sub **\n");
//	printf("***     3.mul           4.div **\n");
//	printf("***     5.xor           0.exit**\n");
//	printf("*********************************\n");
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//int Xor(int x, int y)//异或
//{
//	return x ^ y;
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	//pfArr 是一个函数指针数组 - 转移表	
//	int (*pfArr[])(int, int) = { 0,Add,Sub,Mul,Div,Xor };
//	do
//	{
//		menu();
//		printf("请选择：");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 5)
//		{
//			printf("请输入两个操作数：");
//			scanf("%d%d", &x, &y);
//			int ret = pfArr[input](x, y);
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("退出\n");
//		}
//		else
//		{
//			printf("选择错误\n");
//		}
//	} while (input);
//}

//Calc(int (*pf)(int,int)) //参数是函数指针
//{
//	int x = 0;
//	int y = 0;
//	printf("请输入两个操作数：");
//	scanf("%d%d",&x,&y);
//	printf("%d\n",pf(x,y));
//}
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请选择：");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			Calc(Add);
//			break;
//		case 2:
//			Calc(Sub);
//			break;
//		case 3:
//			Calc(Mul);
//			break;
//		case 4:
//			Calc(Div);
//			break;
//		case 0:
//			printf("退出\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//}









//指向函数指针数组的指针

//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int (*p)[10]=&arr;//取出数组的地址
//	int (*pfArr[4])(int, int);//pfArr是一个数组 - 函数指针的数组
//	int (*(*ppfArr)[4])(int, int) = &pfArr; //ppfArr是一个指向函数指针数组的指针
//	//ppfArr 是一个数组指针,指针指向的数组有4个元素
//	//指向的数组的每个元素的类似是一个函数指针 int(*)(int,int)
//	return 0;
//}









//回调函数


//void print(char* str)   //回调函数
//{
//	printf("hehe:%s",str);
//}
//
//void test(void (*p)(char*))
//{
//	printf("test\n");
//	p("bit");
//}
//int main()
//{
//	test(print);
//	return 0;
//}