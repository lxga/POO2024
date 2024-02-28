#include <cstdio>

int atoi2(const char* str){
	int res=0;
	for(int i=0;str[i];i++){
		if(str[i]>='0' && str[i]<='9')
			res=res*10+str[i]-'0';
	}
	if(str[0]=='-')
		res=-res;
	return res;
}

int main(){
	FILE *pfile;
	pfile=fopen("ini.txt","r");
	if(pfile==NULL) return 1;
	int ans=0;
	char str[256];
	while(fscanf(pfile,"%s",str) != EOF){
		ans+=atoi2(str);
	}
	printf("%d",ans);
	fclose(pfile);
	return 0;
}
