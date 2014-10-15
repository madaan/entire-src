/*
  Copyright (C) 2003  Sridhar Ratnakumar <sridhar.ratna@gmail.com>
	
  This file is part of GNUSim8085.

  GNUSim8085 is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  GNUSim8085 is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with GNUSim8085; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA
  02110-1301, USA.
*/

/*
 * Data List
 *
 * R. Sridhar
 */

#ifndef __GUI_LIST_DATA_H__
#define __GUI_LIST_DATA_H__

#include <gtk/gtk.h>

G_BEGIN_DECLS

void gui_list_data_attach_me (void);

void gui_list_data_clear(void);

void gui_list_data_child_state (gboolean yes);

void gui_list_data_add(guint16 addr, const char *sym_name, guint8 val);

G_END_DECLS

#endif /* __GUI_LIST_DATA_H__*/
