/* 
** Copyright (C) 1994, 1995 Enterprise Integration Technologies Corp.
**         VeriFone Inc./Hewlett-Packard. All Rights Reserved.
** Kevin Hughes, kev@kevcom.com 3/11/94
** Kent Landfield, kent@landfield.com 4/6/97
** Hypermail Project 1998-2023
** 
** This program and library is free software; you can redistribute it and/or 
** modify it under the terms of the GNU (Library) General Public License 
** as published by the Free Software Foundation; either version 3
** of the License, or any later version. 
** 
** This program is distributed in the hope that it will be useful, 
** but WITHOUT ANY WARRANTY; without even the implied warranty of 
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
** GNU (Library) General Public License for more details. 
** 
** You should have received a copy of the GNU (Library) General Public License
** along with this program; if not, write to the Free Software 
** Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA 
*/

#include "hypermail.h"

/* Just a tiny malloc() error checker! */

void *emalloc(int i)
{
    void *p;

    if ((p = (void *)malloc(i)) == NULL)
	progerr(lang[MSG_RAN_OUT_OF_MEMORY]);
    return p;
}

#ifndef HAVE_MEMSET

void *memset(void *s, int c, size_t n)
{
    if (n != 0) {
	register char *d = s;

	do
	    *d++ = c;
	while (--n != 0);
    }
    return (s);
}

#endif
