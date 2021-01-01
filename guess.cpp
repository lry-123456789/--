#include<stdio.h>
#include<math.h>
void spilt_eve(unsigned int array[3]);
void spilt_odd(unsigned int array[4]);
int isprime(int x);
void error_1(int a);
void main()
{
    unsigned int a = 1, c = 1;
    unsigned int eve[3] = { 0 };
    unsigned int odd[4] = { 0 };
    //input a number
    for (; a != 0;)
    {
        printf("Please input a number.(from 0 to 65535)\n");
        scanf_s("%d", &a);
        if ((a % 2 == 0) && (a < 6))
        {
            printf("Error Begin.\nif the number is even number, please make sure that it is beyond 6.\n");
            error_1(1);
            continue;
        }
        else if ((a % 2 != 0) && (a < 9))
        {
            printf("Error Begin.\nif the number is odd number, please make sure that it's beyond 9.\n");
            error_1(1);
            continue;
        }

        /*distinguish number and put the equotion out.*/
        if (a % 2 == 0)
        {
            eve[0] = a;
            spilt_eve(eve);

        }

        else
        {
            odd[0] = a;
            spilt_odd(odd);

        }


    }
}

//make sure the number is prime or not.
int isprime(int x)
{
    int i, y = 1;
    for (i = 2; i <= (int)sqrt(x); i++)
    {
        if (x % i == 0)
        {
            y = 0;
            break;
        }
    }
    return(y);
}

void error_1(int a)
{
    printf("please choose a appropriate number");
}

//split the even number.
void spilt_eve(unsigned int eve[3])
{
    int i, m;
    i = eve[0];
    for (m = 3; m <= i / 2; m++)
    {
        if (isprime(m) == 1)
        {
            if ((isprime(i - m == 1)))
            {
                eve[1] = m;
                eve[2] = i - m;
                printf("%d=%d+%d\n", eve[0], eve[1], eve[2]);
            }
        }
    }
}

//split the odd number.
void spilt_odd(unsigned int odd[4])
{
    unsigned int eve[3];
    int i, j, k;
    i = odd[0];
    for (k = 3; k <= i / 3; k++)
    {
        if (isprime(k) == 1)
        {
            for (j = k; j <= i / 2; j++)
            {
                if (isprime(j) == 1)
                {
                    if (isprime(i - k - j) == 1 && ((i - k - j) >= j))
                    {

                        odd[1] = k;
                        odd[2] = j;
                        odd[3] = i - k - j;
                        printf("%d=%d+%d+%d\n", odd[0], odd[1], odd[2], odd[3]);
                    }
                }
            }
        }
    }
}
