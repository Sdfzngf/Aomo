#include <vector>
#include <iostream>
using namespace std;
#include "../include/print.h"
#include "../include/clarg.h"
#include "../include/symbol.h"

void dspl(string option, string desc, string usage)
{
    Print("选项 " << option << ":\n介绍:\n  " << desc << "\n用法:\n  " << usage << endl);
}
// 显示帮助信息
int DisplayHelpInformation(vector<string> v)
{
    if (v.size() == 1)
    {
        Print(HELPINFORMATION << endl);
        return 0;
    }
    else
    {
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] == "-o")
            {
                dspl("-o","指定输出文件,输出文件只能有一个","aomo (-i) <源文件> -o <输出文件名> ...");
            }
            if (v[i] == "-i")
            {
                dspl("-i","指定输入文件","aomo -i <源文件> ...");
            }
            if (v[i] == "--verbose")
            {
                dspl("--verbose","开启详细输出","aomo ... --verbose");
            }
            if (v[i] == "--help")
            {
                dspl("--help","显示帮助信息","aomo --help [选项]");
            }
            if (v[i] == "--version")
            {
                dspl("--version","显示版本","aomo --version");
            }
        }
    }
    return DONE;
}