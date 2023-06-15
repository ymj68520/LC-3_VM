#include "OtherOperations.h"
#include "LoadingPrograms.h"

void LoadArguments(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("lc3 [image-file1] ...\n");
		exit(2);
	}
	for (int i = 1;i < argc;++i) {
		if (!read_image(argv[i])) {
			printf("failed to load image: %s\n", argv[i]);
			exit(1);
		}
	}
}

void SetUp()
{
	signal(SIGINT, handle_interrupt);
	disable_input_buffering();
}

void handle_interrupt(int signal)
{
	restore_input_buffering();
	printf("\n");
	exit(-2);
}

void disable_input_buffering()
{
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hStdin, &fdwOldMode);
	fdwMode = fdwOldMode ^ ENABLE_ECHO_INPUT ^ ENABLE_LINE_INPUT;
	SetConsoleMode(hStdin, fdwOldMode);
	FlushConsoleInputBuffer(hStdin);
}

void restore_input_buffering()
{
	SetConsoleMode(hStdin, fdwOldMode);
}

uint16_t check_key() {
	return WaitForSingleObject(hStdin, 1000) == WAIT_OBJECT_0 && _kbhit();
}

