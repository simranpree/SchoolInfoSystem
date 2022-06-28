// In this project we've created a database which stores the data of the schools teachers and students. All the information
// must be entered the user which will be stored in the dynamic array.
#include <iostream>
#include <fstream>
using namespace std;

struct Teacher
{
    string name;
    string password;
    int age;
    string subject;
    string qualification;
    int no_of_classes;
    int no_of_students;
};

struct Student
{
    string name;
    string password;
    int age;
    string roll_no;
    string fee;
    int total_subjects;
    string major;
    float cgpa;
    string teachers_name;
    string mname;
    string fname;
};

struct Database
{
    Teacher *teachers = new Teacher[20]; // an array which will store the list of teachers who've signedup
    Student *students = new Student[20]; // an array which will store the list of students who've signedup, with default size of 20
    int number_of_teachers = 0;
    int number_of_students = 0;
    // constructor
    Database()
    {
        number_of_teachers = 0;
    }
    Database(int n)
    {
        number_of_teachers = n;
    }
    // Destuctor
    ~Database()
    {
        delete[] teachers; // after program ends it will destroy the dynamic arrays to clear the memory from the system
        delete[] students;
    }
    // member functions
    void signup(int n) // every user need to signup first, so all the data can be stored. Depending up the user (student or teacher) new user will be added to the respective array
    {
        string _name;
        string _password, subject, qualification;
        int _age, total_classes, total_students;

        cout << "Enter your username: ";
        cin >> _name;

        cout << "Enter  your password: ";
        cin >> _password;

        cout << "Enter your age: ";
        cin >> _age;
        if (n == 1)
        {
            ofstream fout;
            fout.open("teachers.csv");

            cout << "Enter your Qualificatio (BA/MS/BS): ";
            cin >> qualification;

            cout << "Enter the subject you teach: ";
            cin >> subject;

            cout << "Enter total number of classes you take everyday: ";
            cin >> total_classes;

            cout << "Enter total number of student you teach: ";
            cin >> total_students;

            teachers[number_of_teachers] = {_name, _password, _age, subject, qualification, total_classes, total_students}; // an object of all the data will be added to the array at the index depeding upon the number of the users
            number_of_teachers++;                                                                                           // after a user is added to an array, it will be incremented to kepp track of total number of users

            for (int i = 0; i < number_of_teachers; i++)
            {
                fout << "###############\nUser Details\n###############\n";
                fout << "Name:" << teachers[i].name << "\nAge: " << teachers[i].age << "\nSubject: " << teachers[i].subject << "\nQualification: " << teachers[i].qualification << "\nTotal Classes: " << teachers[i].no_of_classes << "\nTotal Students: " << teachers[i].no_of_students << endl;
            }
            fout.close();
        }
        if (n == 2) // if the user signup as student, will part of the code will be executed
        {
            ofstream fout;
            fout.open("students.csv");

            int total_subjects;
            string major, roll_no, mname, fname, fee;
            float cgpa;
            string tname;

            cout << "Enter teacher's name: ";
            cin >> tname;

            cout << "Enter the Enrolment number of the student ";
            cin >> roll_no;

            cout << "Enter you major: ";
            cin >> major;

            cout << "Enter you cgpa: ";
            cin >> cgpa;

            cout << "Enter the total subjects you study: ";
            cin >> total_subjects;

            cout << "Enter the fees of the student: ";
            cin >> fee;

            cout << "Enter the Mother's name of the student: ";
            cin >> mname;

            cout << "Enter the Father's name of the student: ";
            cin >> fname;

            students[number_of_students] = {_name, _password, _age, roll_no, fee, total_subjects, major, cgpa, tname, mname, fname};
            number_of_students++;

            for (int i = 0; i < number_of_students; i++)
            {
                fout << "###############\nUser Details\n###############\n";
                fout << "Name:" << students[i].name << "\nAge: " << students[i].age << "\nTotal Subjects: " << students[i].total_subjects << "\nCGPA: " << students[i].cgpa << "\nMajor: " << students[i].major << "\nClass Teacher's Name: " << students[i].teachers_name << "\nFather's Name: " << students[i].fname << "\nMother's Name: " << students[i].mname << endl;
            }
            fout.close();
        }
    }

    void login(int n) // After loggingin, the user can get an access to the complete data
    {
        string username, password;

        if (n == 1)
        {
            if (number_of_teachers > 0)
            {
                cout << "Enter your username: ";
                cin >> username;

                cout << "Enter  your password: ";
                cin >> password;
                for (int i = 0; i < number_of_teachers; i++)
                {
                    if (teachers[i].name == username && teachers[i].password == password)
                    {
                        cout << "###############\nUser Details\n###############\n";
                        cout << "Name:" << teachers[i].name << "\nAge: " << teachers[i].age << "\nSubject: " << teachers[i].subject << "\nQualification: " << teachers[i].qualification << "\nTotal Classes: " << teachers[i].no_of_classes << "\nTotal Students: " << teachers[i].no_of_students << endl;
                    }
                    else
                    {
                        cout << "Invalid Credentials!!" << endl;
                    }
                }
            }
            else
            {
                cout << "Sign up first!!";
            }
        }
        if (n == 2)
        {
            if (number_of_students > 0)
            {
                cout << "Enter your username: ";
                cin >> username;

                cout << "Enter  your password: ";
                cin >> password;
                for (int i = 0; i < number_of_students; i++)
                {
                    if (students[i].name == username && students[i].password == password)
                    {
                        cout << "###############\nUser Details\n###############\n";
                        cout << "Name:" << students[i].name << "\nAge: " << students[i].age << "\nTotal Subjects: " << students[i].total_subjects << "\nCGPA: " << students[i].cgpa << "\nMajor: " << students[i].major << "\nClass Teacher's Name: " << students[i].teachers_name << endl;
                    }
                    else
                    {
                        cout << "Invalid Credentials!!" << endl;
                    }
                }
            }
            else
            {
                cout << "Sign up first!!";
            }
        }
    }

    void print(int n) // this function will only print the name and the age of the user
    {
        if (n == 1)
        {
            if (number_of_teachers > 0)
            {
                cout << "###############\nTeacher's List\n###############\n";
                for (int i = 0; i < number_of_teachers; i++)
                {
                    cout << "Teacher " << i + 1 << " data:" << endl;
                    cout << "Teeacher's Name: " << teachers[i].name << endl;
                    cout << "Teachers's age : " << teachers[i].age << endl
                         << endl;
                }
            }
            else
            {
                cout << "Empty List\n";
            }
        }
        if (n == 2)
        {
            if (number_of_students > 0)
            {
                cout << "###############\nStudent's List\n###############\n";
                for (int i = 0; i < number_of_students; i++)
                {
                    cout << "Student " << i + 1 << " data:" << endl;
                    cout << "Student's Name: " << students[i].name << endl;
                    cout << "Student's age : " << students[i].age << endl
                         << endl;
                }
            }
            else
            {
                cout << "Empty List\n";
            }
        }
    }
    void Parents()
    {
        string name;
        cout << "Enter student name: ";
        cin >> name;
        if (number_of_students > 0)
        {
            for (int i = 0; i < number_of_students; i++)
            {
                if (students[i].name == name)
                {
                    cout << "Father's Name: " << students[i].fname << "\nMother's Name: " << students[i].mname << endl;
                }
                else if (i == number_of_students)
                {
                    cout << "Student by this name doesn't exist\n";
                }
            }
        }
        else
        {
            cout << "No student in database\n";
        }
    }
    void Report()
    {
        string name;
        cout << "Enter student name: ";
        cin >> name;
        if (number_of_students > 0)
        {
            for (int i = 0; i < number_of_students; i++)
            {
                if (students[i].name == name)
                {
                    cout << "Students CGPA: " << students[i].cgpa << endl;
                }
                else if (i == number_of_students)
                {
                    cout << "Student by this name doesn't exist\n";
                }
            }
        }
        else
        {
            cout << "No student in database\n";
        }
    }
};
void AboutSchool()
{
    cout << " *****************************************************************************************************" << endl;
    cout << " \n                                            ABOUT US                                              " << endl;
    cout << " *****************************************************************************************************" << endl;
    cout << " \n Point View School is a large urban primary school in Auckland, New Zealand. We welcome all the visitors to the school and trust that you will sense what a special place the school is for our students, staff and families. " << endl;
    cout << " \n The period that we left behind was marked by origin, growth, developmentand consolidation.The decade ahead will be known by diversification, brand buildingand maturing into our natural progression." << endl;
    cout << " \n This cannot be achieved without firming up objectives and goals for the future and a set of clear vision and mission.Noble and profound visionand missions can be achieved only if a positive, energeticand dynamic corporateand organizational culture is provided.Our school has a sincere desire to be a family school with parents, studentsand staff following our mottoand all LEARNING TOGETHER." << endl;
    cout << " \n The surroundings are picturesque and ideal for an educational institution. The building is open, airy and functional. We hope you enjoy visiting and find the information available of interest. We would love to hear from you wherever you may be." << endl;
}
void ClassRooms()
{

    cout << " ********************************************" << endl;
    cout << "                    CLASSROOM                " << endl;
    cout << " ********************************************" << endl;
    cout << " \n Total number of tables in a classroom :- 20 " << endl;
    cout << " Total number of chairs in a classroom :- 24 " << endl;
    cout << " \n MEALS FOR THE WEEK  \n * Monday, Wednesday - Fruits, bread, milk \n * Tuesday, Friday - Rice, chicken, vegetables \n * Thursday - Cheese pizza and fried foods " << endl;
    cout << " \n TIMINGS \n * 1 Lecture - 9:00 am to 10:30 am \n * 2 Lecture - 10:40 am to 12:10 pm \n * Break time 12:10 pm to 12: 50 pm \n * Lecture 3 - 1:00 pm to 2: 30 pm " << endl;
    int answer;
    do
    {
        cout << "Enter your year (1-6): ";
        cin >> answer;
        if (answer == 1)
        {
            cout << " Curriculum for Year 1 :- 1. Reading \n * Read books at green level on the colour wheel. \n * Show they have understood the story and talk about what they have read " << endl;
            cout << " \n 2. Writing \n * Learn to write simple stories on their own \n * Learn to plan their writing by talking, or by drawing pictures \n * use many words they know from their reading " << endl;
            cout << " \n 3. Maths \n * Count forwards and backwards up to 20, then up to 100 \n * Explore patterns, shapes and measurement \n * Organize and share objects \n * Know the number before and after any given number " << endl;
        }
        if (answer == 2)
        {
            cout << " Curriculum for Year 2 :- 1. Reading \n * Read books at turquoise level on the colour wheel \n * Read sentences without big pauses \n * Use punctuation to show meaning and add interest \n * Read silently to themselves " << endl;
            cout << " \n 2. Writing \n * Write texts with a variety of uses such as stories, instructions, lists \n * Use punctuation - full stops, question marks and capital letters most of the time \n * Use connecting words correctly " << endl;
            cout << " \n 3. Maths \n * Solve problems using numbers up to 100 \n * Skip count in 2s, 5s, and 10s, forwards and backwards \n * Measure objects using their hands, feet or a pencil " << endl;
        }
        if (answer == 3)
        {
            cout << " Curriculum for Year 3 :- 1. Reading \n * Read books at gold level on the colour wheel - this is the final stage on the wheel \n * Notice when they have made a mistake and fix it up, most of the time " << endl;
            cout << " \n 2. Writing \n * Think about, record and communicate experiences, ideas and information \n * Organise their writing using a basic structure, eg writing a text with a beginning, a middle and an end \n * Build on their knowledge of punctuation and use it more often " << endl;
            cout << " \n 3. Maths \n * Explore patterns in numbers up to 1,000 \n * Organise objects and talk about what’s different and what’s the same \n * Create and describe patterns \n * Measure objects and time \n * Give and follow directions " << endl;
        }

        if (answer == 4)
        {
            cout << " Curriculum for Year 4 :- 1. Reading \n * Know what they like to read and be able to choose what’s right for them \n * Recognise and understand the information in different kinds of books \n * Read smoothly, like talking " << endl;
            cout << " \n 2. Writing \n * Use their writing to think about, record and communicate experiences, ideas and information \n * Write by themselves for different purposes \n * Read and change their writing to improve it, most of the time " << endl;
            cout << " \n 3. Maths \n * work with numbers up to 1,000 \n * Find fractions of sets, shapes and quantities \n * Use simple maps to show position and direction \n * Make and continue patterns and explain the rule for the pattern " << endl;
        }

        if (answer == 5)
        {
            cout << " Curriculum for Year 5 :- 1. Reading \n * Read for longer periods of time \n * Ask and answer questions about things that they read " << endl;
            cout << " \n 2. Writing \n * Use different ways to think about, plan and organise their writing \n * Use words and phrases that are suitable for the topic and audience \n * Choose the best way to express their message or ideas in writing " << endl;
            cout << " \n 3. Maths \n * Choose an appropriate method to solve problems (using +, – , x , ÷) and clearly explain their methods to other people \n * Sort 2D and 3D shapes and justify how they have been grouped \n * Measure the size and capacity of objects " << endl;
        }
        if (answer == 6)
        {
            cout << " Curriculum for Year 6 :- 1. Reading \n * Read longer stories more quickly, and read for longer periods of time \n * Quickly find important ideas and information by ‘skimming’ and ‘scanning’ \n * Work out words they don’t know the meaning of by using clues in the story or pictures and diagrams " << endl;
            cout << " \n 2. Writing \n * Choose the type of writing to suit the audience \n * Plan what they will write in different ways " << endl;
            cout << " \n 3. Maths \n * Solve problems (using +, – , x , ÷) that require them to choose the best method \n * Use repeated halving or known multiplication facts to solve problems involving fractions \n * Find the value of a given number in a pattern \n * Sort, create and identify 2D and 3D shapes " << endl;
        }
        else
        {
            cout << " Invalid Output " << endl;
        }
    } while (answer < 0 || answer > 6);
}
void ContactInfo()
{
    cout << "**************************************************************" << endl;
    cout << "                       CONTACT INFORMATION                    " << endl;
    cout << "**************************************************************" << endl;
    cout << " Facebook: - facebook.com/NewZealandPointViewSchool " << endl;
    cout << " Youtube: - youtube.com/PointViewSchoolAuckland " << endl;
    cout << " Email: - pointviewschool1@gamil.com " << endl;
    cout << " Phone Number: - 21034564, 23418905 " << endl;
    cout << " Our official website: - www.pointviewschool.nz" << endl;
}
void go_back() // an helper function
{
    string key;
    cout << "Press any key to go back\n";
    cin >> key;
}
int main()
{
    Database db;
    int select, choose;
    cout << "*******************************************************************" << endl;
    cout << "                           POINT VIEW SCHOOL                       " << endl;
    cout << "*******************************************************************" << endl;
    do
    {
        cout << "Please Choose: \n\n1- About School\n2- Teacher-Dashboard\n3- Student-Dashboard \n4- Parent \n5- Reports\n6- Classrooms \n7- Contact-info \n8- Quit\n";
        cin >> select;
        if (select == 1)
        {
            AboutSchool();
            go_back();
        }
        else if (select == 4)
        {
            db.Parents();
            go_back();
        }
        else if (select == 5)
        {
            db.Report();
            go_back();
        }
        else if (select == 6)
        {
            ClassRooms();
            go_back();
        }
        else if (select == 7)
        {
            ContactInfo();
            go_back();
        }
        else if (select == 8)
        {
            exit(1);
        }
        else
        {
            do
            {
                cout << "PLease choose: " << endl
                     << "1- Sign up\n2- Login\n3- Print\n4- Exit\n";
                cin >> choose;

                if (choose == 1)
                {
                    if (select == 2)
                    {
                        db.signup(1);
                    }
                    if (select == 3)
                    {
                        db.signup(2);
                    }
                }
                else if (choose == 2)
                {
                    if (select == 2)
                    {
                        db.login(1);
                        go_back();
                    }
                    if (select == 3)
                    {
                        db.login(2);
                        go_back();
                    }
                }
                else if (choose == 3)
                {
                    if (select == 2)
                    {
                        db.print(1);
                        go_back();
                    }
                    if (select == 3)
                    {
                        db.print(2);
                        go_back();
                    }
                }
                else if (choose == 4)
                {
                    break;
                }
                else
                {
                    cout << "Invalid Input\n";
                }
            }

            while (choose != 4);
        }                  // this loop will continue untill user exits
    } while (select != 8); // it will quit the program

    return 0;
}
