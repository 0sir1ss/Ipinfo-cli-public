#include <iostream>
#include <cpr/cpr.h>
#include <string>
#include <format>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

int main()
{
	std::string ip;
	std::cout << "Input IP Address for lookup: ";
	std::cin >> ip;
	cpr::Response r = cpr::Get(cpr::Url{ "https://ipinfo.io/" + ip + "?token=YOURTOKENHERE" });
	std::string body = r.text;
	json data = json::parse(body);
	std::cout << "IP Address   : " << data["ip"].get<std::string>() << "\n";
	std::cout << "Hostname     : " << data["hostname"].get<std::string>() << "\n";
	std::cout << "Organization : " << data["org"].get<std::string>() << "\n";
	std::cout << "Postcode     : " << data["postal"].get<std::string>() << "\n";
	std::cout << "City         : " << data["city"].get<std::string>() << "\n";
	std::cout << "Region       : " << data["region"].get<std::string>() << "\n";
	std::cout << "Country      : " << data["country"].get<std::string>() << "\n";
	std::cout << "Lat/Long     : " << data["loc"].get<std::string>() << "\n";
	std::cout << "Timezone     : " << data["timezone"].get<std::string>() << "\n";

	return 0;
}