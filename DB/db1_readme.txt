-------------------------------------------------------------------
General info about Computer Science BSc at ELTE: 
           http://csbsc.elte.hu/
You can find here a lot of important information, e.g. Regulations,
Semester Schedule, University Accounts etc.
-------------------------------------------------------------------

Databases I. Lecture and Practices
==================================
Lecture:          Monday   14.00-15.30 North Building 0-81  -> Tibor NIKOVITS
Practice group 1: Monday   16.00-17.30 South Building 2-710 -> Tibor NIKOVITS
Practice group 2: Thursday 10.15-11.45 South Building 2-202 -> Péter LEHOTAY-KÉRY
Practice group 3: Monday   16.00-17.30 South Building 2-107 -> Péter LEHOTAY-KÉRY
Practice group 4: Monday   10.15-11.45 South Building 2-219 -> Tibor NIKOVITS

All the handouts, slides, exercises will be on the homepage.
Start here to find files and topics -> db1_schedule.txt

Lecture requirements
--------------------
Exam at the end of the semester, in the exam period.                           <-- Exam
Attendance is compulsory, it will be controlled.                               <-- Attendance
(If you have any problem, e.g. time conflicts, please let me know about that. 
I will accept what is acceptable concerning attandance.)

Practice requirements (Group 1 and 4)
---------------------
Attendance is compulsory, it will be strictly controlled.                            <-- Attendance
If you miss more than 3 occasions you will not get a practical grade.
There can be compulsory exercises during practices, and if you don't complete        <-- Compulsory exercises
them, it counts as a miss. (see in db1_exercise1.txt, db1_exercise2.txt ...) 
There will be two tests in the semester, a midterm test (7th practice)               <-- 2 tests
and an endterm test (12th practice). 
---> [On Mondays we have only 11 weeks in this semester, so the endterm test will be in the first week of the exam period.]
In the tests you have to write exercises in paper (you will type it into a file) 
and write SQL and PL/SQL programs by computer.
The practical grade (1-5) will be the average of the two test grades.
(e.g. Test1: 3, Test2: 4, Average: 3.5, Final practical grade: 4)
Retake will be in the second week of the exam period.                                 <-- Retake
If you retake a test then the average of the old and new grades will
be your test grade. (e.g. original: 2, retake: 5 --> test grade: 3.5)


Some information about the databases we will use in practices:
=========================================================================
We have two Oracle databases, see below the connect information.
When you connect to the databases from SqlDeveloper, you have to fill in 
the appropriate fields with the following information.

ARAMIS
host: aramis.inf.elte.hu
port: 1521
service_name: aramis

ULLMAN                  
host: ullman.inf.elte.hu                
port: 1521
service_name: ullman

Your username is the same as your Neptun code, you will be informed 
about the initial password in pactical courses.
You should change your Oracle password in the databases with the following SQL statement:
ALTER USER my_username IDENTIFIED BY new_password;

You can use a client software -> SqlDeveloper
You can download it from my homepage: https://people.inf.elte.hu/nikovits/DB1/
The name of the file is something like sqldeveloper*.zip
You can find newer versions of SqlDeveloper, but this is perfect for us.

************************************************
New information !!!
If you are able, please install an Oracle Server Express Edition on your computer.
You can download it from Oracle homepage.
This way you can work on your own computer if the University database is busy or unavailable.
************************************************

!!! Attention !!!
-----------------
ELTE has a firewall, so you can connect to the databases from outside ELTE                   <-- Technical info
domain only with ssh tunneling see details in ssh_tunnel.pdf or ssh_SqlDeveloper.pdf.
=====================================================================================
SOME WORDS ABOUT YOUR ACCOUNTS IN THE UNIVERSITY, JUST TO BE CLEAR !!!

You have several accounts (with passwords) for different computers or services. Let's see them.

1. caesar account (managed by the University, all students of the University have this account)
caesar.elte.hu is a cluster of Linux computers. You can use different services with this account,
e.g. WIFI, homepage, email, login to caesar.elte.hu with ssh connection, etc.
--> https://info.caesar.elte.hu/

2. Neptun account (managed by the University)
You can see your courses and results in Neptun system.

3. inf account (managed by the Faculty of Informatics, only students of the Faculty have this account)
You can login to the computers in the computer laboraties of the Faculty with this account
and you need this account to use Microsoft Teams.

4. database accounts (managed by me, only students attending some special courses have this account)
The passwords in the two databases are independent, so if you change one of them, the other will remain.
I can help you (change or reset your password) only in problems related to your database accounts and not
in problems related to the other 3 accounts.

For ssh tunneling you will need your caesar account (you will need an ssh connection to caesar.elte.hu), 
and of course your database account.
