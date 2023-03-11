with Ada.Text_IO;
use Ada.Text_IO;

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
    function reverse(str: String) return String is 
        newStr : String := ""
    begin


    end reverse;


    --
    function isPalindrome(num: Natural) return Boolean is 

    begin

    end isPalindrome;

end lab2;