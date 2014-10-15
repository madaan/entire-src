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

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include "support.h"

GtkWidget*
lookup_widget                          (GtkWidget       *widget,
                                        const gchar     *widget_name)
{
  GtkWidget *parent, *found_widget;

  for (;;)
    {
      if (GTK_IS_MENU (widget))
        parent = gtk_menu_get_attach_widget (GTK_MENU (widget));
      else
        parent = widget->parent;
      if (!parent)
        parent = (GtkWidget*) g_object_get_data (G_OBJECT (widget), "GladeParentKey");
      if (parent == NULL)
        break;
      widget = parent;
    }

  found_widget = (GtkWidget*) g_object_get_data (G_OBJECT (widget),
                                                 widget_name);
  if (!found_widget)
    g_warning ("Widget not found: %s", widget_name);
  return found_widget;
}

GtkAction*
lookup_action_widget                          (GtkWidget       *widget,
											   const gchar     *widget_name)
{
  GtkWidget *parent;
  GtkAction *found_widget;

  for (;;)
    {
      if (GTK_IS_MENU (widget))
        parent = gtk_menu_get_attach_widget (GTK_MENU (widget));
      else
        parent = widget->parent;
      if (!parent)
        parent = (GtkWidget*) g_object_get_data (G_OBJECT (widget), "GladeParentKey");
      if (parent == NULL)
        break;
      widget = parent;
    }

  found_widget = (GtkAction*) g_object_get_data (G_OBJECT (widget),
                                                 widget_name);
  if (!found_widget)
    g_warning ("Widget not found: %s", widget_name);
  return found_widget;
}

/* This is an internally used function to create pixmaps. */
GdkPixbuf*
create_pixbuf                          (const gchar     *filename)
{
  gchar *pathname = NULL;
  GdkPixbuf *pixbuf;
  GError *error = NULL;

  if (!filename || !filename[0])
	return NULL;

  pathname = NULL;

  if (!pathname)
    {
	  GString *str;
	  str = g_string_new(PACKAGE_PIXMAPS_DIR);
	  g_string_append(str, "/");
	  g_string_append(str, filename);
	  pathname = g_strdup(str->str);
	  g_string_free(str, TRUE);
    }

  pixbuf = gdk_pixbuf_new_from_file (pathname, &error);
  if (!pixbuf)
    {
	  GString *str;
          error = NULL;
          pathname = NULL;
          str = g_string_new("pixmaps/");
          g_string_append(str, filename);
          pathname = g_strdup(str->str);
          g_string_free(str, TRUE);
          pixbuf = gdk_pixbuf_new_from_file (pathname, &error);
    }
  if (!pixbuf)
    {
      fprintf (stderr, "Failed to load pixbuf file: %s: %s\n",
               pathname, error->message);
      g_error_free (error);
    }
  g_free (pathname);
  return pixbuf;
}

gchar**
read_authors (){
  gchar *pathname = NULL;
  gchar **authors;
  FILE *fp;
  GString *gstr;
  char *ret;

  pathname = NULL;

  if (!pathname)
    {
	  GString *str;
	  str = g_string_new(PACKAGE_DOC_DIR);
	  g_string_append(str, "/");
	  g_string_append(str, "AUTHORS");
	  pathname = g_strdup(str->str);
	  g_string_free(str, TRUE);
    }
  fp = fopen (pathname, "r");

  if (fp == NULL)
    {
	  GString *str;
          pathname = NULL;
          str = g_string_new("");
          g_string_append(str, "AUTHORS");
          pathname = g_strdup(str->str);
          g_string_free(str, TRUE);
    }
  fp = fopen (pathname, "r");

  if (fp == NULL)
    {
      fprintf (stderr, "Failed to load authors file: %s\n",
               pathname);
      return NULL;
    }
  
  gstr = g_string_new ("");
  while (!feof (fp))
    {
      gchar buf[300] = { 0 };
      // return value stored just to avoid compiler warnings.
      ret = fgets (buf, 100, fp);
      g_string_append (gstr, buf);
    }
  authors = g_strsplit(gstr->str, "\n", -1);
  g_string_free (gstr, TRUE);
  g_free (pathname);
  return authors;
}

GString*
read_tutorial (){
  gchar *pathname = NULL;
  FILE *fp;
  GString *gstr;
  char *ret;

  pathname = NULL;

  if (!pathname)
    {
	  GString *str;
	  str = g_string_new(PACKAGE_DOC_DIR);
	  g_string_append(str, "/");
	  g_string_append(str, "asm-guide.txt");
	  pathname = g_strdup(str->str);
	  g_string_free(str, TRUE);
    }
  fp = fopen (pathname, "r");

  if (fp == NULL)
    {
	  GString *str;
          pathname = NULL;
          str = g_string_new("");
          g_string_append(str, "asm-guide.txt");
          pathname = g_strdup(str->str);
          g_string_free(str, TRUE);
    }
  fp = fopen (pathname, "r");

  if (fp == NULL)
    {
          GString *str;
          pathname = NULL;
          str = g_string_new("");
          g_string_append(str, "doc/asm-guide.txt");
          pathname = g_strdup(str->str);
          g_string_free(str, TRUE);
    }
  fp = fopen (pathname, "r");

  if (fp == NULL)
    {
      fprintf (stderr, "Failed to load tutorial file: %s\n",
               pathname);
      return NULL;
    }
  
  gstr = g_string_new ("");
  while (!feof (fp))
    {
      gchar buf[300] = { 0 };
      // return value stored just to avoid compiler warnings.
      ret = fgets (buf, 100, fp);
      g_string_append (gstr, buf);
    }
  g_free (pathname);
  return gstr;
}
