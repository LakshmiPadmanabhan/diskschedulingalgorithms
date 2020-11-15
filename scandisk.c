#include<stdio.h>
#include<string.h>
//function for left scan
void scanleft(int a[100],int n,int loc){
    int i,c=0,difference,f;
    //compute total seek operations
    for(i=loc;i>0;i--)
    {
        difference=abs(a[i]-a[i-1]);
        c=c+difference;
    }
    f=i;
    for(i=loc+1;i<=n;i++){
        difference=abs(a[i]-a[f]);
        c=c+difference;
        f=i;
    }
    // diaplay seek sequence, total and average seek operations
    printf("Seek Sequence:\n");
    for(i=loc-1;i>=0;i--){
        printf("%d ",a[i]);
    }
    for(i=loc+1;i<=n;i++){
        printf("%d ",a[i]);
    }
    printf("\nTotal: %d",c);
    printf("\nAverage: %f",(float)c/n);
}
//function for right scan
void scanright(int a[100],int n,int loc){
    int i,c=0,difference,f;
    //compute total seek operations
    for(i=loc;i<n;i++)
    {
        difference=abs(a[i+1]-a[i]);
        c=c+difference;
    }
    f=i;
     for(i=loc-1;i>=0;i--){
        difference=abs(a[i]-a[f]);
        c=c+difference;
        f=i;
    }
    // diaplay seek sequence, total and average seek operations
    printf("Seek Sequence:\n");
    for(i=loc+1;i<=n;i++){
        printf("%d ",a[i]);
    }
    for(i=loc-1;i>=0;i--){
        printf("%d ",a[i]);
    }
    printf("\nTotal: %d",c);
    printf("\nAverage: %f",(float)c/n);
}
void main(){
    int i,j,n,t,loc,count,head,a[100],size;
    char direction[5];
    //Enter number of requests and head
    printf("Enter number of requests: ");
    scanf("%d",&n);
    printf("Enter head: ");
    scanf("%d",&head);
    printf("Enter direction: ");
    scanf("%s",direction);
    printf("Enter disk size: ");
    scanf("%d",&size);
    printf("Enter %d cylinder requests:\n",n);
    //Accept cylinder numbers
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    a[0]=head;
    //sort seek sequence
    for(i=0;i<n;i++){
        for ( j = 0; j<n-i; j++)
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
    // call function to scan right or left based on direction specified by user
    if(strcmp(direction,"right")==0){
        scanright(a,n,loc);
    }
    else
    {
        scanleft(a,n,loc);
    }
    
}