with ada.text_io, ada.integer_text_io;
use ada.text_io, ada.integer_text_io;

procedure demo is 
    task some_task is
        entry print (num : in integer);
    end some_task;

task body some_task is
begin
select
accept print (num : in integer) do
put(num);
end print;
or
delay (0.0);
Put("kkk");
end select;
end some_task;


begin
    some_task.print(10);

end demo;