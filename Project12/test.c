#include <stdio.h>
#include <windows.h>  //Sleep(1000);
#include <string.h>   //strcmp(password,"abcdef")==0 ;     则其为真
#include <stdlib.h>   //ststem("cls")l;
#include <time.h>
#include <math.h>
//int main()
//{
    /*int a;
    int b;
    int c;
    int d;
    scanf_s("%d;%d,%d,%d",&a, &b, &c, &d);
    int x = a + b + c + d;
    printf("%d\n",a);*/
    /*int a = 0;
    float b = 0;
    float c = 0;
    float d = 0;
    scanf_s("%d;%f,%f,%f", &a, &b, &c, &d);
    printf("The each subject score of No. %d is %.2f, %.2f, %.2f.", a, b, c, d);*/
    /*int arr[] = {0};
    int i = 0;
    while (i < 4)
    {
        scanf_s("%d", &arr[i]);
        i = i++;
    }
    int max = arr[0];
    int m = 0;
    while (m < 4)
    {
        if (max < arr[m])
        {
            max = arr[m];
        }
        m = ++m;
    }
    printf("%d\n", max);
        */
    /*int max = 0;
    int a = 0;
    int i = 1;
    scanf_s("%d", &max);
        while (i < 4)
        {
            scanf_s("%d", &a);
            if (max<a)
            {
                max = a;
            }
            i++;
        }
        printf("%d\n", max);*/



    //int weight = 0;
    //float high = 0;
    //scanf_s("%d %f", &weight, &high);
    //float c = high / 100;
    //float bmi = weight /(c * c);
    //printf("%.2f\n", bmi);



   /* long a = 0;
    for (a = 0;a < 114514123133; a++)
    {
        int b = a * a;
        printf("%d ", b);
    }*/


    /*int i = 0;
    int k = 0;
    for (i = 0, k = 0;k == 0;k++, i++)
    {
        k++;
        printf("hehe\n");
    }*/



        /*int a = 1;
        int b = 0;
        int n = 1;
        int i = 1;
        for (n = 1;n <= 3; n++)
        {
            a = 1;
            for (i = 1;i <= n;i++)
            {
                a = a * i;
            }
            b = b + a;
        }
        printf("%d\n", b);*/



     /*int a = 1;
     int b = 0;
     int i = 1;
     for(i=1;i<=3;i++)
     {
         a = a * i;
         b = b + a;
     }
     printf("%d\n", b);*/

//int i = 1;
//int a = 1;
//int b = 0;
// while (i <= 3)
//   {
//     a = a * i;
//     b = b + a;
//     i++;
//   }
//    printf("%d\n", b);


    /*int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };
    int k = 7;
    int sz = sizeof(arr) / sizeof(arr[0]);
    int left = 0;
    int right = sz - 1;
    while(left<=right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] < k)
        {
            left = mid + 1;
        }
        else if (arr[mid] > k)
        {
            right = mid - 1;
        }
        else
        {
            printf("下标是: %d", mid);
            break;
        }
    }
    if (left > right)
    {
        printf("没找到");
    }*/



//char arr1[] = "hello world!!!!";
//char arr2[] = "##################";
//int left = 0;
//int right = strlen(arr1) - 1;
//while (left <= right)
//{
//    arr2[left] = arr1[left];
//    arr2[right] = arr1[right];
//    printf("%s\n",arr2);
//    Sleep(1000);
//    left++;
//    right--;
//void menu()
//{
//    printf("**********************************\n");
//    printf("*********** 1.play      **********\n");
//    printf("*********** 0.exit      **********\n");
//    printf("**********************************\n");
//}
//void game()
//{
//    int a = 0;
//    int ret = rand() % 100 + 1;
//    while (1)
//    {
//        printf("请输入猜的数字>:");
//        scanf_s("%d", &a);
//        if (a > ret)
//        {
//            printf("猜大了>:");
//        }
//        else if (a < ret)
//        {
//            printf("猜小了>:");
//        }
//        else
//        {
//            printf("猜对啦！！！>:");
//            break;
//        }
//   }
//}
//int main()
//{
//    srand((unsigned)time(NULL));
//    int input = 0;
//      do
//    {
//        menu();
//        printf("请选择>:\n");
//        scanf_s("%d", &input);
//        switch (input)
//        {
//        case 1:
//            game();
//                    break;
//        case 0:
//                    break;
//        default:
//            printf("输错了，再输一次呗>:\n");
//                    break;
//        }
//      } while (input);
//    return 0;
//}
//int main()
//{
//again:
//    printf("hehe");
//    printf("hehe");
//    goto again;
//}
//int main()
//{
//    char input[20] = { 0 };
//    system("shutdown -s -t 60");
//again:
//    printf("输入a即可不关机\n");
//    scanf_s("%s",input);
//    if (strcmp(input, "a") == 0)
//        system("shutdown -a");
//    else
//        goto again;
//    return 0;
//
//

//void Swep(int x, int y)
//{
//    int z = 0;
//    z = x;
//    x = y;
//    y = z;
//}
//int main()
//{
//    int a = 0;
//    int b = 0;
//    scanf_s("%d %d", &a, &b);
//    printf("修改前 a=%d b=%d\n", a, b);
//    Swep(a, b);
//    printf("修改后 a=%d b=%d\n", a, b);
//}


//新方法


//void Swep(int *px, int *py)
//{
//    int z = 0;
//    z = *px;
//    *px = *py;
//    *py = z;
//}
//int main()
//{
//    int a = 0;
//    int b = 0;
//    scanf_s("%d %d", &a, &b);
//    printf("修改前 a=%d b=%d\n", a, b);
//    Swep(&a,&b);
//    printf("修改后 a=%d b=%d\n", a, b);
//}



//素数


//int main()
//{
//   /* int i = 0;
//    for (i = 100; i <= 200; i++)
//    {
//        int j = 0;
//        for (j = 2;j <= i - 1;j++)
//        {
//            if (i % j == 0)
//                continue;
//        }
//        printf("%d\n", i);
//    }*/
//
//
//    int i = 0;
//    for (i = 101;i <= 200;i +=2)
//    {
//        int flat = 0;
//        int j = 0;
//        for (j = 2;j <= sqrt(i);j++)
//        {
//            if (i % j == 0)
//            {
//                flat = 1;
//                break;
//            }
//        }
//        if (flat == 0)
//            printf("%d ", i);
//    }
//
//    /*int i = 0;
//    int j = 0;
//    scanf_s("%d", &i);
//    for (j = 2;j <= i - 1;j++)
//    {
//        if (i % j == 0)
//        {
//            printf("i不是素数");
//            break;
//        }
//        else if(j==i-1)
//            printf("i是素数");
//    }
//    */
//    return 0;
//}



//闰年
//int Run(int n)
//{
//    if ((n % 4 == 0 && n % 100 != 0) || (n % 100 == 0 && n % 400 == 0))
//        return 1;
//    else
//        return 0;
//}
//
//int main()
//{
//    int a = 0;
//    scanf_s("%d", &a);
//    int c = Run(a);
//    if (c == 1)
//        printf("yes");
//    else
//        printf("no");
//    return 0;
//}

//int main()
//{
//    unsigned int num = 0;
//    scanf_s("%u", &num);
//    int arr[] = { 0 };
//    int i = 1;
//    int b = strlen("num");
//    while (i <= b)
//    {
//        int arr = num % 10;
//        num = num / 10;
//        i++;
//    }
//    int sz = (sizeof(arr) / sizeof(arr[1]));
//    int d = 1;
//    while (d<=sz)
//    {
//        printf("%c ", arr[sz-1]);
//        sz--;
//        d++;
//    }
//    return 0;
//}

//void print(int num) 
//{
//    if (num>9)
//    {
//        print(num/10);
//    }
//    printf("%d ", num % 10);
//}
//int main()
//{
//    unsigned int num = 0;
//    scanf_s("%u", &num);
//    print(num);
//    return 0;
//}



//int main()
//{
//    int i = 1;
//    int n = 1;
//    int sum = 1;
//    while (1)
//    {
//        n=n* (i+ 1);
//        sum = sum + n;
//        i++;
//        printf("%d ", 114514);
//    }
//    printf("%d\n", sum);
//    return 0;
//}

//int fib(int n)
//{
//    if (n <= 2)
//        return 1;
//    else
//        return fib(n - 1) + fib(n - 2);
//}
//int main()
//{
//    int n = 0;
//    scanf_s("%d", &n);
//    int ret = fib(n);
//    printf("%d ", ret);
//    return 0;
//}



//int fib(int n)
//{
//    int a = 1;
//    int b = 1;
//    int c = 1;
//    while(n>=3)
//    {
//        c = a + b;
//        a = b;
//        b = c;
//        n--;
//    }
//    return c;
//}
//int main()
//{
//    int n = 0;
//    scanf_s("%d", &n);
//    int ret = fib(n);
//    printf("%d ", ret);
//    return 0;
//}

void reverse(char* str)
{
    int len = strlen(str);
    char tem = 0;
    tem = *str;
    *str = *(str + len - 1);
    *(str + len - 1) = '\0';
    if (strlen(str + 1) >= 2)
    {
        reverse(*str + 1);
    }
    *(str + len - 1) = tem;
}
int main()
{
    char arr[] = "abcdefg";
    reverse(arr);
    printf("%s", arr);
    return 0;
}



