#include<stdio.h>
#include<string.h>



struct work{
    char name[10];      //��ҵ��
    int start;      //����ʱ��
    int need;       //����ʱ��
    int runtime;        //��תʱ��
    int end;        //����ʱ��
    double dq;    //��Ȩ��תʱ��
 
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

   works[0].end=works[0].start+works[0].need;//����ʱ��+����ʱ��=����ʱ��
   works[0].runtime=works[0].need;//��תʱ��=����ʱ��
   works[0].dq=works[0].runtime*1.0/works[0].need;//��תʱ��/����ʱ��=��Ȩ��תʱ��


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
    printf("��ҵ��\t����ʱ��\t����ʱ��\t���ʱ��\t��תʱ��  ��Ȩ��תʱ��\n");
    for(i=0;i<n;i++)
    {
    printf("%s\t      %d\t        %d\t        %d\t        %d             %.2f\n",works[i].name,works[i].start,works[i].need,works[i].end,works[i].runtime,works[i].dq);
    
    sum_runtime=sum_runtime+works[i].runtime;
    sum_dq=sum_dq+works[i].dq;
    }
    avr_run=sum_runtime*1.0/n;
    avr_dq=sum_dq*1.000/n;
    printf("ƽ����תʱ��:%.2f \n",avr_run);
    printf("ƽ����Ȩ��תʱ��:%.3f \n",avr_dq);
    printf("\n");
}

void main()
{
    struct work works[50];
    int n,i; //��ҵ���� 

    printf("������ҵ����:");
    scanf("%d",&n);
    printf("����ÿ����ҵ����ҵ��,����ʱ��,����ʱ��:\n");
    for(i=0;i<n;i++)
    {
        scanf("%s",works[i].name); //��ҵ��
        scanf("%d",&works[i].start);//����ʱ��
        scanf("%d",&works[i].need);//����ʱ��
    }
    printf("\n");
    printf("��ҵ��\t����ϵͳʱ��\t����ʱ��\n");
    for(i=0;i<n;i++)
    {
    printf("%s\t       %d\t          %d\n",works[i].name,works[i].start,works[i].need);
    }

    sjf(works,n);
    printf("SJF�㷨���н����\n");
    result(works,n);

}
