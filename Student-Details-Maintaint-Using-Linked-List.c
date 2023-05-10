#include <stdio.h>							// Start Header 
#include <stdlib.h>
#include <string.h>
#pragma pack(1)
struct Node {								// structure Declaration
	int  Register_Id;
	char Name[999];							
	char Depart[999];
	char Dob[999];
	char Blood_Group[999];
	long int Phone;
	struct Node *Next;						// Self Ref
};
struct Node *Head = NULL;						// 3 Node Allocate 
struct Node *Current = NULL;
struct Node *NewNode = NULL;
/*    ----------------  Insert Data Function -------------- */
void add_data()
{
	NewNode = malloc(sizeof(struct Node));				// Run Time Memory Allocation.
	printf("Enter the Register ID : ");				
	scanf("%d", &NewNode->Register_Id);				// user input Register ID
	printf("Enter the Name : ");
	getchar();
	scanf("%[^\n]", NewNode->Name);
	printf("Enter the Department : ");				// Same as input Register , Name , Depart, DOB, Phone ...
	getchar();
	scanf("%[^\n]", NewNode->Depart);
	printf("Enter the Data Of Birth DD/MM/YY : ");
	getchar();
	scanf("%[^\n]", NewNode->Dob);
	printf("Enter the Blood Group : ");
	getchar();
	scanf("%[^\n]", NewNode->Blood_Group);
	printf("Enter the Phone Number : +91 " );
	getchar();
	scanf("%ld", &NewNode->Phone);
	NewNode->Next = NULL;
	/* -------------------- Linked List Step Linear Linked List ------------------------ */
	if(Head == NULL)
	{
		Head = NewNode;
		Current = Head;
	}
	else
	{
		Current->Next = NewNode;
		Current = NewNode;
	}
	printf("\n\t Data Inserted \n");
}
/* ---------- Linear Linked List END --------------------- */
/* ----------- Student Data Update ----------- */
void update()										// Update Function .
{
	printf("\n\n");									// New Line 
	int Reg, ch;
	struct Node *RG = Head;								// Tmp Node 
	printf("\n");
	printf("Enter The Old Register ID : ");						// usr input Register Id
	scanf("%d", &Reg);	
	while(RG != NULL)						
	{
		if(Reg == RG->Register_Id)						// If Statement usr input Same Checking.
		{
			printf("1. Update Register ID   \n");				// Displaying Message
			printf("2. Update Name          \n");				
			printf("3. Update Date Of Birth \n");
			printf("4. Update Blood_Group \n");
			printf("5. Update Department    \n");
			printf("6. Update Phone No      \n");
			printf("7. Update All Details   \n");
			printf("8. Goto Main Menu	\n");
			printf("\n");
			printf("Enter The Choice : ");
			scanf("%d", &ch);	
			switch(ch)							// Switch Statement .
			{	
				case 1 :				
					printf("Updating Register ID   .... \n");
					printf("Enter the New Register ID : ");
					scanf("%d", &RG->Register_Id);
					printf("**** UPDATED REGISTER ID => %d \n", RG->Register_Id);
					break;
				case 2 :
					printf("Updating Name 	  .... \n");
					printf("Enter the New  Name : ");
					getchar();
					scanf("%[^\n]", RG->Name);
					printf("**** UPDATED NAME => %s \n", RG->Name);
					break;
				case 3 :
					printf("Updating Date of Birth   .... \n");
					printf("Enter the New Date of Birth : ");
					getchar();
					scanf("%[^\n]", RG->Dob);
					printf("**** UPDATED DATE OF BIRTH => %s \n", RG->Dob);
					break;
				case 4 :
					printf("Updating Blood Group ....");
					printf("Enter the New Blood Group : ");
					getchar();
					scanf("$%[^\n]", RG->Blood_Group);
					printf("**** UPDATED BLOOD GROUP  %s \n", RG->Blood_Group);
				case 5 :
					printf("Updating Department ....\n");
					printf("Enter the New Department : ");
					getchar();
					scanf("%[^\n]", RG->Depart);
					printf("**** UPDATED DEPARTMENT => %s \n", RG->Depart);
					break;
				case 6 :
					printf("Updating Phone No  ....\n");
					printf("Enter the New Phone No : +91 ");
					scanf("%ld", &RG->Phone);
					printf("**** UPDATED PHONE NO  => %ld \n", RG->Phone);
					break;
				case 7 :
					printf("Updating All Details  ....\n");
					printf("Enter the New Register ID : ");
					scanf("%d", &RG->Register_Id);
					printf("Enter the New Name : ");
					getchar();
					scanf("%[^\n]", RG->Name);
					printf("Enter the New Date of Birth : ");
					getchar();
					scanf("%[^\n]", RG->Dob);
					printf("Enter the New Department : ");
					getchar();
					scanf("%[^\n]", RG->Depart);
					printf("Enter the New Phone No : +91 ");
					scanf("%ld", &RG->Phone);
					printf("**** UPDATED ALL DETAILS ****\n");
					break;
				case 8 :
					break;
				default:    
					printf("--------------------");
					printf("\n!! Invalid option !!\n\n");
					printf("--------------------\n\n");
					break;
			}
		}
		RG = RG->Next;
	}
}
/* ------------- Student Data Display function ------------------ */
void display()										// Display Function
{
	int op, usrinput;
	struct Node *tmp = NULL; 
	struct Node *dtmp = NULL;	
	printf("1. Display the particular Student Details \n");
	printf("2. Display the All student Details\n");
	printf("3. Return to Main Menu ");
	printf("\n");
	printf("Enter the choice : ");	
	scanf("%d", &op);
	switch(op)
	{
		case 1:
			tmp = Head;
			printf("Enter the Register id : ");
			scanf("%d", &usrinput);
			while(tmp != NULL)
			{
				if(usrinput == tmp->Register_Id)
				{
					printf("Register_Id\tName\tDepartment\tDOB\tBlood_Group\tPhone_Number \n");
					printf("-------------------------------------------------------------------------------------------\n");
					printf("%d\t%s\t%s\t%s\t%s\t%ld \n", tmp->Register_Id, tmp->Name, tmp->Depart, tmp->Dob, tmp->Blood_Group, tmp->Phone);
					printf("-------------------------------------------------------------------------------------------\n");
				}
				tmp = tmp->Next;
			}
			printf("\n\n");
			break;
		case 2:	
			dtmp = Head;
			if(Head == NULL)
			{
				printf("List is Empty\n");
				exit(0);
			}
			printf("\n\n");
			printf("List of student Details\n");
			printf("Register_Id\tName\tDepartment\tDOB\tBlood_Group\tPhone_Number \n");
			printf("-------------------------------------------------------------------------------------------\n");
			while(dtmp != NULL)
			{
				printf("%d\t\t%s\t\t%s\t%s\t%s\t%ld\n", dtmp->Register_Id, dtmp->Name, dtmp->Depart, dtmp->Dob, dtmp->Blood_Group, dtmp->Phone);
				printf("-------------------------------------------------------------------------------------------\n");
				dtmp = dtmp->Next;
			}
			printf("\n\n");
			break;
		case 3:
			break;
		default:
			printf("--------------------");
			printf("\n!! Invalid option !!\n\n");
			printf("--------------------\n\n");
			break;
	}
}
/* ---------- Student Data Search Funtion -------------------- */
void search()								// Search Function
{
	int option , Check = 0;
	long int Srch;
	char usrchar[999];
	struct Node *Run = Head;
	printf("1. Search Register ID \n");
	printf("2. Search Name \n");
	//	printf("3. Search Department \n");
	printf("3. Search Phone \n");
	printf("Enter the Choice : ");
	scanf("%d", &option);
	switch(option)
	{
		case 1:
			Run = Head;
			printf("****Searching Register ID****\n");
			printf("Enter the Register ID : ");
			scanf("%ld", &Srch);
			while(Run != NULL)
			{
				if(Srch == Run->Register_Id)
				{
					printf("Register_Id\tName\tDepartment\tDOB\tPhone_Number \n");
					printf("-------------------------------------------------------------------------------------------\n");
					printf("%d\t%s\t%s\t%s\t%ld \n", Run->Register_Id, Run->Name, Run->Depart, Run->Dob, Run->Phone);
				}
				Run = Run->Next;
			}
			break;
		case 2:
			Run = Head;
			printf("Enter the Name : ");
			getchar();
			scanf("%[^\n]", usrchar);
			struct Node *up = Head;
			while(up != NULL)
			{
				Check = strcmp(usrchar, up->Name);
				if ( Check == 0)
				{
					printf("Register_Id\tName\tDepartment\tDOB\tBlood_Group\tPhone_Number \n");
					printf("-------------------------------------------------------------------------------------------\n");
					printf("%d\t%s\t%s\t%s\t%s\t%ld \n", up->Register_Id, up->Name, up->Depart, up->Dob, up->Blood_Group, up->Phone);
				}
				up = up->Next;
			}
			break;
			//		case 3:
			//			printf("Enter the Department : ");
			//			getchar();
			//			scanf("%[^\n]", usrchar);
			//			struct Node *tmp = Head;
			//			struct Node *test = Head;
			//
			//			while(tmp != NULL)
			//			{
			//				Check = strcmp(usrchar, tmp->Depart);
			//				if(Check == 0 )
			//				{
			//					printf("Register_Id\tName\tDepartment\tDOB\tPhone_Number \n");
			//					printf("%d\t%s\t%s\t%s\t%ld \n", tmp->Register_Id, tmp->Name, tmp->Depart, tmp->Dob, tmp->Phone);
			//					while(test != NULL)
			//					{
			//						test = tmp;
			//						test = test->Next;
			//						Check = strcmp(usrchar, test->Depart);
			//						if(Check == 0 )
			//						{
			//							printf("Register_Id\tName\tDepartment\tDOB\tPhone_Number \n");
			//							printf("%d\t%s\t%s\t%s\t%ld \n", test->Register_Id, test->Name, test->Depart, test->Dob, test->Phone);
			//						}
			//
			//					}
			//
			//
			//				}
			//				tmp = tmp->Next;
			//			}
			//			break;
		case 3:
			Run = Head;
			printf("Enter the Phone No : ");
			scanf("%ld", &Srch);
			Run = Head;
			while(Run != NULL)
			{
				if(Srch == Run->Phone)
				{
					printf("Register_Id\tName\tDepartment\tDOB\tBlood_Group\tPhone_Number \n");
					printf("-------------------------------------------------------------------------------------------\n");
					printf("%d\t%s\t%s\t%s\t%s\t%ld \n", Run->Register_Id, Run->Name, Run->Depart, Run->Dob, Run->Blood_Group, Run->Phone);
				}
				Run = Run->Next;
			}
			break;
		default:
			printf("--------------------");
			printf("\n!! Invalid option !!\n\n");
			printf("--------------------\n\n");
			break;
	}
}
/*	-----------------  Student Data Delete Function ----------------- */
void delete ()
{
	int Del;
	struct Node *prev = NULL;
	struct Node *Run = Head ;
	printf("*** Delete the Student Data ***\n");
	printf("Enter the Register ID : ");
	scanf("%d", &Del);

	while(Run != NULL)
	{
		if(Del == Run->Register_Id)
		{
			prev->Next = Run->Next;
			printf("Deleted row Register ID => %d", Run->Register_Id);
		}
		prev = Run;
		Run = Run->Next;
	}
	free(Run);
}
/*	--------------- Main Program ----------------- */
int main ()									// Main Program Start ....
{
	char log[100];
	int pass;
	int val;
	char logstore[999] = "Masthan";						// Username Storing Compile Time Memory Allocation
	int pinstore = 1234;							// password Storing Compile Time Memory Allocation
	printf("\t\t------------- Welcome TO ABC School Student Details ------------- ");		// Title School Name
	printf("\n\n");
	printf("\t\t\t\t	Login Page \n\n");				// Login Page ..
Move:										// Goto Jumping Statement ..
	printf("\t\t\t\t\t\tEnter the username : ");				// username message
	getchar();
	scanf("%[^\n]", log);							// inputing username
	val = strcmp(logstore, log);						// veryfing
	if (val == 0 )
	{
Wrong:
		printf("\t\t\t\t\t\tEnter the pin : ");				// pin message
		scanf("%d", &pass);						// usr input pin no 
	}
	else
	{
		printf("\t\t\t\t\t!! Wrong User Name !! \n");
		goto Move;
	}
	if(pass == pinstore)							// pin no check.
	{
		while(1)
		{
			int op, val, pos;
			printf("\n\n");
			printf("************* Student Details *************");
			printf("\n");
			printf("1. Add Student Data       \n");				// display the Main Menu
			printf("2. Update Student Data    \n");
			printf("3. Display Student Data   \n");
			printf("4. Search Student Data    \n");
			printf("5. Delete Student Data    \n");
			printf("6. Exit 		  \n");
			printf("\n");
			printf("Enter The Choice : ");
			scanf("%d", &op);
			switch(op)							// switch statement
			{
				case 1:
					printf("Adding Student Data\n");
					add_data();
					break;
				case 2:
					printf("Updating Student Data");
					update();
					break;
				case 3:
					display();
					break;
				case 4:
					search();
					break;
				case 5:
					delete();
					break;	
				case 6:
					printf("Exit\n");
					exit(0);
				default :
					printf("\nInvalid Option\n");
					break;
			}
		}
	}
	if (pass != pinstore)
	{
		printf("\t\t\t\t\t!! Pin Wrong !! \n");
		goto Wrong;
	}
}
