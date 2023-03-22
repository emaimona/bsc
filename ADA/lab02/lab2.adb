with Ada.Text_IO, Ada.Strings.Fixed;
use Ada.Text_IO, Ada.Strings.Fixed;

package body lab2 is

    function addDigits(num : Natural) return Natural is 
        val, res : Natural := 0;
    begin
        val := num;
        while val /= 0 loop
            res := res + (val mod 10);    
            val := val / 10;    
        end loop;
        return res;
    end addDigits;



    function dividesby9(num: Natural) return Boolean is 
        val : Natural;
    begin
        val := addDigits(num);
        if val mod 9 = 0 then
            return true;
        else
            return false;
        end if;
    end dividesby9;

    -- 
    function isPerfect(num: Natural) return Boolean is 
        sum : Natural := 0;
    begin

        for i in 1..num-1 loop
            if num mod i = 0 then
                sum := sum + i;
            end if;
        end loop;

        return sum = num;
    end isPerfect;


    --
    procedure findPerfects is 
    begin 
        for i in 1..10000 loop
            if isPerfect(i) then
                Put(" " & Natural'Image(i));
            end if;
        end loop;
        Put_Line("");
    end findPerfects;


    --
    function reverseNum(num: Natural) return Natural is 
        rev : Natural := 0;
        old : Natural := num;
    begin

        while old /= 0 loop
            rev := rev * 10 + old mod 10;
            old := old / 10;
        end loop;
        
        return rev;
    end reverseNum;


    --
    function isPalindrome(num: Natural) return Boolean is 

    begin
        return num = reverseNum(num);
    end isPalindrome;


    -- 
    function nthPower(base, exp : Natural) return Natural is
        res : Natural := 1;
    begin
        if exp = 0 then
            return 1;
        end if;

        for i in 1..exp loop
            res := res * base;
        end loop;

        return res;
    end nthPower;


    -- 
    function factorial(num : Positive) return Positive is
    begin
        if num = 1 then 
            return 1;
        end if;

        return num * factorial(num - 1);
    end factorial;

end lab2;