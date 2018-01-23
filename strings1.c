//my very first tutorial C program.
/*
*****
****
*/

#include<stdio.h>
#include<string.h>
#include<malloc.h>
//#include<limits.h>

//helping functions to be defined before calls in the main function( described after main()):
char* initialise_string(char* d);
void print_sizes();
int length(char a[]);
void print_tokens(char* a, const char* delim);

void print_string(char* a){
	
	printf(">>%s\n",a);
}

//user input
char* user_input(){
	char* s;
	scanf("%s",s);
	return s;
}
char* user_input_read(){
	int MAX=100;
	char *s,temp[1];
	s=(char*)malloc(MAX*sizeof(char));
	int i;
	for(i=0;i < MAX ;i++) {
		if(read(0,temp,1))
		{
			if(temp[0]=='\n' /* can check for any delimeter */)
			{
				break;
			}
			else
			{
				s[i]=temp[0];
				i++;
			}
		}
		else{
			break;
		}

	}
	
		    

	return s;

}


//sizes of the primitive types
void print_sizes(){
//lets print sizes, as a bonus of this tutorial!
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
	get_span("01231414","123");// outputs 0
	get_span("1231414","123");// outputs 4
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
{	/*
	char string[5];
	string[0]='d';
	string[1]='o';
	string[2]='n';
	string[3]='e';
	string[4]=0; //needs explanation
	char str[5]={'d','o','n','e','\0'};//another way to do it
	char string[5]="done"; // yet another way 
	char string[]="done"; // yet yet another way 
	char *string = "done"; //since arrays and pointers are (almost) the same thing in C. 
	//yet another crazy way to do that
	const char *string = (char*)malloc( 5 * (sizeof(char)));
	*string = 'd';
	*(string+1)='o';
	*(string+2)='n';
	*(string+3)='e';
	*(string+4)='\0';
	*/
	//for the sake of chosing the easiest way to initialize.
	char *str=value;
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
