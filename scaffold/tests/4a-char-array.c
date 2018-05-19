/* -*-comment-start: "//";comment-end:""-*-
 * Mes --- Maxwell Equations of Software
 * Copyright © 2018 Jan (janneke) Nieuwenhuizen <janneke@gnu.org>
 *
 * This file is part of Mes.
 *
 * Mes is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
 *
 * Mes is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Mes.  If not, see <http://www.gnu.org/licenses/>.
 */

char g_hello[] =
    "hello\n"
    "world\n"
  ;

char *g_hello2 =
    "hello\n"
    "world\n"
  ;

char g_hello3[] =
  {
    'h', 'e', 'l', 'l', 'o', '\n',
    'w', 'o', 'r', 'l', 'd', '\n',
    '\0',
  }
  ;

int g_hello_int[] = {0, 1, 2, 3, 4, 5};

int
main (int argc)
{
  puts ("0:"); puts (g_hello); puts ("\n");
  puts ("2:"); puts (g_hello2); puts ("\n");
  puts ("3:"); puts (g_hello3); puts ("\n");
  if (strcmp (g_hello, g_hello2))
    return 1;

  if (strcmp (g_hello, g_hello3))
    return 2;

  char hello[] =
    "hello\n"
    "world\n"
    ;

  char *hello2 =
    "hello\n"
    "world\n"
    ;

  puts (hello);
  puts (hello2);
  if (strcmp (hello, hello2))
    return 3;

  char hello3[] =
    {
      'h', 'e', 'l', 'l', 'o', '\n',
      'w', 'o', 'r', 'l', 'd', '\n',
      '\0',
    }
    ;

  puts (hello3);
  if (strcmp (hello, hello3))
    return 4;

  if (g_hello_int[0])
    return 5;

  if (g_hello_int[1] != 1)
    return 6;

  int hello_int[] = {0, 1, 2, 3, 4, 5};
  if (hello_int[0])
    return 7;

  if (hello_int[1] != 1)
    return 8;

  return 0;
}
