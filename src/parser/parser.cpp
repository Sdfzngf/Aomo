#include <iostream>
#include <vector>
using namespace std;
#include "../../include/print.h"
#include "../../include/symbol.h"

extern bool verbose;

//预处理器
int Preprocess(vector<string> inputfile,vector<string> outputfile)
{
    if (verbose)
    {
        PrintNotice("源文件:\n|-");
        PrintInJSON(inputfile);
        PrintNotice("目标文件:\n|-");
        PrintInJSON(outputfile);
    }
    if (inputfile.size() == 0)
    {
        PrintWarn("未指定源文件,退出" << endl);
        return NOTSPECIFIEDINPUTFILE;
    }
    if (outputfile.size() == 0)
    {
        PrintWarn("未指定输出文件,退出" << endl);
        return NOTSPECIFIEDOUTPUTFILE;
    }
    if (outputfile.size() > 1)
    {
        PrintError("输出文件只能有一个" << endl);
        return TOOMANYOUTPUTFILE;
    }

    return 0;
}