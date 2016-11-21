/* -*-comment-start: "//";comment-end:""-*-
 * Mes --- Maxwell Equations of Software
 * Copyright © 2016 Jan Nieuwenhuizen <janneke@gnu.org>
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

#if !BOOT
SCM
define_env (SCM e, SCM a)
{
  return vm_call (vm_define_env, e, cell_undefined, a);
}

SCM
vm_define_env ()
{
  SCM x;
  SCM name = cadr (r1);
  if (type (name) != PAIR)
    x = eval_env (caddr (r1), cons (cons (cadr (r1), cadr (r1)), r0));
  else {
    name = car (name);
    SCM p = pairlis (cadr (r1), cadr (r1), r0);
    cache_invalidate_range (p, r0);
    x = eval_env (make_lambda (cdadr (r1), cddr (r1)), p);
  }
  if (eq_p (car (r1), cell_symbol_define_macro) == cell_t)
    x = make_macro (name, x);

  SCM entry = cons (name, x);
  SCM aa = cons (entry, cell_nil);
  set_cdr_x (aa, cdr (r0));
  set_cdr_x (r0, aa);
  SCM cl = assq (cell_closure, r0);
  set_cdr_x (cl, aa);
  return entry;
}
#else // BOOT
SCM define_env (SCM r1, SCM a){}
SCM vm_define_env (SCM r1, SCM a){}
#endif

SCM
define_macro (SCM r1, SCM a)
{
}
