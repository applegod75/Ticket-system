#include<vector>
#include<string>
#include<fstream>
#include <chrono>
#include <iostream>

std::vector<std::string> TicketGeneratorFast(int amount);
std::vector<std::string> TicketGenerator(int amount);
std::vector<std::string> Tickets;
std::vector<std::string> FullConfig;
std::string cfgCheck;
int cfgChecker;
bool rewritecfg = false;
void rewriteCfg();
void CheckFileNames();
void RmCfgDupes();

void WriteTickets(int amount) {
	std::ofstream writer("tickets.tckt");
	auto start = std::chrono::high_resolution_clock::now();
	Tickets = TicketGenerator(amount);

	for (int i = 0; i < Tickets.size(); i++) {
		writer << Tickets[i] << '\n';
	}
	writer.close();
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "operation took about " << duration.count() / 1000 << " millisecond(s)";
	return;
}

bool ReadTicket(std::string hash){
	std::string ReadHash;
	std::ifstream reader("tickets.tckt");
	while (std::getline(reader, ReadHash)) {
		if (ReadHash == hash) {
			return true;
		}
	}
	return false;
}

void WriteTicketsFast(int amount) {
	std::ofstream writer("tickets.tckt");
	auto start = std::chrono::high_resolution_clock::now();
	Tickets = TicketGeneratorFast(amount);

	for (int i = 0; i < Tickets.size(); i++) {
		writer << Tickets[i] << '\n';
	}
	writer.close();
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "operation took about " << duration.count() / 1000 << " millisecond(s)";
	return;
}

bool CheckCfg() {
	std::ifstream configCheck("config.cfg");
	if (configCheck.fail()) {
		std::cerr << "config not found, creating config.cfg";
		rewriteCfg();
		return false;
	}
	while (std::getline(configCheck, cfgCheck)) {
		FullConfig.push_back(cfgCheck);
		if (FullConfig.size() > 1) {
			rewritecfg = true;
		}
	}
	if (rewritecfg == true) {
		configCheck.close();
		return true;
	}
	configCheck.close();
	return false;
}

void rewriteCfg() {
	std::ofstream config("config.cfg");
	if (not FullConfig.empty()) {
		CheckFileNames();
		RmCfgDupes();
		for (int i = 0; i < FullConfig.size(); i++) {
			config << FullConfig[i] << '\n';
		}
		config.close();
		return;
	}
	config.close();
	return;
}

void CheckFileNames() {
	std::ifstream inspector;
	for (int i = 0; i < FullConfig.size(); i++) {
		inspector.open(FullConfig[i]);
		if (inspector.fail()) {
			FullConfig.erase(FullConfig.begin() + i);
			i--;
			inspector.close();
		}
		inspector.close();
	}
}

bool CheckFile(std::string filename) {
	std::ifstream inspector;
	inspector.open(filename);
	if (inspector.fail()) {
		inspector.close();
		return false;
	}
	inspector.close();
	return true;
}

void AppCfg(std::string filename) {
	std::fstream append("config.cfg", std::ios::app);
	if (CheckFile(filename)) {
		append << filename;
		append.close();
		return;
	}
	std::cout << "File not found";
}

void RmCfgDupes() {
	for (int i = 0; i < FullConfig.size(); i++) {
		for (int j = i + 1; j < FullConfig.size(); j++) {
			if (FullConfig[i] == FullConfig[j]) {
				FullConfig.erase(FullConfig.begin() + j);
			}
		}
	}
}