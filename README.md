histogram-and-statics-C
=======================

Originally created for a school assignment in a C programming course. Below is the instruction for the assignment. 

The Program:
Your task is to write a C program that reads a list of marks and prints the following:

The average mark
The standard deviation
The minimum mark
The maximum mark
A text histogram showing the distribution of letter grades
The marks will all be integers between 0 and 100, inclusive. For the histogram, use the letter grade ranges used at Queen's:
    F = 0-49
    D = 50-59
    C = 60-69
    B = 70-79
    A = 80-100
Since we haven't talked about file I/O yet, your program should read the list of marks from the standard input. You can type data directly in while running the program, finishing with a control-D, but the easiest way to test your program is to put a list of marks into an input file and direct that file into the standard input of your program. The sample runs below illustrate this possibility.

Sample Runs:
This putty transcript shows two runs of my solution. Your output doesn't have to look exactly like mine but it should look as similar as possible. In other words, we're not going to take off points if your spacing isn't just like mine, but your output should display the same information in the same order, and your histogram should have the same sort of appearance as mine. There's no set height for the histogram; you should make it as high as necessary for the letter grade with the most marks.

Statistics:
I'm sure everyone knows already that the average of a list of values is their sum divided by the number of values.

To find the standard deviation of a list of N values, find the difference between each value and the average, square each difference, add up all the squares, divide by N-1, and take the square root.

For example, the average of the four values [2,9,6,1] is (2+9+6+1)/4 = 4.5. Their standard deviation is the square root of ((2-4.5)2+(9-4.5)2+(6-4.5)2+(1-4.5)2) divided by 3, which is equal to the square root of ((2.52 + 4.52 + 1.52 + 3.52)/3), or the square root of 41/3, which is approximately 3.7.

Error Handling:
You only need to check for two kinds of errors while reading the input. If the input contains anything other than integer values, write an error message and abort the program. If the input contains fewer than two integer values, you should also write an error message and abort, since you need at least two values to compute a standard deviation.

Your program will need to assume a maximum number of input values. Any values after this in the input should simply be ignored. This maximum number must be at least 20 and you must use a macro for it (i.e. a #define) instead of hard-coding the number into your program.

Using the Math Library:
To compute the standard deviation, you need a square root function. I implemented a square root function in class, but instead of copying mine you should use the sqrt function from the C math library. Include <math.h> in the file that calls sqrt. In addition, whenever you use the math library you must add the flag -lm at the end of your link command (gcc -o program file1.o file2.o .... -lm).

Using Multiple Files:
For full marks, you must split your program up into at least four .c files. In my solution, I used exactly four .c files:

histogram.c: Contains a function that takes an array and an array size as parameters and prints a histogram
readMarks.c: Contains a function that takes an array as a parameter, reads values from the standard input into the array, and returns the number of values read.
statistics.c: Contains functions that take an array and an array size as parameters and return statistics (average, standard deviation, minimum and maximum)
assn6.c: Contains the main function, which calls functions from the other files and prints the statistics.
If you think of a different way to split up the program into files, you may use it, as long as you use at least four .c files and each contains at least one function that performs a non-trivial part of the program.
However you split up your program, you must provide a .h file to go with every .c file, containing header(s) for the functions in the file that will be called from functions in other files. If there are any pre-processor macros (#defines) that need to be used in more than one file, they must be defined in the appropriate .h file.

Using the C Pre-Processor:
Use at least two #define macros somewhere in your program. I've already specified above that one of these must be a limit on the number of marks the program will read in (at least 20). Think of some other way to define and use a #define in your program.

Also, add some debug output to some section of your program so that it will only be printed if the DEBUG macro is defined. In my solution, my debug output was printing the number of marks in each letter grade category immediately before the histogram. You can think of a different kind of debug output if you want.

Build Scripts:
You must write and hand in a bash script called buildAssn6 which performs all of the compilations and a linking step for building your complete program in a version that does not include debug output. Your final executable file must be called assn6. You do not have to write a make file for this assignment; just write a bash script to compile and link everything from scratch.

You must write and hand in a second bash script called buildDebug which performs all of the compilations and a linking step for building your complete program in a version that does include debug output. This should look just like buildAssn6 but with an extra flag in at least one of the compile commands. Your final executable file from this script should also be called assn6.

Style:
You will be marked for your programming style. Good style includes:

A header comment for each file with a brief description of the purpose of the file, and identifying the author(s), the course, the semester and the assignment number
A header comment for each function explaining briefly what it does, what its parameters are for, and what value, if any, it will return.
Meaningful variable names
Clear and consistent indenting
Writing your code in as simple and clear a way as possible.
Comments inside functions if you do anything complicated that would take time for another C programmer to figure out.
You may assume that your program is being read by someone who is familiar with basic C and with basic statistics and histograms. For example, you don't have to write comments explaning what a standard deviation is, or how a printf works.
I'm often asked whether the header comment for a function belongs with its definition in a .c file or its "forward declaration" in a .h file. The answer is both places. It's just a simple cut-and-paste to include these comments twice, and it means that anyone looking at either a .c file or a .h file will see basic information about the purpose of the functions being declared and defined.

The two required bash scripts are short, simple ones, but should still contain header comments similar to the header comments I've asked for above for your C code.

Good style for this program also includes using NO global variables. There will be times later in the course when we need to use globals, but there is no need for them in this program. Your functions should use parameters and return results to communicate with each other.

Example Programs:
If you want to look at examples of small multiple-file C programs, I have put two on the CASLab system for your reference. One is the square root program we discussed in class; its in /cas/course/cisc220/CIntro/squareRootMultipleFiles. The other is a solution to Assignment 6 from Fall 2011 and is in /cas/course/cisc220/CIntro/Fall2011Assn6.

Advice:
If you are feeling uneasy about writing a multiple-file C program, try writing this program in one file and then breaking it up into multiple files, the way I broke up the square root example in class. Save your original one-file program so that if you can't get a multiple file version working you can submit that program for partial credit.

On the other hand, if you understood the example I did in class you can write the program in multiple files from the start.

Either way, don't wait until the last minute. Attend your lab and ask for help if you're having trouble. Remember that it's OK to attend more than one lab and that you don't have to stick to the lab for which you're registered. The only time the TAs will turn any student away from a lab is if there aren't enough seats for everyone, in which case they will give preference to students registered for that lab. In practice, that never happens. I hear that the 8:30 labs are particularly poorly attended, which means the TAs in those labs have lots of time to provide help and support.

Also remember that I have office hours Tuesday through Friday and also usually have time to talk with students after lectures as well.

Finally, make sure to test your program and your scripts. And if you make even a small change, test them again! I often see errors in assignment submissions that would have been quite easy to fix and suspect that the student didn't do enough testing to realise the error was there.

Administrative Information:
You have to hand in a lot of files for this assignment. Make sure not to forget any of them. A complete submission should include:

At least four .c files
At least three .h files (one to go with every .c file except the main file)
Two scripts, called buildAssn6 and buildDebug
That's a total of 9 files. I will set up the Moodle submission area to permit a maximum of 9 files. If you need to submit more than 9 files, or if uploading 9 separate files is a nuisance, another option is to submit a single "zip" file. Here's a simple bash command for creating a zip file of everything you need to hand in:
    zip assn6.zip *.c *.h buildAssn6 buildDebug This command creates the file assn6.zip, which will contain a compressed copy of every other file in the list of arguments. If you decide to create a zip file, please create it in this way instead of creating it with a zip program on your Windows or Mac computer. The zip files from different systems may have slightly different formats, and we need zip files that the TAs can unzip quickly on Linux.
Please use the file names I've asked for for your scripts. Don't combine your files in any other way except a Linux zip file -- no rar files, etc. If you waste TA time by using different file names or formats, we will deduct an administrative point or two from your mark.

Here is the marking scheme for this assignment: 
    basic correctness: 16 
        reading marks and printing statistics: 8 
        printing histograms: 8 
    error handling: 4 
    organizing program using at least 4 modules: 8 
    use of at least 2 #defines: 4 
    conditional debug output: 4 
    two build scripts: 4 
    style: 4 
    total: 44
