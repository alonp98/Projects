#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <cstdlib>

using namespace std;


float wageType(int role, float wage);
float dailySalary(int shiftType, float hours, float wage);
std::string currentDate();
void saveData(float totalSalary);
float readMonthlyData();
string currentMonth();
void dailyCalculator();


int main() {
    int choice;
    cout << "Hi!" << endl << "What Would You Like To Do Today?: " << endl;
    cout << "1 --> Calculate & Register A New Shift" << endl;
    cout << "2 --> Calculate How Much Money I Made This Month" << endl;
    cout << "3 --> Exit" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            dailyCalculator();
            main();
            break;
        case 2:
            cout << readMonthlyData() << endl;
            main();
            break;

        case 3:
            exit(0);

        default:
            cout << "Wrong Input, Please Try Again!" << endl;
            main();
    }
}

// Choose the wage from 3 options
float wageType(int role, float wage) {
    switch (role) {
        case 1:
            wage = 40.64;
            break;

        case 2:
            wage = 41.64;
            break;

        case 3:
            wage = 46.14;
            break;

        default:
            break;
    }
    return wage;
}

float dailySalary(int shiftType, float hours, float wage) {
    float finalSalary = 0;

    // Shift Types
    //	1 --> Regular
    //	2 --> Night Shift
    //	3 --> Saturday Morning
    //	4 --> Friday Night
    //	5 --> Friday Noon
    //	6 --> Saturday Noon

    switch (shiftType) {

        case 1: // Regular Shift, Overtime starts after 8 hours
            if (hours <= 8) {
                finalSalary = (wage * hours);
            } else if (hours > 8 && hours <= 10) {
                finalSalary = (wage * 8) + (wage * 1.25 * 2) + (wage * 1.25 * (hours - 8));
            } else {
                finalSalary = (wage * 8) + (wage * 1.25 * 2) + (wage * 1.5 * (hours - 10));
            }
            break;

        case 2: // Night Shift, overtime starts after 7 hours
            if (hours <= 7) {
                finalSalary = (wage * hours);
            } else if (hours > 7 && hours <= 9) {
                finalSalary = (wage * 7) + (wage * 1.25 * (hours - 7));
            } else
                finalSalary = (wage * 7) + (wage * 1.25 * 2) + (wage * 1.5 * (hours - 9));
            break;

        case 3: // Saturday Morning (the whole shift is in overtime)
            if (hours <= 8) {
                finalSalary = (wage * hours * 1.5);
            } else if (hours > 8 && hours <= 10) {
                finalSalary = (wage * 8 * 1.5) + (wage * 1.75 * (hours - 8));
            } else
                finalSalary = (wage * 8 * 1.5) + (wage * 1.75 * (hours - 8));

            break;

        case 4: // Friday Night (the whole shift is in overtime salary + bonuses starts after 7 hours)
            if (hours <= 7)
                finalSalary = (wage * hours * 1.5);
            else if (hours > 7 && hours <= 9)
                finalSalary = (wage * 7 * 1.5) + ((wage * (float) (hours - 7)) * 1.75);
            else
                finalSalary = (wage * 7 * 1.5) + (wage * 2 * 1.75) + (wage * (hours - 10) * 2);

            break;

        case 5: // Friday Noon (2.75 hours is in regular wage, after that bonus starts)
            if (hours == 6.75)
                finalSalary = (wage * 2.75) + (wage * 4 * 1.5);

            else if (hours == 7.75)
                finalSalary = (wage * 2.75) + (wage * 5 * 1.5);

            break;

        case 6: // # Saturday Noon (2.75 hours is in overtime wage, after that regular)
            if (hours == 6.75)
                finalSalary = (wage * 1.5 * 2.75) + (wage * 4);

            else if (hours == 7.75)
                finalSalary = (wage * 1.5 * 2.75) + (wage * 5);

            break;

        default:
            break;
    }

    return finalSalary;
}

string currentDate() {
    time_t now = time(NULL);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d-%m-%Y", &tstruct);

    return buf;

}

void saveData(float totalSalary) {
    ofstream outFile("Shifts.txt", ios::app);
    outFile << currentDate() << " " << totalSalary << endl;
}

string currentMonth() {
    string month = currentDate();
    if (string(1, month[3]) == "0") {
        if (string(1, month[4]) == "1") return {"01"};
        if (string(1, month[4]) == "2") return {"02"};
        if (string(1, month[4]) == "3") return {"03"};
        if (string(1, month[4]) == "4") return {"04"};
        if (string(1, month[4]) == "5") return {"05"};
        if (string(1, month[4]) == "6") return {"06"};
        if (string(1, month[4]) == "7") return {"07"};
        if (string(1, month[4]) == "8") return {"08"};
        if (string(1, month[4]) == "9") return {"09"};
    }
    if (string(1, month[3]) == "1") {
        if (string(1, month[4]) == "1") return {"11"};
        if (string(1, month[4]) == "1") return {"12"};
    }
    return NULL;
}

float readMonthlyData() {
    ifstream inFile("Shifts.txt", ios::in);
    if (inFile.is_open()) {
        string line;
        string month = currentMonth();
        string comparedMonth;
        float temp;
        float monthlySalary = 0;
        while (true) {
            getline(inFile, line, '-');
            getline(inFile, comparedMonth, '-');
            getline(inFile, line, ' ');
            if (comparedMonth == month) {
                inFile >> temp;
            }
            if (inFile.eof()) break;
            monthlySalary += temp;
        }
        return monthlySalary;
    }
    cout << "No Shifts File Generated, Please Save Some Shifts First" << endl;
    return 0;
}

void dailyCalculator() {
    int shiftType, role;
    float hours, wage = 0, finalSalary;
    cout << "How Many Hours Have You Worked Today? " << endl;
    cin >> hours;
    cout << "What Role Have You Worked In Today? Choose One (1 / 2 / 3) " << endl;
    cout << "1 - Guard - 40.64₪" << endl;
    cout << "2 - Operations Controller - 41.74₪" << endl;
    cout << "3 - Team Leader - 46.14₪" << endl;
    cin >> role;
    cout << "What Type Of Shift Have You Worked? " << endl;
    cout << "1 --> Regular" << endl << "2 --> Night Shift" << endl << "3 --> Saturday Morning" << endl
         << "4 --> Friday Night" << endl << "5 --> Friday Noon" << endl << "6 --> Saturday Noon" << endl;
    cin >> shiftType;

    wage = wageType(role, wage);
    finalSalary = dailySalary(shiftType, hours, wage);

    cout << "You Got Today " << finalSalary << "₪" << endl;
    cout << "Please Choose One Of The Following Options: " << endl;
    cout << "1 --> Save The Shift" << endl;
    cout << "2 --> Return To Main Menu" << endl;
    cout << "3 --> Exit" << endl;
    int save_or_exit;
    cin >> save_or_exit;
    if (save_or_exit == 1) {
        saveData(finalSalary);
        cout << "Data Saved Successfully!!" << endl;
        main();
    }
    if (save_or_exit == 2) {
        main();
    }
    if (save_or_exit == 3) {
        exit(0);
    }
}
