#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// a struct to read and write
struct ques
{
	int id;
	char question[1000];
	char option1[50];
	char option2[50];
	char option3[50];
	char option4[50];
    int correctoption;

}qst1;

//a structure for score
struct score{
    char name[100];
    int score;
}scr;


void highest_score();
void show_score();
void add_score(char name[100], int score1);
void add_quesion();
void password();

void help()
{
	printf("\n\n ************************* GAME HELP *************************");
    printf("\n -------------------------------------------------------------------------");
    printf("\n .................... C program Quiz Game...........\n");
    printf("\n >> There will be a total of 10 questions");
    printf("\n >> You will be given 4 options and you have to press 1, 2 ,3 or 4 for the");
    printf("\n    right option");
    printf("\n >> Each question will carry 1 points");
    printf("\n >> You will be asked questions continuously.");
	printf("\n >> There is no negative marking for wrong answer");
    printf("\n >> Only authorized user get acces to add question\n");

}
int main()
{
    FILE*p;
    char name[50];
    int a1,i;
    int score=0;
    int choose;


     printf("\n\t\t****************************************");
     printf("\n\t\t\t   WELCOME TO QUIZ GAME");
     printf("\n\t\t****************************************");
     printf("\n\t\t***********************************************");
     printf("\n\t\t   HIMALYAN WHITE HOUSE INTERNATIONAL COLLEGE") ;
     printf("\n\t\t***********************************************");
     printf("\n\t\t****************************************");
     printf("\n\t\t Enter 1 to start the game");
     printf("\n\t\t Enter 2 to view the highest score  ");
     printf("\n\t\t Enter 3 to Add Question");
     printf("\n\t\t Enter 4 for Help            ");
     printf("\n\t\t Enter 5 to Quit             ");
     printf("\n\t\t****************************************\n\n");
     scanf("%d",&choose);
     fflush(stdin);
     system("cls");
     if(choose==5)
     {
    	exit(1);
     }
     else if(choose==2)
     {
         highest_score();
     }
    else if(choose==3)
     {
        password();
     }
    else if(choose==4)
     {
        help();
     }
    else if(choose==1)
     {
    printf("Enter your name:\n");
	scanf("%[^\n]s",name);
    fflush(stdin);

	FILE *infile;
	// open file for writing
	infile = fopen ("question.txt", "r");
	if (infile == NULL)
	{
		fprintf(stderr, "\nError opened file\n");
		exit (1);
	}

	while(fread(&qst1,sizeof(struct ques),1,infile))
    {
   		 printf("\n\nQ.%s",qst1.question);
   		 printf("\n1.%s\t\t2.%s\n3.%s\t\t4.%s\n",qst1.option1,qst1.option2,qst1.option3,qst1.option4);
   		 printf("\nPut your answer here: ");
   		 scanf("%d",&a1);
         fflush(stdin);

   		 	if(a1==qst1.correctoption)
   		 	{
   		 		printf("\ncorrerct answer");
   		 		score++;

			}

			else
			{
				printf("\nwrong answer\n");
			}
    }
    printf("Your name %s and score is %d",name,score);
    add_score(name,score);


     }

     else
     {
        printf("Invalid input");
     }


return 0;
}




void add_score(char name[100],int score1)
{
    FILE *p;
    p=fopen("score.txt","ab");
    struct score inputs;
    strcpy(inputs.name,name);
    inputs.score =score1;
    fwrite(&inputs, sizeof(struct score),1,p);
    fclose(p);
}


void highest_score()
{
    FILE *infile;
    struct score s1,highest;

    infile = fopen ("score.txt", "rb");
	if (infile == NULL)
	{
		fprintf(stderr, "\nError opened file\n");
		exit (1);
	}

	fread(&highest,sizeof(struct score),1,infile);

	while(fread(&s1,sizeof(struct score),1,infile))
    {
        if(s1.score>highest.score)
          {
        highest.score=s1.score;
        strcpy(highest.name, s1.name);
        }
    }
    printf("\n\nHighest score=> %s : %d",highest.name,highest.score);

}


void add_quesion(){
    FILE *outfile;
    int tid=11;
    int i,n;
    struct ques inputs;
	// open file for writing
	outfile = fopen ("question.txt", "ab");
	if (outfile == NULL)
	{
		fprintf(stderr, "\nError opened file\n");
		exit (1);
	}
    else{
        printf("How many question you want to add?\n");
        scanf("%d",&n);
        fflush(stdin);
        for(i=0;i<n;i++)
        {
            printf("Enter question :");
            scanf("%[^\n]s",inputs.question);
            fflush(stdin);
            printf("Enter option 1:");
            scanf("%[^\n]s",inputs.option1);
            fflush(stdin);
            printf("Enter option 2:");
            scanf("%[^\n]s",inputs.option2);
            fflush(stdin);
            printf("Enter option 3:");
            scanf("%[^\n]s",inputs.option3);
            fflush(stdin);
            printf("Enter option 4:");
            scanf("%[^\n]s",inputs.option4);
            fflush(stdin);
            printf("Enter correct option:");
            scanf("%d",&inputs.correctoption);
            fflush(stdin);
            fwrite(&inputs, sizeof(struct ques),1,outfile);
        }

        fclose(outfile);

    }
}
void password()
{
    char username[100],password[100];
    printf("Enter username\n");
    scanf("%s",username);
    fflush(stdin);
    printf("\nEnter password\n");
    scanf("%s",password);
    fflush(stdin);
    if(strcmp(username,"dipsam")==0)
    {
        if(strcmp(password,"1234")==0)
        {
            printf("Sucessfully login\n");
            system("cls");
              add_quesion();
        }
    }
}
