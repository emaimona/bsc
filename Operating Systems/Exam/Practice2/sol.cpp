#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <ctime>
#include <random>
#include <cstring>
#include <sys/ipc.h>
#include <sys/msg.h>

// Structure for observation data
struct Observation {
    char observing_personname[100];
    char territory_name[100];
    int rabbit_number;
    char rabbit_age[20];
    time_t observation_time;
};

// Structure for message queue data
struct Message {
    long mtype;
    char mtext[256];
};

int msgqid; // Message queue ID

// Signal handler for child process arrival
void childArrivalSignalHandler(int signum) {
    std::cout << "Child process " << getpid() << " has arrived." << std::endl;
}

// Signal handler for parent process to terminate child process
void terminateChildProcess(int signum) {
    std::cout << "Terminating child process " << getpid() << std::endl;
    exit(0);
}

// Signal handler for child process to receive identification text
void receiveIdentificationSignalHandler(int signum) {
    char identificationText[100];
    std::strcpy(identificationText, "Lion"); // Replace with appropriate identification text

    // Send identification text to parent process using signal or pipe
    // ...

    // Wait for parent process to send confirmation signal
    // ...

    // Write out the identification text
    std::cout << "Child process " << getpid() << " received identification text: " << identificationText << std::endl;

    // Send confirmation signal to parent process
    // ...
}

// Function for child process to perform observations and send data to parent process
void observeRabbits(const char* identificationText) {
    // Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> sleepTimeDistribution(2, 5);

    // Perform observations for a specific duration
    time_t startTime = std::time(nullptr);
    time_t observationDuration = 60; // Observation time in seconds

    while (std::time(nullptr) - startTime < observationDuration) {
        // Simulate observation for a rabbit
        Observation observation;
        std::strcpy(observation.observing_personname, "Observer"); // Replace with observer name
        std::strcpy(observation.territory_name, "Territory"); // Replace with territory name
        observation.rabbit_number = 1; // Replace with actual rabbit number
        std::strcpy(observation.rabbit_age, "Adult"); // Replace with actual rabbit age
        observation.observation_time = std::time(nullptr);

        // Send observation data to parent process using message queue
        Message message;
        message.mtype = 1; // Replace with appropriate message type
        std::memcpy(message.mtext, &observation, sizeof(Observation));

        // Send message to parent process using message queue
        if (msgsnd(msgqid, &message, sizeof(Observation), 0) == -1) {
            perror("Failed to send message to parent process");
            exit(1);
        }

        // Sleep for random seconds before the next observation
        sleep(sleepTimeDistribution(gen));
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <number_of_expeditions> <observation_time>" << std::endl;
        return 1;
    }

    int numExpeditions = std::atoi(argv[1]);
    int observationTime = std::atoi(argv[2]);

    // Create message queue
    key_t key = ftok(".", 'M');
    msgqid = msgget(key, IPC_CREAT | 0666);
    if (msgqid == -1) {
        perror("Failed to create message queue");
        return 1;
    }

    // Set up signal handler for child process arrival
    signal(SIGUSR1, childArrivalSignalHandler);

    // Set up signal handler for parent process to terminate child process
    signal(SIGINT, terminateChildProcess);

    for (int i = 0; i < numExpeditions; ++i) {
        pid_t pid = fork();

        if (pid < 0) {
            std::cerr << "Error creating child process." << std::endl;
            return 1;
        } else if (pid == 0) {
            // Child process code
            std::cout << "Child process " << getpid() << " created." << std::endl;

            // Send arrival signal to parent process
            kill(getppid(), SIGUSR1);

            // Set up signal handler for child process to receive identification text
            signal(SIGUSR2, receiveIdentificationSignalHandler);

            // Wait for termination signal from parent process
            while (true) {
                // ...
            }

            return 0;
        }
    }

    // Wait for arrival signals from all child processes
    for (int i = 0; i < numExpeditions; ++i) {
        pause(); // Wait for arrival signal from child process
    }

    // Send identification text to child processes
    // ...

    // Wait for confirmation signals from child processes
    // ...

    // Start observations in child processes
    for (int i = 0; i < numExpeditions; ++i) {
        observeRabbits("Lion"); // Replace with appropriate identification text for each expedition
    }

    // Receive observation data from child processes and save to the database
    Message receivedMessage;
    while (msgrcv(msgqid, &receivedMessage, sizeof(Observation), 0, IPC_NOWAIT) != -1) {
        Observation observation;
        std::memcpy(&observation, receivedMessage.mtext, sizeof(Observation));

        // Save observation data to the database
        // ...
    }

    // Terminate child processes randomly (optional)
    // ...

    // Wait for all child processes to terminate
    for (int i = 0; i < numExpeditions; ++i) {
        wait(NULL);
    }

    // Cleanup message queue
    if (msgctl(msgqid, IPC_RMID, NULL) == -1) {
        perror("Failed to remove message queue");
    }

    return 0;
}
