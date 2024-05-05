#include<stdio.h>
#include<string.h>



struct work{
    char name[10];      //作业名
    int start;      //到达时间
    int need;       //服务时间
    int runtime;        //周转时间
    int end;        //结束时间
    double dq;    //带权周转时间
 
};

void sjf(struct work works[50],int n)
{
   int i=0,b=0;
   char temp[10];
   int min;            
   for(i=0;i<n-1;i++) 
      {
          if(works[i].start>works[i+1].start)
          {   
              min=works[i].start;
              works[i].start=works[i+1].start;
              works[i+1].start=min;

			  
              min=works[i].need;
              works[i].need=works[i+1].need;
              works[i+1].need=min;

              strcpy(temp,works[i].name);
              strcpy(works[i].name,works[i+1].name);
              strcpy(works[i+1].name,temp);
          }
      }                      

   works[0].end=works[0].start+works[0].need;//到达时间+服务时间=结束时间
   works[0].runtime=works[0].need;//周转时间=服务时间
   works[0].dq=works[0].runtime*1.0/works[0].need;//周转时间/服务时间=带权周转时间


    for(i=1;i<n;i++)
    {
        if(works[i].start>works[0].end) ;  
            else b=b+1;        
    }

    for(i=1;i<=b-1;i++)
    {
        if(works[i].need>works[i+1].need)
        { 
          min=works[i].start;
          works[i].start=works[i+1].start;
          works[i+1].start=min;
                  
          min=works[i].need;
          works[i].need=works[i+1].need;
          works[i+1].need=min;

          strcpy(temp,works[i].name);             
          strcpy(works[i].name,works[i+1].name);
          strcpy(works[i+1].name,temp);
        }                 
    }

    for(i=1;i<n;i++)
    {
      if(works[i].start>works[i-1].end)
      {                                         
        works[i].end=works[i].start+works[i].need; 
        works[i].runtime=works[i].need;
      }
      else
      {
         works[i].end=works[i-1].end+works[i].need;
         works[i].runtime=works[i].end-works[i].start; 
      }
      works[i].dq=works[i].runtime*1.0/works[i].need;
    }
}

void result(struct work works[50],int n)
{
    int i;
    double avr_run;
    double avr_dq;
    int sum_runtime=0;
    double  sum_dq=0.00;
    printf("作业名\t到达时间\t运行时间\t完成时间\t周转时间  带权周转时间\n");
    for(i=0;i<n;i++)
    {
    printf("%s\t      %d\t        %d\t        %d\t        %d             %.2f\n",works[i].name,works[i].start,works[i].need,works[i].end,works[i].runtime,works[i].dq);
    
    sum_runtime=sum_runtime+works[i].runtime;
    sum_dq=sum_dq+works[i].dq;
    }
    avr_run=sum_runtime*1.0/n;
    avr_dq=sum_dq*1.000/n;
    printf("平均周转时间:%.2f \n",avr_run);
    printf("平均带权周转时间:%.3f \n",avr_dq);
    printf("\n");
}

void main()
{
    struct work works[50];
    int n,i; //作业总数 

    printf("输入作业个数:");
    scanf("%d",&n);
    printf("输入每个作业的作业名,到达时间,服务时间:\n");
    for(i=0;i<n;i++)
    {
        scanf("%s",works[i].name); //作业名
        scanf("%d",&works[i].start);//到达时间
        scanf("%d",&works[i].need);//服务时间
    }
    printf("\n");
    printf("作业名\t到达系统时间\t运行时间\n");
    for(i=0;i<n;i++)
    {
    printf("%s\t       %d\t          %d\n",works[i].name,works[i].start,works[i].need);
    }

    sjf(works,n);
    printf("SJF算法运行结果：\n");
    result(works,n);

}
