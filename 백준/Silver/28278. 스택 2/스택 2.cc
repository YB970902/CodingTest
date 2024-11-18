#include<stdio.h>
using namespace std;

int stack[1000000] = {0};

int main()
{
    int N;
    scanf("%d", &N);
    int C;
    int size = 0;
    int val;
    for(int i = 0; i < N; ++i)
    {
        scanf("%d", &C);
        switch(C)
        {
            case 1:
                scanf("%d", &val);
                stack[size++] = val;
                break;
            case 2:
                if(size == 0) printf("-1\n");
                else printf("%d\n", stack[--size]);
                break;
            case 3:
                printf("%d\n", size);
                break;
            case 4:
                printf("%d\n", (size == 0 ? 1 : 0));
                break;
            case 5:
                if(size == 0) printf("-1\n");
                else printf("%d\n", stack[size - 1]);
                break;
        }
    }
}
