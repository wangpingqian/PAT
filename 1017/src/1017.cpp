//============================================================================
// Name        : 1017.cpp
// Author      : wq
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
#define mx 10000
struct pepinfo{
	int start;
	int arrive;
	int end;
	int wait;
	int pa;
}p[mx];
struct win{
	int start=8*3600;
	int end;
	queue<int> list;
}w[101];
bool cmp(pepinfo A,pepinfo B){
	return A.arrive<B.arrive;
}

int main() {
	int n,m;
	char tim[20];
	int hh,mm,ss,wa;
	for(int t=0;t<n;t++){
		scanf("%d:%d:%d",&hh,&mm,&ss);
		scanf("%d",&wa);
		p[t].pa=wa;
		p[t].arrive=hh*3600+mm*60+ss;
	}
	sort(p,p+n,cmp);
	for(int t=0;t<m;t++){
		p[t].start=w[t].start;
		w[t].end=p[t].start+p[t].pa;
	}
	return 0;
}
