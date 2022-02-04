// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure
typedef struct Person {
   int id;
   char name[20];
   char email[20];
   char password[20];
}Person;

// Function Declarations
void addTrainer();
void addTrainee();
int uniqueEmail();
// void modifyTrainer();
// void modifyTrainee();
// void search();
// void display();
// int main(){

// Admin Panel
void admin(){
	int ch;
	char login[20] = "admin";
	char p[20] = "admin";
	printf("Login id : ");
	scanf("%s",&login);
	printf("Password : ");
	scanf("%s",&p);
	if(strcmp(login,"admin")==0 && strcmp(p,"admin")==0){
		do{
			square0:
			printf("\n1. Add Trainer");
			printf("\n2. Add Trainee");
			printf("\n3. Modify Trainer");
			printf("\n4. Modify Trainee");
			printf("\n5. Exit");
			printf("\nEnter your choice ");
			scanf("%d",&ch);
			switch(ch){
				case 1:
					addTrainer();
					break;
				case 2:
					addTrainee();
					break;
				case 3:
					// display();
					break;
				case 4:
					// search();
					break;
			}
		}while(ch != 5);
	}
	else{
		printf("Wrong Credentials");
		exit(0);
}
}

// Add Trainer
void addTrainer(){
	Person p1;
	int status = 0;
	int statusEmail = 0;
	int validPass = 0;
	FILE *fp;
	int n,i;
	fp = fopen("Trainee.txt","a");
		printf("\nEnter Employee ID : ");
		scanf("%d",&p1.id);
		fflush(stdin);
		do
    	{
        	printf("Enter Employee Name");
        	fflush(stdin);
        	fgets(p1.name,20,stdin);
        	status = isNameValid(p1.name);
        	if (!status)
        	{
        	    printf("Name contain invalid character. Please enter again.");
        	}
    	}while(!status);
		do{
			printf("Enter Email : ");
			scanf("%s",&p1.email);
			statusEmail = uniqueEmail(p1.email);
			if(statusEmail == -1){
				printf("Invalid Email ! ");
			}
			if(statusEmail == -2){
				printf("Email already exists ! ");
			}
		}while(statusEmail == -1 || statusEmail == -2);
		do{
			printf("Enter password : ");
			scanf("%s",&p1.password);
			validPass = validatePassword(p1.password);
			if(validPass == -1){
				printf("Invalid password ! ");
			}
		}while(validPass == -1);
		// fwrite(&p1,sizeof(Person),1,fp);
		fprintf(fp,"%d\t%s\t%s\t%s\n",p1.id,p1.name,p1.email,p1.password);
	fclose(fp);
}

// Add Trainee
void addTrainee(){
	Person p1;
	int status = 0;
	int statusEmail = 0;
	int validPass = 0;
	FILE *fp;
	int n,i;
	fp = fopen("Trainee.txt","a");
		printf("\nEnter Employee ID : ");
		scanf("%d",&p1.id);
		fflush(stdin);
		do
    	{
        	printf("Enter Employee Name");
        	fflush(stdin);
        	fgets(p1.name,20,stdin);
        	status = isNameValid(p1.name);
        	if (!status)
        	{
        	    printf("Name contain invalid character. Please enter again.");
        	}
    	}while(!status);
		do{
			printf("Enter Email : ");
			scanf("%s",&p1.email);
			statusEmail = uniqueEmail(p1.email);
			if(statusEmail == -1){
				printf("Invalid Email ! ");
			}
			if(statusEmail == -2){
				printf("Email already exists ! ");
			}
		}while(statusEmail == -1 || statusEmail == -2);
		do{
			printf("Enter password : ");
			scanf("%s",&p1.password);
			validPass = validatePassword(p1.password);
			if(validPass == -1){
				printf("Invalid password ! ");
			}
		}while(validPass == -1);
		// fwrite(&p1,sizeof(Person),1,fp);
		fprintf(fp,"%d\t%s\t%s\t%s\n",p1.id,p1.name,p1.email,p1.password);
	fclose(fp);
}

// Displaying all Details of Trainee
void display(){
	FILE *fp;  
	Person p1;
	char buff[255];//creating char array to store data of file  
	fp = fopen("Trainee.txt", "r");  
	while(fscanf(fp,"%d\t%s\t%s\t%s\n",&p1.id,p1.name,p1.email,p1.password)!=EOF){  
		printf("%d\t%s\t%s\t%s\n",p1.id,p1.name,p1.email,p1.password);
		// printf("\n");  
	}  
	fclose(fp);  
}

// Unique email
int uniqueEmail(char *email){
	Person p1;
	FILE *fp;
	int status = 0;
	printf("\nStatus outside = %d",status);
	fp = fopen("trainee.txt","r");
	
	while(fscanf(fp,"%*d\t%*s\t%s\t%*s\n",p1.email)!=EOF)
	{
		printf("%s\n",p1.email);
		if(strcmp(p1.email,email)==0){
			status = -2;
			break;
			}
			else{
				status = validateEmail(email);
			}
	}
	rewind(fp);
		fclose(fp);
		return status;
}

// Validating Name
int isNameValid(const char *name)
{
    int validName = 1;
    int len = 0;
    int index = 0;
    len = strlen(name);
    for(index =0; index <len ; ++index)
    {
        if(!(isalpha(name[index])) && (name[index] != '\n'))
        {
            validName = 0;
            break;
        }
    }
    return validName;
}

// Validating Email
int validateEmail(char *str)
{
    // Check the first character
    // is an alphabet or not
    char c=str[0];
    char str1[]="appcino";
    int At = -1, Dot = -1, i, j=0;
    if ((c >= 'a' && c <= 'z')|| (c >= 'A' && c <= 'Z'))
    {
        for (i = 0;i<strlen(str);i++)
        {
            if (str[i] == '@') {
                At = i;
            }
            else if (str[i] == '.') {
                Dot = i;
            }
        }
        if (At == -1 || Dot == -1)
            return -1;
        if (At > Dot)
            return -1;
        for(i=At+1;i<Dot;i++)
        {
            if(str[i]!=str1[j])
                return -1;
            j++;
        }
        if(Dot >= (strlen(str) - 1))
            return -1;
    }
    return 1;
}

// Validating password
int validatePassword(char *str)
{
    // password must be exactly 8 char long
    // must contain atleast 1 number and 1 special character
    // special characters include only '@', '!', '_', '#'
    // must not contain any space
    int len=strlen(str);
    int i, countSpChar=0, countNum=0;
    
    // password must be exactly 8 char long
    if(len==8)
    {
        for(i=0;i<len;i++)
        {
            // must not contain space
            if(str[i]==32)
                return -1;
            // must contain atleast 1 number and 1 special character
            if(str[i]=='@'||str[i]=='_'||str[i]=='!'||str[i]=='#')
                countSpChar++;
            if(str[i]>=48&&str[i]<=57)
                countNum++;
        }
        if(countSpChar>=1 && countNum>=1)
            return 1;
    }
    return -1;
}


// void search(){
// 	Person p1;
// 	FILE *fp;
// 	int id,found=0;
// 	fp = fopen("Data.txt","r");
// 	printf("Enter the id you want to search : ");
// 	scanf("%d",&id);
// 	while(fscanf(fp,"%d\t%s\t%s\t%s\n",&p1.id,p1.name,p1.email,p1.password)!=EOF)
// 	// while(fread(&p1,sizeof(Person),1,fp))
// 	{
// 		if(p1.id == id){
// 			found = 1;
// 			// printf("\n%d\t%s\t%s\t%s",p1.id,p1.name,p1.email,p1.password); //,p1.lname
// 			printf("%d\t%s\t%s\t%s\n",p1.id,p1.name,p1.email,p1.password);
// 		}
// 	}
// 	if(!found){
// 		printf("Record Not Found");
// 	}
// 	fclose(fp);
// }

// // validate login id pass
// void search(){
// 	Person p1;
// 	FILE *fp;
// 	int id,found=0;
// 	char pass[50];
// 	fp = fopen("Data.txt","r");
// 	printf("Enter the id : ");
// 	scanf("%d",&id);
// 	printf("Enter the password : ");
// 	scanf("%s",&pass);
// 	while(fscanf(fp,"%d\t%s\t%s\t%s\n",&p1.id,p1.name,p1.email,p1.password)!=EOF)
// 	// while(fread(&p1,sizeof(Person),1,fp))
// 	{
// 		// printf("%d %s",p1.id,p1.password);
// 		if(p1.id == id){
// 			printf("Go");
// 			if((strcmp(p1.password,pass)==0)){
// 			found = 1;
// 			// printf("\n%d\t%s\t%s\t%s",p1.id,p1.name,p1.email,p1.password); //,p1.lname
// 			// printf("%d\t%s\t%s\t%s\n",p1.id,p1.name,p1.email,p1.password);
// 			printf("FOUND");
// 			}
// 		}
// 	}
// 	if(!found){
// 		printf("Record Not Found");
// 	}
// 	fclose(fp);
// }


// // void modify(){
// // 	Person p1;
// // 	FILE *fp;
// // 	FILE *fp1;
// // 	int id,found=0;
// // 	fp = fopen("Data.txt","r");
// // 	fp1 = fopen("Temp.txt","w");
// // 	printf("Enter the id you want to update : ");
// // 	scanf("%d",&id);
// // 	while(fread(&p1,sizeof(Person),1,fp))
// // 	{
// // 		if(p1.id == id){
// // 			found = 1;
// // 			fflush(stdin);
// // 			printf("Enter New Name : ");
// // 			scanf("%[^\n]s",p1.name);
// // 			fflush(stdin);
// // 			printf("Enter New Email : ");
// // 			scanf("%[^\n]s",p1.email);
// // 			fflush(stdin);
// // 			printf("Enter New Password : ");
// // 			scanf("%[^\n]s",p1.password);
// // 		}
// // 		fwrite(&p1,sizeof(Person),1,fp1);
// // 	}
// // 	fclose(fp);
// // 	fclose(fp1);
// // 	if(found){
// // 		fp1 = fopen("Temp.txt","r");
// // 		fp = fopen("Data.txt","w");
// // 		while(fread(&p1,sizeof(Person),1,fp1)){
// // 			fwrite(&p1,sizeof(Person),1,fp);
// // 		}
// // 		fclose(fp);
// // 		fclose(fp1);
// // 	}
// // 	else{
// // 		printf("Record Not Found");
// // 	}
// // }

// void modify(){
// 	Person p1;
// 	FILE *fp;
// 	FILE *fp1;
// 	int id,found=0;
// 	fp = fopen("Data.txt","r");
// 	fp1 = fopen("Temp.txt","w");
// 	printf("Enter the id you want to update : ");
// 	scanf("%d",&id);
// 	// while(fread(&p1,sizeof(Person),1,fp)){
// 		fscanf(fp,"%d\t%s\t%s\t%s\n",&p1.id,p1.name,p1.email,p1.password);
// 		if(p1.id == id){
// 			found = 1;
// 			fflush(stdin);
// 			printf("Enter New Name : ");
// 			scanf("%[^\n]s",p1.name);
// 			fflush(stdin);
// 			printf("Enter New Email : ");
// 			scanf("%[^\n]s",p1.email);
// 			fflush(stdin);
// 			printf("Enter New Password : ");
// 			scanf("%[^\n]s",p1.password);
// 		// }
// 		// fwrite(&p1,sizeof(Person),1,fp1);
// 		fprintf(fp1,"%d\t%s\t%s\t%s\n",p1.id,p1.name,p1.email,p1.password);
// 	}
// 	fclose(fp);
// 	fclose(fp1);
// 	if(found){
// 		fp1 = fopen("Temp.txt","r");
// 		fp = fopen("Data.txt","w");
// 		// while(fread(&p1,sizeof(Person),1,fp1)){
// 		// 	fwrite(&p1,sizeof(Person),1,fp);
// 		// }
// 		while(fscanf(fp1,"%d\t%s\t%s\t%s\n",&p1.id,p1.name,p1.email,p1.password)!=EOF){
// 			fprintf(fp,"%d\t%s\t%s\t%s\n",p1.id,p1.name,p1.email,p1.password);
// 		}
// 		fclose(fp);
// 		fclose(fp1);
// 	}
// 	else{
// 		printf("Record Not Found");
// 	}
// }

