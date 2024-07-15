#include <filesystem>
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
using namespace std;
#include "../../include/print.h"
#include "../../include/symbol.h"

extern bool verbose;
vector<fstream> file;
vector<ifstream> tmpfiles;
vector<fstream> optfile;

//编译
int Compile()
{
    for(int i=0;i<tmpfiles.size();i++)
    {
        string s;
        while(getline(tmpfiles[i],s))
        {
            if(verbose)
            {
                PrintNotice(s<<endl);
            }
            //在这里分词并汇编
        }
    }
    
    //递归关闭所有文件
    for(int i=0;i<tmpfiles.size();i++)
    {
        tmpfiles[i].close();
    }
    return 0;
}

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
    
    std::filesystem::create_directory("AomoFiles");
    //遍历所有输入文件并生成预处理文件
    for (int i = 0; i < inputfile.size(); i++)
    {
        file.push_back(fstream(inputfile[i]));

        if(!file[i])
        {
            PrintError("无法读取文件 \""<<inputfile[i]<<"\"");
            return IOERROR;
        }
        if(verbose)
        {
            PrintNotice("!file["<<i<<"]:"<<!file[i]<<"("<<inputfile[i]<<";good:"<<file[i].good()<<")"<<endl);
        }
        
        ofstream o("./AomoFiles/"+to_string(i),ofstream::out);
        tmpfiles.push_back(ifstream("./AomoFiles/"+to_string(i),ifstream::in));
        if(!tmpfiles[i])
        {
            PrintError("无法读取或创建临时文件")
            return IOERROR;
        }

        string s;
        while (getline(file[i],s))
        {
            if(verbose)
            {
                PrintNotice(s<<endl);
            }
            //此处解析预处理指令
            //目前一条预处理指令也没有
            o<<s;
        }
        
        o.close();
        file[i].close();
    }
    return Compile();
}