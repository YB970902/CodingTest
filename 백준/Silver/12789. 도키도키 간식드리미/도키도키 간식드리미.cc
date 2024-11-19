#include<stdio.h>
using namespace std;

int stackA[1000000] = {0};
int stackB[1000000] = {0};
int startA = 0;
int sizeA = 0;
int sizeB = 0;

int main()
{
    int N;
    
    scanf("%d", &N);
    
    int temp;
    for(int i = 0; i < N; ++i)
    {
        scanf("%d", &stackA[sizeA++]);
    }
    
    int currNum = 1;
    
    while(sizeA > 0 || sizeB > 0)
    {
        if(sizeA > 0 && stackA[startA] == currNum)
        {
            --sizeA;
            ++startA;
            ++currNum;
        }
        else if(sizeB > 0 && stackB[sizeB - 1] == currNum)
        {
            --sizeB;
            ++currNum;
        }
        else
        {
            if(sizeA == 0)
            {
                printf("Sad\n");
                return 0;
            }
            stackB[sizeB++] = stackA[startA];
            --sizeA;
            ++startA;
        }
    }
    
    printf("Nice\n");
}
