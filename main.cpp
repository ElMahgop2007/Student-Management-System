#include<iostream>   
#include<string>
#include<iomanip>

using namespace std;

struct student {            // struct
	string name;
	int id;
	float grades[5];
	float average;
	char status;

};

student students[100];			// student number 	
int studentCount = 0;

float calculatAverage(float grade[])		//function 1 calculate grade
{
	 float sum = 0;
	for (int i = 0; i < 5; i++)
    {
		sum += grade[i];
	}
	return sum / 5;
}

char calculateStatus(float average){			// function 2 calculate avarage
	if (average >= 60){
		return 'P';
	}
	else{
		return 'f';
	}
}

void addstudent()    // function 3 Add student 
{
	if (studentCount >= 100)
	{
		cout << "maximum Number of students :" << endl;
		return;
	}

    
    student &s = students[studentCount];
    cout << "Enter your name :" << "\n";
    cin >> s.name;
    s.id = studentCount + 1;
    for (int i = 0; i < 5; i++)
    {
        do {
		cout << "Enter grade " << i + 1 << "\n";
		cin >> s.grades[i];
	} while (students[studentCount].grades[i] < 0 || s.grades[i] > 100);   
}
    s.average = calculatAverage(s.grades);
    s.status = calculateStatus(s.average);
    studentCount++;

    cout << "student added successfully" << endl;
}

void displayAllStudents() {
    if (studentCount == 0) {
        cout << "No students \n";
        return;
    }
    for(int i=0;i<studentCount;i++)
    {
        cout << "ID: " << students[i].id << "\n";
        cout << "Name: " << students[i].name << "\n";
     
        cout << "\nAverage: " << fixed << setprecision(2) << students[i].average << "\n";
        cout << "Status: " << students[i].status << "\n";
    }
}
void searchStudentByID()
{
    int id;
    cout<<"Enter student id to search: ";
    cin>>id;
    for(int i=0; i<studentCount; i++)
    {
        if(students[i].id == id)
        {
            cout << "ID: " << students[i].id << "\n";
            cout << "Name: " << students[i].name << "\n";

            cout<<"Grades: ";
            for(int j=0;j<5;j++)
            {
                cout<<students[i].grades[j]<<" ";
            }
            cout<<endl; 

            cout<<"Avarage: "<<students[i].average<<endl;
            cout<<"Status: "<<students[i].status<<endl;
            return;
        }
    }
    cout<<"students not found \n";
}
void showStatistics() {

    if (studentCount == 0) {
        cout << "No students available.\n";
        return;
    }

    int pass = 0, fail = 0;
    float totalAvg = 0;

    for (int i = 0; i < studentCount; i++) {
        totalAvg += students[i].average;

        if (students[i].status == 'P')
            pass++;
        else
            fail++;
    }

    cout << "Total students: " << studentCount << endl;
    cout << "Overall average: " << totalAvg / studentCount << endl;
    cout << "Passed: " << pass << endl;
    cout << "Failed: " << fail << endl;
}
void updateStudentGrades() {
    int id;
    cout << "Enter student ID: ";
    cin >> id;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {

            for (int j = 0; j < 5; j++) {
                do {
                    cout << "Enter new grade " << j + 1 ;
                    cin >> students[i].grades[j];
                } while (students[i].grades[j] < 0 || students[i].grades[j] > 100);
            }

            students[i].average = calculatAverage(students[i].grades);
            students[i].status = calculateStatus(students[i].average);

            cout << "Grades updated successfully!\n";
            return;
        }
    }

    cout << "Student not found!\n";
}
int main()
{
        int choice;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Update Student Grades\n";
        cout << "5. Statistics\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
                        case 1: addstudent(); break;
            case 2: displayAllStudents(); break;
            case 3: searchStudentByID(); break;
            case 4: updateStudentGrades(); break;
            case 5: showStatistics(); break;
            case 6: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 6); 

    return 0;
}
