# Ticket system
a simple ticketing system that writes to, and reads from tickets.txt

# important:
make sure you do ***NOT*** run the application without having backed up the tickets.txt file, as it overwrites it as soon as you use the "generate" command.

# inner workings

## generate:

this generates the amount of ticket values that you add after the command, and writes them to a file.

This function works by first generating a random string (with characters 'A-Z', 'a-z', and '1-9') of a random size (you can never be too random), and then encoding it into an SHA256 hash. It then writes this hash to a file.

## check:

This checks if the hash you give it is in the "tickets.txt" file, that's it.

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
