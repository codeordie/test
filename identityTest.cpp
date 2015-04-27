#include<iostream>

using namespace std;

int a[3][3]={
	7,4,1,
	8,5,2,
	9,6,3
};

int b[3][3]={
	3,2,1,
	6,5,4,
	9,8,7
};

int d[3][3]={
	1,0,0,
	0,1,0,
	0,0,1
};

int c[3][3]={};

void main(){
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			for(int k=0;k<3;k++)
				c[i][j]+=a[i][k]*d[k][j];

	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			cout<<c[i][j]<<" ";
		cout<<endl;
	}

}
