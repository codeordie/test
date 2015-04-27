#include<iostream>
#include<cstdlib>
#include<iomanip>

using namespace std; /* sexualy transmited desease */

inline void die(char*e){
	cout<<e<<endl;
	exit(1);
}

class mat{
 private:
	int w,h;
	int**a;
 public:

	mat(int w,int h):w(w),h(h){
		a=new int*[h];
		for(int i=0;i<h;i++)
			a[i]=new int[w];
	}

	~mat(){
		delete[]a;
	}

	void fill(){
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				a[i][j]=rand()%100;
	}

	void init(){
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				a[i][j]=0;
	}

	void print(){
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++)
					cout<<setw(8)<<a[i][j];
			cout<<endl;
		}
		cout<<endl;
	}

	void input(){
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++){
				cout<<"pls enter value for row "<<i<<" column "<<j<<":";
				cin>>a[i][j];
			}
	}

	int getElement(int m,int n){
		return a[m][n];
	}

	void setElement(int m,int n,int value){
		a[m][n]=value;
	}

	int getWidth(){
		return w;
	}

	int getHeight(){
		return h;
	}

	mat*clone(){
		return new mat(*this);
	}

	mat*transpose(){
		mat*tt=new mat(h,w);
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				tt->setElement(j,i,a[i][j]);
		return tt;
	}

	void shiftDown(){
		a[w]=a[0];
		for(int i=0;i<w-1;i++)
			a[i]++;
	}

  mat*mult(mat*b){
      if(h!=b->w)die("Illegal matrix dimensions");
      mat*c=new mat(w,b->h);
      for(int i=0;i<w;i++)
          for(int j=0;j< c->h;j++)
              for(int k=0;k<h;k++)
                  c->a[i][j]+=(a[i][k]*b->a[k][j]);
      return c;
  }

	mat*rmRowCol(int r,int c){
		mat*tt=new mat(w-1,w-1);
		tt->init();
		for(int i=0,k=0;i<w;i++){
			if(i==r)
				continue;
			for(int j=0,l=0;j<w;j++){
				if(j==c)
					continue;
				tt->setElement(k,l,a[i][j]);
				l++;
			}
			k++;
		}
		return tt;
	}

	int det(){
		if(w!=h)
			die("determinant of nonsquare matrix");
		if(w==1)
			return a[0][0];
		if(w==2)
			return a[0][0]*a[1][1]-a[0][1]*a[1][0];
		if(w==3)
		  return a[0][0]*a[1][1]*a[2][2]+a[0][1]*a[1][2]*a[2][0]+a[0][2]*a[1][0]*a[2][1]-a[0][0]*a[1][2]*a[2][1]-a[0][1]*a[1][0]*a[2][2]-a[0][2]*a[1][1]*a[2][0];
		else{
			int result=0;
			for(int i=0,sign=1;i<w;i++){
				result+=sign*a[0][i]*rmRowCol(0,i)->det();
				sign*=-1;
			}
			return result;
		}
	}

};

int main(int argc, char**argv){
	mat*m=new mat(4,4);
	m->input();
	m->print();
	cout<<"determinantata e "<<m->det();
	return 0;
}
