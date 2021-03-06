/* t-strerror.c - Regression test.
   Copyright (C) 2003 g10 Code GmbH

   This file is part of libgpg-error.

   libgpg-error is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public License
   as published by the Free Software Foundation; either version 2.1 of
   the License, or (at your option) any later version.

   libgpg-error is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with libgpgme-error; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
   02111-1307, USA.  */

#include <config.h>
#include <stdio.h>
#include <stdlib.h>

#include <gpg-error.h>

int
strerror_main (int argc, char *argv[])
{
  if (argc > 1)
    {
      int i = 1;
      while (i + 1 < argc)
	{
	  gpg_error_t err = atoi (argv[i + 1]);
	  printf ("%s\n", gpg_strerror (err));
	  i += 2;
	}
    }
  else
    {
      gpg_error_t list[] = { 0, 201, 2, 102, 100, 99, 110, 7, 888 };
      int i = 0;

      while (i < sizeof (list) / sizeof (list[0]))
	{
	  gpg_error_t err = list[i];
	  printf ("%s\n", gpg_strerror (err));
	  i++;
	}
    }
  return 0;
}
