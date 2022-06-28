#include <iostream>
// In this project we&#39;ve created a database which stores the data of the schools teachers and
students.All the information
// must be entered the user which will be stored in the dynamic array.
#include &lt;iostream&gt;
#include &lt;fstream&gt;
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
	Teacher* teachers = new Teacher[20]; // an array which will store the list of teachers
	who& #39; ve signedup
		Student* students = new Student[20]; // an array which will store the list of students
	who& #39; ve signedup, with default size of 20
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
		delete[] teachers; // after program ends it will destroy the dynamic arrays to clear the
		memory from the system
			delete[] students;
	}
	// member functions
	void signup(int n) // every user need to signup first, so all the data can be stored.
		Depending up the user(student or teacher) new user will be added to the respective array
	{
	string _name;
	string _password, subject, qualification;
	int _age, total_classes, total_students;
	cout& lt; &lt; &quot; Enter your username : &quot;;
	cin& gt; &gt; _name;
	cout& lt; &lt; &quot; Enter your password : &quot;;
	cin& gt; &gt; _password;
	cout& lt; &lt; &quot; Enter your age : &quot;;
	cin& gt; &gt; _age;
	if (n == 1)
	{
	ofstream fout;
	fout.open(&quot; teachers.csv & quot;);
	cout& lt; &lt; &quot; Enter your Qualificatio(BA / MS / BS) : &quot;;
	cin& gt; &gt; qualification;
	cout& lt; &lt; &quot; Enter the subject you teach : &quot;;
	cin& gt; &gt; subject;
	cout& lt; &lt; &quot; Enter total number of classes you take everyday : &quot;;
	cin& gt; &gt; total_classes;
	cout& lt; &lt; &quot; Enter total number of student you teach : &quot;;
	cin& gt; &gt; total_students;
	teachers[number_of_teachers] = {_name, _password, _age, subject, qualification,
	total_classes, total_students}; // an object of all the data will be added to the array at the
	index depeding upon the number of the users

	number_of_teachers++; // after a
	user is added to an array, it will be incremented to kepp track of total number of users
	for (int i = 0; i & lt; number_of_teachers; i++)
	{
	fout & lt; &lt; &quot; ###############\nUser Details\n###############\n & quot;;
	fout& lt; &lt; &quot; Name:&quot; &lt; &lt; teachers[i].name& lt; &lt; &quot; \nAge: &quot; &lt; &lt; teachers[i].age& lt; &lt; &quot; \nSubject:
	&quot; &lt; &lt; teachers[i].subject& lt; &lt; &quot; \nQualification: &quot; &lt; &lt; teachers[i].qualification& lt; &lt; &quot; \nTotal Classes :
	&quot; &lt; &lt; teachers[i].no_of_classes& lt; &lt; &quot; \nTotal Students : &quot; &lt; &lt; teachers[i].no_of_students& lt; &lt; endl;
	}
	fout.close();
	}
	if (n == 2) // if the user signup as student, will part of the code will be executed
	{
	ofstream fout;
	fout.open(&quot; students.csv & quot;);
	int total_subjects;
	string major, roll_no, mname, fname, fee;
	float cgpa;
	string tname;
	cout& lt; &lt; &quot; Enter teacher& #39; s name : &quot;;
	cin& gt; &gt; tname;
	cout& lt; &lt; &quot; Enter the Enrolment number of the student& quot;;
	cin& gt; &gt; roll_no;
	cout& lt; &lt; &quot; Enter you major : &quot;;
	cin& gt; &gt; major;
	cout& lt; &lt; &quot; Enter you cgpa : &quot;;
	cin& gt; &gt; cgpa;
	cout& lt; &lt; &quot; Enter the total subjects you study : &quot;;
	cin& gt; &gt; total_subjects;
	cout& lt; &lt; &quot; Enter the fees of the student : &quot;;
	cin& gt; &gt; fee;
	cout& lt; &lt; &quot; Enter the Mother& #39; s name of the student : &quot;;
	cin& gt; &gt; mname;
	cout& lt; &lt; &quot; Enter the Father& #39; s name of the student : &quot;;
	cin& gt; &gt; fname;

	students[number_of_students] = {_name, _password, _age, roll_no, fee,
	total_subjects, major, cgpa, tname, mname, fname};
	number_of_students++;
	for (int i = 0; i & lt; number_of_students; i++)
	{
	fout & lt; &lt; &quot; ###############\nUser Details\n###############\n & quot;;
	fout& lt; &lt; &quot; Name:&quot; &lt; &lt; students[i].name& lt; &lt; &quot; \nAge: &quot; &lt; &lt; students[i].age& lt; &lt; &quot; \nTotal
	Subjects : &quot; &lt; &lt; students[i].total_subjects& lt; &lt; &quot; \nCGPA: &quot; &lt; &lt; students[i].cgpa& lt; &lt; &quot; \nMajor: &quot; &lt; &lt;
	students[i].major& lt; &lt; &quot; \nClass Teacher& #39; s Name : &quot; &lt; &lt; students[i].teachers_name& lt; &lt;
	&quot; \nFather& #39; s Name : &quot; &lt; &lt; students[i].fname& lt; &lt; &quot; \nMother& #39; s Name : &quot; &lt; &lt; students[i].mname& lt; &lt;
	endl;
	}
	fout.close();
	}
	}
		void login(int n) // After loggingin, the user can get an access to the complete data
	{
		string username, password;
		if (n == 1)
		{
			if (number_of_teachers& gt; 0)
			{
				cout& lt; &lt; &quot; Enter your username : &quot;;
				cin& gt; &gt; username;
				cout& lt; &lt; &quot; Enter your password : &quot;;
				cin& gt; &gt; password;
				for (int i = 0; i & lt; number_of_teachers; i++)
				{
					if (teachers[i].name == username & amp; &amp; teachers[i].password == password)
					{
						cout & lt; &lt; &quot; ###############\nUser Details\n###############\n & quot;;
						cout& lt; &lt; &quot; Name:&quot; &lt; &lt; teachers[i].name& lt; &lt; &quot; \nAge: &quot; &lt; &lt; teachers[i].age& lt; &lt;
						&quot; \nSubject: &quot; &lt; &lt; teachers[i].subject& lt; &lt; &quot; \nQualification: &quot; &lt; &lt; teachers[i].qualification& lt; &lt;
						&quot; \nTotal Classes : &quot; &lt; &lt; teachers[i].no_of_classes& lt; &lt; &quot; \nTotal Students : &quot; &lt; &lt;
						teachers[i].no_of_students& lt; &lt; endl;
					}
					else
					{
						cout& lt; &lt; &quot; Invalid Credentials!!&quot; &lt; &lt; endl;
					}
				}
			}
			else

			{
				cout& lt; &lt; &quot; Sign up first!!&quot;;
			}
		}
		if (n == 2)
		{
			if (number_of_students& gt; 0)
			{
				cout& lt; &lt; &quot; Enter your username : &quot;;
				cin& gt; &gt; username;
				cout& lt; &lt; &quot; Enter your password : &quot;;
				cin& gt; &gt; password;
				for (int i = 0; i & lt; number_of_students; i++)
				{
					if (students[i].name == username & amp; &amp; students[i].password == password)
					{
						cout & lt; &lt; &quot; ###############\nUser Details\n###############\n & quot;;
						cout& lt; &lt; &quot; Name:&quot; &lt; &lt; students[i].name& lt; &lt; &quot; \nAge: &quot; &lt; &lt; students[i].age& lt; &lt;
						&quot; \nTotal Subjects : &quot; &lt; &lt; students[i].total_subjects& lt; &lt; &quot; \nCGPA: &quot; &lt; &lt; students[i].cgpa& lt; &lt;
						&quot; \nMajor: &quot; &lt; &lt; students[i].major& lt; &lt; &quot; \nClass Teacher& #39; s Name : &quot; &lt; &lt;
						students[i].teachers_name& lt; &lt; endl;
					}
					else
					{
						cout& lt; &lt; &quot; Invalid Credentials!!&quot; &lt; &lt; endl;
					}
				}
			}
			else
			{
				cout& lt; &lt; &quot; Sign up first!!&quot;;
			}
		}
	}
	void print(int n) // this function will only print the name and the age of the user
	{
		if (n == 1)
		{
			if (number_of_teachers& gt; 0)
			{
				cout & lt; &lt; &quot; ###############\nTeacher & #39; s List\n###############\n & quot;;
				for (int i = 0; i & lt; number_of_teachers; i++)
				{
					cout& lt; &lt; &quot; Teacher& quot; &lt; &lt; i + 1 & lt; &lt; &quot; data:&quot; &lt; &lt; endl;
					cout& lt; &lt; &quot; Teeacher& #39; s Name : &quot; &lt; &lt; teachers[i].name& lt; &lt; endl;

					cout& lt; &lt; &quot; Teachers& #39; s age : &quot; &lt; &lt; teachers[i].age& lt; &lt; endl
						& lt; &lt; endl;
				}
			}
			else
			{
				cout& lt; &lt; &quot; Empty List\n& quot;;
			}
		}
		if (n == 2)
		{
			if (number_of_students& gt; 0)
			{
				cout & lt; &lt; &quot; ###############\nStudent & #39; s List\n###############\n & quot;;
				for (int i = 0; i & lt; number_of_students; i++)
				{
					cout& lt; &lt; &quot; Student& quot; &lt; &lt; i + 1 & lt; &lt; &quot; data:&quot; &lt; &lt; endl;
					cout& lt; &lt; &quot; Student& #39; s Name : &quot; &lt; &lt; students[i].name& lt; &lt; endl;
					cout& lt; &lt; &quot; Student& #39; s age : &quot; &lt; &lt; students[i].age& lt; &lt; endl
						& lt; &lt; endl;
				}
			}
			else
			{
				cout& lt; &lt; &quot; Empty List\n& quot;;
			}
		}
	}
	void Parents()
	{
		string name;
		cout& lt; &lt; &quot; Enter student name : &quot;;
		cin& gt; &gt; name;
		if (number_of_students& gt; 0)
		{
			for (int i = 0; i & lt; number_of_students; i++)
			{
				if (students[i].name == name)
				{
					cout& lt; &lt; &quot; Father& #39; s Name : &quot; &lt; &lt; students[i].fname& lt; &lt; &quot; \nMother& #39; s Name : &quot; &lt; &lt;
					students[i].mname& lt; &lt; endl;
				}
				else if (i == number_of_students)
				{
					cout& lt; &lt; &quot; Student by this name doesn& #39; t exist\n& quot;;
				}
			}

		}
		else
		{
			cout& lt; &lt; &quot; No student in database\n& quot;;
		}
	}
	void Report()
	{
		string name;
		cout& lt; &lt; &quot; Enter student name : &quot;;
		cin& gt; &gt; name;
		if (number_of_students& gt; 0)
		{
			for (int i = 0; i & lt; number_of_students; i++)
			{
				if (students[i].name == name)
				{
					cout& lt; &lt; &quot; Students CGPA : &quot; &lt; &lt; students[i].cgpa& lt; &lt; endl;
				}
				else if (i == number_of_students)
				{
					cout& lt; &lt; &quot; Student by this name doesn& #39; t exist\n& quot;;
				}
			}
		}
		else
		{
			cout& lt; &lt; &quot; No student in database\n& quot;;
		}
	}
};
void AboutSchool()
{
	cout& lt; &lt; &quot;
	***************************************************************************
		**************************&quot; &lt; &lt; endl;
	cout& lt; &lt; &quot; \n ABOUT US& quot; &lt; &lt; endl;
	cout& lt; &lt; &quot;
	***************************************************************************
		**************************&quot; &lt; &lt; endl;
	cout& lt; &lt; &quot; \n Point View School is a large urban primary school in Auckland, New Zealand.
		We welcome all the visitors to the schooland trust that you will sense what a special place
		the school is for our students, staffand families.& quot; &lt; &lt; endl;
	cout& lt; &lt; &quot; \n The period that we left behind was marked by origin, growth,
		developmentand consolidation.The decade ahead will be known by diversification, brand
		buildingand maturing into our natural progression.& quot; &lt; &lt; endl;

	cout& lt; &lt; &quot; \n This cannot be achieved without firming up objectivesand goals for the
		futureand a set of clear visionand mission.Nobleand profound visionand missions can be
		achieved only if a positive, energeticand dynamic corporateand organizational culture is
		provided.Our school has a sincere desire to be a family school with parents, studentsand
		staff following our mottoand all LEARNING TOGETHER.& quot; &lt; &lt; endl;
	cout& lt; &lt; &quot; \n The surroundings are picturesqueand ideal for an educational institution.The
		building is open, airyand functional.We hope you enjoy visitingand find the information
		available of interest.We would love to hear from you wherever you may be.& quot; &lt; &lt; endl;
}
void ClassRooms()
{
	cout& lt; &lt; &quot; ********************************************&quot; &lt; &lt; endl;
	cout& lt; &lt; &quot; CLASSROOM& quot; &lt; &lt; endl;
	cout& lt; &lt; &quot; ********************************************&quot; &lt; &lt; endl;
	cout& lt; &lt; &quot; \n Total number of tables in a classroom : -20 & quot; &lt; &lt; endl;
	cout& lt; &lt; &quot; Total number of chairs in a classroom : -24 & quot; &lt; &lt; endl;
	cout& lt; &lt; &quot; \n MEALS FOR THE WEEK \n* Monday, Wednesday - Fruits, bread, milk \n*
		Tuesday, Friday - Rice, chicken, vegetables \n* Thursday - Cheese pizza and fried foods & quot; &lt; &lt;
	endl;
	cout& lt; &lt; &quot; \n TIMINGS \n * 1 Lecture - 9:00 am to 10 : 30 am \n * 2 Lecture - 10:40 am to
		12 : 10 pm \n * Break time 12:10 pm to 12 : 50 pm \n * Lecture 3 - 1:00 pm to 2 : 30 pm & quot; &lt; &lt;
	endl;
	int answer;
	do
	{
		cout& lt; &lt; &quot; Enter your year(1 - 6) : &quot;;
		cin& gt; &gt; answer;
		if (answer == 1)
		{
			cout& lt; &lt; &quot; Curriculum for Year 1 :-1. Reading \n * Read books at green level on the
				colour wheel. \n * Show they have understood the story and talk about what they have read
				& quot; &lt; &lt; endl;
			cout& lt; &lt; &quot; \n 2. Writing \n * Learn to write simple stories on their own \n * Learn to
				plan their writing by talking, or by drawing pictures \n * use many words they know from
				their reading & quot; &lt; &lt; endl;
			cout& lt; &lt; &quot; \n 3. Maths \n * Count forwards and backwards up to 20, then up to 100 \n
				* Explore patterns, shapesand measurement \n* Organizeand share objects \n* Know the
				number beforeand after any given number& quot; &lt; &lt; endl;
		}
		if (answer == 2)
		{
			cout& lt; &lt; &quot; Curriculum for Year 2 :-1. Reading \n * Read books at turquoise level on the
				colour wheel \n * Read sentences without big pauses \n * Use punctuation to show
				meaning and add interest \n * Read silently to themselves & quot; &lt; &lt; endl;

			cout& lt; &lt; &quot; \n 2. Writing \n * Write texts with a variety of uses such as stories,
				instructions, lists \n* Use punctuation - full stops, question marksand capital letters most
				of the time \n* Use connecting words correctly& quot; &lt; &lt; endl;
			cout& lt; &lt; &quot; \n 3. Maths \n * Solve problems using numbers up to 100 \n * Skip count in
				2s, 5s, and 10s, forwardsand backwards \n* Measure objects using their hands, feet or a
				pencil & quot; &lt; &lt; endl;
		}
		if (answer == 3)
		{
			cout& lt; &lt; &quot; Curriculum for Year 3 :-1. Reading \n * Read books at gold level on the
				colour wheel - this is the final stage on the wheel \n * Notice when they have made a
				mistake and fix it up, most of the time& quot; &lt; &lt; endl;
			cout& lt; &lt; &quot; \n 2. Writing \n * Think about, recordand communicate experiences, ideas
				and information \n* Organise their writing using a basic structure, eg writing a text with a
				beginning, a middleand an end \n* Build on their knowledge of punctuationand use it
				more often& quot; &lt; &lt; endl;
			cout& lt; &lt; &quot; \n 3. Maths \n * Explore patterns in numbers up to 1, 000 \n * Organise
				objects and talk about what’s different and what’s the same \n * Create and describe
				patterns \n * Measure objects and time \n * Give and follow directions & quot; &lt; &lt; endl;
		}
		if (answer == 4)
		{
			cout& lt; &lt; &quot; Curriculum for Year 4 :-1. Reading \n * Know what they like to read and be
				able to choose what’s right for them \n* Recogniseand understand the information in
				different kinds of books \n* Read smoothly, like talking& quot; &lt; &lt; endl;
			cout& lt; &lt; &quot; \n 2. Writing \n * Use their writing to think about, recordand communicate
				experiences, ideasand information \n* Write by themselves for different purposes \n*
				Readand change their writing to improve it, most of the time& quot; &lt; &lt; endl;
			cout& lt; &lt; &quot; \n 3. Maths \n * work with numbers up to 1, 000 \n * Find fractions of sets,
				shapesand quantities \n* Use simple maps to show positionand direction \n* Makeand
				continue patternsand explain the rule for the pattern& quot; &lt; &lt; endl;
		}
		if (answer == 5)
		{
			cout& lt; &lt; &quot; Curriculum for Year 5 :-1. Reading \n * Read for longer periods of time \n*
				Askand answer questions about things that they read& quot; &lt; &lt; endl;
			cout& lt; &lt; &quot; \n 2. Writing \n * Use different ways to think about, planand organise their
				writing \n* Use wordsand phrases that are suitable for the topicand audience \n* Choose
				the best way to express their message or ideas in writing & quot; &lt; &lt; endl;
			cout& lt; &lt; &quot; \n 3. Maths \n * Choose an appropriate method to solve problems(using + ,
				–, x, ÷) and clearly explain their methods to other people \n * Sort 2D and 3D shapes and
				justify how they have been grouped \n * Measure the size and capacity of objects & quot; &lt; &lt; endl;
		}
		if (answer == 6)
		{

			cout& lt; &lt; &quot; Curriculum for Year 6 :-1. Reading \n * Read longer stories more quickly,
				and read for longer periods of time \n* Quickly find important ideasand information by
				‘skimming’and ‘scanning’ \n* Work out words they don’t know the meaning of by using
				clues in the story or pictures and diagrams & quot; &lt; &lt; endl;
			cout& lt; &lt; &quot; \n 2. Writing \n * Choose the type of writing to suit the audience \n * Plan
				what they will write in different ways & quot; &lt; &lt; endl;
			cout& lt; &lt; &quot; \n 3. Maths \n * Solve problems(using + , –, x, ÷) that require them to
				choose the best method \n * Use repeated halving or known multiplication facts to solve
				problems involving fractions \n * Find the value of a given number in a pattern \n * Sort,
				createand identify 2D and 3D shapes & quot; &lt; &lt; endl;
		}
		else
		{
			cout& lt; &lt; &quot; Invalid Output& quot; &lt; &lt; endl;
		}
	} while (answer& lt; 0 || answer & gt; 6);
}