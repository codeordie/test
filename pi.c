#include<stdio.h>
#include<math.h>
int main(){
	double sum = 1.0,val,pval;
	double denominator = 3.0;
	double numerator = 1.0;
	double temp;
	unsigned long counter = 0;
	while(1){
		numerator = -numerator;
		temp = numerator;
		temp/=denominator;
		sum += temp;
		pval=val;
		val=sum*4;
		if(abs(val-pval)<0.000001)return 0;
		denominator += 2;
		counter++;
		printf("%19.17f\n",val);
		counter=0;
	}
	return 0;
}
