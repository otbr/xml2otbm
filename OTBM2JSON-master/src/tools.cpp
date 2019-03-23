////////////////////////////////////////////////////////////////////////////////
// Survival Server - An MMPORPG (Massive MultiPlayer Online Role Playing Game)//
////////////////////////////////////////////////////////////////////////////////
// Developed by Dark-bart.                                                    //
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//Return true if the file exists
/*bool fileExists(char* filename)
{
	FILE *f = fopen(filename, "rb");
	bool exists = (f != NULL);
	if (f != NULL)
		fclose(f);

	return exists;
}*/

// Get a random number
int random_range(int lowest_number, int highest_number)
{
	if(lowest_number > highest_number){
		int nTmp = highest_number;
		highest_number = lowest_number;
		lowest_number = nTmp;
    }

    double range = highest_number - lowest_number + 1;
    return lowest_number + int(range * rand()/(RAND_MAX + 1.0));
}

// Dump a part of the memory to stderr.
/*void hexdump(unsigned char *_data, int _len) {
    int i;
    for (; _len > 0; _data += 16, _len -= 16) {
        for (i = 0; i < 16 && i < _len; i++)
            fprintf(stderr, "%02x ", _data[i]);
        for (; i < 16; i++)
            fprintf(stderr, "   ");
        fprintf(stderr, " ");
        for (i = 0; i < 16 && i < _len; i++)
            fprintf(stderr, "%c", (_data[i] & 0x70) < 32 ? '�' : _data[i]);
        fprintf(stderr, "\n");
    }
}*/

#if 0
//////////////////////////////////////////////////
// Enable asynchronous function calls.
// This function does not wait for return of the called function;
// instead, this function returns immediately.
// The called function must be of type void *fn(void *).
// You can use the pointer to the function for anything you want to.
// Return: a thread handle.
pthread_t *detach(void *(*_fn)(void *), void *_arg) {
    pthread_t *thread = new pthread_t();
    if (pthread_create(thread, NULL, _fn, _arg))
        perror("pthread");
    return thread;
}
#endif

//////////////////////////////////////////////////
// Upcase a char.
char upchar(char c) {
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 'A';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else if (c == '�')
        return '�';
    else
        return c;
}

//////////////////////////////////////////////////
// Upcase a 0-terminated string.
void upper(char *upstr, char *str) {
    for (; *str; str++, upstr++)
        *upstr = upchar(*str);
    *upstr = '\0';
}


//////////////////////////////////////////////////
// Upcase a 0-terminated string, but at most n chars.
void upper(char *upstr, char *str, int n) {
    for (; *str && n; str++, upstr++, n--)
        *upstr = upchar(*str);
    if (n) *upstr = '\0';
}
