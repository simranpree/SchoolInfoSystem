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
