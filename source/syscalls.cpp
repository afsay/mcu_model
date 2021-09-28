#include <stdio.h>
#include <stdint.h>
#include "microcontroller.h"
extern unsigned char *_pvHeapStart;
//void * _sbrk (ptrdiff_t incr) asm("_sbrk");
extern "C"
{

static int
sample_putc(char c, FILE *file)
{
	(void) file;
	MicroController::Uart0.uart_putc(c);
	return c;
}

static int
sample_getc(FILE *file)
{
	unsigned char c;
	(void) file;
	c = MicroController::Uart0.read();;
	return c;
}


static FILE __stdio = FDEV_SETUP_STREAM(sample_putc,
					sample_getc,
					NULL,
					_FDEV_SETUP_RW);

/*
int
_putc_r (struct _reent *ptr,
       int c,
       register FILE *fp)
{
	MicroController::Uart0.uart_putc(c);
}

int
_putchar_r (struct _reent *ptr,
       int c)
{
	MicroController::Uart0.uart_putc(c);
}*/
/*
int
putc (int c,
       register FILE *fp)
{
	MicroController::Uart0.uart_putc(c);
}

int
putchar (int c)
{
	MicroController::Uart0.uart_putc(c);
}*/

/*
void *_sbrk(int incr) {
  static unsigned char *heap = NULL;
  unsigned char *prev_heap;

  if (heap == NULL) {
    heap = (unsigned char *)&_pvHeapStart;
  }
  prev_heap = heap;

  heap += incr;

  return prev_heap;
}

_ssize_t _write_r (struct _reent *ptr,
     int fd,
     const void *buf,
     size_t cnt)
{
	for (int i = 0; i<cnt; i++)
			MicroController::Uart0.uart_putc(((uint8_t *)buf)[i]);
		return cnt;
}

int _read (int file, void * ptr, size_t len)
{
	return 0;
}

int _kill (int pid, int sig)
{
	return 0;
}

_off_t _lseek (int file, _off_t ptr, int dir)
{
	_off_t x;
	return x;
}

int _close (int file)
{
	return 0;
}
typedef int pid_t;
pid_t _getpid (void)
{
	pid_t x;
	return x;
}

int _fstat (int file, struct stat * st)
{
	return 0;
}

int _isatty (int fd)
{
	return 0;
}*/
void _exit (int status)
{
	return;
}

}
FILE *const stdin = &__stdio; __strong_reference(stdin, stdout); __strong_reference(stdin, stderr);
