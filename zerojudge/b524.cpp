#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int main(){
	char chars[100000];
	while(scanf("%s",chars)!=EOF){
		if(strlen(chars)>=3){
			int front1=0;
			int times=0;
			for(int i = 0; i<strlen(chars);i++){
				if(chars[i]=='y') {
					times+= abs(front1-i);
					front1+=3;
				}
			}
			printf("%d\n",times);
		}
	}
	return 0;
}
