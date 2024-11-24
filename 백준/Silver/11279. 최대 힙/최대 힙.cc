#include <stdio.h>
int tree[100001],ans[100001],n,i=1,j=1,k,l,c,tem,b,t;

void push(int a){

    tree[i++]=a;
    c=i-1;
    while(c!=1&&tree[c/2]<tree[c])
    {
        if(tree[c/2]<tree[c]&&c>1)
        {
            tem=tree[c/2];
            tree[c/2]=a;
            tree[c]=tem;
            c=c/2;
        }

    }
}

void pop(){
    if(i>1) printf("%d\n",tree[1]);
    else printf("0\n");
    tree[1]=tree[i-1];
    tree[i-1]=0;
    if(i>1)i--;
}

void clean(){
    for(k=1;2*k+1<i+1;)
    {
        if(tree[2*k]>tree[k]&&tree[2*k]>=tree[2*k+1])
        {
            tem=tree[k];
            tree[k]=tree[2*k];
            tree[2*k]=tem;
            k=2*k;

        }
        else if(tree[2*k+1]>tree[k]&&tree[2*k+1]>=tree[2*k])
            {
            tem=tree[k];
            tree[k]=tree[2*k+1];
            tree[2*k+1]=tem;
            k=2*k+1;

            }
        else break;

    }

}


int main()
{
    scanf("%d",&n);
    for(l=1;l<n+1;l++)
    {
        scanf("%d",&b);
        if(b!=0)push(b);
        else
        {
            pop();
            clean();
        }
        /*for(t=1;t<=10;t++)
        {
            printf("%d ",tree[t]);
        }
    puts("");*/
    }

    // for(i=1;i<zero+1;i++)
      //  {
        //    printf("%d\n",ans[i]);
      //  }
   return 0;
}
