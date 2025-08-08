#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "FileHandling.h"

void PrintHelp();
std::string SHA256(const std::string& input);
std::vector<std::string> TicketGenerator(int amount);
std::string cmd1;
std::string cmd2;
int amount;

int main() {

	std::cin >> cmd1;
	if (cmd1 == "generate") {
		std::cin >> amount;
		WriteTickets(amount);
	}
	if (cmd1 == "generate-fast") {
		std::cin >> amount;
		WriteTicketsFast(amount);
	}
	if (cmd1 == "check-cfg") {
		if (CheckCfg()) {
			rewriteCfg();
		}
	}
	if (cmd1 == "add-cfg") {
		std::cin >> cmd2;
		if (CheckCfg()) {
			rewriteCfg();
			AppCfg(cmd2);
		}
	}
	if (cmd1 == "check") {
		std::cin >> cmd2;
		if (ReadTicket(cmd2)) {
			std::cout << "ticket found";
			return 0;
		}
		std::cout << "ticket not found";
	}
	if (cmd1 == "help") {
		PrintHelp();
	}
	return 0;
}