
#include<stdio.h>
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


int main()
{
    FILE*p;

	write_questions(); //for initialization

     printf("\n\t\t****************************************");
     printf("\n\t\t\t   WELCOME TO QUIZ GAME");
     printf("\n\t\t****************************************");
     printf("\n\t\t***********************************************");
     printf("\n\t\t   HIMALYAN WHITE HOUSE INTERNATIONAL COLLEGE") ;
     printf("\n\t\t***********************************************");
     printf("\n\t\t****************************************");


return 0;
}


void write_questions()
{
	FILE *outfile;

	// open file for writing
	outfile = fopen ("question.txt", "wb");
	if (outfile == NULL)
	{
		fprintf(stderr, "\nError opened file\n");
		exit (1);
	}

	// write struct to file

    struct ques inputs[100] ={ {1, "What do you call a computer on a network that requests files from another computer?", "A client","A host","A router","A web server",1},
	 {2, "Hardware devices that are not part of main computer system and are often added later to the system", "clip art", "peripheral", "Highlight", "Excute",2},
     {3, "The main computer that store the files that can be sent to computer that are network together is :", "clip art", "Motherboard", "peripheral", "File server",4},
	 {4, "How can you catch a computer virus?", "Sending email messages", "Using a laptop during the winter", "Opening email attachment", "Shopping online",3},
	 {5, "Which is not protocol?", "HTTP", "FTP", "STP", "IP",3},
	 {6, "Which of the following is not a valid domain name?", "WWW.yahoo.com", "WWW.yahoo.co.uk", "WWW.com.yahoo", "WWW.yahoo.co.in",3},
	 {7, "AOL stands for", "Arrange outer line", "American over lan", "America on-line", "Audio over lan",4},
	 {8, "Another name for a computer chip is", "Excute", "Micro chip", "Microprocessor", "Select",2},
	 {9, "WWW stands for", "World Wide Web", "World Wide Wares", "World Wide Wait", "World Wide War",1},
	{10, "The first web server was built in", "1990 in Geneva", "1985 in Berkely", "1988 in Cambridge", "1947 in Birmingham",1}
    };
	//write struct to file
	for(int i=0;i<10;i++)
        fwrite(&inputs[i],sizeof(struct ques),1,outfile);

	if(fwrite != 0)
		printf("contents to file written successfully !\n");
	else
		printf("error writing file !\n");

	// close file
	fclose (outfile);


}


