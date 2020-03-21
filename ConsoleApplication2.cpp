// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

// #include <stdio.h>
// #include <string.h>

typedef void(*callback_func1)(unsigned char *p, unsigned char len);
typedef void(*callback_func2)(unsigned int no);

void Register_Callback_Connect(callback_func1 f_con);
void Register_Callback_Disconnect(callback_func2 f_discon);

void Stack_Init(void);
void Stack_Run(void);
//--------user function declaration
void user_function1(unsigned char *p, unsigned char len);
void user_function2(unsigned int no);
//--------user funciton definition
void user_function1(unsigned char *p, unsigned char len)
{
    char xx[30];
    printf("-----create new connection--------------\n");

    sprintf_s(xx, "the mac is %02x-%02x-%02x-%02x-%02x-%02x\n", p[0], p[1], p[2], p[3], p[4], p[5]);
    printf(xx);
    printf("\n\n");
}
void user_function2(unsigned int no)
{
    char xx[30];
    printf("------------the connection is dropped\n");

    sprintf_s(xx, "the ticket number is %d\n", no);
    printf(xx);
    printf("\n\n");
}
//----------------
// global callback function variable
callback_func1 g_CallbackPtr_Con;
callback_func2 g_CallbackPtr_DisCon;

unsigned char g_Mac[]={0x11,0x22,0x33,0x44,0x55,0x66};
unsigned int  g_nCount;

// internal delay function
void self_delay(void)
{
    int i,k;
    for ( i = 0; i < 10000; i++)
    {
        for ( k = 0; k < 20000; k++)
        {
           ;
        }
        
    }
    
}
// register callback function of connection
void Register_Callback_Connect(callback_func1 f_con)
{
    if (f_con != NULL)
    {
        g_CallbackPtr_Con = f_con;
    }
}
// register callback function of disconnection
void Register_Callback_Disconnect(callback_func2 f_discon)
{
    if (f_discon != NULL)
    {
        g_CallbackPtr_DisCon = f_discon;
    }
}
// initialize the stack
void Stack_Init(void)
{
    g_nCount = 0x00;
    g_CallbackPtr_Con = NULL;
    g_CallbackPtr_DisCon = NULL;
}

// run stack
void Stack_Run(void)
{
    self_delay();

    // insert task1
    do
    {
        //tast1
        ;
    } while (0);
    

    g_nCount++;

    if (g_CallbackPtr_Con != NULL)
    {
        g_CallbackPtr_Con(g_Mac, 6);
    }

    self_delay();
    self_delay();

    // insert task2
    do
    {
        //tast2
        ;
    } while (0);

    if (g_CallbackPtr_DisCon != NULL)
    {
        g_CallbackPtr_DisCon(g_nCount);
    }
}


int main()
{
    //std::cout << "Hello World!\n";
    Stack_Init();

    Register_Callback_Connect(user_function1);
    Register_Callback_Disconnect(user_function2);

    while (1)
    {
        Stack_Run();
    }
    
}

