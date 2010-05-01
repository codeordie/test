#include<iostream>
#include<string>
using namespace std;
char pole[3][3];
char*rr=&pole[0][0];
void draw(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			cout<<pole[i][j];
		cout<<endl;
	}
}
bool wins(char symbol){
	int row,col;
	for(row=0;row<3;row++)
		if(pole[row][0]==symbol&&pole[row][1]==symbol&&pole[row][2]==symbol)
			return true;
	for(col=0;col<3;col++)
		if(pole[0][col]==symbol&&pole[1][col]==symbol&&pole[2][col]==symbol)
			return true;
	if(pole[0][0]==symbol&&pole[1][1]==symbol&&pole[2][2]==symbol)
		return true;
	if(pole[0][2]==symbol&&pole[1][1]==symbol&&pole[2][0]==symbol)
		return true;
	return false;
}
int main(){
	cout<<"TIC TAC TOE\nBy Blagovest Kostov\n#######"<<endl;
	cout<<"use the digits from 1 to 9 to play\n123\n456\n789\n";
	for(int i=0;i<9;i++,*rr++='#');
	string p1,p2;
	bool turn=true;
	int pos,moves=0;
	cout<<"Player one, please enter your name:";
	cin>>p1;
	cout<<"Player two, please enter your name:";
	cin>>p2;
	while(1){
		draw();
		if(wins('x')){cout<<p1<<" wins"<<endl;break;}
		if(wins('o')){cout<<p2<<" wins"<<endl;break;}
		if(moves==9){cout<<"It's a tie"<<endl;break;}
		turn?cout<<p1:cout<<p2;cout<<"'s turn:";
		cin>>pos;
		if(pos>=1&&pos<=9&&pole[(pos-1)/3][(pos-1)%3]=='#'){
			pole[(pos-1)/3][(pos-1)%3]=turn?'x':'o';moves++;
			turn=!turn;
		}else return;
	}
	return 0;
}
