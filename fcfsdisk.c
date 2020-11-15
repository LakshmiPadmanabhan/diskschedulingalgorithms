#include<stdio.h>
void main(){
    int i,n,count=0,difference,head,a[100],size;
    //Enter number of requests and head
    printf("Enter number of requests: ");
    scanf("%d",&n);
    printf("Enter head: ");
    scanf("%d",&head);
    printf("Enter disk size: ");
    scanf("%d",&size);
    printf("Enter %d cylinder requests:\n",n);
    //Accept cylinder numbers
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    a[0]=head;
    //compute total seek operations
    for ( i = 0; i <= n; i++)
    {
        difference=abs(a[i]-head);
        count=count+difference;
        head=a[i];
    }
    //display seek sequence
    printf("Seek Sequence :\n");
    for ( i = 0; i <= n; i++)
    {
        printf("%d ",a[i]);
    }
    //display total and average seek operations
    printf("\nTotal: %d",count);
    printf("\nAverage: %f",(float)(count)/n);
}