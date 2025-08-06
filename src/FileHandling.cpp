#include<vector>
#include<string>
#include<fstream>
#include <chrono>
#include <iostream>

std::vector<std::string> TicketGeneratorFast(int amount);
std::vector<std::string> TicketGenerator(int amount);
std::vector<std::string> Tickets;

void WriteTickets(int amount) {
	std::ofstream writer("tickets.txt");
	auto start = std::chrono::high_resolution_clock::now();
	Tickets = TicketGenerator(amount);

	for (int i = 0; i < Tickets.size(); i++) {
		writer << Tickets[i] << '\n';
	}
	writer.close();
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "operation took about " << duration.count() / 1000000 << " second(s)";
	return;
}

bool ReadTicket(std::string hash){
	std::string ReadHash;
	std::ifstream reader("tickets.txt");
	while (std::getline(reader, ReadHash)) {
		if (ReadHash == hash) {
			return true;
		}
	}
	return false;
}

void WriteTicketsFast(int amount) {
	std::ofstream writer("tickets.txt");
	auto start = std::chrono::high_resolution_clock::now();
	Tickets = TicketGeneratorFast(amount);

	for (int i = 0; i < Tickets.size(); i++) {
		writer << Tickets[i] << '\n';
	}
	writer.close();
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "operation took about " << duration.count() / 1000000 << " second(s)";
	return;
}