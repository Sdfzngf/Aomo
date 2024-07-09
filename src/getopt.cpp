#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#include "../include/print.h"
#include "../include/clarg.h"
#include "../include/symbol.h"
#include "../include/config.h"
#include "../include/parser/parser.h"

extern bool verbose;

// 把命令行参数解析为vector
vector<vector<string>> Getopt(int argc, char *argv[])
{
    vector<vector<string>> v;
    vector<string> tmp; // 临时vector
    bool afterhelp = false;
    // 程序的运行命令
    v.push_back(vector<string>{argv[0]});
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "--help") == 0)
        {
            if (!tmp.empty())
            {
                v.push_back(tmp);
            }
            tmp.clear();
            afterhelp = true; // 判断选项是否在 --help 之后
        }
        // 识别选项
        if (argv[i][0] == '-' && !afterhelp) // 如果识别到选项
        {
            if (!tmp.empty())
            {
                v.push_back(tmp);
            }
            tmp.clear();
        }

        tmp.push_back(argv[i]);
    }
    if (!tmp.empty())
    {
        v.push_back(tmp);
        tmp.clear();
    }
    return v;
}
// 处理参数
int CLArg(vector<vector<string>> arg)
{
    vector<string> inputfile;
    vector<string> outputfile;
    for (int i = 1; i < arg.size(); i++)
    {
        for (int j = 0; j < arg[i].size(); j++)
        {
            if (arg[i][0] == "--help")
            {
                // 显示帮助信息并返回
                return DisplayHelpInformation(arg[i]);
            }
            if (arg[i][0] == "--version")
            {
                Print("Aomo" << " " << AOMO_VERSION << endl);
                return DONE;
            }
            else if (arg[i][0] == "--verbose")
            {
                verbose = true;
            }
            else if (arg[i][0] == "-o")
            {
                if (j!=0)
                    outputfile.push_back(arg[i][j]);
            }
            else if (arg[i][0] == "-i")
            {
                if (j!=0)
                    inputfile.push_back(arg[i][j]);
            }
            else if (arg[i][0][0] == '-')
            {
                // 报错并返回
                PrintError("未知的选项: " << arg[i][j] << endl);
                return UNKNOWOPTION;
            }
            else
            {
                inputfile.push_back(arg[i][j]);
            }
        }
    }
    if (verbose)
    {
        PrintInJSON(arg);
    }
    return Preprocess(inputfile,outputfile);
}