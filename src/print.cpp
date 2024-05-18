#include <iostream>
#include <vector>
using namespace std;
#include "../include/print.h"
#include "../include/symbol.h"

int PrintInJSON(vector<vector<string>> v)
{
    Print("(" << v.size() << ")");
    Print("\033[1;34m{\033[0m");
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            Print("\033[36m\"" << v[i][j] << "\"\033[0m");
            if (j == 0)
            {
                Print(":\033[1;35m[\033[0m");
            }
            else if (j != v[i].size() - 1)
            {
                Print(",")
            }
            if (j == v[i].size() - 1)
            {
                Print("\033[1;35m]\033[0m")
            }
        }
        if (i != v.size() - 1)
        {
            Print(",");
        }
    }
    Print("\033[1;34m}\033[0m\n");
    // 这段代码理论来说不会出错，所以直接返回0
    return DONE;
}

int PrintInJSON(vector<string> v)
{
    Print("(" << v.size() << ")");
    Print("\033[1;34m{\033[0m");
    for (int i = 0; i < v.size(); i++)
    {
        Print(v[i]);
        if (i != v.size() - 1)
        {
            Print(",");
        }
    }
    Print("\033[1;34m}\033[0m\n");
    return DONE;//返回0的原因同上
}