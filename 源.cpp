#include <iostream>
#include <fstream>    //文件流头文件
#include <Windows.h>
#include <string>

#define N 32

using namespace std;

bool isPeak(int grid[N][N], int r, int c);

int main(void) {
	int nrows, ncols;
	int map[N][N];
	string filename;
	ifstream file;

	cout << "请输入文件名：";
	cin >> filename;
	
	file.open(filename.c_str());
	if (file.fail()) {
		cout << "打开输入文件出错！" << endl;
		exit(1);
	}

	file >> nrows >> ncols;

	if (nrows > N || ncols > N) {
		cout << "网格太大！调整程序！" << endl;
		exit(1);
	}

	//从数据文件中读取数据到二维数组
	for (int i = 0; i < nrows; i++) {
		for (int f = 0; f < ncols; f++) {
			file >> map[i][f];
		}
	}

	//判断并打印峰值的位置
	for (int i = 1; i < nrows - 1; i++) {
		for (int f = 1; f < ncols - 1; f++) {
			if (isPeak(map, i, f)) {
				cout << "峰点出现在：" << i << "行 " << f << "列" << endl;
			}
		}
	}

	system("pause");
	//关闭文件
	file.close();

	//结束程序
	return 0;
}

bool isPeak(int grid[N][N], int r, int c) {
	if ((grid[r][c] > grid[r - 1][c]) && (grid[r][c] > grid[r + 1][c]) &&
		(grid[r][c] > grid[r][c - 1]) && (grid[r][c] > grid[r][c + 1])) {
		return true;
	} else {
		return false;
	}
}