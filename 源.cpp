#include <iostream>
#include <fstream>    //�ļ���ͷ�ļ�
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

	cout << "�������ļ�����";
	cin >> filename;
	
	file.open(filename.c_str());
	if (file.fail()) {
		cout << "�������ļ�����" << endl;
		exit(1);
	}

	file >> nrows >> ncols;

	if (nrows > N || ncols > N) {
		cout << "����̫�󣡵�������" << endl;
		exit(1);
	}

	//�������ļ��ж�ȡ���ݵ���ά����
	for (int i = 0; i < nrows; i++) {
		for (int f = 0; f < ncols; f++) {
			file >> map[i][f];
		}
	}

	//�жϲ���ӡ��ֵ��λ��
	for (int i = 1; i < nrows - 1; i++) {
		for (int f = 1; f < ncols - 1; f++) {
			if (isPeak(map, i, f)) {
				cout << "�������ڣ�" << i << "�� " << f << "��" << endl;
			}
		}
	}

	system("pause");
	//�ر��ļ�
	file.close();

	//��������
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