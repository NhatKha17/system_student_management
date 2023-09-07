#include "Function.h"
int TotalCourse;
int TotalStudent;
bool Run = true;

int main() {
	//Dataseed();
	Account();
	while (Run) {
		Option();
		int choice = -1;
		scanf("%d", &choice);

		switch (choice) {

		case 0:
			system("cls");
			char Confirm0 = 'N';
			getchar();
			printf("\n\n");
			printf(" Exit program What are your choice? (Y/N): ");
			scanf("%c", &Confirm0);

			if (Confirm0 == 'Y' || Confirm0 == 'y') {
				Run = false;
				ExitProgram();
			}
			break;

		case 1://open file
			system("cls");
			char Confirm1 = 'N';
			getchar();
			printf("\n\n");
			printf(" Opening file What are your choice? (Y/N): ");
			scanf("%c", &Confirm1);

			if (Confirm1 == 'Y' || Confirm1 == 'y') {
				ReadStudentFromFile(Student);
				ReadCourseFromFile(Course);
			}
			GobackOrExit();
			break;

		case 2:
			system("cls");
			char Confirm2 = 'N';
			getchar();
			printf("\n\n");
			printf(" Opening file What are your choice? (Y/N): ");
			scanf("%c", &Confirm2);

			if (Confirm2 == 'Y' || Confirm2 == 'y') {
				AddStudent();
			}
			GobackOrExit();
			break;

		case 3:
			system("cls");
			char Confirm3 = 'N';
			getchar();
			printf("\n\n");
			printf(" Showing all student What are your choice? (Y/N): ");
			scanf("%c", &Confirm3);

			if (Confirm3 == 'Y' || Confirm3 == 'y') {
				ShowAllStudent();
			}
			GobackOrExit();
			break;

		case 4:
			system("cls");
			char Confirm4 = 'N';
			getchar();
			printf("\n\n");
			printf(" Searching student What are your choice? (Y/N): ");
			scanf("%c", &Confirm4);

			if (Confirm4 == 'Y' || Confirm4 == 'y') {
				SearchStudent();
			}
			GobackOrExit();
			break;

		case 5:
			system("cls");
			char Confirm5 = 'N';
			getchar();
			printf("\n\n");
			printf(" Editing student What are your choice? (Y/N): ");
			scanf("%c", &Confirm5);

			if (Confirm5 == 'Y' || Confirm5 == 'y') {
				EditStudent();
			}
			GobackOrExit();
			break;

		case 6:
			system("cls");
			char Confirm6 = 'N';
			getchar();
			printf("\n\n");
			printf(" Deletie a student What are your choice? (Y/N): ");
			scanf("%c", &Confirm6);

			if (Confirm6 == 'Y' || Confirm6 == 'y') {
				DeleteStudent();
			}
			GobackOrExit();
			break;

		case 7:
			system("cls");
			char Confirm7 = 'N';
			getchar();
			printf("\n\n");
			printf(" Delete all student What are your choice? (Y/N): ");
			scanf("%c", &Confirm7);

			if (Confirm7 == 'Y' || Confirm7 == 'y') {
				DeleteAllStudent();
			}
			GobackOrExit();
			break;

		case 8:
			system("cls");
			char Confirm8 = 'N';
			getchar();
			printf("\n\n");
			printf(" Are you sure want to delete this student? (Y/N): ");
			scanf("%c", &Confirm8);

			if (Confirm8 == 'Y' || Confirm8 == 'y') {
				WriteStudentToFile(Student, TotalStudent);
				WriteCourseToFile(Course, TotalCourse);
			}
			GobackOrExit();
			break;

		default:

			printf("\nDo not have function!\n");
			printf("Choice other fuction in Menu!\n");
			GobackOrExit();
			break;
		}
	}
	return 0;
}