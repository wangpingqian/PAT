//============================================================================
// Name        : 1016.cpp
// Author      : wq
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
#include<string.h>
#include<cstring>
#include<string>
using namespace std;
#define mx 1001
struct com {
	int flag;
	int time;
};
struct pepinfo {
	string name;
	com c[mx];
	int f[mx];
	int m;
	int mon;
	int n;
	pepinfo() {
		m = 0;
		n=0;
	}
} p[mx];
bool cmp(com A, com B) {
	return A.time < B.time;
}
bool cmp1(pepinfo A, pepinfo B) {
	return A.name < B.name;
}
int fee[24] = { 0 };
int fee2[24] = { 0 };

int main() {
	cin >> fee[0];
	for (int t = 1; t < 24; t++) {
		cin >> fee[t];
		fee2[t] = fee2[t - 1] + 60 * fee[t - 1];
	}
	int n;
	int sum = 0;
	cin >> n;
	map<string, int> mp;
	char tim[20];
	int a1, a2, a3, a4;
	int all = 0;
	char type[20];
	string name;
	int id;
	int ty = 0;
	for (int t = 0; t < n; t++) {
		cin >> name >> tim >> type;
		all = 0;
		map<string, int>::iterator it = mp.find(name);
		if (it == mp.end()) {
			mp[name] = sum;
			id = sum;
			sum++;
		} else {
			id = it->second;
		}
		if (type[2] == 'f')
			ty = 1;
		else {
			ty = 0;
		}
		sscanf(tim, "%d:%d:%d:%d", &a1, &a2, &a3, &a4);
		all = a2 * 60 * 24 + a3 * 60 + a4;
		p[id].c[p[id].m].flag = ty;
		p[id].c[p[id].m].time = all;
		p[id].name = name;
		p[id].mon = a1;
		p[id].m++;
	}
	sort(p, p + sum, cmp1);
	for (int t = 0; t < sum; t++) {
		sort(p[t].c, p[t].c + p[t].m, cmp);
		for (int i = 1; i < p[t].m; i++) {
			if (p[t].c[i - 1].flag == 0 && p[t].c[i].flag == 1) {
				p[t].f[i - 1] = 1;
				p[t].f[i] = 1;
				p[t].n=1;
				i = i + 1;
			}
		}
	}
	for (int t = 0; t < sum; t++) {
		if(p[t].n==0)
					continue;
		cout << p[t].name << " ";
		printf("%02d\n", p[t].mon);
		int total1 = 0;
		int total2 = 0;
		int total = 0;
		int i, j;
		int m = 0;

		for (int ii = 0; ii < p[t].m; ii++) {
			if (p[t].f[ii] == 1) {
				if (m % 2 == 0) {
					i = p[t].c[ii].time;
					m++;
				} else {
					j = p[t].c[ii].time;
					m++;
					int day, hour, min;
					day = i / (24 * 60);
					hour = (i - day * 24 * 60) / 60;
					min = (i - day * 24 * 60) % 60;
					total1 = day * (fee2[23] + 60 * fee[23]) + (fee2[hour])
							+ fee[hour] * min;
					printf("%02d:%02d:%02d ", day, hour, min);
					day = j / (24 * 60);
					hour = (j - day * 24 * 60) / 60;
					min = (j - day * 24 * 60) % 60;
					total2 = day * (fee2[23] + 60 * fee[23]) + (fee2[hour])
							+ fee[hour] * min;
					printf("%02d:%02d:%02d ", day, hour, min);

					printf("%d $%d.%02d\n", j - i, (total2 - total1) / 100,
							(total2 - total1) % 100);
					total = total + total2 - total1;
				}
			}
		}
		printf("Total amount: $%d.%02d\n", total / 100, total % 100);
		int tt = 0;
	}
	return 0;
}
