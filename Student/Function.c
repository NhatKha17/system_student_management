#include "Function.h"

void Option() {
	{	system("cls");
	printf("\n\n========================================================================================================================\n\n");
	printf("\n\t\t\t\t***STUDENT SYSTEM MANAGEMENT using C***\n\n");
	printf("\t\t\t\t\t\tMAIN MENU\n");
	printf("\t\t\t\t\t=======================\n");
	printf("\t\t\t\t\t[1] Open File.\n");
	printf("\t\t\t\t\t[2] Add A New student.\n");
	printf("\t\t\t\t\t[3] Show All students.\n");
	printf("\t\t\t\t\t[4] Search A student.\n");
	printf("\t\t\t\t\t[5] Edit A student.\n");
	printf("\t\t\t\t\t[6] Delete A student.\n");
	printf("\t\t\t\t\t[7] Delete All students.\n");
	printf("\t\t\t\t\t[8] Save Data into File.\n");
	printf("\t\t\t\t\t[0] Exit the Program.\n");
	printf("\t\t\t\t\t=======================\n");
	printf("\t\t\t\t\tEnter The Choice: ");
	}

}

/*void Dataseed() {
	//student 1
	strcpy(Student[0].ID, "1711");
	strcpy(Student[0].Name, "Nguyen Nhat Kha");
	strcpy(Student[0].Phone, "0767538873");
	strcpy(Student[0].Email, "nhatkhaa310@gmail.com");
	Student[0].Age = 24;
	Student[0].Sex = Male;
	Student[0].GPA = 8.46;
	Student[0].Rank = Good;
	Student[0].NumberofCourse = 2;
	strcpy(Course[0].StudentID, Student[0].ID);
	strcpy(Course[0].CourseCode, "0707");
	strcpy(Course[0].CourseName, "C programming");
	strcpy(Course[1].StudentID, Student[0].ID);
	strcpy(Course[1].CourseCode, "0808");
	strcpy(Course[1].CourseName, "C embedded");

	//student 2
	strcpy(Student[1].ID, "2609");
	strcpy(Student[1].Name, "Nguyen Ngoc Bao Chau");
	strcpy(Student[1].Phone, "0935578277");
	strcpy(Student[1].Email, "sammy@gmail.com");
	Student[1].Age = 26;
	Student[1].Sex = Female;
	Student[1].GPA = 9.5;
	Student[1].Rank = VeryGood;
	Student[1].NumberofCourse = 1;
	strcpy(Course[2].StudentID, Student[1].ID);
	strcpy(Course[2].CourseCode, "0909");
	strcpy(Course[2].CourseName, "Music");

	//student 3
	strcpy(Student[2].ID, "0708");
	strcpy(Student[2].Name, "Banh Bao");
	strcpy(Student[2].Phone, "0385538873");
	strcpy(Student[2].Email, "banhbao@gmail.com");
	Student[2].Age = 20;
	Student[2].Sex = Unknow;
	Student[2].GPA = 5.78;
	Student[2].Rank = Average;
	Student[2].NumberofCourse = 2;
	strcpy(Course[3].StudentID, Student[2].ID);
	strcpy(Course[3].CourseCode, "0707");
	strcpy(Course[3].CourseName, "C programming");
	strcpy(Course[3].StudentID, Student[2].ID);
	strcpy(Course[4].CourseCode, "0808");
	strcpy(Course[4].CourseName, "C embedded");

	TotalStudent = 3;
	TotalCourse = 5;
}*/
void Account() {
	char Acc[50];
	char Pass[50];
	char Buf[2];
again:
	system("cls");
	printf("\n\n========================================================================================================================\n\n");
	printf("\n\t\t\t\t***STUDENT SYSTEM MANAGEMENT using C***\n\n");
	printf("\n\t\t\t\t\t\tLog in\n");
	printf("\t\t\tAccount:"); scanf("%s", Acc);
	printf("\n\t\t\tPassword:"); scanf("%s", Pass);
	if ((strcmp(Acc, "nhatkha17") != 0) || (strcmp(Pass, "17111999") != 0)) {
		printf("\n\t\t\tAccount or Password not correctly!");
		printf("\n\t\t\tYou want countinue ? (0) Exit - (1) Countinue : ");
		scanf("%s", &Buf);
		if (strcmp(Buf, "0") == 0) {
			for (int i = 0; i < 4; i++)
			{
				Sleep(1000); // 1 second pause;
				printf(".");
			}
			printf("\n");
			ExitProgram();
		}
		else goto again;
	}
	else  printf("\n\t\t\tLog in successfully!");

	while ((strcmp(Acc, "nhatkha17") != 0) || (strcmp(Pass, "17111999") != 0));
}
void WriteStudentToFile(struct StudentInfo student[], int TotalStudent) {
	char Filename[100];
	printf("\nEnter the link and name file : "); scanf(" %s", Filename);


	FILE* AllStudent;
	AllStudent = fopen(Filename, "wb");
	if (AllStudent == NULL) {
		printf("\nOpen file not necessary!");
		return;
	}
	else {
		printf("\n Starting load into %s \n", Filename);
		fwrite(&TotalStudent, sizeof(TotalStudent), 1, AllStudent);
		printf("Having total course in file %d", TotalStudent);
		for (int i = 0; i < TotalStudent; i++) {
			fwrite(&Student[i], sizeof(Student), 1, AllStudent);
		}
		printf("\nLoading data into %s complete!\n", Filename);
	}

	fclose(AllStudent);
}

void ReadStudentFromFile(struct StudentInfo student[]) {
	char Filename[100];
	printf("Enter the link and STUDENT name file : "); scanf(" %s", Filename);

	FILE* AllStudent;
	AllStudent = fopen(Filename, "rb");
	if (AllStudent == NULL) {
		printf("\nOpen file not necessary!");
		return;
	}
	else {
		printf("\n Starting load data form %s \n", Filename);
		fread(&TotalStudent, sizeof(TotalCourse), 1, AllStudent);
		printf("The number of students have in file : %d", TotalStudent);
		for (int i = 0; i < TotalStudent; i++) {
			fread(&Student[i], sizeof(Student), 1, AllStudent);
		}
		printf("\nRead data from %s complete \n", Filename);
		printf("-----------------------------------------------------------------\n\n");
	}

	fclose(AllStudent);
}

void WriteCourseToFile(struct StudentInfo course[], int Totalcourse) {
	char Filename[100];
	printf("\nEnter the link and name file : "); scanf(" %s", Filename);

	FILE* AllCourse;
	AllCourse = fopen(Filename, "wb");
	if (AllCourse == NULL) {
		printf("\nOpen file not necessary!");
		return;
	}
	else {
		printf("\n Starting load into %s \n", Filename);
		fwrite(&TotalCourse, sizeof(TotalCourse), 1, AllCourse);
		printf("Having total course in file %d", TotalCourse);
		for (int i = 0; i < TotalCourse; i++) {
			fwrite(&Course[i], sizeof(Course), 1, AllCourse);
		}
		printf("\nLoading data into %s complete!\n", Filename);
	}

	fclose(AllCourse);
}

void ReadCourseFromFile(struct StudentInfo course[]) {

	char Filename[100];
	printf("Enter the link and COURSE name file : "); scanf(" %s", Filename);

	FILE* AllCourse;
	AllCourse = fopen(Filename, "rb");
	if (AllCourse == NULL) {
		printf("\nOpen file not necessary!");
		return;
	}
	else {
		printf("\n Starting load into %s \n", Filename);
		fread(&TotalCourse, sizeof(TotalCourse), 1, AllCourse);
		printf("The number of courses have in file : %d", TotalCourse);
		for (int i = 0; i < TotalCourse; i++) {
			fread(&Course[i], sizeof(Course), 1, AllCourse);
		}
		printf("\nReading data from %s complete!\n", Filename);
		printf("-----------------------------------------------------------------\n\n");
	}

	fclose(AllCourse);
}

void AddStudent() {

	system("cls");

	int  n = 0;
	char    studentID[100];
	char    studentName[100];
	char    studentEmail[100];
	char    studentPhone[100];
	int     studentAge;
	float   studentGPA;
	int     studentnumberofcourse;
	Sex     studentSex;
	Rank    studentRank;

	char    courseCode[100];
	char    courseName[100];

	GuideUser();

	printf("-------ENTER INFORMATION OF STUDENT-------\r\n");
	printf("Number of students need to enter : "); scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		printf("Enter the info of student %d \r\n", i + 1);

		int ValidID = 0;
		while (!ValidID) {
			printf("Enter the ID : ");
			scanf("%s", &studentID);
			if (CheckAlreadyExists(studentID, 'I') > 0) {
				printf("ERROR : ID has already exists. \n\n");
				ValidID = 0;
			}
			else if (strlen(studentID) > 10) {
				printf("ERROR : ID can maximum 10 characters long. \n\n");
				ValidID = 0;
			}
			else if (strlen(studentID) <= 0) {
				printf("ERROR : ID can\'t be empty.\n\n");
				ValidID = 0;
			}
			else ValidID = 1;
		}

		int ValidName = 0;
		while (!ValidName) {
			printf("Enter the Name : ");
			scanf(" %[^\n]s", &studentName);
			if (strlen(studentName) > 25) {
				printf("ERROR : Name too long! Name can maximum 32 characters long.\n\n");
				ValidName = 0;
			}
			else if (strlen(studentName) <= 0) {
				printf("ERROR : Name can\'t  empty.\n\n");
				ValidName = 0;
			}
			else ValidName = 1;
		}

		int ValidEmail = 0;
		while (!ValidEmail) {
			printf("Enter the Email : ");
			scanf("%s", &studentEmail);
			if (CheckAlreadyExists(studentEmail, 'E') > 0) {
				printf("ERROR : Email has already exists.\n\n");
				ValidEmail = 0;
			}
			else if (strlen(studentEmail) > 30) {
				printf("ERROR : Email too long! Email can maximum 50 characters long. \n\n");
				ValidEmail = 0;
			}
			else if (strlen(studentEmail) <= 0) {
				printf("ERROR : Email can\'t empty. \n\n");
				ValidEmail = 0;
			}
			else ValidEmail = 1;
		}

		int ValidPhone = 0;
		while (!ValidPhone) {
			printf("Enter the Number Phone : ");
			scanf("%s", &studentPhone);
			if (CheckAlreadyExists(studentPhone, 'P') > 0) {
				printf("ERROR : Number phone has already exists.\n\n");
				ValidPhone = 0;
			}
			else if (strlen(studentPhone) > 10) {
				printf("ERROR : Number phone too long! Email can maximum 50 characters long. \n\n");
				ValidPhone = 0;
			}
			else if (strlen(studentPhone) <= 0) {
				printf("ERROR : Number phone can\'t empty. \n\n");
				ValidPhone = 0;
			}
			else ValidPhone = 1;
		}

		int ValidAge = 0;
		while (!ValidAge) {
			printf("Enter the Age (Enter two character(ex 08,18 ): ");
			while (scanf("%d", &studentAge) != 1) {
				printf("This is not an integer number. Please retype the input: ");
				while (getchar() != '\n');
			}

			if (studentAge > 100) {
				printf("ERROR : Too old! Should take a rest.\n\n");
				ValidAge = 0;
			}
			else if (studentAge < 0) {
				printf("ERROR : Not born yet.\n\n");
				ValidAge = 0;
			}
			else ValidAge = 1;
		}

		int ValidSex = 0;
		while (!ValidSex) {
			printf("Enter The Sex ( (0) : Male - (1): Female -(2): Unknow ) : ");
			while (scanf("%d", &studentSex) != 1) {
				printf("This is not an integer number. Please retype the input: ");
				while (getchar() != '\n');
			}

			if (studentSex < 0 || studentSex>2) {
				printf("ERROR: Enter the same number (0) Male - (1): Female -(2): Unknow  ");
				ValidSex = 0;
			}
			else ValidSex = 1;
		}

		int ValidGPA = 0;
		while (!ValidGPA) {

			printf("Enter the GPA : ");
			while (scanf("%f", &studentGPA) != 1) {
				printf("This is not an integer number. Please retype the input: ");
				while (getchar() != '\n');
			}

			if (studentGPA > 10.0) {
				printf("ERROR : GPA not greater than 10.\n\n");
				ValidGPA = 0;
			}
			else if (studentGPA < 0.0) {
				printf("ERROR : GPA not less than 0.\n\n");
				ValidGPA = 0;
			}
			else ValidGPA = 1;
		}


		if (studentGPA > 8.5) {
			studentRank = VeryGood;
		}
		else if (studentGPA > 6.5) {
			studentRank = Good;
		}
		else if (studentGPA > 5.0) {
			studentRank = Average;
		}
		else studentRank = Week;

		int ValidNumberofCourse = 0;
		while (!ValidNumberofCourse) {
			printf("Enter the Number of Course : ");
			while (scanf("%d", &studentnumberofcourse) != 1) {
				printf("This is not an integer number. Please retype the input: ");
				while (getchar() != '\n');
			}

			if (studentnumberofcourse > 3) {
				printf("ERROR : Students can register maximum 3 courses. \n\n");
				ValidNumberofCourse = 0;
			}
			else if (studentnumberofcourse < 0) {
				printf("ERROR : Students must regist least 1 course. \n\n");
				ValidNumberofCourse = 0;
			}
			else ValidNumberofCourse = 1;
		}
		strcpy(Student[TotalStudent].ID, studentID);
		strcpy(Student[TotalStudent].Name, studentName);
		strcpy(Student[TotalStudent].Email, studentEmail);
		strcpy(Student[TotalStudent].Phone, studentPhone);
		Student[TotalStudent].Age = studentAge;
		Student[TotalStudent].GPA = studentGPA;
		Student[TotalStudent].Sex = studentSex;
		Student[TotalStudent].Rank = studentRank;
		Student[TotalStudent].NumberofCourse = studentnumberofcourse;
		TotalStudent++;


		for (int i = 0; i < studentnumberofcourse; i++) {
			int ValidCodeCourse = 0;
			while (!ValidCodeCourse) {
				printf("Enter the Code Course %d : ", i + 1); scanf("%s", &courseCode);
				if ((strlen(courseCode) <= 0) || (strlen(courseCode) > 10)) {
					printf("ERROR: Course code from 1 to 10 characters long.\n\n");
					ValidCodeCourse = 0;
				}
				else ValidCodeCourse = 1;
			}

			int ValidNameCourse = 0;
			while (!ValidNameCourse) {
				printf("Enter the Name Course %d : ", i + 1); scanf(" %[^\n]s", &courseName);
				if ((strlen(courseName) <= 0) || (strlen(courseName) > 20)) {
					printf("ERROR: Course code from 1 to 20 characters long.\n\n");
					ValidNameCourse = 0;
				}
				else ValidNameCourse = 1;
			}
			strcpy(Course[TotalCourse].StudentID, studentID);
			strcpy(Course[TotalCourse].CourseCode, courseCode);
			strcpy(Course[TotalCourse].CourseName, courseName);
			TotalCourse++;
		}
		printf("\n ---Student %d Added Successfully.----------------------------------------------------------------\n\n", TotalStudent);
	}


}

void GuideUser() {
	printf("\n\t\t **** How Adding Student Works? ****\n\n");
	printf(" -> You will only able to store the Student's ID, Name, Email, Phone, Number of Courses.\n");
	printf(" -> A student can have maximum 3 courses and minimum 1 course.\n");
	printf(" -> Student ID can be maximum 10 characters long and unique for every students.\n");
	printf(" -> Student Name can be maximum 25 characters long.\n");
	printf(" -> Student Email can be maximum 30 characters long and unique for every students.\n");
	printf(" -> Student Phone can be maximum 10 characters long and unique for every students.\n");
	printf(" -> Age must greater than 0 and less than 100.\n");
	printf(" -> Age must greater than 0 and less than 10.\n");
	printf(" -> Course code can be maximum 10 characters long.\n");
	printf(" -> Course Name can be maximum 20 characters long.\n\n");
}

static int CheckAlreadyExists(char NewInfo[100], char TypeExists) {

	int IDExists = 0;
	int EmailExists = 0;
	int PhoneExists = 0;

	for (int count = 0; count < TotalStudent; count++) {
		if (strcmp(NewInfo, Student[count].ID) == 0) {
			IDExists++;
		}
		if (strcmp(NewInfo, Student[count].Email) == 0) {
			EmailExists++;
		}
		if (strcmp(NewInfo, Student[count].Phone) == 0) {
			PhoneExists++;
		}
		if (TypeExists == 'I') {
			return IDExists;
		}
		else if (TypeExists == 'E') {
			return EmailExists;
		}
		else if (TypeExists == 'P') {
			return PhoneExists;
		}
		else {
			return 0;
		}
	}
}

void PrintStudent(struct StudentInfo A) {


	printf("\n");
	printf("|============================================================================================================================================|\n");
	printf("|                                                         ALL STUDENTS                                                                       |\n");
	printf("|===========|==========================|================================|=============|========|==========|========|===========|=============|\n");
	printf("|    ID     |        Name              |            Email               |    Phone    |   Age  |    Sex   |  GPA   |    Rank   |  NO.Course  |\n");
	printf("|===========|==========================|================================|=============|========|==========|========|===========|=============|\n");
	//print ID
	printf("| ");
	printf("%s", A.ID);
	for (int j = 0; j < 11 - strlen(A.ID) - 1; j++) {
		printf(" ");
	}
	//print NAME    
	printf("| ");
	printf("%s", A.Name);
	for (int j = 0; j < 26 - strlen(A.Name) - 1; j++) {
		printf(" ");
	}
	//print Email
	printf("| ");
	printf("%s", A.Email);
	for (int j = 0; j < 32 - strlen(A.Email) - 1; j++) {
		printf(" ");
	}
	//print Phone
	printf("| ");
	printf("%s", A.Phone);
	for (int j = 0; j < 13 - strlen(A.Phone) - 1; j++) {
		printf(" ");
	}
	//print Age
	printf("| ");
	printf("%d", A.Age);
	if (A.Age < 10) {
		for (int j = 0; j < 6; j++) {
			printf(" ");
		}
	}
	else {
		for (int j = 0; j < 5; j++) {
			printf(" ");
		}
	}

	//Print Sex
	printf("| ");
	printf("%s", (A.Sex == Female) ? "Female   " : (A.Sex == Male) ? "Male     " : "Unknown  ");

	//print GPA
	printf("| ");
	printf("%.1f", A.GPA);
	if (A.GPA >= 10.0) {
		for (int j = 0; j < 3; j++) {
			printf(" ");
		}
	}
	else {
		for (int j = 0; j < 4; j++) {
			printf(" ");
		}
	}
	//print Rank
	printf("| ");
	printf("%s", (A.Rank == VeryGood) ? "VeryGood  " : (A.Rank == Good) ? "Good      " : (A.Rank == Average) ? "Average   " : "Week      ");

	//printf NO.course
	printf("| ");
	printf("%d", A.NumberofCourse);
	for (int j = 0; j < 11; j++) {
		printf(" ");
	}
	printf("|\n");
	printf("|===========|==========================|================================|=============|========|==========|========|===========|=============|\n");

}

void ShowAllStudent() {

	system("cls");

	ShowGPAHightoLow();

	printf("\n");
	printf("|============================================================================================================================================|\n");
	printf("|                                                         ALL STUDENTS                                                                       |\n");
	printf("|===========|==========================|================================|=============|========|==========|========|===========|=============|\n");
	printf("|    ID     |        Name              |            Email               |    Phone    |   Age  |    Sex   |  GPA   |    Rank   |  NO.Course  |\n");
	printf("|===========|==========================|================================|=============|========|==========|========|===========|=============|\n");
	for (int i = 0; i < TotalStudent; i++) {
		//print ID
		printf("| ");
		printf("%s", Student[i].ID);
		for (int j = 0; j < 11 - strlen(Student[i].ID) - 1; j++) {
			printf(" ");
		}
		//print NAME    
		printf("| ");
		printf("%s", Student[i].Name);
		for (int j = 0; j < 26 - strlen(Student[i].Name) - 1; j++) {
			printf(" ");
		}
		//print Email
		printf("| ");
		printf("%s", Student[i].Email);
		for (int j = 0; j < 32 - strlen(Student[i].Email) - 1; j++) {
			printf(" ");
		}
		//print Phone
		printf("| ");
		printf("%s", Student[i].Phone);
		for (int j = 0; j < 13 - strlen(Student[i].Phone) - 1; j++) {
			printf(" ");
		}
		//print Age
		printf("| ");
		printf("%d", Student[i].Age);
		if (Student[i].Age < 10) {
			for (int j = 0; j < 6; j++) {
				printf(" ");
			}
		}
		else {
			for (int j = 0; j < 5; j++) {
				printf(" ");
			}
		}
		//Print Sex
		printf("| ");
		printf("%s", (Student[i].Sex == Female) ? "Female   " : (Student[i].Sex == Male) ? "Male     " : "Unknown  ");

		//print GPA
		printf("| ");
		printf("%.1f", Student[i].GPA);
		if (Student[i].GPA >= 10.0) {
			for (int j = 0; j < 3; j++) {
				printf(" ");
			}
		}
		else {
			for (int j = 0; j < 4; j++) {
				printf(" ");
			}
		}

		//print Rank
		printf("| ");
		printf("%s", ((Student[i].Rank == VeryGood) ? "VeryGood  " : ((Student[i].Rank == Good) ? "Good      " : ((Student[i].Rank == Average) ? "Average   " : "Week      "))));

		//printf NO.course
		printf("| ");
		printf("%d", Student[i].NumberofCourse);
		for (int j = 0; j < 11; j++) {
			printf(" ");
		}
		printf("|\n");
		printf("|===========|==========================|================================|=============|========|==========|========|===========|=============|\n");
	}


}

static void ShowGPAHightoLow() {
	struct StudentInfo Buffer = { 0 };

	for (int i = 0; i < TotalStudent; i++) {
		for (int j = i; j < TotalStudent; j++) {
			if (Student[i].GPA < Student[i + 1].GPA) {
				Buffer = Student[i];
				Student[i] = Student[i + 1];
				Student[i + 1] = Buffer;
			}
		}
	}
}

int SearchStudent() {

	system("cls");
	int StudentFoundIndex = (-1);


	printf("---------- SEARCH STUDENT BY ID --------------------------\n");

	int NoFound = 0;
	while (!NoFound) {
		printf("Enter the Student ID Search : "); scanf("%s", StudentID);
		for (int i = 0; i < TotalStudent; i++) {
			if (strcmp(StudentID, Student[i].ID) == 0) {
				StudentFoundIndex = i;
				PrintStudent(Student[i]);

				int CourseFoundIndex = 0;
				for (int j = 0; j < TotalCourse; j++) {
					if (strcmp(StudentID, Course[j].StudentID) == 0) {
						CourseFoundIndex++;
						printf("Course %d.\n", CourseFoundIndex);
						printf("Course code : %s.\n", Course[j].CourseCode);
						printf("Course name : %s.\n\n", Course[j].CourseName);
					}
				}
			}
		}

		if (StudentFoundIndex == (-1)) {
			char countinue[2];
			printf("No Student found. \n");
			printf("Do you want to try again? YES (y) or No (n) : "); scanf("%s", countinue);
			if (strcmp(countinue, "y") == 0) {
				NoFound = 0;
			}
			else NoFound = 1;
		}
		else NoFound = 1;
	}

	return StudentFoundIndex;

}

void EditStudent() {

	int EditStudentFoundIndex = SearchStudent();//position need edit
	if (EditStudentFoundIndex != (-1)) {
		char NewID[100];
		char NewName[100];
		char NewPhone[100];
		char NewEmail[100];
		int NewAge;
		float NewGPA;
		Sex NewSex;
		int NewNumberOfCourses;

		char NewCodeCourse[100];
		char NewNameCourse[100];

		strcpy(NewID, Student[EditStudentFoundIndex].ID);//take ID
		printf("\n===================================================================================================\n\n");
		printf("\t\tEDIT Information of student \n");

		int ValidName = 0;
		while (!ValidName) {
			printf("Enter the Name ( 0 for skip) : ");
			scanf(" %[^\n]s", &NewName);
			if (strlen(NewName) > 25) {
				printf("ERROR : Name too long! Name can maximum 25 characters long.\n\n");
				ValidName = 0;
			}
			else if (strlen(NewName) <= 0) {
				printf("ERROR : Name can\'t  empty.\n\n");
				ValidName = 0;
			}
			else ValidName = 1;
		}

		int ValidEmail = 0;
		while (!ValidEmail) {
			printf("Enter the Email (0 for skip) : ");
			scanf("%s", NewEmail);
			if (CheckAlreadyExists(NewEmail, 'E') > 0) {
				printf("ERROR : Email has already exists.\n\n");
				ValidEmail = 0;
			}
			else if (strlen(NewEmail) > 30) {
				printf("ERROR : Email too long! Email can maximum 50 characters long. \n\n");
				ValidEmail = 0;
			}
			else if (strlen(NewEmail) <= 0) {
				printf("ERROR : Email can\'t empty. \n\n");
				ValidEmail = 0;
			}
			else ValidEmail = 1;
		}

		int ValidPhone = 0;
		while (!ValidPhone) {
			printf("Enter the Number Phone (0 for skip): ");
			scanf("%s", NewPhone);
			if (CheckAlreadyExists(NewPhone, 'P') > 0) {
				printf("ERROR : Number phone has already exists.\n\n");
				ValidPhone = 0;
			}
			else if (strlen(NewPhone) > 10) {
				printf("ERROR : Number phone too long! Email can maximum 50 characters long. \n\n");
				ValidPhone = 0;
			}
			else if (strlen(NewPhone) <= 0) {
				printf("ERROR : Number phone can\'t empty. \n\n");
				ValidPhone = 0;
			}
			else ValidPhone = 1;
		}

		int ValidAge = 0;
		while (!ValidAge) {
			printf("Enter the Age : ");
			while (scanf("%d", &NewAge) != 1) {
				printf("This is not an integer number. Please retype the input: ");
				while (getchar() != '\n');
			}

			if (NewAge > 100) {
				printf("ERROR : Too old! Should take a rest.\n\n");
				ValidAge = 0;
			}
			else if (NewAge < 0) {
				printf("ERROR : Not born yet.\n\n");
				ValidAge = 0;
			}
			else ValidAge = 1;
		}
		int ValidSex = 0;
		while (!ValidSex) {
			printf("Enter The Sex ( (0) : Male - (1): Female -(2): Unknow ) : ");
			while (scanf("%d", &NewSex) != 1) {
				printf("This is not an integer number. Please retype the input: ");
				while (getchar() != '\n');
			}

			if (NewSex < 0 || NewSex>2) {
				printf("ERROR: Enter the same number (0) Male - (1): Female -(2): Unknow  ");
				ValidSex = 0;
			}
			else ValidSex = 1;
		}

		int ValidGPA = 0;
		while (!ValidGPA) {
			printf("Enter the GPA : ");
			while (scanf("%f", &NewGPA) != 1) {
				printf("This is not an integer number. Please retype the input: ");
				while (getchar() != '\n');
			}

			if (NewGPA > 10) {
				printf("ERROR : GPA not greater than 10.\n\n");
				ValidGPA = 0;
			}
			else if (NewGPA < 0) {
				printf("ERROR : GPA not less than 0.\n\n");
				ValidGPA = 0;
			}
			else ValidGPA = 1;
		}

		//save new info data into position need to update
		if (strcmp(NewName, "0") != 0) {
			strcpy(Student[EditStudentFoundIndex].Name, NewName);
		}
		if (strcmp(NewEmail, "0") != 0) {
			strcpy(Student[EditStudentFoundIndex].Email, NewEmail);
		}
		if (strcmp(NewPhone, "0") != 0) {
			strcpy(Student[EditStudentFoundIndex].Phone, NewPhone);
		}
		Student[EditStudentFoundIndex].Age = NewAge;
		Student[EditStudentFoundIndex].GPA = NewGPA;
		Student[EditStudentFoundIndex].Sex = NewSex;
		//new course data
		int ValidNumberofCourse = 0;
		while (!ValidNumberofCourse) {
			printf("Enter the Number of Course : ");
			while (scanf("%d", &NewNumberOfCourses) != 1) {
				printf("This is not an integer number. Please retype the input: ");
				while (getchar() != '\n');
			}

			if (NewNumberOfCourses > 3) {
				printf("ERROR : Students can register maximum 3 courses! \n\n");
				ValidNumberofCourse = 0;
			}
			else if (NewNumberOfCourses < 0) {
				printf("ERROR : The number of course must greater than 0! \n\n");
				ValidNumberofCourse = 0;
			}
			else ValidNumberofCourse = 1;
		}
		//have to delete all course of that ID in store

		int OldNumberofCourse = Student[EditStudentFoundIndex].NumberofCourse;
		Student[EditStudentFoundIndex].NumberofCourse = NewNumberOfCourses;

		int FirstCourseIndex = 0;
		for (int i = 0; i < TotalCourse; i++) {
			if (strcmp(NewID, Course[i].StudentID) == 0) {
				FirstCourseIndex = i;//find start adress course
				break;
			}
		}

		for (int j = 0; j < OldNumberofCourse; j++) {
			DeleteCourseIndex(FirstCourseIndex);
		}
		//save new course data into store
		for (int i = 0; i < NewNumberOfCourses; i++) {
			int ValidCodeCourse = 0;
			while (!ValidCodeCourse) {
				printf("Enter the Code Course %d : ", i + 1); scanf("%s", NewCodeCourse);
				if ((strlen(NewCodeCourse) <= 0) || (strlen(NewCodeCourse) > 10)) {
					printf("ERROR: Course code from 1 to 10 characters long.\n\n");
					ValidCodeCourse = 0;
				}
				else ValidCodeCourse = 1;
			}

			int ValidNameCourse = 0;
			while (!ValidNameCourse) {
				printf("Enter the Name Course %d : ", i + 1); scanf(" %[^\n]s", NewNameCourse);
				if ((strlen(NewNameCourse) <= 0) || (strlen(NewNameCourse) > 20)) {
					printf("ERROR: Course code from 1 to 20 characters long.\n\n");
					ValidNameCourse = 0;
				}
				else ValidNameCourse = 1;
			}
			strcpy(Course[TotalCourse].StudentID, Student[EditStudentFoundIndex].ID);
			strcpy(Course[TotalCourse].CourseCode, NewCodeCourse);
			strcpy(Course[TotalCourse].CourseName, NewNameCourse);
			TotalCourse++;
		}

	}
}

static void DeleteCourseIndex(int FisrtCourseIndex) {

	for (int course = 0; course < TotalCourse - 1; course++)
	{
		if (course >= FisrtCourseIndex)
		{
			Course[course] = Course[course + 1];
		}
	}
	TotalCourse--;
}

static void DeleteStudentIndex(int StudentIDdelete) {
	for (int student = 0; student < TotalStudent - 1; student++)
	{
		if (student >= StudentIDdelete)
		{
			Student[student] = Student[student + 1];
		}
	}
	TotalStudent--;
}

void DeleteStudent() {


	int DeleleStudentID = SearchStudent();//return position ID search

	char Confirm = 'N';
	getchar();
	printf("\n\n");
	printf(" Are you sure want to delete this student? (Y/N): ");
	scanf("%c", &Confirm);

	if (Confirm == 'Y' || Confirm == 'y') {
		int FirstCourseIndex = 0;
		for (int i = 0; i < TotalCourse; i++) {
			if (strcmp(Student[DeleleStudentID].ID, Course[i].StudentID) == 0) {
				FirstCourseIndex = i;
				break;
			}
		}
		for (int i = 0; i < Student[DeleleStudentID].NumberofCourse; i++) {
			DeleteCourseIndex(FirstCourseIndex);
		}
		DeleteStudentIndex(DeleleStudentID);
		printf(" Student Deleted Successfully.\n\n");
	}
	else {
		printf("Data is not deleted.\n\n");
	}

}

void DeleteAllStudent() {

	char Confirm = 'N';
	getchar();
	system("cls");
	printf("\n\n----- Delete All Data ---------------\n\n");
	printf("Are you sure delete all data? Yes(Y) or No(N) : "); scanf("%c", &Confirm);
	if (Confirm == 'Y' || Confirm == 'y') {
		TotalCourse = 0;
		TotalStudent = 0;
		printf("All Data is deleted\n\n");
	}
	else {
		printf("Data still safe\n\n");
	}
}

void GobackOrExit() {
	getchar();
	char Option;
	printf(" Go back(b)? or Exit(0)?: ");
	scanf("%c", &Option);
	if (Option == '0')
	{
		ExitProgram();
	}
	else
	{
		system("cls");
	}
}

void ExitProgram() {
	system("cls");
	char S1[50] = "========= Thank You ==========\n";
	char S2[50] = "======= See You Later ========\n";
	for (int i = 0; i < strlen(S1); i++) {
		printf("%c", S1[i]);
		Sleep(50);
	}
	for (int i = 0; i < strlen(S2); i++) {
		printf("%c", S2[i]);
		Sleep(50);
	}
	exit(0);
}
