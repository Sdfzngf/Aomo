#ifndef H_PRINT
#define H_PRINT

#define Print(text) {cout << text;}
#define PrintNotice(notice) {cout << "\033[36;1mN:\033[0m" << notice;}
#define PrintError(err) {cout << "\033[31;1mE:\033[0m" << err;}
#define PrintWarn(warn) {cout << "\033[33;1mW:\033[0m" << warn;}

int PrintInJSON(vector<vector<string>> v);
int PrintInJSON(vector<string> v);

#endif