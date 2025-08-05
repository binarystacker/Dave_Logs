#include "dave_logs/dave_logs.h"

int main(int argc, char const* argv[]) {

	LOG_TRACE("This is tracelog")
	LOG_DEBUG("Debugging log comes as a plus one")
	LOG_INFO("info log third wheeling here")
	LOG_WARNING("Warning log also comes uninvited")
	LOG_ERROR("Error log eve drops on the prarty")
	LOG_CRITICAL("Critical log ruins the party, party over.");

	return 0;
}
