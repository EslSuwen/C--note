/*
	@author w
	@date 2019.6.17
	主函数：整合各部分功能
*/
#include "common_header.h"
#define bufsize 300
using namespace std;
char sentence[bufsize];
int main() {
	cout << "请输入文法，每行一个，在行首输入 quit 结束。第一个文法的首字符将被视为开始符号" << endl;
	input_grammer();
	pick_up();
	getFirstN();
	getFirstP();
	getFollow();
	generateTable();
	printAllTerminator();
	printAllNonTerminator();
	printAllFirstN();
	printAllFirstP();
	printAllFollow();
	printTable();

}