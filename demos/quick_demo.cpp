#include <stdexcept>

#include "dave_logs/dave_logs.h"

class ControlBoard {
  public:
	ControlBoard(int b) {
		LOG_TRACE("Constructor called with b = " << b << ", at = " << this);
		if (b < 0)
			throw std::invalid_argument("Negative value not allowed");
		//...

		/* elapsed_time.start() */
	}

	void setup_config() {
		LOG_DEBUG("Loading configuration files...")

		//...
	}

	void connect_to_database() {
		LOG_INFO("Attempting to connect to the database...")

		//...

		LOG_WARNING("Connection took longer than expected, retrying...")
	}

	void start_server() {
		LOG_ERROR("Failed to bind to port 8080. Is it already in use?")

		//...

		if (/* elapsed_time.get() > */ 30) {
			LOG_CRITICAL("Unable to start server. Exiting application.")
		}
	}

	~ControlBoard() {
		LOG_TRACE("Destructor called for object at " << this)
	}
};

int main(int argc, char const* argv[]) {
	try {
		ControlBoard control_board_one(-1);
	} catch (std::exception& e) {
		LOG_CRITICAL(e.what())	// you may optionally opt to log this permanently.
	}

	ControlBoard ctrl_board_one(5);

	ctrl_board_one.setup_config();
	ctrl_board_one.connect_to_database();
	ctrl_board_one.start_server();

	return 0;
}
