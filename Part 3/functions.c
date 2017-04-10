#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

bool z = false,n = false,o = false;
char t[16];
int r[12] = {0}, obj[26] = {0}, ic = 15,cc = 1,sp = 0,chg = 1,Mcheck, bnum ;

void resetf(){
	z = false;
}

int MOV(int x, int y){
	x = y;
	return x;
}

void CMP(int x, int y){
    if ((x - y) == 0) {
        z = true;
        n = false;
    } else if ((x - y) < 0) {
    n = true;
    z = false;
    o = false;
    }
	else {
		n = false;
		z = false;
	}
}

int ADD(int x,int y) {
	x=x+y;
	if(x==0)
		z = false;
	if (x>31)
		o = true;
		n = false;
	return x;
}

int SUB(int x ,int y){
	x=(x-y);
	if(x<0) 
		n = true;
	if(x==0)
		z = true;
    	o = false;
	return x;		
}

int DIV(int x,int y){
	if(y==0)
		printf("BAD INSTRUCTION!");
	if(x==0);
		z = true;
    o = false;
	x = x / y;
	return x;
}

int MUL(int x,int y){
	x=x*y;
	if(x==0)
		z = true;
	if(x<0)
		n = true;
	if(x>31)
		o = true;
	return x;
}

void HLT() {
	int i=0,count=0,j;
	printf("\n\n MAP : \n----------");
	for (i=1; i<26; i++)
	{
	j=i-1;
		if ((j%5) == 0)
		{
			printf("\n|");
		}
		if ((j%5) != 4)
		{
		printf("%d ", obj[i]);
		}
		else printf("%d|", obj[i]);
	}	
	printf("\n----------");
	printf("\n+------------------+--------------------+---+---+---+----+----+----+-----+-----------------------------------+\n");	
	printf("\nProgram Terminated!\n\n\n");
	exit(0);
}

void MOVU()
{
	cc++;
	if ((cc+1)%5 == 1)
	{
		r[10] = 0;
	}
	else
	{
		r[10] = 1;
	}
}

void MOVD()
{
	cc++;
	if ((cc+1)%5 == 1)
	{
		r[10] = 0;
	}
	else
	{
		r[10] = 1;
	}
}

void MOVR()
{
	if (cc >= 25)
	{
		printf("\nCC = %d\n\n", cc);
		r[10] = 1;
	}
	else
	{
		r[10] = 0;
	}
}

void SLG(){
	printf("\n\nApp Update: Log Recieved.");
}

void SFC(){
	printf(" ROBOVAC Working on Self Clean Mode.");
}

int DIMD(){
    int x = 10;
    return x;
}
 
int GETD(){
    int x = 2;
    return x;
}

int SUP(int x, int y){	
   x=y;
   return x;
}

int CLT(int x ){
	x = 10;
    return x;
}

int GST(int x ){
	x = 4;
    return x;
}

int TYM(int x ){
	x =4;
    return x;
}

int CGL(){
	int x = rand()%10 ;
    return x;
}

void RTM(){
    if(Mcheck == 1 )
    cc = cc-1;
    if(Mcheck == 0 )
    cc = cc-5 ;
}

int GCC(int x){
	x = cc;
	return x;
}

int  SETP(int x){
    return (sp + x)%10;
}

int ODET(int x){
    x = rand()%2;
	obj[cc] = rand()%2; 
    return x;
}

void CLN(int x, int y){
    if(y==1)
        printf("Cleaning on progress!"); 
    else
        printf("No need to Clean!");
}