#include "libft_test.h"

void		sandbox_sig_int(int s) {
	printf("%s", "sandbox exit !\n");
	fflush(stdout);
	unsandbox();
	kill(g_pid, SIGINT);
	(void)s;
}

void		sandbox(void) {
//	signal(SIGINT, sandbox_sig_int);
//	signal(SIGQUIT, sandbox_sig_int);
}

void		unsandbox(void) {
//	signal(SIGINT, SIG_DFL);
//	signal(SIGQUIT, SIG_DFL);
}
