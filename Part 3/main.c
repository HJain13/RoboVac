#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>
#include "functions.c"

char* sstr(char* s, int a, int b){
	int i;
	for (i=a;i<=b;i++){
		t[i-a] = s[i];
	}
	if (b-a!=15) t[b-a+1] = '\0';
	return t;
}

void printStatus(){
	int i;
	printf("| %d | %d | %d ",z,n,o);
	 if (cc<10) printf("|  %d ",cc);
	 else printf("| %d ",cc);
	 if (ic<10) printf("|  %d ",ic);
	 else printf("| %d ",ic);
	 if (sp<10) printf("|  %d ",sp);
	 else printf("| %d ",sp);
	 if (chg<10) printf("|   %d |",chg);
	 else printf("|  %d |",chg);
	for(i=0;i<=11;i++)
	{
		printf("% d",r[i]);
	}
	printf(" ");
}

int cBD(char n[]) {
	int decimalNumber = 0, i = 0, remainder,len;
	int result=0;
	len = strlen(n);
	for(i=0; i<len; i++){
		result = result * 10 + ( n[i] - '0' );
	}
	i=0;
	while (result!=0) {
		remainder = result%10;
		result /= 10;
		decimalNumber += remainder*pow(2,i);
		++i;
	}
	return decimalNumber;
}

int* a2rop(char* a,int p, int q){
	char b[6];
	int n;
	strcpy(b , sstr(a,p,q));
	b[5]='\0';
	n= cBD(b);
	if (n<=11){
		printf(" R%d",n);		
		return &r[n];
	}
	else if (n==12){
		printf(" IC");		
		return &ic;
	}
	else if (n==13){
		printf(" CHG");				
		return &chg;
	}
	else if (n==14){
		printf(" SP");			
		return &sp;
	}
	else if (n==15){
		printf(" CC");			
		return &cc;
	}
	else {
		printf("\n~~~~Error~~~~~ [%d]\n",n);
	}
}

int* a2vop(char* a,int p, int q){
	char b[6];
	strcpy(b , sstr(a,p,q));
	b[5]='\0';
	bnum= cBD(b);
	if (bnum<=31){
		printf(" %d",bnum);		
		return &bnum;
	}
	else {
		printf("\n~~~~Error~~~~~ [%d]\n",n);
	}
}

void runf(char* s, char* a){
	int *x,*y,*z;	
	if(strcmp(s,"ADD")==0){
		x = a2rop(a,6,10);
		y = a2rop(a,11,15);
		*x = ADD(*x,*y);
		printf(" \t \t");							
	}
	else if(strcmp(s,"SUB")==0){
		x = a2rop(a,6,10);
		y = a2rop(a,11,15);
		*x = SUB(*x,*y);
		printf(" \t \t");			
	}
	else if(strcmp(s,"MUL")==0){
		x = a2rop(a,6,10);
		y = a2vop(a,11,15);
		*x = MUL(*x,*y);
		printf(" \t \t");			
	}
	else if(strcmp(s,"DIV")==0){
		x = a2rop(a,6,10);
		y = a2rop(a,11,15);
		*x = DIV(*x,*y);
		printf(" \t \t");			
	}
	else if(strcmp(s,"CMP")==0){
		x = a2rop(a,6,10);
		y = a2vop(a,11,15);
		CMP(*x,*y);
		printf(" \t \t");								
	}
	else if(strcmp(s,"MOV")==0){
		x = a2rop(a,6,10);
		y = a2rop(a,11,15);
		printf("\t\t");
		//cmp(x,y);
	}
	else if(strcmp(s,"CLN")==0){
		x = a2vop(a,6,10);
		y = a2vop(a,11,15);
		printf(" \t \t");
		//cmp(x,y);
	}
	else if(strcmp(s,"DIMD")==0){
		y = a2rop(a,11,15);
		*y = DIMD();
		printf(" \t \t");								
	}
	else if(strcmp(s,"GETD")==0){
		y = a2rop(a,11,15);
		*y = GETD();
		printf(" \t \t");									
	}
	else if(strcmp(s,"SETP")==0){
		y = a2vop(a,11,15);
		sp = SETP(*y);
		printf(" \t \t");									
	}
	else if(strcmp(s,"SFC")==0){
		printf(" \t \t");									
	}
	else if(strcmp(s,"ODET")==0){
		y = a2rop(a,11,15);
		*y = ODET(*y);
		printf(" \t \t");									
	}
	else if(strcmp(s,"DIMD")==0){
		y = a2rop(a,11,15);
		printf(" \t \t");									
	}
	else if(strcmp(s,"MOVU")==0){
		MOVU();
		printf(" \t \t");									
	}
	else if(strcmp(s,"MOVD")==0){
		MOVD();
		printf(" \t \t");									
	}
	else if(strcmp(s,"MOVR")==0){
		MOVR();
		printf(" \t \t");									
	}
	else if(strcmp(s,"SUP")==0){
		x  = a2rop(a,6,10);
		y = a2vop(a,11,15);
		*x = SUP(*x,*y);
		printf(" \t \t");									
	}
	else if(strcmp(s,"HLT")==0){
		HLT();
	}
	else if(strcmp(s,"CGL")==0){
		y = a2rop(a,11,15);
		*y = CGL();
		printf(" \t \t");
	}
	else if(strcmp(s,"SLG")==0){
		SLG();
		printf(" \t \t");
	}
	else if(strcmp(s,"CLT")==0){
		y = a2rop(a,11,15);
		*y = CLT(*y);
		printf(" \t \t");
	}	
	else if(strcmp(s,"TYM")==0){
		x = a2rop(a,6,10);
		y = a2vop(a,11,15);
		*x = TYM(*x);
		printf(" \t \t");
	}
	else if(strcmp(s,"GST")==0){
		y = a2rop(a,11,15);
		*y = GST(*y);
		printf(" \t \t");
	}
	else if(strcmp(s,"GCC")==0){
		y = a2rop(a,11,15);
		*y = GCC(*y);
		printf(" \t \t");
	}
	else if(strcmp(s,"RTM")==0){
		RTM();
		printf(" \t \t");
	}				
	printStatus();
}


int main() {
	char bic[17],a[17],opc[5],b[17],temp;
	FILE *bcode,*jump,*add1,*add2,*add0;
	int lcnt = 0,jflag,jpt,choice;
	add0 = fopen("0add.txt","r");
	add1 = fopen("1add.txt","r");
	add2 = fopen("2add.txt","r");
	char xa[20];
// Choice Menu
   while (choice!=9) {
      printf("\n +----------------------+\n");
      printf(" |  ROBOVAC FUNCTIONS   |\n");
      printf(" |         MENU         |\n");
      printf(" +----------------------+\n");
      printf(" | 0: Custom Function   |\n");
      printf(" | 1: Scheduling        |\n");
      printf(" | 2: Dust Detection    |\n");
      printf(" | 3: Surface Boost     |\n");
      printf(" | 4: Self Cleaning     |\n");
      printf(" | 5: Navigation        |\n");
      printf(" | 6: Charging          |\n");
      printf(" | 7: Virtual Guard     |\n");
      printf(" | 8: App Updates       |\n");
      printf(" | 9: Mapping           |\n");	  
      printf(" | 10: Exit             |\n");
      printf(" +----------------------+\n\n");
      printf(" Enter Choice: ");
      scanf("%d",&choice);

      if (choice == 0) {
      	bcode = fopen("bcode.txt", "r");
      	jump = fopen("bcode.txt", "r");
		strcpy(xa,"Custom Function");
      }
	  else if (choice == 1) {
      	bcode = fopen("bcodesc.txt", "r"); 
      	jump = fopen("bcodesc.txt", "r");
		strcpy(xa,"Scheduling");
	  }	  
      else if (choice == 2) {
      	bcode = fopen("bcodedd.txt", "r");
      	jump = fopen("bcodedd.txt", "r");
		strcpy(xa,"Dust Detection");
	  }
      else if (choice == 3) {
      	bcode = fopen("bcodesb.txt", "r");
      	jump = fopen("bcodesb.txt", "r");
		strcpy(xa,"Surface Boost");
      }
      else if (choice == 4) {
      	bcode = fopen("bcodesec.txt", "r");
      	jump = fopen("bcodesec.txt", "r");
		strcpy(xa,"Self Cleaning");
      }
      else if (choice == 5) {
      	bcode = fopen("bcodena.txt", "r");
      	jump = fopen("bcodena.txt", "r");
		strcpy(xa,"Navigation");
      }
      else if (choice == 6) {
      	bcode = fopen("bcodech.txt", "r");
      	jump = fopen("bcodech.txt", "r");
		strcpy(xa,"Charging");
      }
      else if (choice == 7) {
      	bcode = fopen("bcodevg.txt", "r");
      	jump = fopen("bcodevg.txt", "r");
		strcpy(xa,"Virtual Guard");
      }	  
      else if (choice == 8) {
      	bcode = fopen("bcodeau.txt", "r");
      	jump = fopen("bcodeau.txt", "r");
		strcpy(xa,"App Update");
      }	  
      else if (choice==10) { printf("\n Exiting....\n\n"); exit(0);	}
	  else printf("\n ~~~ Choose from Existing Options ~~~\n");

		if (bcode == NULL){
			printf("Text File does not exist.");
			return 0;
		}

		printf("\n\n\n====================================\n");
		printf("\nExecuting Binary Code of %s through simulation of Robovac",xa);
		printf("\n\n");
		printf("+------------------+--------------------+---+---+---+----+----+----+-----+-----------------------------------+\n");
		printf("| BINARY CODE      | OPCODE  \t\t| Z | N | O | CC | IC | SP | CHG | REGISTERS\n");
		printf("+------------------+--------------------+---+---+---+----+----+----+-----+-----------------------------------+\n");
		int found;
		while (fscanf(bcode, "%s\n",bic) != EOF) {
			bic[16] = '\0';
			lcnt = 0;
			printf("| %s ",bic);
			found = 0;
			b[0] ='\0';
			strcpy(b , sstr(bic,0,5));
			b[7]='\0';

	// Checking for 2 Address Opcodes in Given binary Code
			while (fscanf(add2, "%s\t%s\n",a,opc) != EOF) {
				if (strcmp(a, b) == 0) {
					printf("| %s", opc);
					runf(opc, bic);
					printf(" ");										
					found = 1;
					}
			}
			rewind(add2);

	// Checking for 1 Address Opcodes in Given binary Code
			strcpy(b , sstr(bic,0,10));
			b[11] ='\0';
			while (fscanf(add1, "%s\t%s\n",a,opc) != EOF) {
				lcnt = 0;
				a[11]='\0';
				if(strcmp(a,b)==0){
					printf("| %s",opc);

				// Specific Hard Codes for Jumping Opcodes
					jpt = cBD(sstr(bic,11,15));
					if (strcmp(opc, "JMP") == 0) {														// No ectra conditions required	
						printf(" %d",jpt);
						printf(" \t\t");	
						for (temp = getc(jump); temp!= EOF; temp = getc(jump)){
							if (lcnt >= jpt-1) break;
							if (temp == '\n') {
								lcnt++;
							}
						}
						fseek(bcode,ftell(jump)-1,0);
						printStatus();
					}
					else if (strcmp(opc, "JIG") == 0){
						printf(" %d",jpt);
						printf("\t\t");	
						if (z == false && n == false){													// Conditions
							for (temp = getc(jump); temp!= EOF; temp = getc(jump)){						// For JMP
								if (lcnt >= jpt-1) break;
								if (temp == '\n') {
									lcnt++;
								}
							}
							fseek(bcode,ftell(jump)-1,0);
						}
						printStatus();
					}		
					else if (strcmp(opc, "JIE") == 0){
						printf(" %d",jpt);
						printf("\t\t");	
						if (z == true){																	// Conditions
							for (temp = getc(jump); temp!= EOF; temp = getc(jump)){						// For JIE
								if (lcnt >= jpt-1) break;
								if (temp == '\n') {
									lcnt++;
								}
							}
							fseek(bcode,ftell(jump)-1,0);
						}
						printStatus();
					}		
					else if (strcmp(opc, "JLE") == 0){
						printf(" %d",jpt);
						printf("\t\t");	
						if (z == true || n == true){																				// Conditions
							for (temp = getc(jump); temp!= EOF; temp = getc(jump)){							//For JLE
								if (lcnt >= jpt-1) break;
								if (temp == '\n') {
									lcnt++;
								}
							}
						fseek(bcode,ftell(jump)-1,0);
						}
						printStatus();
					}				
					else {
						runf(opc, bic);
						printf("\t\t");	
					}
					rewind(jump);				
					found = 1;
				}
			}
			rewind(add1);

	// Checking for 0 Address Opcodes in Given binary Code
			strcpy(b , sstr(bic,0,15));
			b[16]='\0';
			while (fscanf(add0, "%s %s\n", a, opc) != EOF) {
				if(strcmp(a,b)==0){
				printf("| %s",opc);
				runf(opc, bic);		
				printf(" \t\t\t ");	
				found = 1;
				}
			}	
			rewind(add0);
			printf("\n");
		}
		fclose(bcode);
		fclose(add0);
		fclose(add1);
		fclose(add2);
   }
	return 0;
}