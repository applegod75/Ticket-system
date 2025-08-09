# Ticket system
a simple ticketing system.

# important:
make sure you do ***NOT*** run the application without having backed up your ticket-containing files, as it overwrites them as soon as you use the "generate" command.

# inner workings

## generate:

this generates the amount of ticket values that you add after the command, and writes them to a file.

This function works by first generating a random string (with characters 'A-Z', 'a-z', and '1-9') of a random size (you can never be too random), and then encoding it into an SHA256 hash. It then writes this hash to a file. <br>
Due to this function having to compute an SHA256 hash, it is pretty slow. To compensate for this, I added the "generate-fast" function.

## generate-fast:

this generates the amount of tickets you add in the value, and writes them to a file, with a faster algorithm then "generate".

This function works by just generating a random string with a length of 32. It is about 7-8 times faster then "generate", but less secure because there is no such thing as absolute randomness, it is predictable in computing.

## check:

This checks if the hash you give it is in the "tickets.tckt" file, that's it.

## add-cfg:

This adds a filename to the config file. <br>

- the function works by first checking if the cfg exists, if it does, it checks all filenames inside, to see if they exist, then checks for duplicates, and then rewrites the file.
- then it appends the filename you gave to the funtion, if the file exists.

## help:

Brings up a simple help page, doesn't support specific commands yet.

# roadmap

from here, I want to make this application better over time, so here is some of the tings I want to add to the application.

## QR code generation

- I want to allow anyone using this application to be able to quickly turn a ticket hash into a (png of a) QR code.

## multiple ticket-containing files

I want to allow people to add multiple files to keep their tickets in.

- The application will save these files in a .cfg file.
- It will only ask what file to use if there are multiple files, or if there is already text in tickets.txt.
- It will also be able to check specific files when using "check"

## safe mode

I want to add a safe mode that keeps the application running, and never closes the file it's writing to.

- This makes it so that it will always append to the file, and doesn't overwrite it, <br>
as long as you keep the command line instance open.

The downside to this is that it will be inefficient.

# important notes:

## OpenSSL

This program uses OpenSSL. If you wish to build this yourself, you have to install the **full** version of OpenSSL.

## SHA256 function

I did not code the SHA256 function myself. I'm not smart enough for that, chatgpt did that. All of the other code was written by me.
