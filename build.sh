#! /bin/sh

# Mes --- Maxwell Equations of Software
# Copyright © 2017,2018 Jan (janneke) Nieuwenhuizen <janneke@gnu.org>
#
# This file is part of Mes.
#
# Mes is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or (at
# your option) any later version.
#
# Mes is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Mes.  If not, see <http://www.gnu.org/licenses/>.

set -ex

export CC=${CC-$(type -p gcc)}
export CC32=${CC32-$(type -p i686-unknown-linux-gnu-gcc)}
export MESCC=${MESCC-$(type -p mescc)}
export MES_SEED=${MES_SEED-../mes-seed}
export GUILE=${GUILE-$(type -p guile)}
export MES_ARENA=${MES_ARENA-300000000}
export MES_DEBUG=${MES_DEBUG-2}

export PREFIX=${PREFIX-/usr/local}
export DATADIR=${DATADIR-$PREFIX/share/mes}
export MODULEDIR=${MODULEDIR-$DATADIR/module}


if [ -n "$GUILE" ]; then
    sh build-aux/build-guile.sh
fi

if [ -n "$CC" ]; then
    sh build-aux/build-cc.sh
    cp src/mes.gcc-out src/mes
fi

if [ -n "$CC32" ]; then
    sh build-aux/build-mlibc.sh
    cp src/mes.mlibc-out src/mes
fi

sh build-aux/build-mes.sh
