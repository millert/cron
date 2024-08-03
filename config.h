/*
 * Copyright (c) 1988,1990,1993,1994,2021 by Paul Vixie ("VIXIE")
 * Copyright (c) 2004 by Internet Systems Consortium, Inc. ("ISC")
 * Copyright (c) 1997,2000 by Internet Software Consortium, Inc.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND VIXIE DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL VIXIE BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/* config.h - configurables for Vixie Cron
 *
 * $Id: config.h,v 1.11 2006/07/11 02:44:58 vixie Exp $
 */

/*
 * these are site-dependent
 */

#ifndef DEBUGGING
#define DEBUGGING 1	/* 1 or 0 -- do you want debugging code built in? */
#endif

			/*
			 * choose one of these mailer commands.  some use
			 * /bin/mail for speed; it makes biff bark but doesn't
			 * do aliasing.  sendmail does do aliasing but is
			 * a hog for short messages.  aliasing is not needed
			 * if you make use of the MAILTO= feature in crontabs.
			 * (hint: MAILTO= was added for this reason).
			 */

#define MAILFMT "%s -FCronDaemon -odi -oem -oi -t" /*-*/
			/* -Fx	 = Set full-name of sender
			 * -odi	 = Option Deliverymode Interactive
			 * -oem	 = Option Errors Mailedtosender
			 * -oi   = Ignore "." alone on a line
			 * -t    = Get recipient from headers
			 */
#define MAILARG _PATH_SENDMAIL				/*-*/

/* #define MAILFMT "%s -d %s"				/*-*/
			/* -d = undocumented but common flag: deliver locally?
			 */
/* #define MAILARG "/bin/mail",mailto

/* #define MAILFMT "%s -mlrxto %s"			/*-*/
/* #define MAILARG "/usr/mmdf/bin/submit",mailto	/*-*/

/* #define MAIL_DATE				/*-*/
			/* should we include an ersatz Date: header in
			 * generated mail?  if you are using sendmail
			 * as the mailer, it is better to let sendmail
			 * generate the Date: header.
			 */

/* #define MAIL_FROMUSER			/*-*/
			/* use this if you want all cron-job e-mail to come
			 * from the executing user rather than from "root".
			 */

			/* if you want to use syslog(3) instead of appending
			 * to CRONDIR/LOG_FILE (/var/cron/log, e.g.), define
			 * SYSLOG here.  Note that quite a bit of logging
			 * info is written, and that you probably don't want
			 * to use this on 4.2bsd since everything goes in
			 * /usr/spool/mqueue/syslog.  On 4.[34]bsd you can
			 * tell /etc/syslog.conf to send cron's logging to
			 * a separate file.
			 *
			 * Note that if this and LOG_FILE in "pathnames.h"
			 * are both defined, then logging will go to both
			 * places.
			 */
#define SYSLOG	 			/*-*/

			/* if your OS has a setproctitle() function. */
/*#define HAVE_SETPROCTITLE		/*-*/

			/* if you want cron to capitalize its name in ps
			 * when running a job.  Does not work on SYSV.
			 */
/*#define CAPITALIZE_FOR_PS		/*-*/

			/* if your OS has a futimens() function */
/*#define HAVE_FUTIMENS			/*-*/

			/* if you have a tm_gmtoff member in struct tm.
			 * If not, we will have to compute the value ourselves.
			 */
/*#define HAVE_TM_GMTOFF		/*-*/

			/* if your OS supports a BSD-style login.conf file */
/*#define LOGIN_CAP			/*-*/

			/* if your OS supports BSD authentication */
/*#define BSD_AUTH			/*-*/

			/* if you want built-in atrun support */
#define ATRUN				/*-*/

			/* if your OS has a getloadavg() function */
/*#define HAVE_GETLOADAVG              /*-*/

			/* Maximum load at which batch jobs will still run. */
			/* Only valid if HAVE_GETLOADAVG is defined above. */
#define BATCH_MAXLOAD 1.5		/*-*/

			/* Define this to run crontab setgid instead of   
			 * setuid root.  Group access will be used to read
			 * the tabs/atjobs dirs and the allow/deny files.
			 * If this is not defined then crontab and at
			 * must be setuid root.
			 */
/*#define CRON_GROUP	"crontab"	/*-*/
