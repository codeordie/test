#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<int>P;



bool isPrime(int n){
    if(n<2)
        return false;
    else if(2==n)
        return true;
    else if(n%2==0)
        return false;
    else{
        int limit=int(sqrt(n)+1);
        int divisor=3;
        while(divisor<=limit){
            if(n%divisor==0)
                return false;
            divisor+=2;
        }
        return true;
    }
}

void fillArrayWithPrimes(){
	for(int i=0;i<10000;i++)
		if(isPrime(i))
			P.push_back(i);
}

void printPrecomputedPrimes(){
	for(int i=0;i<P.size();i++)
		cout<<P[i]<<endl;
}

bool binarySearch(int value){
	int left=0,right=P.size(),mid;
  while(left<=right){
        mid=(right-left)/2+left;
        if(P[mid]==value)
            return true;
        if(value<P[mid])
            right=mid-1;
        else
            left=mid+1;
  }
  return false;
}

int getNextPrime(){
	static int pr=0;
	do
		pr++;
	while(!isPrime(pr));
	return pr;
}

bool isSumOfTwoPrimes(int n,unsigned&p1,unsigned&p2){
	if(n%2)
		return false;
	do{
		p1=getNextPrime();
		p2=n-p1;
	}while(!isPrime(p2));
	return true;
}

int main(){
  int k;
	unsigned a,b;
	while(true){
		cout<<"vavedi 4islo:";
		cin>>k;
		if(isSumOfTwoPrimes(k,a,b))
			cout<<"yep "<<k<<"="<<a<<"+"<<b<<endl;
		else
			cout<<"nope"<<endl;
	}
	return 0;
}
