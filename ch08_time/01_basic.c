#include <time.h>

#include <sys/timeb.h>

#ifdef __unix__
#  include <sys/time.h>
#endif

int main() {
  time_t t;
  clock_t clock;

  struct tm;
  //  {
  //    int	tm_sec;		/* seconds after the minute [0-60] */
  //    int	tm_min;		/* minutes after the hour [0-59] */
  //    int	tm_hour;	/* hours since midnight [0-23] */
  //    int	tm_mday;	/* day of the month [1-31] */
  //    int	tm_mon;		/* months since January [0-11] */
  //    int	tm_year;	/* years since 1900 */
  //    int	tm_wday;	/* days since Sunday [0-6] */
  //    int	tm_yday;	/* days since January 1 [0-365] */
  //    int	tm_isdst;	/* Daylight Savings Time flag */
  //    long	tm_gmtoff;	/* offset from UTC in seconds */
  //    char	*tm_zone;	/* timezone abbreviation */
  //  };

  struct timespec; // C11; MSVC
  //  {
  //    __darwin_time_t tv_sec;
  //    long            tv_nsec;
  //  };

  struct timeb;
  //  {
  //    time_t          time;           /* [XSI] Seconds since the Epoch */
  //    unsigned short  millitm;        /* [XSI] Milliseconds since the Epoch */
  //    short           timezone;       /* [XSI] Minutes west of CUT */
  //    short           dstflag;        /* [XSI] non-zero if DST in effect */
  //  };

#ifdef __unix__
  struct timeval;
#endif

  return 0;
}
