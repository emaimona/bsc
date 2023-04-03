#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

const std::string entryFileName = "entry.dat";
const std::string applicantsFileName = "applicants.dat";


// Limits of Applications
int MONDAY;
int WEDNESDAY;
int THURSDAY;

//
struct Applicant {
    std::string name;
    std::vector<std::string> daysOfWeek;
};

// ======== UTILS ==========

std::string toUpperCase(std::string &str) {
    for (size_t i=0; i < str.size(); i++) {
        str[i] = std::toupper(str[i]);
    }
    return str;
}

std::string capitalize(std::string &str) {
    if (str == "")
        return "";

    str[0] = toupper(str[0]);
    for (size_t i=1; i < str.size(); i++) {
        str[i] = std::tolower(str[i]);
    }
    return str;
}

// ==========================


std::string getLimits()
{
    std::ifstream entryFile(entryFileName);
    std::string result;

    if (entryFile.is_open()) {
        std:: getline(entryFile, result);
        if (entryFile.is_open()) {
            std:: getline(entryFile, result);
            return result;
        }
        entryFile.close();
    }
    
    return "";
}

void writeLimitsToFile() {
    std::ofstream o_entryFile(entryFileName);
    o_entryFile << "MONDAY WEDNESDAY THURSDAY\n";
    o_entryFile << MONDAY << "," << WEDNESDAY << "," << THURSDAY << "\n";
    o_entryFile.close();
}

void getApplicants(std::vector<Applicant> &list_of_applicants) {
    std::ifstream applicantsFile(applicantsFileName);   
    std::string result;

    if (applicantsFile.is_open()) {
        std:: getline(applicantsFile, result);
        if (applicantsFile.is_open()) {
            std::string line;
            while (getline(applicantsFile, line)) {
                std::stringstream ss(line);
                std::string name;
                std::getline(ss, name, ',');

                std::string day;
                std::vector<std::string> daysOfWorking;
                while (getline(ss, day, ',')) {
                    daysOfWorking.push_back(day);
                }

                Applicant applicant = { name, daysOfWorking };
                list_of_applicants.push_back(applicant);
            }

            applicantsFile.close();
        }
    }
}

void writeApplicantsToFile(std::vector<Applicant> &list_of_applicants) {
    std::ofstream o_applicantsFile(applicantsFileName);
    o_applicantsFile << "NAME DAYS_OF_WORK\n";

    for (auto item: list_of_applicants) {
        o_applicantsFile<< item.name << ",";
        size_t list_size = item.daysOfWeek.size();
        for (size_t i=0; i<list_size-1; i++) {
            o_applicantsFile << item.daysOfWeek[i] << ",";
        }
        o_applicantsFile << item.daysOfWeek[list_size-1] << "\n";
    }

    o_applicantsFile.close();
}

void getConstantsForDays(std::string limits) {
    std::stringstream ss(limits);
    std:: string temp;
    std::getline(ss, temp, ',');
    MONDAY = std::stoi(temp);
    std::getline(ss, temp, ',');
    WEDNESDAY = std::stoi(temp);
    std::getline(ss, temp, ',');
    THURSDAY = std::stoi(temp);
}


bool setVacancy(std::string day) {
    if (day == "Monday" && MONDAY) {
        MONDAY--;
        return true;
    } else if (day == "Wednesday" && WEDNESDAY) {
        WEDNESDAY--;
        return true;
    } else if (day == "Thursday" && THURSDAY) {
        THURSDAY--;
        return true;
    }
    return false;
}

void increaseVacancy(std::string day) {
    if (day == "Monday") {
        MONDAY++;
    } else if (day == "Wednesday") {
        WEDNESDAY++;
    } else if (day == "Thursday") {
        THURSDAY++;
    }
}


// ====== Menu methods ======
void addApplicant(std::vector<Applicant> &list_of_applicants, bool isNew) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string name;
    std::cout << "Enter the " << (isNew ? " " : " new ") << "applicant's name: ";
    std::getline(std::cin, name);

    std::string days;
    std::cout << "Enter the" << (isNew ? " " : " new ") << "day(s) the applicant is available to work (separated by spaces) [Monday Wednesday Thursday]: ";
    std::getline(std::cin, days);

    std::stringstream ss(days);
    std::string day;
    std::vector<std::string> daysOfWorking;

    while (ss >> day) {
        capitalize(day);
        if (setVacancy(day)) {
            daysOfWorking.push_back(day);
        }
    }


    if (daysOfWorking.size()) {
        Applicant applicant = {name, daysOfWorking };
        list_of_applicants.push_back(applicant);
        std::cout <<  "Applicant" << (isNew ? " added " : " updated ") << "successfully on ";
        std::cout << "[ ";
        for (auto elem: daysOfWorking) {
            std:: cout<< elem << " ";
        }
        std::cout << "]"<< std::endl;
    } else {
        std::cout << "There are no vacancies for the days entered. Applicant not added." << std::endl;
    }
}


void deleteApplicant(std::vector<Applicant> &list_of_applicants) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string name;
    std::cout << "Enter the name of the applicant to delete: ";
    getline(std::cin, name);

    bool foundApplicant = false;
    for (auto it = list_of_applicants.begin(); it != list_of_applicants.end(); ++it) {
        if (it->name == name) {
            for (auto day : it->daysOfWeek) {
                increaseVacancy(capitalize(day));
            }

            it = list_of_applicants.erase(it);
            foundApplicant = true;
            std::cout << "Applicant " << name << " removed successfully." << std::endl;

            break;
        }
    }

    if (!foundApplicant) {
        std::cout << "Applicant was not found!" << std::endl;
    }
}


void modifyApplicant(std::vector<Applicant> &list_of_applicants) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string name;
    std::cout << "Enter the name of the applicant to modify: ";
    getline(std::cin, name);

    bool foundApplicant = false;
    for (auto it = list_of_applicants.begin(); it != list_of_applicants.end(); ++it) {
        if (it->name == name) {
            for (auto day : it->daysOfWeek) {
                setVacancy(capitalize(day));
            }
            it = list_of_applicants.erase(it);
            foundApplicant = true;
            addApplicant(list_of_applicants, false);
            break;
        }
    }

    if (!foundApplicant) {
        std::cout << "Applicant was not found!" << std::endl;
    }
}


void listApplicantsByDay(std::vector<Applicant> list_of_applicants) {
    std::string dayOfWeek;
    std::cout << "Enter day of the week to list applicants [Monday Wednesday Thursday]: ";
    std::cin >> dayOfWeek;
    std::cout << "\nApplicants for " << dayOfWeek << ":" << std::endl;

    capitalize(dayOfWeek);
    bool foundApplicant = false;
    for (auto it : list_of_applicants) {
        for (auto day: it.daysOfWeek)
            if (day == dayOfWeek) {
                std::cout << it.name << std::endl;
                foundApplicant = true;
            }
    }

    if (!foundApplicant) {
        std::cout << "No Applicants found for " << dayOfWeek << "!" << std::endl;
    }
}
//============================


void printMenu() {
    std:: cout<< "\n\n========== Drink My Friend Vineyard ==========\n\n \
1. Add applicant\n \
2. Delete applicant\n \
3. Modify applicant\n \
4. List all applicants\n \
5. List applicants by day\n \
6. Show vacancies\n\n \
\
0. Exit\n \
=============================================="<< std:: endl;
}


void showVacancies() {
    std::cout<< "\n\n1\
==================== \
\nAvailable Vacancies \
\n==================== \
\nMonday : " << MONDAY << "\nWednesday : " << WEDNESDAY << "\nThursday : " << THURSDAY << "\n\n"; 

}

void listAllApplicants(std::vector<Applicant> &list) {
    std:: cout<< "\n\n=================== List of all applicants ===================\n \
Name                                   Available Days\n \
-------------------------------------------------------------\n\n";

    for (auto item: list) {
        std:: cout<< item.name << "\t\t\t\t";
        for (auto elem : item.daysOfWeek) {
            std::cout<< elem << " ";
        }
        std:: cout<< std::endl;
    }

    std:: cout<< "-----------------------------------------------------------\n\n";
}





int main()
{
    std::string limits = getLimits();
    std::vector<Applicant> list_of_applicants;

    if (limits.size() == 0)
    {
        std::cout << "An error occurred!" << std::endl;
        return 1;
    }
    
    getConstantsForDays(limits);
    getApplicants(list_of_applicants);

    int option = 0;

    do {
        printMenu();    
        std:: cout<< "Choice: ";
        std:: cin >> option;

        if (option == 1) {
            addApplicant(list_of_applicants, true);
        } else if (option == 2) {
            deleteApplicant(list_of_applicants);
        } else if (option == 3) {
            modifyApplicant(list_of_applicants);
        } else if (option == 4) {
            listAllApplicants(list_of_applicants);
        } else if (option == 5) {
            listApplicantsByDay(list_of_applicants);
        } else if (option == 6) {
            showVacancies();
        }

    } while (option != 0);
    

    writeLimitsToFile();
    writeApplicantsToFile(list_of_applicants);
    return 0;
}