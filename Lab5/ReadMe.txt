Lab 5 Readme


Additional MacroCommand we made: ted
	stands for touch edit display. calls touch then cat then display all at once when creating a file
ted hi.txt
	this content is being written to file
	:wq
	>this content is being written to file

ExtraCredit: We implemented chmod

test commands we ran:
touch hi.txt
ls
cat hi.txt
cat hi.txt -a
rn hi.txt hello
cp hi.txt hey

help
help ds
help touch
etc

touch pass.txt -p
enter password: 1234
cat pass.txt
	this is text going into file
	:wq
	Enter file password: 1234
	(if password is not successfully entered the file is not saved)
ds pass.txt
enter file password
1234
	this is text going into file
 

touch image.img
cat image.img
    X  X  X  X  4
ds image.img
ds image.img -d

ted test.txt
hello
hello

touch text.txt
chmod text.txt -
cat text.txt
	hello hello
	:wq
	This file is read-only
chmod text.txt +
cat text.txt
	hello hello
	:wq
ds text.txt
	hello hello



Errors we ran into in the process (All fixed now):
rn hi.txt hello
	closes program
	this was before we successfully implemented macrocommands as other macros would make it crash
rn hi
	closes program
touch -p hi
	used to create broken file -p hi that was listed in ls
	fixed by making sure -p is after file name, and that file name has an extension

cat hi.txt
	when i enter data and :wq it doesn't quit
	this was due to it needing a password but not prompting, and was fixed

for ds hi.txt when password is inputted it displays but should ask for password

rn and cp messes up ls formating, making them together with no space
	we fixed by editing width value

When password inputted it works but it also prints the message "command not found" because it thinks its a command
It thought the next input was "" and the prompt would run twice for no reason.
	we fixed this issue by flushing cin after the password is read in

