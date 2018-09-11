#include <stdio.h>
#include <string.h>

int f[10][10];
int rec[10];
int n,m;

int rec_pair(){
	int i,j,l,ret=0;
	for(i=0;i<n;i++){
		if(!rec[i]){
			l=i;
			break;
		}
	}
	if(i==n)
		return 1;
	for(i=l+1;i<n;i++){
		if(f[l][i]&&!rec[i]){
			rec[l]=1;
			rec[i]=1;
			ret+=rec_pair();
			rec[l]=0;
			rec[i]=0;
		}
	}
	return ret;
}
int main(){
	int T;
	
	int i,j;
	int x,y;
	scanf("%d",&T);

	while(T--){
		memset(f,0,100*sizeof(int));
		memset(rec,0,10*sizeof(int));
		scanf("%d %d",&n,&m);
		for(i=0;i<m;i++){
			scanf("%d %d",&x,&y);
			if(x>y)
				f[y][x]=1;
			else	
				f[x][y]=1;
		}
		printf("%d\n",rec_pair());
	}
}