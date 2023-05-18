with text_io; use text_io;
procedure Shoe is

	task sand is 
		entry L;
		entry R;
	end Sand;

	task Left;
	task Right;

	task body Sand is 
		steps : Natural := 0;
	begin
		loop
		select when steps < 10 =>
			accept L;
			Put_Line("Left");

			accept R;
			Put_Line("Right");
			steps := steps + 2;
		or 
			terminate;
		end select;
		end loop;
	end Sand;

	task body Left is 
	begin
		for i in POSITIVE'range loop
			Sand.L;
		end loop;
	end Left;

	task body right is 
	begin
		for i in POSITIVE'range loop
			Sand.R;
		end loop;
	end Right;
begin
	null;
	--  a.Init("John"); b.Init("Mary");
end Shoe;