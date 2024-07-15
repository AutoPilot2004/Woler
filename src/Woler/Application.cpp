#include "Application.h"

#include <iostream>
#include <vector>

#include <Sock/Socket/Socket.h>
#include <Sock/Parse.h>

using MacAddrs = std::vector<Sock::MacAddr>;

namespace
{
	void print_usage()
	{
		std::cout << "USAGE: " << TARGET_NAME << " mac1 [mac2...]\n";
	}

	MacAddrs parse_cli_args(int argc, char** argv)
	{
		MacAddrs res;

		for (int i = 0; i < argc; i++) {
			res.push_back(Sock::parse_mac(argv[i]));
		}

		return res;
	}

	void fill_16_macs(unsigned char* destStart, Sock::MacAddr mac)
	{
		for (int i = 0; i < 16; i++) {
			std::memcpy(destStart + (i * 6), mac.byte, Sock::MacAddr::BYTE_SIZE);
		}
	}
}

namespace Application
{
	void run(int argc, char** argv)
	{
		argc--;
		argv++;

		if (argc < 1) {
			print_usage();
			return;
		}

		MacAddrs ma = parse_cli_args(argc, argv);
		Sock::MacAddr ffma = Sock::parse_mac("ff-ff-ff-ff-ff-ff");
		constexpr auto ms = Sock::MacAddr::BYTE_SIZE;

		unsigned char bytes[ms * 17];
		std::memcpy(bytes, ffma.byte, ms);

		Sock::DatagramIPv4Socket s;
		s.set_opt(Sock::OptLevel::SOCKET, Sock::OptName::BROADCAST, true);
		s.bind({
			.af   = Sock::AF::IPv4,
			.ip   = "0.0.0.0",
			.port = 0
		});

		Sock::Addr sendAddr{
			.af   = Sock::AF::IPv4,
			.ip   = "255.255.255.255",
			.port = 9
		};

		for (size_t i = 0; i < ma.size(); i++) {
			fill_16_macs(bytes + 6, ma.at(i));

			s.send_to(bytes, sizeof(bytes), sendAddr);
		}
	}
}