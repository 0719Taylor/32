#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>



//������� ָ�����


//1.���鴫��

//void test(int arr[3][5])
//{}
//void test1(int arr[][5])
//{}
//void test2(int arr[3][]) //error - �б겻����ʡ��
//{}
//void test3(int arr[][]) //error - ����Ҫ���б�
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
//	//test(arr);//��ά���鴫��
//	//test1(arr);
//	//test2(arr);
//	//test3(arr);
//	//test4(arr);
//	//test5(arr);
//	test6(arr);
//	return 0;
//}


//2.ָ�봫��

//(1)һ��ָ�봫��
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



//(2)����ָ�봫��
//void test(int** p)
//{}
//int main()
//{
//	int* ptr;
//	int** pp = &ptr;
//	test(&ptr);
//	test(pp);
//	int* arr[10];
//	test(arr);//ָ������Ҳ����
//	return 0;
//}







//����ָ��


//����ָ�� - ��ָ�������ָ��
//����ָ�� - ��ָ������ָ�� - ��ź�����ַ��һ��ָ��

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
//	//&������ �� ������ ���Ǻ����ĵ�ַ
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











//(*(void(*)())0)()     -  ��0ǿ������ת���ɣ�void(*)()����ָ������ - 0����һ�������ĵ�ַ    Ȼ�����0��ַ���ĺ���

//singal��һ����������     
//signal�����Ĳ�����2��,��һ����int,�ڶ����Ǻ���ָ��,�ú���ָ��ָ��ĺ���������int,����������void
//signal�����ķ�������Ҳ��һ������ָ��,�ú���ָ��ָ��ĺ����Ĳ�����int,����������void
//void(*       singal(int, void(*)(int))    )(int);   
//
//typedef void(* pfun_t)(int);	
//pfun_t signal(int, pfun_t);  //���汾
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










//����ָ������


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
//	//ָ������
//	//int* arr[5];
//	//��Ҫһ������,���������Դ��4�������ĵ�ַ - ����ָ�������
//	int (*pa)(int, int) = Add; // Sub/Mul/Div
//	int (*parr[4])(int, int) = { Add,Sub,Mul,Div }; //����ָ�������
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d\n", parr[i](2, 3));
//	}
//	return 0;
//}










/*char* my_strcpy(char* dest, const char* src);
1.дһ������ָ��pf,�ܹ�ָ��my_strcpy
char* (*pf)(char*, const char*) = my_strcpy;

2.дһ������ָ������pfArr,�ܹ����4��my_strcpy�����ĵ�ַ
char* (*pfArr[4])(char*, const char*) = { my_strcpy,my_strcpy,my_strcpy,my_strcpy };*/ 


//����ָ���������;��ת�Ʊ�

//������
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
//int Xor(int x, int y)//���
//{
//	return x ^ y;
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	//pfArr ��һ������ָ������ - ת�Ʊ�	
//	int (*pfArr[])(int, int) = { 0,Add,Sub,Mul,Div,Xor };
//	do
//	{
//		menu();
//		printf("��ѡ��");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 5)
//		{
//			printf("������������������");
//			scanf("%d%d", &x, &y);
//			int ret = pfArr[input](x, y);
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("�˳�\n");
//		}
//		else
//		{
//			printf("ѡ�����\n");
//		}
//	} while (input);
//}

//Calc(int (*pf)(int,int)) //�����Ǻ���ָ��
//{
//	int x = 0;
//	int y = 0;
//	printf("������������������");
//	scanf("%d%d",&x,&y);
//	printf("%d\n",pf(x,y));
//}
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("��ѡ��");
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
//			printf("�˳�\n");
//			break;
//		default:
//			printf("ѡ�����\n");
//			break;
//		}
//	} while (input);
//}









//ָ����ָ�������ָ��

//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int (*p)[10]=&arr;//ȡ������ĵ�ַ
//	int (*pfArr[4])(int, int);//pfArr��һ������ - ����ָ�������
//	int (*(*ppfArr)[4])(int, int) = &pfArr; //ppfArr��һ��ָ����ָ�������ָ��
//	//ppfArr ��һ������ָ��,ָ��ָ���������4��Ԫ��
//	//ָ��������ÿ��Ԫ�ص�������һ������ָ�� int(*)(int,int)
//	return 0;
//}









//�ص�����


//void print(char* str)   //�ص�����
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