#include<iostream>
#include<new>
using namespace std;
int main(){
	try{
		for(;;)
			new double[100];
	}catch(bad_alloc){
		cout<<"RAMA NE STIGA!!!"<<endl;
		return 0;
	}
}
