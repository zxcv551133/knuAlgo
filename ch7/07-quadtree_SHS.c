#include <stdio.h>
#include <string.h>

char str[1001];
char ans[1001];
int cur_index=0;

char *flip(){
	int i,j;
	int start_index=cur_index;
	char strtmp[4][1001]={"","","",""};
	char ret[1001]="x";
	for(i=0;i<4;i++){
		if(str[cur_index]=='x'){
			cur_index++;
			strcat(strtmp[i],flip());
		}else{
			strtmp[i][0]=str[cur_index++];
		}
	}
	for(i=2;i<6;i++){
		strcat(ret,strtmp[i%4]);
	}
	return ret;
}

int main(){
	int i,j;
	int T;
	scanf("%d",&T);
	while(T--){
		memset(str,0,sizeof(str));
		memset(ans,0,sizeof(ans));
		cur_index=0;
		scanf("%s",str);
		if(str[cur_index]=='x'){
			cur_index++;
			strcat(ans,flip());
		}else{
			strcat(ans,str);
		}
		
		puts(ans);
	}
}