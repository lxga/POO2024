#include <cstdio>
#include <cstring>

void sortwords(int order[],int n){
	
}

int main(){
	int n=0;
	char prop[1001][256];
	int len[1001],order[1001];
	while(scanf(prop[n])!=EOF){
		len[n]=strlen(prop[n]);
		order[n]=n;
		n++;
	}
	
	sortwords(order,n);

	for(int i=0;i<n;i++){
		printf("%s\n",prop[i]);
	}
	return 0;	
}
