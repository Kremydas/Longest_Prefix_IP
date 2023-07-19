#include<stdio.h>    
#include<stdlib.h>  
#include <ctype.h>
#include <string.h>

typedef char* treeItem;

typedef struct treenode *treelink;

struct treenode{
	
	int EndNode;	
	treeItem data;
	treelink left, right;
	
};

treelink createleaf();
int * convert(int a);	




    int main(){

	 FILE *file;
	 char buff[1000];
	 char delim[]=".";
	 char *a,*b,*c,*d,*sub,prefix[32],str[20],ipaddr[32];
	 int A,B,C,D,s,*arr1,*arr2,*arr3,*arr4,*array,i=0,index=0,j=0,num1,num2,num3,num4,pre,*ar1,*ar2,*ar3,*ar4,index2=0,k=0,*ip,q=0;
	 char *filename;
    
    
    printf("Please enter the name of the file you wish to read from:\n");
    

	filename=(char*)malloc(sizeof(char));
	scanf("%s",filename);
	
	treelink root;
	root = createleaf();


	if (!(file=fopen(filename,"r")))
         {   
		printf("Error opening file: %s",filename);
		return 0;      
	   }

	while(fscanf(file,"%s",buff)!= EOF){

	a=(char*)malloc(sizeof(char));
	b=(char*)malloc(sizeof(char));
	c=(char*)malloc(sizeof(char));
	d=(char*)malloc(sizeof(char));
	sub=(char*)malloc(sizeof(char));


	a  = strtok(buff,delim);
	A=atoi(a);
	printf("%d.",A);

	b  = strtok(NULL,delim);
	B=atoi(b);
	printf("%d.",B);

	c  = strtok(NULL,delim);
	C=atoi(c);
	printf("%d.",C);
	
	d = strtok(NULL,"/");
	D=atoi(d);
	printf("%d/",D);

	sub = strtok(NULL,"\n");
	s=atoi(sub);
	printf("%d",s);
	
	arr1=(int*)malloc(8*sizeof(int));
	arr2=(int*)malloc(8*sizeof(int));
	arr3=(int*)malloc(8*sizeof(int));
	arr4=(int*)malloc(8*sizeof(int));
	array=(int*)malloc(32*sizeof(int));


	
	printf("\n");

	arr1=convert(A);
	arr2=convert(B);
	arr3=convert(C);
	arr4=convert(D);

	for(i=7 ; i>=0 ; i--){
	  array[index]=arr1[i];
	  index++;
	}

	for(i=7 ; i>=0 ; i--){
	  array[index]=arr2[i];
	  index++;
	}

	for(i=7 ; i>=0 ; i--){
	  array[index]=arr3[i];
	  index++;
	}

	for(i=7 ; i>=0 ; i--){
	  array[index]=arr4[i];
	  index++;
	}

	for(i=0 ; i<32 ; i++)
		printf("%d",array[i]);

	printf("\n");

	index=0;
	

	treelink tmproot = root;

	while(j<=s-1){			


	if(array[j] == 0) {

	  if(tmproot->left == NULL){

		tmproot->left = createleaf();

	     }

		tmproot = tmproot->left;

	  }

	else if(array[j]==1) {

		if(tmproot->right == NULL){

		   tmproot->right = createleaf();
		  
		           }

		tmproot = tmproot->right;

		}

	     if(j==s-1){
	
	       for(i=0 ; i<s ; i++){
		  tmproot->data[i]=array[i];
	         }
		
	   	tmproot->EndNode=5;


	   }
	    
		   
	     j++;

		
	    }
	j=0;
	
	}

	fclose(file);
	do{
	printf("Give Ip Address\n");		
	scanf("%d%d%d%d",&num1,&num2,&num3,&num4);


	ar1=(int*)malloc(8*sizeof(int));
	ar2=(int*)malloc(8*sizeof(int));
	ar3=(int*)malloc(8*sizeof(int));
	ar4=(int*)malloc(8*sizeof(int));
	ip=(int*)malloc(32*sizeof(int));


	ar1=convert(num1);
	ar2=convert(num2);
	ar3=convert(num3);
	ar4=convert(num4);



	for(i=7 ; i>=0 ; i--){
	  ip[index2]=ar1[i];
	  index2++;
	}

	for(i=7 ; i>=0 ; i--){
	  ip[index2]=ar2[i];
	  index2++;
	}

	for(i=7 ; i>=0 ; i--){
	  ip[index2]=ar3[i];
	  index2++;
	}

	for(i=7 ; i>=0 ; i--){
	  ip[index2]=ar4[i];
	  index2++;
	}	


	for(i=0 ; i<32 ;i++)
		printf("%d",ip[i]);

	printf("\n");

	
	treelink temproot=root;

	treelink found;
	found=(treelink)malloc(sizeof*found);

	while(temproot->left!=NULL || temproot->right!=NULL){   	

	if(ip[k] == 0) {

		temproot = temproot->left;

	  }

	else if(ip[k]==1) {

		temproot=temproot->right;

	     }

		if(temproot->EndNode==5){
			printf("Found Prefix!\n");
			found=temproot;
			}

		k++;

	

	}

	i=0;
	while(found->data[i]!=-1){
		printf("%d",found->data[i]);
		i++;
	}
	
	

	printf("\n");

	}while(num1!=0);

	return 0;

 }
	   
	int * convert(int n){

	  int *a;
	  int i=0;
	
	  a=(int*)malloc(8*sizeof(int));
     
	for(i=0 ; i<8 ; i++)
		a[i]=0;
       
       	  for(i=0;n>0;i++)    
         {    
           a[i]=n%2;    
           n=n/2;    	
         }    

	return a;

	}



	treelink createleaf(){
	
	treelink tmproot = (treelink)malloc(sizeof *tmproot);

	tmproot->data=(char*)malloc(32*sizeof(char));
							
	tmproot->left = NULL;
					
	tmproot->right = NULL;	
}

    
    

   


