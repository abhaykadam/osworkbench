# 1 "demo.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "demo.c"
struct _node{ void* data; struct _node* next;}
;
typedef struct _node node;
struct _queue{ node *front, *rear; unsigned size;}
;
typedef struct _queue queue;
queue* init_queue ();
void push(queue**, void*);
void* pick_front (queue*);
void* front(queue**);
int is_empty(queue*);
unsigned size(queue*);
void display_queue (queue*);
# 1 "/usr/include/stdio.h" 1 3 4
# 28 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 352 "/usr/include/features.h" 3 4
# 1 "/usr/include/sys/cdefs.h" 1 3 4
# 365 "/usr/include/sys/cdefs.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 366 "/usr/include/sys/cdefs.h" 2 3 4
# 353 "/usr/include/features.h" 2 3 4
# 376 "/usr/include/features.h" 3 4
# 1 "/usr/include/gnu/stubs.h" 1 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 5 "/usr/include/gnu/stubs.h" 2 3 4
# 1 "/usr/include/gnu/stubs-64.h" 1 3 4
# 10 "/usr/include/gnu/stubs.h" 2 3 4
# 377 "/usr/include/features.h" 2 3 4
# 29 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/lib/gcc/x86_64-redhat-linux/4.4.1/include/stddef.h" 1 3 4
# 211 "/usr/lib/gcc/x86_64-redhat-linux/4.4.1/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 35 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/bits/types.h" 1 3 4
# 28 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 29 "/usr/include/bits/types.h" 2 3 4
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;
typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
# 131 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/typesizes.h" 1 3 4
# 132 "/usr/include/bits/types.h" 2 3 4
typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; }
 __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef int __daddr_t;
typedef long int __swblk_t;
typedef int __key_t;
typedef int __clockid_t;
typedef void * __timer_t;
typedef long int __blksize_t;
typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;
typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;
typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;
typedef long int __ssize_t;
typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;
typedef long int __intptr_t;
typedef unsigned int __socklen_t;
# 37 "/usr/include/stdio.h" 2 3 4
# 45 "/usr/include/stdio.h" 3 4
struct _IO_FILE;
typedef struct _IO_FILE FILE;
# 65 "/usr/include/stdio.h" 3 4
typedef struct _IO_FILE __FILE;
# 75 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/libio.h" 1 3 4
# 32 "/usr/include/libio.h" 3 4
# 1 "/usr/include/_G_config.h" 1 3 4
# 15 "/usr/include/_G_config.h" 3 4
# 1 "/usr/lib/gcc/x86_64-redhat-linux/4.4.1/include/stddef.h" 1 3 4
# 16 "/usr/include/_G_config.h" 2 3 4
# 1 "/usr/include/wchar.h" 1 3 4
# 83 "/usr/include/wchar.h" 3 4
typedef struct{  int __count;  union  {    unsigned int __wch;    char __wchb[4];  } __value;}
 __mbstate_t;
# 21 "/usr/include/_G_config.h" 2 3 4
typedef struct{  __off_t __pos;  __mbstate_t __state;}
 _G_fpos_t;
typedef struct{  __off64_t __pos;  __mbstate_t __state;}
 _G_fpos64_t;
# 53 "/usr/include/_G_config.h" 3 4
typedef int 
_G_int16_t __attribute__ ((__mode__ (__HI__)));
typedef int 
_G_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int 
_G_uint16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int 
_G_uint32_t __attribute__ ((__mode__ (__SI__)));
# 33 "/usr/include/libio.h" 2 3 4
# 53 "/usr/include/libio.h" 3 4
# 1 "/usr/lib/gcc/x86_64-redhat-linux/4.4.1/include/stdarg.h" 1 3 4
# 40 "/usr/lib/gcc/x86_64-redhat-linux/4.4.1/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 54 "/usr/include/libio.h" 2 3 4
# 170 "/usr/include/libio.h" 3 4
struct _IO_jump_t;
 struct _IO_FILE;
# 180 "/usr/include/libio.h" 3 4
typedef void _IO_lock_t;
struct _IO_marker {  struct _IO_marker *_next;  struct _IO_FILE *_sbuf;  int _pos;
# 203 "/usr/include/libio.h" 3 4
}
;
enum __codecvt_result{  __codecvt_ok,  __codecvt_partial,  __codecvt_error,  __codecvt_noconv}
;
# 271 "/usr/include/libio.h" 3 4
struct _IO_FILE {  int _flags;  char* _IO_read_ptr;  char* _IO_read_end;  char* _IO_read_base;  char* _IO_write_base;  char* _IO_write_ptr;  char* _IO_write_end;  char* _IO_buf_base;  char* _IO_buf_end;  char *_IO_save_base;  char *_IO_backup_base;  char *_IO_save_end;  struct _IO_marker *_markers;  struct _IO_FILE *_chain;  int _fileno;  int _flags2;  __off_t _old_offset;  unsigned short _cur_column;  signed char _vtable_offset;  char _shortbuf[1];  _IO_lock_t *_lock;
# 319 "/usr/include/libio.h" 3 4
  __off64_t _offset;
# 328 "/usr/include/libio.h" 3 4
  void *__pad1;  void *__pad2;  void *__pad3;  void *__pad4;  size_t __pad5;  int _mode;  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];}
;
typedef struct _IO_FILE _IO_FILE;
struct _IO_FILE_plus;
extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
# 364 "/usr/include/libio.h" 3 4
typedef 
__ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);
typedef __ssize_t __io_write_fn (void *__cookie, __const char *__buf,
     size_t __n);
typedef 
int __io_seek_fn (void *__cookie, __off64_t *__pos, int __w);
typedef 
int __io_close_fn (void *__cookie);
# 416 "/usr/include/libio.h" 3 4
extern 
int __underflow (_IO_FILE *);
extern 
int __uflow (_IO_FILE *);
extern 
int __overflow (_IO_FILE *, int);
# 458 "/usr/include/libio.h" 3 4
extern 
int _IO_getc (_IO_FILE *__fp);
extern 
int _IO_putc (int __c, _IO_FILE *__fp);
extern 
int _IO_feof (_IO_FILE *__fp) __attribute__ ((__nothrow__));
extern 
int _IO_ferror (_IO_FILE *__fp) __attribute__ ((__nothrow__));
extern 
int _IO_peekc_locked (_IO_FILE *__fp);
extern 
void _IO_flockfile (_IO_FILE *) __attribute__ ((__nothrow__));
extern 
void _IO_funlockfile (_IO_FILE *) __attribute__ ((__nothrow__));
extern 
int _IO_ftrylockfile (_IO_FILE *) __attribute__ ((__nothrow__));
# 488 "/usr/include/libio.h" 3 4
extern int _IO_vfscanf (_IO_FILE * __restrict, const char * __restrict,
   __gnuc_va_list, int *__restrict);
extern int _IO_vfprintf (_IO_FILE *__restrict, const char *__restrict,
    __gnuc_va_list);
extern 
__ssize_t _IO_padn (_IO_FILE *, int, __ssize_t);
extern 
size_t _IO_sgetn (_IO_FILE *, void *, size_t);
extern 
__off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int);
extern 
__off64_t _IO_seekpos (_IO_FILE *, __off64_t, int);
extern 
void _IO_free_backup_area (_IO_FILE *) __attribute__ ((__nothrow__));
# 76 "/usr/include/stdio.h" 2 3 4
# 89 "/usr/include/stdio.h" 3 4
typedef _G_fpos_t fpos_t;
# 141 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/bits/stdio_lim.h" 1 3 4
# 142 "/usr/include/stdio.h" 2 3 4
extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;
extern 
int remove (__const char *__filename) __attribute__ ((__nothrow__));
extern 
int rename (__const char *__old, __const char *__new) __attribute__ ((__nothrow__));
extern int renameat (int __oldfd, __const char *__old, int __newfd,
       __const char *__new) __attribute__ ((__nothrow__));
extern 
FILE *tmpfile (void) ;
# 188 "/usr/include/stdio.h" 3 4
extern 
char *tmpnam (char *__s) __attribute__ ((__nothrow__)) ;
extern 
char *tmpnam_r (char *__s) __attribute__ ((__nothrow__)) ;
# 206 "/usr/include/stdio.h" 3 4
extern char *tempnam (__const char *__dir, __const char *__pfx)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;
extern 
int fclose (FILE *__stream);
extern 
int fflush (FILE *__stream);
# 231 "/usr/include/stdio.h" 3 4
extern 
int fflush_unlocked (FILE *__stream);
# 245 "/usr/include/stdio.h" 3 4
extern FILE *fopen (__const char *__restrict __filename,
      __const char *__restrict __modes) ;
extern FILE *freopen (__const char *__restrict __filename,
        __const char *__restrict __modes,
        FILE *__restrict __stream) ;
# 274 "/usr/include/stdio.h" 3 4
# 285 "/usr/include/stdio.h" 3 4
extern 
FILE *fdopen (int __fd, __const char *__modes) __attribute__ ((__nothrow__)) ;
# 298 "/usr/include/stdio.h" 3 4
extern FILE *fmemopen (void *__s, size_t __len, __const char *__modes)
  __attribute__ ((__nothrow__)) ;
extern 
FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__)) ;
extern 
void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__));
extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__));
extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__));
extern 
void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__));
extern int fprintf (FILE *__restrict __stream,
      __const char *__restrict __format, ...);
extern 
int printf (__const char *__restrict __format, ...);
extern int sprintf (char *__restrict __s,
      __const char *__restrict __format, ...) __attribute__ ((__nothrow__));
extern int vfprintf (FILE *__restrict __s, __const char *__restrict __format,
       __gnuc_va_list __arg);
extern 
int vprintf (__const char *__restrict __format, __gnuc_va_list __arg);
extern int vsprintf (char *__restrict __s, __const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));
extern int snprintf (char *__restrict __s, size_t __maxlen,
       __const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));
extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        __const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));
# 396 "/usr/include/stdio.h" 3 4
extern int vdprintf (int __fd, __const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, __const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));
extern int fscanf (FILE *__restrict __stream,
     __const char *__restrict __format, ...) ;
extern 
int scanf (__const char *__restrict __format, ...) ;
extern int sscanf (__const char *__restrict __s,
     __const char *__restrict __format, ...) __attribute__ ((__nothrow__));
# 427 "/usr/include/stdio.h" 3 4
extern 
int fscanf (FILE *__restrict __stream, __const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf") ;
extern 
int scanf (__const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf") ;
extern 
int sscanf (__const char *__restrict __s, __const char *__restrict __format, ...) __asm__ ("" "__isoc99_sscanf") __attribute__ ((__nothrow__));
# 447 "/usr/include/stdio.h" 3 4
extern int vfscanf (FILE *__restrict __s, __const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (__const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (__const char *__restrict __s,
      __const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
# 478 "/usr/include/stdio.h" 3 4
extern int vfscanf (FILE *__restrict __s, __const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (__const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (__const char *__restrict __s, __const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vsscanf")
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
# 506 "/usr/include/stdio.h" 3 4
extern 
int fgetc (FILE *__stream);
extern 
int getc (FILE *__stream);
extern 
int getchar (void);
# 534 "/usr/include/stdio.h" 3 4
extern 
int getc_unlocked (FILE *__stream);
extern 
int getchar_unlocked (void);
# 545 "/usr/include/stdio.h" 3 4
extern 
int fgetc_unlocked (FILE *__stream);
extern 
int fputc (int __c, FILE *__stream);
extern 
int putc (int __c, FILE *__stream);
extern 
int putchar (int __c);
# 578 "/usr/include/stdio.h" 3 4
extern 
int fputc_unlocked (int __c, FILE *__stream);
extern 
int putc_unlocked (int __c, FILE *__stream);
extern 
int putchar_unlocked (int __c);
extern 
int getw (FILE *__stream);
extern 
int putw (int __w, FILE *__stream);
extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     ;
extern 
char *gets (char *__s) ;
# 640 "/usr/include/stdio.h" 3 4
extern __ssize_t __getdelim (char **__restrict __lineptr,
          size_t *__restrict __n, int __delimiter,
          FILE *__restrict __stream) ;
extern __ssize_t getdelim (char **__restrict __lineptr,
        size_t *__restrict __n, int __delimiter,
        FILE *__restrict __stream) ;
extern __ssize_t getline (char **__restrict __lineptr,
       size_t *__restrict __n,
       FILE *__restrict __stream) ;
extern 
int fputs (__const char *__restrict __s, FILE *__restrict __stream);
extern 
int puts (__const char *__s);
extern 
int ungetc (int __c, FILE *__stream);
extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite (__const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s) ;
# 712 "/usr/include/stdio.h" 3 4
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite_unlocked (__const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream) ;
extern 
int fseek (FILE *__stream, long int __off, int __whence);
extern long 
int ftell (FILE *__stream) ;
extern 
void rewind (FILE *__stream);
# 748 "/usr/include/stdio.h" 3 4
extern 
int fseeko (FILE *__stream, __off_t __off, int __whence);
extern 
__off_t ftello (FILE *__stream) ;
# 767 "/usr/include/stdio.h" 3 4
extern 
int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);
extern 
int fsetpos (FILE *__stream, __const fpos_t *__pos);
# 790 "/usr/include/stdio.h" 3 4
# 799 "/usr/include/stdio.h" 3 4
extern 
void clearerr (FILE *__stream) __attribute__ ((__nothrow__));
extern 
int feof (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern 
int ferror (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern 
void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__));
extern 
int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern 
int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern 
void perror (__const char *__s);
# 1 "/usr/include/bits/sys_errlist.h" 1 3 4
# 27 "/usr/include/bits/sys_errlist.h" 3 4
extern int sys_nerr;
extern __const char *__const sys_errlist[];
# 829 "/usr/include/stdio.h" 2 3 4
extern 
int fileno (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern 
int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;
# 848 "/usr/include/stdio.h" 3 4
extern 
FILE *popen (__const char *__command, __const char *__modes) ;
extern 
int pclose (FILE *__stream);
extern 
char *ctermid (char *__s) __attribute__ ((__nothrow__));
# 888 "/usr/include/stdio.h" 3 4
extern 
void flockfile (FILE *__stream) __attribute__ ((__nothrow__));
extern 
int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern 
void funlockfile (FILE *__stream) __attribute__ ((__nothrow__));
# 918 "/usr/include/stdio.h" 3 4
# 33 "demo.c" 2
# 1 "/usr/include/pthread.h" 1 3 4
# 24 "/usr/include/pthread.h" 3 4
# 1 "/usr/include/endian.h" 1 3 4
# 37 "/usr/include/endian.h" 3 4
# 1 "/usr/include/bits/endian.h" 1 3 4
# 38 "/usr/include/endian.h" 2 3 4
# 61 "/usr/include/endian.h" 3 4
# 1 "/usr/include/bits/byteswap.h" 1 3 4
# 28 "/usr/include/bits/byteswap.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 29 "/usr/include/bits/byteswap.h" 2 3 4
# 62 "/usr/include/endian.h" 2 3 4
# 25 "/usr/include/pthread.h" 2 3 4
# 1 "/usr/include/sched.h" 1 3 4
# 29 "/usr/include/sched.h" 3 4
# 1 "/usr/lib/gcc/x86_64-redhat-linux/4.4.1/include/stddef.h" 1 3 4
# 30 "/usr/include/sched.h" 2 3 4
# 1 "/usr/include/time.h" 1 3 4
# 120 "/usr/include/time.h" 3 4
struct timespec  {    __time_t tv_sec;    long int tv_nsec;  }
;
# 33 "/usr/include/sched.h" 2 3 4
# 1 "/usr/include/bits/sched.h" 1 3 4
# 71 "/usr/include/bits/sched.h" 3 4
struct sched_param  {    int __sched_priority;  }
;
extern int clone (int (*__fn) (void *__arg), void *__child_stack,
    int __flags, void *__arg, ...) __attribute__ ((__nothrow__));
extern 
int unshare (int __flags) __attribute__ ((__nothrow__));
extern 
int sched_getcpu (void) __attribute__ ((__nothrow__));
struct __sched_param  {    int __sched_priority;  }
;
# 113 "/usr/include/bits/sched.h" 3 4
typedef unsigned long int __cpu_mask;
typedef struct{  __cpu_mask __bits[1024 / (8 * sizeof (__cpu_mask))];}
 cpu_set_t;
# 196 "/usr/include/bits/sched.h" 3 4
extern int __sched_cpucount (size_t __setsize, const cpu_set_t *__setp)
  __attribute__ ((__nothrow__));
extern 
cpu_set_t *__sched_cpualloc (size_t __count) __attribute__ ((__nothrow__)) ;
extern 
void __sched_cpufree (cpu_set_t *__set) __attribute__ ((__nothrow__));
# 36 "/usr/include/sched.h" 2 3 4
extern 
int sched_setparam (__pid_t __pid, __const struct sched_param *__param)     __attribute__ ((__nothrow__));
extern 
int sched_getparam (__pid_t __pid, struct sched_param *__param) __attribute__ ((__nothrow__));
extern int sched_setscheduler (__pid_t __pid, int __policy,
          __const struct sched_param *__param) __attribute__ ((__nothrow__));
extern 
int sched_getscheduler (__pid_t __pid) __attribute__ ((__nothrow__));
extern 
int sched_yield (void) __attribute__ ((__nothrow__));
extern 
int sched_get_priority_max (int __algorithm) __attribute__ ((__nothrow__));
extern 
int sched_get_priority_min (int __algorithm) __attribute__ ((__nothrow__));
extern 
int sched_rr_get_interval (__pid_t __pid, struct timespec *__t) __attribute__ ((__nothrow__));
# 118 "/usr/include/sched.h" 3 4
# 26 "/usr/include/pthread.h" 2 3 4
# 1 "/usr/include/time.h" 1 3 4
# 30 "/usr/include/time.h" 3 4
# 1 "/usr/lib/gcc/x86_64-redhat-linux/4.4.1/include/stddef.h" 1 3 4
# 39 "/usr/include/time.h" 2 3 4
# 1 "/usr/include/bits/time.h" 1 3 4
# 43 "/usr/include/time.h" 2 3 4
# 58 "/usr/include/time.h" 3 4
typedef __clock_t clock_t;
# 74 "/usr/include/time.h" 3 4
typedef __time_t time_t;
# 92 "/usr/include/time.h" 3 4
typedef __clockid_t clockid_t;
# 104 "/usr/include/time.h" 3 4
typedef __timer_t timer_t;
# 131 "/usr/include/time.h" 3 4
struct tm{  int tm_sec;  int tm_min;  int tm_hour;  int tm_mday;  int tm_mon;  int tm_year;  int tm_wday;  int tm_yday;  int tm_isdst;  long int tm_gmtoff;  __const char *tm_zone;}
;
struct itimerspec  {    struct timespec it_interval;    struct timespec it_value;  }
;
struct sigevent;
typedef __pid_t pid_t;
extern 
clock_t clock (void) __attribute__ ((__nothrow__));
extern 
time_t time (time_t *__timer) __attribute__ ((__nothrow__));
extern double difftime (time_t __time1, time_t __time0)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern 
time_t mktime (struct tm *__tp) __attribute__ ((__nothrow__));
extern size_t strftime (char *__restrict __s, size_t __maxsize,
   __const char *__restrict __format,
   __const struct tm *__restrict __tp) __attribute__ ((__nothrow__));
# 215 "/usr/include/time.h" 3 4
# 1 "/usr/include/xlocale.h" 1 3 4
# 28 "/usr/include/xlocale.h" 3 4
typedef struct __locale_struct{  struct locale_data *__locales[13];  const unsigned short int *__ctype_b;  const int *__ctype_tolower;  const int *__ctype_toupper;  const char *__names[13];}
 *__locale_t;
typedef __locale_t locale_t;
# 216 "/usr/include/time.h" 2 3 4
extern size_t strftime_l (char *__restrict __s, size_t __maxsize,
     __const char *__restrict __format,
     __const struct tm *__restrict __tp,     __locale_t __loc) __attribute__ ((__nothrow__));
# 230 "/usr/include/time.h" 3 4
extern struct 
tm *gmtime (__const time_t *__timer) __attribute__ ((__nothrow__));
extern struct 
tm *localtime (__const time_t *__timer) __attribute__ ((__nothrow__));
extern struct 
tm *gmtime_r (__const time_t *__restrict __timer,       struct tm *__restrict __tp) __attribute__ ((__nothrow__));
extern struct 
tm *localtime_r (__const time_t *__restrict __timer,          struct tm *__restrict __tp) __attribute__ ((__nothrow__));
extern 
char *asctime (__const struct tm *__tp) __attribute__ ((__nothrow__));
extern 
char *ctime (__const time_t *__timer) __attribute__ ((__nothrow__));
extern 
char *asctime_r (__const struct tm *__restrict __tp,   char *__restrict __buf) __attribute__ ((__nothrow__));
extern char *ctime_r (__const time_t *__restrict __timer,
        char *__restrict __buf) __attribute__ ((__nothrow__));
extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;
extern char *tzname[2];
extern 
void tzset (void) __attribute__ ((__nothrow__));
extern int daylight;
extern long int timezone;
extern 
int stime (__const time_t *__when) __attribute__ ((__nothrow__));
# 313 "/usr/include/time.h" 3 4
extern 
time_t timegm (struct tm *__tp) __attribute__ ((__nothrow__));
extern 
time_t timelocal (struct tm *__tp) __attribute__ ((__nothrow__));
extern 
int dysize (int __year) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
# 328 "/usr/include/time.h" 3 4
extern 
int nanosleep (__const struct timespec *__requested_time,        struct timespec *__remaining);
extern 
int clock_getres (clockid_t __clock_id, struct timespec *__res) __attribute__ ((__nothrow__));
extern 
int clock_gettime (clockid_t __clock_id, struct timespec *__tp) __attribute__ ((__nothrow__));
extern 
int clock_settime (clockid_t __clock_id, __const struct timespec *__tp)     __attribute__ ((__nothrow__));
extern int clock_nanosleep (clockid_t __clock_id, int __flags,
       __const struct timespec *__req,       struct timespec *__rem);
extern 
int clock_getcpuclockid (pid_t __pid, clockid_t *__clock_id) __attribute__ ((__nothrow__));
extern int timer_create (clockid_t __clock_id,
    struct sigevent *__restrict __evp,    timer_t *__restrict __timerid) __attribute__ ((__nothrow__));
extern 
int timer_delete (timer_t __timerid) __attribute__ ((__nothrow__));
extern int timer_settime (timer_t __timerid, int __flags,
     __const struct itimerspec *__restrict __value,     struct itimerspec *__restrict __ovalue) __attribute__ ((__nothrow__));
extern 
int timer_gettime (timer_t __timerid, struct itimerspec *__value)     __attribute__ ((__nothrow__));
extern 
int timer_getoverrun (timer_t __timerid) __attribute__ ((__nothrow__));
# 417 "/usr/include/time.h" 3 4
# 27 "/usr/include/pthread.h" 2 3 4
# 1 "/usr/include/signal.h" 1 3 4
# 31 "/usr/include/signal.h" 3 4
# 1 "/usr/include/bits/sigset.h" 1 3 4
# 24 "/usr/include/bits/sigset.h" 3 4
typedef int __sig_atomic_t;
typedef struct  {    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];  }
 __sigset_t;
# 34 "/usr/include/signal.h" 2 3 4
# 50 "/usr/include/signal.h" 3 4
typedef __sigset_t sigset_t;
# 408 "/usr/include/signal.h" 3 4
# 30 "/usr/include/pthread.h" 2 3 4
# 1 "/usr/include/bits/pthreadtypes.h" 1 3 4
# 23 "/usr/include/bits/pthreadtypes.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 24 "/usr/include/bits/pthreadtypes.h" 2 3 4
# 50 "/usr/include/bits/pthreadtypes.h" 3 4
typedef unsigned long int pthread_t;
typedef union{  char __size[56];  long int __align;}
 pthread_attr_t;
typedef struct __pthread_internal_list{  struct __pthread_internal_list *__prev;  struct __pthread_internal_list *__next;}
 __pthread_list_t;
# 76 "/usr/include/bits/pthreadtypes.h" 3 4
typedef union{
  struct __pthread_mutex_s  {    int __lock;    unsigned int __count;    int __owner;    unsigned int __nusers;    int __kind;    int __spins;    __pthread_list_t __list;

# 101 "/usr/include/bits/pthreadtypes.h" 3 4

  }
 __data;  char __size[40];  long int __align;}
 pthread_mutex_t;
typedef union{  char __size[4];  int __align;}
 pthread_mutexattr_t;
typedef union{
  struct  {    int __lock;    unsigned int __futex;    __extension__ unsigned long long int __total_seq;    __extension__ unsigned long long int __wakeup_seq;    __extension__ unsigned long long int __woken_seq;    void *__mutex;    unsigned int __nwaiters;    unsigned int __broadcast_seq;  }
 __data;  char __size[48];  __extension__ long long int __align;}
 pthread_cond_t;
typedef union{  char __size[4];  int __align;}
 pthread_condattr_t;
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
typedef union{
  struct  {    int __lock;    unsigned int __nr_readers;    unsigned int __readers_wakeup;    unsigned int __writer_wakeup;    unsigned int __nr_readers_queued;    unsigned int __nr_writers_queued;    int __writer;    int __shared;    unsigned long int __pad1;    unsigned long int __pad2;    unsigned int __flags;  }
 __data;
# 187 "/usr/include/bits/pthreadtypes.h" 3 4
  char __size[56];  long int __align;}
 pthread_rwlock_t;
typedef union{  char __size[8];  long int __align;}
 pthread_rwlockattr_t;
typedef volatile int pthread_spinlock_t;
typedef union{  char __size[32];  long int __align;}
 pthread_barrier_t;
typedef union{  char __size[4];  int __align;}
 pthread_barrierattr_t;
# 31 "/usr/include/pthread.h" 2 3 4
# 1 "/usr/include/bits/setjmp.h" 1 3 4
# 27 "/usr/include/bits/setjmp.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 28 "/usr/include/bits/setjmp.h" 2 3 4
typedef long int __jmp_buf[8];
# 32 "/usr/include/pthread.h" 2 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 33 "/usr/include/pthread.h" 2 3 4
enum{  PTHREAD_CREATE_JOINABLE,  PTHREAD_CREATE_DETACHED}
;
enum{  PTHREAD_MUTEX_TIMED_NP,  PTHREAD_MUTEX_RECURSIVE_NP,  PTHREAD_MUTEX_ERRORCHECK_NP,  PTHREAD_MUTEX_ADAPTIVE_NP
# 63 "/usr/include/pthread.h" 3 4
}
;
enum{  PTHREAD_MUTEX_STALLED,  PTHREAD_MUTEX_STALLED_NP = PTHREAD_MUTEX_STALLED,  PTHREAD_MUTEX_ROBUST,  PTHREAD_MUTEX_ROBUST_NP = PTHREAD_MUTEX_ROBUST}
;
# 117 "/usr/include/pthread.h" 3 4
enum{  PTHREAD_RWLOCK_PREFER_READER_NP,  PTHREAD_RWLOCK_PREFER_WRITER_NP,  PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP,  PTHREAD_RWLOCK_DEFAULT_NP = PTHREAD_RWLOCK_PREFER_READER_NP}
;
# 149 "/usr/include/pthread.h" 3 4
enum{  PTHREAD_INHERIT_SCHED,  PTHREAD_EXPLICIT_SCHED}
;
enum{  PTHREAD_SCOPE_SYSTEM,  PTHREAD_SCOPE_PROCESS}
;
enum{  PTHREAD_PROCESS_PRIVATE,  PTHREAD_PROCESS_SHARED}
;
# 184 "/usr/include/pthread.h" 3 4
struct _pthread_cleanup_buffer{  void (*__routine) (void *);  void *__arg;  int __canceltype;  struct _pthread_cleanup_buffer *__prev;}
;
enum{  PTHREAD_CANCEL_ENABLE,  PTHREAD_CANCEL_DISABLE}
;
enum{  PTHREAD_CANCEL_DEFERRED,  PTHREAD_CANCEL_ASYNCHRONOUS}
;
# 222 "/usr/include/pthread.h" 3 4
extern int pthread_create (pthread_t *__restrict __newthread,
      __const pthread_attr_t *__restrict __attr,
      void *(*__start_routine) (void *),
      void *__restrict __arg) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 3)));
extern 
void pthread_exit (void *__retval) __attribute__ ((__noreturn__));
extern 
int pthread_join (pthread_t __th, void **__thread_return);
# 265 "/usr/include/pthread.h" 3 4
extern 
int pthread_detach (pthread_t __th) __attribute__ ((__nothrow__));
extern 
pthread_t pthread_self (void) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
extern 
int pthread_equal (pthread_t __thread1, pthread_t __thread2) __attribute__ ((__nothrow__));
extern 
int pthread_attr_init (pthread_attr_t *__attr) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_destroy (pthread_attr_t *__attr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getdetachstate (__const pthread_attr_t *__attr,
     int *__detachstate)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setdetachstate (pthread_attr_t *__attr,
     int __detachstate)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getguardsize (__const pthread_attr_t *__attr,
          size_t *__guardsize)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setguardsize (pthread_attr_t *__attr,
          size_t __guardsize)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getschedparam (__const pthread_attr_t *__restrict
           __attr,
           struct sched_param *__restrict __param)     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setschedparam (pthread_attr_t *__restrict __attr,
           __const struct sched_param *__restrict           __param) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_getschedpolicy (__const pthread_attr_t *__restrict
     __attr, int *__restrict __policy)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setschedpolicy (pthread_attr_t *__attr, int __policy)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getinheritsched (__const pthread_attr_t *__restrict
      __attr, int *__restrict __inherit)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setinheritsched (pthread_attr_t *__attr,
      int __inherit)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getscope (__const pthread_attr_t *__restrict __attr,
      int *__restrict __scope)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setscope (pthread_attr_t *__attr, int __scope)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getstackaddr (__const pthread_attr_t *__restrict
          __attr, void **__restrict __stackaddr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__deprecated__));
extern int pthread_attr_setstackaddr (pthread_attr_t *__attr,
          void *__stackaddr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__deprecated__));
extern int pthread_attr_getstacksize (__const pthread_attr_t *__restrict
          __attr, size_t *__restrict __stacksize)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setstacksize (pthread_attr_t *__attr,
          size_t __stacksize)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getstack (__const pthread_attr_t *__restrict __attr,
      void **__restrict __stackaddr,
      size_t *__restrict __stacksize)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2, 3)));
extern int pthread_attr_setstack (pthread_attr_t *__attr, void *__stackaddr,
      size_t __stacksize) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 415 "/usr/include/pthread.h" 3 4
extern int pthread_setschedparam (pthread_t __target_thread, int __policy,
      __const struct sched_param *__param)     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3)));
extern int pthread_getschedparam (pthread_t __target_thread,
      int *__restrict __policy,
      struct sched_param *__restrict __param)     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 3)));
extern int pthread_setschedprio (pthread_t __target_thread, int __prio)
     __attribute__ ((__nothrow__));
# 468 "/usr/include/pthread.h" 3 4
extern int pthread_once (pthread_once_t *__once_control,
    void (*__init_routine) (void)) __attribute__ ((__nonnull__ (1, 2)));
# 480 "/usr/include/pthread.h" 3 4
extern 
int pthread_setcancelstate (int __state, int *__oldstate);
extern 
int pthread_setcanceltype (int __type, int *__oldtype);
extern 
int pthread_cancel (pthread_t __th);
extern 
void pthread_testcancel (void);
typedef struct{  struct  {    __jmp_buf __cancel_jmp_buf;    int __mask_was_saved;  } __cancel_jmp_buf[1];  void *__pad[4];}
 
__pthread_unwind_buf_t __attribute__ ((__aligned__));
# 514 "/usr/include/pthread.h" 3 4
struct __pthread_cleanup_frame{  void (*__cancel_routine) (void *);  void *__cancel_arg;  int __do_it;  int __cancel_type;}
;
# 654 "/usr/include/pthread.h" 3 4
extern void __pthread_register_cancel (__pthread_unwind_buf_t *__buf)
     ;
# 666 "/usr/include/pthread.h" 3 4
extern void __pthread_unregister_cancel (__pthread_unwind_buf_t *__buf)
  ;
# 707 "/usr/include/pthread.h" 3 4
extern void __pthread_unwind_next (__pthread_unwind_buf_t *__buf)
     __attribute__ ((__noreturn__))
     __attribute__ ((__weak__))
     ;
struct __jmp_buf_tag;
extern 
int __sigsetjmp (struct __jmp_buf_tag *__env, int __savemask) __attribute__ ((__nothrow__));
extern int pthread_mutex_init (pthread_mutex_t *__mutex,
          __const pthread_mutexattr_t *__mutexattr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_destroy (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_trylock (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_lock (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_timedlock (pthread_mutex_t *__restrict __mutex,
                                    __const struct timespec *__restrict                                    __abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutex_unlock (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 769 "/usr/include/pthread.h" 3 4
extern int pthread_mutex_consistent_np (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 782 "/usr/include/pthread.h" 3 4
extern int pthread_mutexattr_init (pthread_mutexattr_t *__attr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_destroy (pthread_mutexattr_t *__attr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_getpshared (__const pthread_mutexattr_t *
      __restrict __attr,
      int *__restrict __pshared)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutexattr_setpshared (pthread_mutexattr_t *__attr,
      int __pshared)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 838 "/usr/include/pthread.h" 3 4
extern int pthread_mutexattr_getrobust (__const pthread_mutexattr_t *__attr,
     int *__robustness)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutexattr_setrobust (pthread_mutexattr_t *__attr,
     int __robustness)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 864 "/usr/include/pthread.h" 3 4
extern int pthread_rwlock_init (pthread_rwlock_t *__restrict __rwlock,
    __const pthread_rwlockattr_t *__restrict
    __attr) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_destroy (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_rdlock (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_tryrdlock (pthread_rwlock_t *__rwlock)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_timedrdlock (pthread_rwlock_t *__restrict __rwlock,
           __const struct timespec *__restrict           __abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_rwlock_wrlock (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_trywrlock (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_timedwrlock (pthread_rwlock_t *__restrict __rwlock,
           __const struct timespec *__restrict           __abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_rwlock_unlock (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlockattr_init (pthread_rwlockattr_t *__attr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlockattr_destroy (pthread_rwlockattr_t *__attr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlockattr_getpshared (__const pthread_rwlockattr_t *
       __restrict __attr,
       int *__restrict __pshared)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_rwlockattr_setpshared (pthread_rwlockattr_t *__attr,
       int __pshared)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlockattr_getkind_np (__const pthread_rwlockattr_t *
       __restrict __attr,
       int *__restrict __pref)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_rwlockattr_setkind_np (pthread_rwlockattr_t *__attr,
       int __pref) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_init (pthread_cond_t *__restrict __cond,
         __const pthread_condattr_t *__restrict
         __cond_attr) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_destroy (pthread_cond_t *__cond)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_signal (pthread_cond_t *__cond)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_broadcast (pthread_cond_t *__cond)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_wait (pthread_cond_t *__restrict __cond,
         pthread_mutex_t *__restrict __mutex)
     __attribute__ ((__nonnull__ (1, 2)));
# 976 "/usr/include/pthread.h" 3 4
extern int pthread_cond_timedwait (pthread_cond_t *__restrict __cond,
       pthread_mutex_t *__restrict __mutex,
       __const struct timespec *__restrict       __abstime) __attribute__ ((__nonnull__ (1, 2, 3)));
extern int pthread_condattr_init (pthread_condattr_t *__attr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_condattr_destroy (pthread_condattr_t *__attr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_condattr_getpshared (__const pthread_condattr_t *
                                        __restrict __attr,
                                        int *__restrict __pshared)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_condattr_setpshared (pthread_condattr_t *__attr,
                                        int __pshared) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_condattr_getclock (__const pthread_condattr_t *
          __restrict __attr,
          __clockid_t *__restrict __clock_id)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_condattr_setclock (pthread_condattr_t *__attr,
          __clockid_t __clock_id)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 1020 "/usr/include/pthread.h" 3 4
extern int pthread_spin_init (pthread_spinlock_t *__lock, int __pshared)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_destroy (pthread_spinlock_t *__lock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_lock (pthread_spinlock_t *__lock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_trylock (pthread_spinlock_t *__lock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_unlock (pthread_spinlock_t *__lock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrier_init (pthread_barrier_t *__restrict __barrier,
     __const pthread_barrierattr_t *__restrict
     __attr, unsigned int __count)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrier_destroy (pthread_barrier_t *__barrier)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrier_wait (pthread_barrier_t *__barrier)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrierattr_init (pthread_barrierattr_t *__attr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrierattr_destroy (pthread_barrierattr_t *__attr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrierattr_getpshared (__const pthread_barrierattr_t *
        __restrict __attr,
        int *__restrict __pshared)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_barrierattr_setpshared (pthread_barrierattr_t *__attr,
                                           int __pshared)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 1087 "/usr/include/pthread.h" 3 4
extern int pthread_key_create (pthread_key_t *__key,
          void (*__destr_function) (void *))
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern 
int pthread_key_delete (pthread_key_t __key) __attribute__ ((__nothrow__));
extern 
void *pthread_getspecific (pthread_key_t __key) __attribute__ ((__nothrow__));
extern int pthread_setspecific (pthread_key_t __key,
    __const void *__pointer) __attribute__ ((__nothrow__)) ;
extern int pthread_getcpuclockid (pthread_t __thread_id,
      __clockid_t *__clock_id)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
# 1121 "/usr/include/pthread.h" 3 4
extern int pthread_atfork (void (*__prepare) (void),
      void (*__parent) (void),
      void (*__child) (void)) __attribute__ ((__nothrow__));
# 1135 "/usr/include/pthread.h" 3 4
# 34 "demo.c" 2
# 47 "demo.c"
char log_buffer [10000];
void logging (char*);
void kill_handler (int);
unsigned last_internal_id;
pthread_mutex_t mutex1;
pthread_mutex_t mutex2;
pthread_mutex_t mutex3;
pthread_cond_t cond;
int virtual_memory_present;
enum BOOLEAN {FALSE,TRUE}
;
enum STATE{ BLOCKED, READY, RUNNING, TERMINATED}
;
struct _process{ unsigned pid; unsigned internal_id; enum STATE state; char* source_filename; pthread_cond_t cond; pthread_mutex_t mutex; pthread_mutex_t state_mutex; int waiting; int process_size; int page_frame_allocated; pthread_mutex_t IO_mutex; pthread_cond_t IO_cond_var;}
;
typedef struct _process Process;
struct _PCB{ Process* p; int priority;}
;
typedef struct _PCB PCB;
struct _Scheduler{ queue* PCB_list; PCB* cur_PCB;}
;
typedef struct _Scheduler Scheduler;
Scheduler* sched; unsigned pid; Process* p;
int main_p2(){pthread_mutex_unlock (&mutex2); {  
	io_start_instrumented(sched,2);
printf ("test2\n");
io_end_instrumented(sched,2);cc(sched,2);
 } return 0;
}
void init_p2 (Scheduler* s) {sched=s;}
