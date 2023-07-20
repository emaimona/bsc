rem   This is an sql autoconfig file that runs at sqlplus startup.
rem   Upload this file into the directory where you start sqlplus.
rem   ============================================================

rem   Login to pandora.inf.elte.hu with ssh.
rem   Use your inf credentials (that you use in MS Teams)
rem   Start sqlplus with the following syntax:
rem   sqlplus username/password@ullman.inf.elte.hu:1521/ullman
rem   or
rem   sqlplus username/password@aramis.inf.elte.hu:1521/aramis
rem   Below you can see some settings, read SQLPLUS user's guide and change them if needed.

define _editor = vi
set sqlcontinue "> "
set sqlprompt "SQL> "
set sqlterminator ";"
set suffix "sql"
set trimout ON
set underline '='
set null ""
set linesize 120
set pause "<Press Enter>"
set pause on
set pagesize 50
column ename format a10
column job format a10
column dnev format a10
column foglalkozas format a12
column nev format a10
column gyumolcs format a10
column name format a10
column fruits format a10
column dname format a12
column loc format a10
column onev format a12
column telephely format a12
column first_name format a12
column last_name format a12
column email format a10
column phone_number format a15
column job_id format a10
column department_name format a20
alter session set nls_date_format="yyyy.mm.dd";
