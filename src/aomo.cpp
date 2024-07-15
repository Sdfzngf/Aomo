#include <iostream>
#include <vector>
#include <csignal>
#include <unistd.h>
using namespace std;
#include "../include/parser/parser.h"
#include "../include/config.h"
#include "../include/getopt.h"
#include "../include/print.h"

bool verbose = false;

void signalHandler( int signum )
{
    Print("Exit("<<signum<<")\n");
    exit(signum);  
}

int main(int argc, char *argv[])
{
    signal(SIGINT, signalHandler); 
    // 解析出来的命令行参数
    vector<vector<string>> arg = Getopt(argc, argv);

    // 处理解析出来的参数，然后返回
    return CLArg(arg);
}