/* -*-comment-start: "//";comment-end:""-*-
 * GNU Mes --- Maxwell Equations of Software
 * Copyright © 2017 Jan (janneke) Nieuwenhuizen <janneke@gnu.org>
 *
 * This file is part of GNU Mes.
 *
 * GNU Mes is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
 *
 * GNU Mes is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Mes.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libmes.h>
#include <libmes.h>
#include <stdlib.h>
#include <string.h>

int
main ()
{
  char *p = "mes";

  puts ("\n");
  puts ("t: itoa (33) == \"33\"\n");
  if (strcmp (itoa (33), "33"))
    return 1;

  puts ("strcmp (itoa (-1), \"-1\")\n");
  puts (itoa (-1));
  if (strcmp (itoa (-1), "-1"))
    return 2;

  puts ("strcmp (itoa (0), \"0\")\n");
  if (strcmp (itoa (0), "0"))
    return 3;

  puts ("strcmp (itoa (1), \"1\")\n");
  if (strcmp (itoa (1), "1"))
    return 4;

  return 0;
}
