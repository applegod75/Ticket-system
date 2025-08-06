#include <iostream>
#include <iomanip>
#include <string>
// yes, I know I made an entire file just for the help page, but that's just to make formatting easier.

void PrintHelp() {
	std::cout << "TicketSystem" << '\n' << '\n';


	std::cout << "Usage: " << '\n';
	std::cout << '\t' << "TicketSystem [enter] [subcommand] [value]" << '\n' << '\n';

	std::cout << "subcommands: " << '\n';
	std::cout << '\t' << "generate: " << std::setw(60) << "generates the amount of ticket hashes in the value" << '\n';
	std::cout << '\t' << "generate-fast: " << std::setw(97) << "generates the amount of ticket strings in the value. Faster, but less secure than \"generate\"" << '\n';
	std::cout << '\t' << "check: " << std::setw(59) << "Checks whether the value exists in tickets.txt" << '\n';
	std::cout << '\t' << "help:" << std::setw(39) << "prints this help message" << '\n';
}