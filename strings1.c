//my very first tutorial C program.
/*
*****
cc main.c getline.c strindex.c
compiles the three files, placing the resulting object code in files main.o , getline.o , and
strindex.o , then loads them all into an executable file called a.out . If there is an error, say
in main.c , the file can be recompiled by itself and the result loaded with the previous object
files, with the command
cc main.c getline.o strindex.o
The cc command uses the `` .c '' versus `` .o ''
naming convention to distinguish source files
from object files.
****
*/

#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<limits.h>

//helping functions to be defined before calls in the main function( described after main()):
char* initialise_string(char* d);
void print_sizes();
int length(char a[]);
void print_tokens(char* a, const char* delim);

void print_string(char* a){
	
	printf(">>%s\n",a);
}

//sizes of the primitive types
void print_sizes(){
//int size_of_int=sizeof(int l); cant do this in c
	int size_of_char=sizeof(char);
	int size_of_long=sizeof(long);
	long long s;
	int size_of_long_long=sizeof(s);
	int size_of_float=sizeof(float);
	int size_of_double=sizeof(double);
	int size_of_int=sizeof(int);
	int size_of_void=sizeof(void);
	printf("size of char on this architecture: %d bytes\n",size_of_char);
	printf("size of int on this architecture: %d bytes\n",size_of_int);
	printf("size of long on this architecture: %d bytes\n",size_of_long);
	printf("size of long long on this architecture: %d bytes\n",size_of_long_long);
	printf("size of float on this architecture: %d bytes\n",size_of_float);
	printf("size of double on this architecture: %d bytes\n",size_of_double);
	printf("size of void on this architecture: %d bytes\n",size_of_void);
}

//main function
int main(){
	print_sizes();
	

	char string[]="my name";
	const char* spac=" ";

	char str[]="your name is something";
	//or this can also work with some warnings off course:
	//char str[length("your name is something")]="your name is something";


	//the following line gives segmentation fault when used with strtok
	//char* str="your name is something";
	print_tokens(str,spac);
	//char* d=strtok(str,spac);
	//print_string(d);


	length(string);
	length(str);
	//it will seem that any size of target works but its actually adveturing on some other variable's memory and leaving its own space
	//char target[0];
	//or this will also do fine:
	char *target=(char*)malloc(sizeof(char)*length(str)); 
	strcpy(target,str);
	print_string(target);
	free(target);
	/*
	str=(char*)malloc(100000000000);
	if(!str) printf("not possible");
	free(str);
	*/
	char k[]="hello and buy";
	//if_contains custom function checks for the substring
	int a=if_contains(k,spac);
	print_tokens(k,spac);
	printf("contians: %d",a);
	get_span("01231414","123");
	return 0;
}

//gets the span of characters from b in a (only initial part of the string is considered!).
//strspan():
int get_span(char* a,char* b){
	int j=strspn(a,b);
	printf("span: %d",j);
	return j;
}

//initialise a string
char* initialise_string(char* value)
{
	char *str=value;

	/*other ways to initialise:
	char string[]="my name";
	const char* spac=" ";

	char str[]="your name is something";
	*/
	
	return str;
}
	


//strstr():finding a string needle in a text haystack!!
//uses a naive algorithms, better algorithms are Boyer–Moore,Horspool's algorithm(a simplification of boyer-moore's),kmp, etc.
int if_contains(const char* src,const char* pattern)
{
	char* position=strstr(src,pattern);
	if(position==NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}


}



//strtok():tokens printing seperated by a delimeter(similar to the split() method from java!)
void print_tokens(char* a,const char* delim){
	char *j;
	j=strtok(a,delim);
	//print_string(j);
	while(j!=NULL)
	{
		if(j[0]!=0)
		print_string(j);
		j=strtok(NULL,delim);
	}
	//optionally can return an array of words as character arrays!

}

//length of the string
//same as strlen()
int length(char a[]){
	char k=a[0];
	int i=0;
	//print_string(a);
	while(k!='\0'){
	//	printf("character: %c, value: %d \n",k,k);
		i++;
		k=a[i];
		
	}
	//printf("ends here: '%d' \n",k);
	//printf("length: '%d' \n",i+1);


	//i+1 for the null character('\0') inclusion.
	return i+1;
}


