/*
 * Copyright (c) 1996-1998 University of Utah and the Flux Group.
 * All rights reserved.
 * 
 * This file is part of the Flux OSKit.  The OSKit is free software, also known
 * as "open source;" you can redistribute it and/or modify it under the terms
 * of the GNU General Public License (GPL), version 2, as published by the Free
 * Software Foundation (FSF).  To explore alternate licensing terms, contact
 * the University of Utah at csl-dist@cs.utah.edu or +1-801-585-3271.
 * 
 * The OSKit is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GPL for more details.  You should have
 * received a copy of the GPL along with the OSKit; see the file COPYING.  If
 * not, write to the FSF, 59 Temple Place #330, Boston, MA 02111-1307, USA.
 */
#ifndef _OSKIT_C_STDDEF_H_
#define _OSKIT_C_STDDEF_H_

#include <oskit/types.h>

#ifndef _SIZE_T
#define _SIZE_T
typedef oskit_size_t size_t;
#endif

#ifndef _WCHAR_T
#define _WCHAR_T
typedef oskit_wchar_t wchar_t;
#endif

typedef long ptrdiff_t;

#ifndef NULL
#define NULL 0
#endif

#ifndef offsetof
#define	offsetof(type, member)	((size_t)(&((type *)0)->member))
#endif

#endif /* _OSKIT_C_STDDEF_H_ */
