#include <stdio.h>
#include <string.h>

char str[20];
int arr[20][20];
int x,y;

int board[4][2][3]={
	{0,1,1,0,1,0},
	{0,1,1,0,0,1},
	{0,1,0,1,1,0},
	{0,1,0,0,1,1}};
//isVaild : 블럭을 놓을수 있으면 1 아니면 0 리턴
int isVaild(int a,int b,int n){
	int i,j;
	int ret=1;
	
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			if(board[n][i][j]&&(((a+i)>=x)||((b+j-1)<-1)||((b+j-1)>=y))){
				ret=0;
			}
			if(board[n][i][j]&&!(arr[a+i][b+j-1]))
				ret=0;
		}
	}
	return ret;
}

int rec_cover(){
	int i,j,max;
	int a,b,ret=0;
	max=x*y;
	for(i=0;i<max;i++){
		if(arr[i/y][i%y]){
			a=i/y,b=i%y;
			break;
		}
	}
	if(i==max)
		return 1;
	for(i=0;i<4;i++){
		if(isVaild(a,b,i)){
			for(j=0;j<6;j++){
				if(board[i][j/3][j%3])
					arr[a+j/3][b+j%3-1]=0;
			}
			ret+=rec_cover();
			for(j=0;j<6;j++){
				if(board[i][j/3][j%3])
					arr[a+j/3][b+j%3-1]=1;
			}
		}
	}
	return ret;
}

int main(){
	int i,j,c=0;
	int T;
	scanf("%d",&T);
	while(T--){
		memset(arr,0,400*sizeof(int));


		scanf("%d %d",&x,&y);
		for(i=0;i<x;i++){
			scanf("%s",str);
			for(j=0;j<y;j++){
				if(str[j]=='.'){
					arr[i][j]=1;
					c++;
				}else{
					arr[i][j]=0;
				}
			}
		}
		if(!c||c%3)
			printf("0\n");
		else
			printf("%d\n",rec_cover());
	}
}