#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <locale.h>

#if defined(__linux__)
#  include <unistd.h>
#  define sleep(s) SleepMs((s))
#elif defined(_WIN32)
#  include <windows.h>
#endif
 
int main(int argc, char** argv) {
    fflush(NULL);
    fflush(stdin);
    setbuf(stdout, NULL);

    const char *cam[4];
    const char *cbm[13];

    cam[ 0] = "Коллега А:";
    cam[ 1] = "Здравствуй, коллега.";
    cam[ 2] = " Tablet грязный";
    cam[ 3] = " - Как чистый?";
    cbm[ 0] = "Коллега Б:";
    cbm[ 1] = "Посмотрите";
    cbm[ 2] = ", это свет";
    cbm[ 3] = ", как тарелка.";
    cbm[ 4] = "Это трудно";
    cbm[ 5] = ", как тарелка.";
	cbm[ 6] = "Это гладкий";
    cbm[ 7] = ", как тарелка.";
	cbm[ 8] = "Это грязно";
    cbm[ 9] = ", как тарелка!";
    cbm[10] = "Ответ очевиден";
    cbm[11] = ": вы моете его";
    cbm[12] = ", как тарелка!";

    if(argc > 1) {
	    if(strcmp(argv[1], "ENG") == 0
	    || strcmp(argv[1], "eng") == 0) {
	        cam[ 0] = "Comrade A:";
	        cam[ 1] = "Hello, colleague.";
	        cam[ 2] = " Tablet is dirty";
	        cam[ 3] = " - how clean?";
	        cbm[ 0] = "Comrade B:";
	        cbm[ 1] = "Look";
	        cbm[ 2] = ", is light";
	        cbm[ 3] = ", like plate.";
	        cbm[ 4] = "Is hard";
	        cbm[ 5] = ", like plate.";
	        cbm[ 6] = "Is smooth";
	        cbm[ 7] = ", like plate.";
	        cbm[ 8] = "Is dirty";
	        cbm[ 9] = ", like plate!";
	        cbm[ 10] = "Answer is obvious";
	        cbm[ 11] = ": You wash";
	        cbm[ 12] = ", like plate!";
	    } else if(strcmp(argv[1], "FON") == 0
	           || strcmp(argv[1], "fon") == 0) {
	    	cam[ 0] = "Kollega A:";
	        cam[ 1] = "Zdravstvuy, kollega.";
	        cam[ 2] = " Tablet gryaznyy";
	        cam[ 3] = " - Kak chistyy?";
	        cbm[ 0] = "Kollega B:";
	        cbm[ 1] = "Posmotrite";
	        cbm[ 2] = ", eto svet";
	        cbm[ 3] = ", kak tarelka.";
	        cbm[ 4] = "Eto trudno";
	        cbm[ 5] = ", kak tarelka.";
	        cbm[ 6] = "Eto gladkiy";
	        cbm[ 7] = ", kak tarelka.";
	        cbm[ 8] = "Eto gryazno";
	        cbm[ 9] = ", kak tarelka!";
	        cbm[ 10] = "Otvet ocheviden";
	        cbm[ 11] = ": vy moyete yego";
	        cbm[ 12] = ", kak tarelka!";
	    } else if(strcmp(argv[1], "credits") == 0) {
			typeText("\n╔══════════════════════════════════════════════════════════════════════════════╗", 1);
			typeText("\n║        _/_/_/  _/_/_/    _/_/_/_/  _/_/_/    _/_/_/  _/_/_/_/_/    _/_/_/    ║", 5);
			typeText("\n║     _/        _/    _/  _/        _/    _/    _/        _/      _/           ║", 5);
			typeText("\n║    _/        _/_/_/    _/_/_/    _/    _/    _/        _/        _/_/        ║", 5);
			typeText("\n║   _/        _/    _/  _/        _/    _/    _/        _/            _/       ║", 5);
			typeText("\n║    _/_/_/  _/    _/  _/_/_/_/  _/_/_/    _/_/_/      _/      _/_/_/          ║", 5);
			typeText("\n╟──────────────────────────────────────┬───────────────────────────────────────╢", 1);
			typeText("\n║        Made by: Roel Walraven        │        Compiled with gcc 4.8.2        ║", 5);
			typeText("\n╟──────────────────────────────────────┴───────────────────────────────────────╢", 1);
			typeText("\n║                                - thanks to -                                 ║", 5);
			typeText("\n║ /u/Gambatte on reddit, for his awesome comment in /r/talesfromtechsupport.   ║", 5);
			typeText("\n║                                                                              ║", 1);
			typeText("\n║                            - special thanks to -                             ║", 5);
			typeText("\n║ Colin Percival, for his UTF-8 character counting tutorial.                   ║", 5);
			typeText("\n║ http://www.daemonology.net/blog/2008-06-05-faster-utf8-strlen.html           ║", 5);
			typeText("\n║                                                                              ║", 1);
			typeText("\n║ The guys over at stackoverflow, for moral support...                         ║", 5);
            typeText("\n║                                                                              ║", 1);
            typeText("\n║ My dad, for conceiving me                                                    ║", 5);
            typeText("\n║ My mom, for giving birth to me                                               ║", 5);
			typeText("\n╚══════════════════════════════════════════════════════════════════════════════╝", 1);
			printf("\n\n");
	        return 1;
	    }
	}

	int length = 0;
    typeText("\n╔════════════════╤═════════════════════════════════════════════════════════════╗", 1);
    printf("\n║     %s │ ", cam[0]);

    typeText(cam[1], 40);
    sleep(1000);
    typeText(cam[2], 40);
    sleep(1000);
    typeText(cam[3], 40);
    length = cp_strlen_utf8(cam[1])
           + cp_strlen_utf8(cam[2])
           + cp_strlen_utf8(cam[3])
           ;
    printf("%*s", 80-(length+17), "║");

    typeText("\n╟────────────────┼─────────────────────────────────────────────────────────────╢", 1);
    printf("\n║     %s │ ", cbm[0]);

    typeText(cbm[1], 60);
    sleep(1000);
    typeText(cbm[2], 60);
    sleep(1000);
    typeText(cbm[3], 60);
    sleep(2000);
    length = cp_strlen_utf8(cbm[1])
           + cp_strlen_utf8(cbm[2])
           + cp_strlen_utf8(cbm[3])
           ;
    printf("%*s", 80-(length+17), "║");

    typeText("\n║                │ ", 1);
    typeText(cbm[4], 60);
    sleep(1000);
    typeText(cbm[5], 60);
    sleep(2000);
    length = cp_strlen_utf8(cbm[4])
           + cp_strlen_utf8(cbm[5])
           ;
    printf("%*s", 80-(length+17), "║");

    typeText("\n║                │ ", 1);
    typeText(cbm[6], 60);
    sleep(1000);
    typeText(cbm[7], 60);
    sleep(2000);
    length = cp_strlen_utf8(cbm[6])
           + cp_strlen_utf8(cbm[7])
           ;
    printf("%*s", 80-(length+17), "║");

    typeText("\n║                │ ", 1);
    typeText(cbm[8], 60);
    sleep(1000);
    typeText(cbm[9], 60);
    sleep(2000);
    length = cp_strlen_utf8(cbm[8])
           + cp_strlen_utf8(cbm[9])
           ;
    printf("%*s", 80-(length+17), "║");

    typeText("\n║                │ ", 1);
    typeText(cbm[10], 60);
    sleep(1000);
    typeText(cbm[11], 60);
    sleep(1000);
    typeText(cbm[12], 60);
    length = cp_strlen_utf8(cbm[10])
           + cp_strlen_utf8(cbm[11])
           + cp_strlen_utf8(cbm[12])
           ;
    printf("%*s", 80-(length+17), "║");

    typeText("\n╚════════════════╧═════════════════════════════════════════════════════════════╝", 1);
    printf("\n\n");
    if(argc < 2) {
        typeText("To follow this conversation in english, type ENG after the command.\n", 30);
        typeText("To read the phonetic version, type FON after the command.\n", 30);
        typeText("To view the credits, type credits after the command.\n", 30);
        printf("\n");
    }
}

int typeText(char *text, int speed) {
	size_t length = strlen(text);
	int i=0;
	while(i <= length) {
		printf("%c", text[i]);
		sleep(speed);
		i++;
	}
	return 1;
}

int SleepMs(int ms) {
    usleep(ms*1000);
    return 1;
}

#define ONEMASK ((size_t)(-1) / 0xFF)

int cp_strlen_utf8(const char * _s) {
	const char * s;
	size_t count = 0;
	size_t u;
	unsigned char b;

	/* Handle any initial misaligned bytes. */
	for (s = _s; (sizeof(size_t) - 1); s++) {
		b = *s;

		/* Exit if we hit a zero byte. */
		if (b == '\0')
			goto done;

		/* Is this byte NOT the first byte of a character? */
		count += (b >> 7) & ((~b) >> 6);
	}

	/* Handle complete blocks. */
	for (; ; s += sizeof(size_t)) {
		/* Prefetch 256 bytes ahead. */
		__builtin_prefetch(&s[256], 0, 0);

		/* Grab 4 or 8 bytes of UTF-8 data. */
		u = *(size_t *)(s);

		/* Exit the loop if there are any zero bytes. */
		if ((u - ONEMASK) & (~u) & (ONEMASK * 0x80))
			break;

		/* Count bytes which are NOT the first byte of a character. */
		u = ((u & (ONEMASK * 0x80)) >> 7) & ((~u) >> 6);
		count += (u * ONEMASK) >> ((sizeof(size_t) - 1) * 8);
	}

	/* Take care of any left-over bytes. */
	for (; ; s++) {
		b = *s;

		/* Exit if we hit a zero byte. */
		if (b == '\0')
			break;

		/* Is this byte NOT the first byte of a character? */
		count += (b >> 7) & ((~b) >> 6);
	}

done:
// printf("%d\n", (int)((s - _s) - count));
	return ((s - _s) - count);
}