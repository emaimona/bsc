#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

//* C libraries
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <sys/types.h> 
#include <cstdio> 
#include <cstdlib> 
#include <csignal>
#include <cstring> 
#include <unistd.h> 
#include <sys/wait.h> 


using namespace std;
const std::string entryFileName = "entry.dat";
const std::string applicantsFileName = "applicants.dat";


// Limits of Applications
int MONDAY;
int WEDNESDAY;
int THURSDAY;

#define MAX_NUMBER_OF_WORKERS 10
#define MAX_STRING_LENGTH 1600000

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
6. Show vacancies\n \
7. Run Buses\n\n \
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




//* SECOND PART OF THE HOMEWORK

void handler(int signumber){

    if (SIGUSR1 == signumber) {
         cout<< "Bus 1 has arrived!\n";
    } else if (SIGTERM == signumber) {
         cout<< "Bus 2 has arrived!\n";
    }
       
}


string serialize(vector<string> list, int start, int end) {
    string res = "";
    for (int i = start; i<end; i++) {
        if (i == end-1)
            res += list[i];
        else
            res += list[i] + ",";
    }
    return res;
}

vector<string> deserialize(string joinedNames) {
    std::vector<std::string> result;
    std::string delimiter = ",";
    size_t pos = 0;
    std::string token;
    while ((pos = joinedNames.find(delimiter)) != std::string::npos)
    {
        token = joinedNames.substr(0, pos);
        result.push_back(token);
        joinedNames.erase(0, pos + delimiter.length());
    }
    result.push_back(joinedNames);

    return result;
}

void printNames(vector<string> names) {
    int c = 0;
    for (auto i: names) {
        cout<<"\t"<< ++c << " - "<< i << endl;
    }
}

void handle_signal(int sig) {
    // Do nothing, just catch the signal
}

struct messg { 
     long mtype;
     int mtext;
}; 

// sendig a message
int send(int mqueue, int val ) 
{ 
     const struct messg m = {5, val }; 
     int status = msgsnd( mqueue, &m, sizeof(m) , 0 ); 
     if ( status < 0 ) 
          perror("msgsnd error"); 
     return 0; 
} 
     
// receiving a message. 
int receive(int mqueue) 
{ 
     struct messg m; 
     int status; 
     status = msgrcv(mqueue, &m, sizeof(m), 5, 0 ); 
     if ( status < 0 ) 
          perror("msgsnd error"); 
     else
        cout<< "Parent sent summary message with count = " <<  m.mtext << endl; 
     return 0; 
} 



void runBuses(std::vector<Applicant> list_of_applicants, char* argv) {
    std::string dayOfWeek;
    std::cout << "Enter day of the week to process the applications [Monday Wednesday Thursday]: ";
    std::cin >> dayOfWeek;
    // std::cout << "\nApplicants for " << dayOfWeek << ":" << std::endl;

    vector<string> applicantNames;

    capitalize(dayOfWeek);
    bool foundApplicant = false;
    for (auto it : list_of_applicants) {
        for (auto day: it.daysOfWeek)
            if (day == dayOfWeek) {
                // std::cout << it.name << std::endl;
                applicantNames.push_back(it.name);
                foundApplicant = true;
            }
    }

    if (!foundApplicant) {
        std::cout << "No Applicants found for " << dayOfWeek << "!" << std::endl;
        std::cout << "The buses are not working on " << dayOfWeek << "!" << std::endl;
    } else {

        int fd[2]; // file descriptors for the pipe
        pipe(fd);

        int messg, status; 
        key_t key = ftok(argv,1);
        printf ("\nThe key: %d\n",key);
        messg = msgget( key, 0600 | IPC_CREAT ); 
        if ( messg < 0 ) { 
          perror("msgget error 1"); 
          exit(EXIT_FAILURE); 
        } 
        pid_t pid;
        
        pid = fork();
        if (pid < 0) {
            perror("Error processing the buses!");
            exit(EXIT_FAILURE);
        } 
        
        if (pid > 0) {
            
            close(fd[1]); // close write end of pipe
         
            cout<< "Parent waits 3 seconds for the arrival of the first bus"<< endl;
            sleep(3);

            char buffer[MAX_STRING_LENGTH];
            if (read(fd[0], buffer, MAX_STRING_LENGTH) > 0) {
                cout<< " ::-> Bus '1' has arrived with the worker(s): \n";
                vector<string> names = deserialize(buffer);
                printNames(names);
                send( messg, names.size()); 
            } else {
                cout<< " ::-> Bus '1' has arrived with the worker(s): \n";
            }

            kill(pid, SIGUSR1);


            sleep(2);
            cout<< "Parent waits 3 seconds for the arrival of the Second bus"<< endl;
            sleep(3);

            if (read(fd[0], buffer, MAX_STRING_LENGTH) > 0) {
                cout<< " ::-> Bus '2' has arrived with the worker(s): \n";
                vector<string> names = deserialize(buffer);
                printNames(names);

                close(fd[0]);
                send( messg, names.size()); 
            } else {
                cout<< " ::-> Bus '2' has arrived with no worker(s): \n";
                // cerr<<"Error reading the second message";
                send(messg, 0);
            }

            wait(NULL);
            status = msgctl( messg, IPC_RMID, NULL ); 
            if ( status < 0 ) 
                perror("msgctl error");
        } else {
            close(fd[0]);

            int nbrOfWorkers = applicantNames.size() <= 5 ? applicantNames.size() : 5; 
            int i = 0;

            cout<< "Bus '1' is ready to send " << nbrOfWorkers <<" worker(s)!" << endl;
            string message1 = serialize(applicantNames, 0, nbrOfWorkers);

            write(fd[1], message1.data(), strlen(message1.data())+1); // write each string to the pipe

              // Set up signal handler for SIGUSR1
            struct sigaction sa;
            memset(&sa, 0, sizeof(sa));
            sa.sa_handler = handle_signal;
            sigaction(SIGUSR1, &sa, NULL);

            // Wait for signal to write message 2 to pipe
            pause();
            receive(messg); 
            int workersLeft = applicantNames.size() - nbrOfWorkers;

            if (workersLeft <= 0)
                cout<< "\nBus 2 is Empty!" << endl;
            else
                cout<< "\nBus '2' is ready to send "<< (workersLeft > 5 ? 5 : workersLeft) << " worker(s)!" << endl;
            

            if (workersLeft > 0) {
                string message2 = serialize(applicantNames, nbrOfWorkers, (workersLeft > 5) ? nbrOfWorkers+5 : applicantNames.size());
                write(fd[1], message2.data(), strlen(message2.data())+1); // write each string to the pipe
            }


            close(fd[1]); // close write end of pipe
            receive(messg); 
            exit(EXIT_SUCCESS);
        } 

    }
}



int main(int argc, char* argv[])
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
        } else if (option == 7) {
            runBuses(list_of_applicants, argv[0]);
        }

    } while (option != 0);
    

    writeLimitsToFile();
    writeApplicantsToFile(list_of_applicants);
    return 0;
}