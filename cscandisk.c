#include<stdio.h>
//function to scan
void scan(int a[20],int n,int loc){
    int c=0,i,f,difference;
    //compute total seek timr
    for(i=loc;i<n;i++){
        difference=abs(a[i+1]-a[i]);
        c=c+difference;
    }
    f=i;
    for(i=0;i<loc;i++){
        difference=abs(a[f]-a[i]);
        c=c+difference;
        f=i;
    }
    //display seek sequence,total and average seek time
    printf("Seek Sequence:\n");
    for(i=loc+1;i<=n;i++){
        printf("%d ",a[i]);
    }
    for(i=0;i<loc;i++){
        printf("%d ",a[i]);
    }
    printf("\nTotal seek time: %d\n",c);
    printf("Average seek time: %f\n",(float)c/n);
}
void main(){
    int i,j,n,t,loc,count,head,a[100],size;
    //Enter number of requests and head
    printf("Enter number of requests: ");
    scanf("%d",&n);
    printf("Enter head: ");
    scanf("%d",&head);
    printf("Enter disk size: ");
    scanf("%d",&size);
    printf("Enter %d cylinder numbers:\n",n);
    //Accept cylinder numbers
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    a[0]=head;
    //sort seek sequence
    for(i=0;i<n;i++){
        for ( j = 0; j<n-1-i; j++)
        {
            if(a[j]>a[j+1]){
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    //find location of head
    for(i=0;i<n;i++){
        if(a[i]==head){
            loc=i;
            break;
        }
    }
    // call function to scan
    scan(a,n,loc);
}