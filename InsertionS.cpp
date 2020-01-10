#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))
#define MAX 999
// 배열을 화면에 보기 좋게 출력하는 함수. 디폴트 매개변수 사용
static void printArray( int arr[], int n, char *str="Array" )
{
    printf("%s = ", str);
    for( int i=0 ; i<n ; i++ )
       printf("%3d", arr[i]);
    printf("\n");
}

int ascend (int x, int y) { return y - x; }
int descend(int x, int y) { return x - y; }

void insertion_sort_fn (int list[], int n, int (*f)(int,int))
{
	int i, j, key;
	for(i=1; i<n; i++){
		key = list[i];
		for(j=i-1 ; j>=0 && f(list[j],key) < 0 ;j--)
			list[j+1] = list[j];
			list[j+1] = key;
	}
}

void main() {
	int k, n;
	int list[MAX];

	scanf("%d", &n);
	if(n<1 || n>100000) {
		printf("다시 입력해주세요");
		scanf("%d", &n);
	}

	for(int i = 0; i < n; i++) {
		scanf("%d ",&list[i]);
		if(list[i]<-10000 || list[i]>10000) {
			printf("다시 입력해주세요");
			scanf("%d", &list[i]);
		}
	}

	scanf("%d", &k);
	if(k<1 || k>100000) {
		printf("다시 입력해주세요");
		scanf("%d", &k);
	}
	for (int i = 0; i < k; i++) {
        int asc, desc;
        scanf("%d %d", &asc, &desc);
		insertion_sort_fn( list, asc, ascend );
		insertion_sort_fn( list, desc, descend );
    }
	printArray( list, n, "Sorted Data  " );
	system("pause");
}