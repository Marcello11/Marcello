#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
void change(char *s, int begin, int end)  
{  
    char temp;  
    while(end > begin) {  
        temp = s[begin];  
        s[begin] = s[end];  
        s[end] = temp;  
        begin++;  
        end--;  
    }  
      
}  
void main(){
	FILE *fp1,*fp2;
	char ch='0', a[100];
	int i=0,j=0,b,c;	
	fp1=fopen("change1.txt","rw");
	fp2=fopen("change2.txt","w");
	fseek(fp1,0L,2);
	int length=ftell(fp1);
	fseek(fp1,0L,0);
	//���ļ�����д������ 
	while(ch!=EOF)
	{
		ch=fgetc(fp1);
		//putchar(ch);		
		a[i++]=ch;		
	}
	//printf("%d\n",strlen(a));
	//printf("%d\n",length);
	a[length]='\0';
	//puts(a);
	//printf("%d\n",strlen(a));
	change(a, 0, strlen(a)-1); //�����鵹��
 	//puts(a);
    while(j < strlen(a)) { //����ÿ������ʹ������ 
        //�����ո�   
        while(a[j] == ' ' && j < strlen(a)) {  
            j++;  
        }  
        b = j;
		printf("%d\n",b); //��֤�����Ƿ���ȷ 
		
        //�����ǿո��ַ�   
        while(a[j] != ' ' && j < strlen(a)) {  
            j++;  
        }  
        c = j-1; 
        printf("%d\n",c); //��֤�����Ƿ���ȷ 
        change(a,b,c);  
    }  
    //д�����ļ��� 
	i=0;
	while(ch!='\0'){
		ch=a[i++];
		fputc(ch,fp2);
	}
//	puts(a);
	
	fclose(fp1);	
	fclose(fp2);
}
