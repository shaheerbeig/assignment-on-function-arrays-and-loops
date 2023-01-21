#include<stdio.h>
#include<string.h>
struct student{
	char rollnumber[20];
	char name[20];
	float mid1;
	float mid2;
	float quiz;
	float assign;
	float final;	
};
char type;
float accumulateEvaluation(struct student[],int);
float getGPA(float);
void option();
void smartFunction(struct student [],int);

int main(){
	struct student data[10];
	char ID[10];
	char rollno[10];
	int num,i,maxvalue;
	float totalmid1=0,totalmid2=0,totalfinal=0,avgmid1,avgmid2,avgfinal,grandweightage,c,max=0.0;
	printf("WELCOME TO THE PORTAL. PLEASE FILL IN THE DETAILS TO PROCEED \n");
	printf("---------------------------------------------------------------------------\n");
	num=321;
	float totalweightage[num];
		for(i=0;i<num;i++){
			printf("ENTER THE  ROLL NUMBER OF THE STUDENT \n");
			scanf("%s",&data[i].rollnumber);
			printf("ENTER THE NAME OF THE STUDENT \n");
			scanf("%s",&data[i].name);
			fflush(stdin);
			printf("ENTER THE MID 1 MARKS OF THE STUDENT<OUT OF 15>\n");
			scanf("%f",&data[i].mid1);
			printf("ENTER THE MID 2 MARKS OF THE STUDENT<OUT OF 15> \n");
			scanf("%f",&data[i].mid2);
			printf("ENTER THE QUIZ MARKS OF THE STUDENT<OUT OF 10> \n");
			scanf("%f",&data[i].quiz);
			printf("ENTER THE ASSIGMENT MARKS OF THE STUDENT<OUT OF 10> \n");
			scanf("%f",&data[i].assign);
			printf("ENTER THE FINAL MARKS OF THE STUDENT<OUT OF 50> \n");
			scanf("%f",&data[i].final);
		}
		
	fflush(stdin);
	while(type!='e'){
		option();
	if(type=='a'){
		printf("rollnumber     name       gpa\n");
		for(i=0;i<num;i++){
		printf("%s       %s      %.2f \n",data[i].rollnumber,data[i].name,accumulateEvaluation(data,i));
		}
	}
	else if(type=='g'){
		int flag=1,found;
		printf("ENTER THE ROLL NUMBER TO SEARCH\n");
		scanf("%s",&rollno);
		for(i=0;i<num;i++){
			if(strcmp(data[i].rollnumber,rollno)==0){
				flag=0;
				found=i;
				break;
			}
		}
		if(flag==0){
			printf("STUDENT ID:%s \n",data[found].rollnumber);
			printf("STUDENT NAME:%s \n",data[found].name);
			printf("STUDENT GPA:%.2f \n",accumulateEvaluation(data,found));
		}
		else{
			printf("DATA NOT FOUND \n");
		}
	}
	else if(type=='s'){
		for(i=0;i<num;i++){
		totalmid1=totalmid1+data[i].mid1;
		totalmid2=totalmid2+data[i].mid2;
		totalfinal=totalfinal+data[i].final;
		}
		avgmid1=totalmid1/num;
		avgmid2=totalmid2/num;
		avgfinal=totalfinal/num;
		
			for(i=0;i<num;i++){
				grandweightage=data[i].mid1+data[i].mid2+data[i].assign+data[i].quiz+data[i].final;
				totalweightage[i]=grandweightage;
			}
			
			for(i=0;i<num;i++){
				if(totalweightage[i]>max){
					max=totalweightage[i];
					maxvalue=i;
				}
			}	
					
		printf("TOTAL STUDENT COUNT IS %d \n",num);
		printf("AVERAGE MID 1 SCORE IS %.2f \n",avgmid1);
		printf("AVERAGE MID 2 SCORE IS  %.2f \n",avgmid2);
		printf("AVERAGE FINAL SCORE IS %.2f \n",avgfinal);
		printf("STUDENT ID %s HAS THE HIGHEST SCORE OF %.2f\n",data[maxvalue].rollnumber,max);
		printf("LIST OF FAILED STUDENTS IS \n");
		for(i=0;i<num;i++){
			c=accumulateEvaluation(data,i);
			if(c<1.00){
				printf("%s\n",data[i].rollnumber);
			}
		}
		printf("Thank you , my ID is 22k-4321 and my name is shaheer beig\n");
	}
	else if(type=='f'){
		smartFunction(data,num);
	}
	else if(type=='r'){
	printf("ENTER YOUR NAME \n");
	scanf("%s",&data[7].name);
	printf("ENTER YOUR ID \n");
	scanf("%s",&data[7].rollnumber);
	printf("ENTER YOUR MID 1 MARKS \n");
	scanf("%.2f",&data[7].mid1);
	printf("ENTER YOUR MID 1 MARKS \n");
	scanf("%.2f",&data[7].mid2);
	printf("ENTER YOUR QUIZ MARKS \n");
	scanf("%.2f",&data[7].quiz);
	printf("ENTER YOUR ASSIGNMENT MARKS \n");
	scanf("%.2f",&data[7].assign);
	printf("ENTER YOUR FINAL MARKS \n");
	scanf("%.2f",&data[7].final);
	}
}
}
void option(){
	printf("---------------------------------------------------------------------------\n");
	printf("SELECT FROM THE MENU BELOW WHAT YOU WANT TO PROCEED WITH \n");
	printf("<g>- CALCULATE AND PRINT THE GPA OF THE STUDENT \n <a>- TO SHOW THE CLASS RESULT \n <r>-TO ADD YOUR DETAILS AT THE 7th INDEX \n <f>- FIND THE DETAIL OF A STUDENT \n <s>- TO PRINT THE STATISTICS OF THE CLASS \n <e>- TO EXIT\n");
	printf("SELECT AN OPTION FROM ABOVE\n");
	scanf(" %c",&type);
}

float accumulateEvaluation(struct student data[],int i){
	float total,c;
	total=data[i].mid1+data[i].mid2+data[i].assign+data[i].quiz+data[i].final;
	c=getGPA(total);
	return c;
}
float getGPA(float total){
	float gpa;
	if(total>=86){
		gpa=4.0;
		return gpa;
	}
	else if(total>82&&total<=85){
		gpa=3.67;
		return gpa;
	}
	else if(total>78&&total<=81){
		gpa=3.33;
		return gpa;
	}
	else if(total>74&&total<=77){
		gpa=3.0;
		return gpa;
	}
		else if(total>70&&total<=73){
		gpa=2.67;
		return gpa;
	}
		else if(total>66&&total<=69){
		gpa=2.33;
		return gpa;
	}
	else if(total>62&&total<=65){
		gpa=2.0;
		return gpa;
	}
	else if(total>58&&total<=61){
		gpa=1.67;
		return gpa;
	}
		else if(total>54&&total<=57){
		gpa=1.33;
		return gpa;
	}
		else if(total>50&&total<=53){
		gpa=1.0;
		return gpa;
	}
	else{
		return 0;
	}
}

void smartFunction(struct student data[],int num){
	int i,value;
	char name[10];
	printf("ENTER THE NAME OR THE ID YOU WANT TO SEARCH \n");
	scanf("%s",&name);
	for(i=0;i<num;i++){
		if(strcmp(data[i].name,name)==0||strcmp(data[i].rollnumber,name)==0){
			value=i;
			break;
		}
	}
			printf("STUDENT ID: %s \n",data[value].rollnumber);
			printf("STUDENT NAME: %s \n",data[value].name);
			printf("STUDENT MID1 MARKS: %.2f \n",data[value].mid1);
			printf("STUDENT MID2 MARKS: %.2f \n",data[value].mid2);
			printf("STUDENT ASSIGNMENT: %.2f \n",data[value].assign);
			printf("STUDENT QUIZ MARKS: %.2f \n",data[value].quiz);
			printf("STUDENT FINAL MARKS: %.2f \n",data[value].final);
}