#include "pipex.h"

void func1()
{
    
    *g_pid = 1;
    g_pid++;
    *g_pid = 2;
    g_pid++;
    *g_pid = 3;
    g_pid++;
    *g_pid = 4;
    g_pid++;
    *g_pid = 5;
}

int main()
{
    int i = 0;
    while (i < 5)
    {
        func1();
        i++;
    }
    // waitpid(pid)
    i = 0;
    while (g_pid[i])
    {
        printf("====%d\n", g_pid[i]);
        g_pid--;
    }
    // i--;
    // while (i)
    // {
    //     printf("====%d\n", g_pid[i]);
    //     i--;
    // }
}
