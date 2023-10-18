#include "shell.h"

/**
  * signal_handler - Function that handles the signals
  * @signal_id: identifier of the signal to handle
  */
void signal_handler(int signal_id)
{
	if (signal_id == SIGINT)
		write(STDOUT_FILENO, "\n($) ", 5);
}
