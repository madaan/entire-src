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
#include <config.h>
#endif

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name)						\
  g_object_set_data_full (G_OBJECT (component), name,					\
						  gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_ACTION_OBJECT(component,widget,name)				\
  g_object_set_data_full (G_OBJECT (component), name,					\
						  g_object_ref (widget), (GDestroyNotify) g_object_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name)	\
  g_object_set_data (G_OBJECT (component), name, widget)

static const GtkActionEntry entries[] = {
  { "FileMenu", NULL, N_("_File") },
  { "ResetMenu", NULL, N_("_Reset") },
  { "AssemblerMenu", NULL, N_("_Assembler") },
  { "DebugMenu", NULL, N_("_Debug") },
  { "BreakPointMenu", NULL, N_("_Breakpoints") },
  { "HelpMenu", NULL, N_("_Help") },
  { "New", GTK_STOCK_NEW, NULL, NULL, N_("New source file"), G_CALLBACK(on_new1_activate) },
  { "Open", GTK_STOCK_OPEN, NULL, NULL, N_("Open a file"), G_CALLBACK(on_open1_activate) },
  { "Save", GTK_STOCK_SAVE, NULL, NULL, N_("Save file"), G_CALLBACK(on_save1_activate) },
  { "SaveAs", GTK_STOCK_SAVE_AS, NULL, "<shift><control>S", N_("Save file as"), G_CALLBACK(on_save_as1_activate) },
  { "Print", GTK_STOCK_PRINT, NULL, "<control>P", N_("Print program"), G_CALLBACK(on_print_activate) },
  { "Font", GTK_STOCK_SELECT_FONT, NULL, "<control>f", N_("Select font"), G_CALLBACK(on_font_select_activate) },
  { "Quit", GTK_STOCK_QUIT, NULL, NULL, NULL, G_CALLBACK(on_quit1_activate) },
  { "Registers", NULL, N_("_Registers"), NULL, N_("Reset Registers"), G_CALLBACK(on_registers1_activate) },
  { "Flags", NULL, N_("_Flags"), NULL, N_("Reset Flags"), G_CALLBACK(on_flags1_activate) },
  { "IOPorts", NULL, N_("_IO Ports"), NULL, N_("Reset IO Ports"), G_CALLBACK(on_io_ports1_activate) },
  { "Memory", NULL, N_("_Memory"), NULL, N_("Reset Memory"), G_CALLBACK(on_main_memory1_activate) },
  { "ResetAll", GTK_STOCK_REFRESH, N_("Reset _All"), "<control>R", N_("Reset All"), G_CALLBACK(on_reset_all1_activate) },
  { "Assemble", GTK_STOCK_CONVERT, N_("A_ssemble"), "F8", N_("Only assemble program"), G_CALLBACK(on_assemble1_activate) },
  { "Execute", GTK_STOCK_EXECUTE, NULL, "F9", N_("Execute assembled and loaded program"), G_CALLBACK(on_execute1_activate) },
  { "Listing", GTK_STOCK_EDIT, N_("Show _listing"), "<control>L", N_("Show the source code along with opcodes and operands in hex numbers"), G_CALLBACK(on_show_listing1_activate) },
  { "StepIn", GTK_STOCK_GO_FORWARD, N_("Step _in"), "F5", N_("Step in the code"), G_CALLBACK(on_step_in1_activate) },
  { "StepOver", GTK_STOCK_GO_UP, N_("Step o_ver"), "F6", N_("Step over the code without calling functions"), G_CALLBACK(on_step_over1_activate) },
  { "StepOut", GTK_STOCK_GO_BACK, N_("Step _out"), "F7", N_("Step out of the current function"), G_CALLBACK(on_step_out1_activate) },
  { "ToggleBreak", GTK_STOCK_NO, N_("Toggle _breakpoint"), "<control>B", N_("Toggles breakpoint at current line"), G_CALLBACK(on_toggle_breakpoint1_activate) },
  { "ClearBreak", NULL, N_("_Clear all breakpoints"), "<control><shift>B", N_("Remove all breakpoints"), G_CALLBACK(on_clear_all_breakpoints1_activate) },
  { "StopExec", GTK_STOCK_STOP, N_("Stop execution"), NULL, N_("Stop debugging"), G_CALLBACK(on_stop_execution1_activate) },
  { "Help", GTK_STOCK_HELP, N_("_Contents"), "F1", NULL, G_CALLBACK(on_help_activate) },
  { "Manual", GTK_STOCK_INFO, N_("8085 _Manual"), "<control>M", NULL, G_CALLBACK(on_8085_manual1_activate) },
  { "Tutorial", GTK_STOCK_DIALOG_INFO, N_("Assembler _Tutorial"), "<control><shift>T", NULL, G_CALLBACK(on_assembler_tutorial1_activate) },
  { "About", GTK_STOCK_ABOUT, NULL, NULL, NULL, G_CALLBACK(on_about1_activate) }
};

static const GtkToggleActionEntry toggle_entries[] = {
  { "SidePane", GTK_STOCK_FULLSCREEN, NULL, NULL, N_("Show/Hide side pane"), G_CALLBACK (show_hide_side_pane) }
};

static const char *ui_description =
  "<ui>"
  "  <menubar name='MainMenu'>"
  "    <menu action='FileMenu'>"
  "      <menuitem action='New'/>"
  "      <menuitem action='Open'/>"
  "      <menuitem action='Save'/>"
  "      <menuitem action='SaveAs'/>"
  "      <menuitem action='Print'/>"
  "      <separator/>"
  "      <menuitem action='Font'/>"
  "      <separator/>"
  "      <menuitem action='Quit'/>"
  "    </menu>"
  "    <menu action='ResetMenu'>"
  "      <menuitem action='Registers'/>"
  "      <menuitem action='Flags'/>"
  "      <menuitem action='IOPorts'/>"
  "      <menuitem action='Memory'/>"
  "      <separator/>"
  "      <menuitem action='ResetAll'/>"
  "    </menu>"
  "    <menu action='AssemblerMenu'>"
  "      <menuitem action='Assemble'/>"
  "      <menuitem action='Execute'/>"
  "      <separator/>"
  "      <menuitem action='Listing'/>"
  "    </menu>"
  "    <menu action='DebugMenu'>"
  "      <menuitem action='StepIn'/>"
  "      <menuitem action='StepOver'/>"
  "      <menuitem action='StepOut'/>"
  "      <separator/>"
  "      <menu action='BreakPointMenu'>"
  "        <menuitem action='ToggleBreak'/>"
  "        <separator/>"
  "        <menuitem action='ClearBreak'/>"
  "      </menu>"
  "      <separator/>"
  "      <menuitem action='StopExec'/>"
  "    </menu>"
  "    <menu action='HelpMenu'>"
  "      <menuitem action='Help'/>"
  "      <separator/>"
  "      <menuitem action='Manual'/>"
  "      <menuitem action='Tutorial'/>"
  "      <separator/>"
  "      <menuitem action='About'/>"
  "    </menu>"
  "  </menubar>"
  "  <toolbar name='MainToolBar'>"
  "    <toolitem action='New'/>"
  "    <toolitem action='Open'/>"
  "    <toolitem action='Save'/>"
  "    <toolitem action='SaveAs'/>"
  "    <toolitem action='Print'/>"
  "    <separator/>"
  "    <toolitem action='Assemble'/>"
  "    <toolitem action='Execute'/>"
  "    <separator/>"
  "    <toolitem action='StepIn'/>"
  "    <toolitem action='StepOver'/>"
  "    <toolitem action='StepOut'/>"
  "    <separator/>"
  "    <toolitem action='ToggleBreak'/>"
  "    <toolitem action='StopExec'/>"
  "    <separator/>"
  "    <toolitem action='SidePane'/>"
  "  </toolbar>"
  "</ui>";

GtkWidget*
create_window_main (void)
{
  GtkWidget *window_main;
  GdkPixbuf *window_main_icon_pixbuf;
  GtkWidget *vbox1;
  GtkWidget *menubar1;
  GtkWidget *handlebox1;
  GtkWidget *toolbar1;
  GtkWidget *main_hpaned_left;
  GtkWidget *vbox9;
  GtkWidget *hbox15;
  GtkWidget *frame9;
  GtkWidget *table7;
  GtkWidget *label107;
  GtkWidget *label108;
  GtkWidget *label109;
  GtkWidget *label110;
  GtkWidget *label111;
  GtkWidget *label112;
  GtkWidget *label113;
  GtkWidget *main_reg_a;
  GtkWidget *main_reg_b;
  GtkWidget *main_reg_c;
  GtkWidget *main_reg_d;
  GtkWidget *main_reg_e;
  GtkWidget *main_reg_h;
  GtkWidget *main_reg_l;
  GtkWidget *main_reg_pswh;
  GtkWidget *main_reg_pswl;
  GtkWidget *main_reg_pch;
  GtkWidget *main_reg_pcl;
  GtkWidget *main_reg_sph;
  GtkWidget *main_reg_spl;
  GtkWidget *main_reg_int_reg;
  GtkWidget *label106;
  GtkWidget *registersbox;
  GtkWidget *label96;
  GtkWidget *frame10;
  GtkWidget *table8;
  GtkWidget *label129;
  GtkWidget *label130;
  GtkWidget *label131;
  GtkWidget *label132;
  GtkWidget *label133;
  GtkWidget *main_flag_s;
  GtkWidget *main_flag_z;
  GtkWidget *main_flag_ac;
  GtkWidget *main_flag_p;
  GtkWidget *main_flag_c;
  GtkWidget *flagsbox;
  GtkWidget *label163;
  GtkWidget *frame12;
  GtkWidget *hbox29;
  GtkWidget *vbox13;
  GtkWidget *label154;
  GtkWidget *main_entry_dec;
  GtkWidget *main_but_to_hex;
  GtkWidget *alignment7;
  GtkWidget *hbox30;
  GtkWidget *image293;
  GtkWidget *label156;
  GtkWidget *vbox14;
  GtkWidget *label155;
  GtkWidget *main_entry_hex;
  GtkWidget *main_but_to_dec;
  GtkWidget *alignment8;
  GtkWidget *hbox31;
  GtkWidget *image294;
  GtkWidget *label157;
  GtkWidget *hbox38;
  GtkWidget *image369;
  GtkWidget *label153;
  GtkWidget *vbox10;
  GtkWidget *frame6;
  GtkWidget *vbox11;
  GtkWidget *hbox13;
  GtkObject *main_io_spin_adj;
  GtkWidget *main_io_spin;
  GtkWidget *main_io_entry;
  GtkWidget *main_io_update;
  GtkWidget *alignment4;
  GtkWidget *hbox16;
  GtkWidget *image226;
  GtkWidget *label139;
  GtkWidget *hbox36;
  GtkWidget *image367;
  GtkWidget *label164;
  GtkWidget *frame8;
  GtkWidget *vbox12;
  GtkWidget *hbox14;
  GtkObject *main_mem_spin_adj;
  GtkWidget *main_mem_spin;
  GtkWidget *main_mem_entry;
  GtkWidget *main_mem_update;
  GtkWidget *alignment5;
  GtkWidget *hbox17;
  GtkWidget *image227;
  GtkWidget *label140;
  GtkWidget *hbox37;
  GtkWidget *image368;
  GtkWidget *label165;
  GtkWidget *main_hpaned_msg;
  GtkWidget *main_vpaned_data;
  GtkWidget *main_vbox_center;
  GtkWidget *hbox24;
  GtkWidget *label147;
  GtkWidget *main_entry_sa;
  GtkWidget *notebook5;
  GtkWidget *main_frame_data;
  GtkWidget *main_data_scroll;
  GtkWidget *label150;
  GtkWidget *hbox25;
  GtkWidget *image232;
  GtkWidget *label148;
  GtkWidget *frame11;
  GtkWidget *main_stack_scroll;
  GtkWidget *label152;
  GtkWidget *hbox26;
  GtkWidget *image233;
  GtkWidget *label149;
  GtkWidget *frame14;
  GtkWidget *main_keypad_scroll;
  GtkWidget *hbox40;
  GtkWidget *image371;
  GtkWidget *label168;
  GtkWidget *main_progressbar;
  GtkWidget *main_statusbar;
  GtkWidget *status_box;
  GtkWidget *main_memory_frame;
  GtkWidget *label177;
  GtkWidget *label178;
  GtkWidget *alignment12;
  GtkWidget *main_memory_scroll;
  GtkWidget *vbox19;
  GtkWidget *hbox48;
  GtkWidget *label179;
  GtkWidget *mem_list_start;
  GtkWidget *button12;
  GtkWidget *main_io_frame;
  GtkWidget *label180;
  GtkWidget *label181;
  GtkWidget *alignment13;
  GtkWidget *main_io_scroll;
  GtkWidget *vbox20;
  GtkWidget *hbox49;
  GtkWidget *label182;
  GtkWidget *io_list_start;
  GtkWidget *button13;
  GtkActionGroup *action_group;
  GtkUIManager *ui_manager;
  GtkAccelGroup *accel_group;
  GError *error;

  window_main = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window_main), _("GNUSim8085 - 8085 Microprocessor Simulator"));
  gtk_window_set_position (GTK_WINDOW (window_main), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size (GTK_WINDOW (window_main), 500, 400);
  window_main_icon_pixbuf = create_pixbuf ("gnusim8085.svg");
  if (!window_main_icon_pixbuf)
    window_main_icon_pixbuf = create_pixbuf ("gnusim8085.ico");

  if (window_main_icon_pixbuf)
    {
      gtk_window_set_icon (GTK_WINDOW (window_main), window_main_icon_pixbuf);
      gdk_pixbuf_unref (window_main_icon_pixbuf);
    }

  vbox1 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox1);
  gtk_container_add (GTK_CONTAINER (window_main), vbox1);

  action_group = gtk_action_group_new ("MenuActions");
  gtk_action_group_set_translation_domain (action_group, NULL);
  gtk_action_group_add_actions (action_group, entries, G_N_ELEMENTS (entries), window_main);
  gtk_action_group_add_toggle_actions (action_group, toggle_entries, G_N_ELEMENTS (toggle_entries), window_main);

  ui_manager = gtk_ui_manager_new ();
  gtk_ui_manager_insert_action_group (ui_manager, action_group, 0);

  accel_group = gtk_ui_manager_get_accel_group (ui_manager);
  gtk_window_add_accel_group (GTK_WINDOW (window_main), accel_group);

  error = NULL;
  if (!gtk_ui_manager_add_ui_from_string (ui_manager, ui_description, -1, &error))
    {
      g_message ("building menus failed: %s", error->message);
      g_error_free (error);
      exit (-1); // EXIT_FAILURE);
    }

  menubar1 = gtk_ui_manager_get_widget (ui_manager, "/MainMenu"); 
  gtk_box_pack_start (GTK_BOX (vbox1), menubar1, FALSE, FALSE, 0);
  gtk_widget_show (menubar1);

  handlebox1 = gtk_handle_box_new ();
  gtk_widget_show (handlebox1);
  gtk_box_pack_start (GTK_BOX (vbox1), handlebox1, FALSE, TRUE, 0);

  toolbar1 = gtk_ui_manager_get_widget (ui_manager, "/MainToolBar");
  gtk_widget_show (toolbar1);
  gtk_container_add (GTK_CONTAINER (handlebox1), toolbar1);
  gtk_toolbar_set_style (GTK_TOOLBAR (toolbar1), GTK_TOOLBAR_ICONS);

  main_hpaned_left = gtk_hpaned_new ();
  gtk_widget_show (main_hpaned_left);
  gtk_box_pack_start (GTK_BOX (vbox1), main_hpaned_left, TRUE, TRUE, 0);
  gtk_paned_set_position (GTK_PANED (main_hpaned_left), 230);

  vbox9 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox9);
  gtk_paned_pack1 (GTK_PANED (main_hpaned_left), vbox9, FALSE, TRUE);

  hbox15 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox15);
  gtk_box_pack_start (GTK_BOX (vbox9), hbox15, FALSE, TRUE, 0);

  frame9 = gtk_frame_new (NULL);
  gtk_widget_show (frame9);
  gtk_box_pack_start (GTK_BOX (hbox15), frame9, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame9), 5);

  table7 = gtk_table_new (8, 3, TRUE);
  gtk_widget_show (table7);
  gtk_container_add (GTK_CONTAINER (frame9), table7);
  gtk_container_set_border_width (GTK_CONTAINER (table7), 5);
  gtk_table_set_row_spacings (GTK_TABLE (table7), 10);
  gtk_table_set_col_spacings (GTK_TABLE (table7), 6);

  label107 = gtk_label_new ("<i>BC</i>");
  gtk_widget_show (label107);
  gtk_table_attach (GTK_TABLE (table7), label107, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_use_markup (GTK_LABEL (label107), TRUE);

  label108 = gtk_label_new ("<i>DE</i>");
  gtk_widget_show (label108);
  gtk_table_attach (GTK_TABLE (table7), label108, 0, 1, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_use_markup (GTK_LABEL (label108), TRUE);

  label109 = gtk_label_new ("<i>HL</i>");
  gtk_widget_show (label109);
  gtk_table_attach (GTK_TABLE (table7), label109, 0, 1, 3, 4,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_use_markup (GTK_LABEL (label109), TRUE);

  label110 = gtk_label_new ("<i>PSW</i>");
  gtk_widget_show (label110);
  gtk_table_attach (GTK_TABLE (table7), label110, 0, 1, 4, 5,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_use_markup (GTK_LABEL (label110), TRUE);

  label111 = gtk_label_new ("<i>PC</i>");
  gtk_widget_show (label111);
  gtk_table_attach (GTK_TABLE (table7), label111, 0, 1, 5, 6,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_use_markup (GTK_LABEL (label111), TRUE);

  label112 = gtk_label_new ("<i>SP</i>");
  gtk_widget_show (label112);
  gtk_table_attach (GTK_TABLE (table7), label112, 0, 1, 6, 7,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_use_markup (GTK_LABEL (label112), TRUE);

  label113 = gtk_label_new ("<i>Int-Reg</i>");
  gtk_widget_show (label113);
  gtk_table_attach (GTK_TABLE (table7), label113, 0, 1, 7, 8,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_use_markup (GTK_LABEL (label113), TRUE);

  main_reg_a = gtk_label_new (_("00"));
  gtk_widget_show (main_reg_a);
  gtk_table_attach (GTK_TABLE (table7), main_reg_a, 1, 3, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  main_reg_b = gtk_label_new (_("00"));
  gtk_widget_show (main_reg_b);
  gtk_table_attach (GTK_TABLE (table7), main_reg_b, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  main_reg_c = gtk_label_new (_("00"));
  gtk_widget_show (main_reg_c);
  gtk_table_attach (GTK_TABLE (table7), main_reg_c, 2, 3, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  main_reg_d = gtk_label_new (_("00"));
  gtk_widget_show (main_reg_d);
  gtk_table_attach (GTK_TABLE (table7), main_reg_d, 1, 2, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  main_reg_e = gtk_label_new (_("00"));
  gtk_widget_show (main_reg_e);
  gtk_table_attach (GTK_TABLE (table7), main_reg_e, 2, 3, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  main_reg_h = gtk_label_new (_("00"));
  gtk_widget_show (main_reg_h);
  gtk_table_attach (GTK_TABLE (table7), main_reg_h, 1, 2, 3, 4,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  main_reg_l = gtk_label_new (_("00"));
  gtk_widget_show (main_reg_l);
  gtk_table_attach (GTK_TABLE (table7), main_reg_l, 2, 3, 3, 4,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  main_reg_pswh = gtk_label_new (_("00"));
  gtk_widget_show (main_reg_pswh);
  gtk_table_attach (GTK_TABLE (table7), main_reg_pswh, 1, 2, 4, 5,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  main_reg_pswl = gtk_label_new (_("00"));
  gtk_widget_show (main_reg_pswl);
  gtk_table_attach (GTK_TABLE (table7), main_reg_pswl, 2, 3, 4, 5,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  main_reg_pch = gtk_label_new (_("00"));
  gtk_widget_show (main_reg_pch);
  gtk_table_attach (GTK_TABLE (table7), main_reg_pch, 1, 2, 5, 6,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  main_reg_pcl = gtk_label_new (_("00"));
  gtk_widget_show (main_reg_pcl);
  gtk_table_attach (GTK_TABLE (table7), main_reg_pcl, 2, 3, 5, 6,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  main_reg_sph = gtk_label_new (_("00"));
  gtk_widget_show (main_reg_sph);
  gtk_table_attach (GTK_TABLE (table7), main_reg_sph, 1, 2, 6, 7,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  main_reg_spl = gtk_label_new (_("00"));
  gtk_widget_show (main_reg_spl);
  gtk_table_attach (GTK_TABLE (table7), main_reg_spl, 2, 3, 6, 7,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  main_reg_int_reg = gtk_label_new (_("00"));
  gtk_widget_show (main_reg_int_reg);
  gtk_table_attach (GTK_TABLE (table7), main_reg_int_reg, 1, 3, 7, 8,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  label106 = gtk_label_new ("<i>A</i>");
  gtk_widget_show (label106);
  gtk_table_attach (GTK_TABLE (table7), label106, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_use_markup (GTK_LABEL (label106), TRUE);

  registersbox = gtk_hbox_new (FALSE, 5);
  gtk_widget_show (registersbox);
  gtk_frame_set_label_widget (GTK_FRAME (frame9), registersbox);

  label96 = gtk_label_new (g_strconcat("<b>", _("Registers"), "</b>", NULL));
  gtk_widget_show (label96);
  gtk_box_pack_start (GTK_BOX (registersbox), label96, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label96), TRUE);
  gtk_label_set_justify (GTK_LABEL (label96), GTK_JUSTIFY_LEFT);

  frame10 = gtk_frame_new (NULL);
  gtk_widget_show (frame10);
  gtk_box_pack_start (GTK_BOX (hbox15), frame10, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame10), 5);

  table8 = gtk_table_new (5, 2, TRUE);
  gtk_widget_show (table8);
  gtk_container_add (GTK_CONTAINER (frame10), table8);
  gtk_container_set_border_width (GTK_CONTAINER (table8), 5);
  gtk_table_set_row_spacings (GTK_TABLE (table8), 10);
  gtk_table_set_col_spacings (GTK_TABLE (table8), 5);

  label129 = gtk_label_new ("<i>S</i>");
  gtk_widget_show (label129);
  gtk_table_attach (GTK_TABLE (table8), label129, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_use_markup (GTK_LABEL (label129), TRUE);

  label130 = gtk_label_new ("<i>Z</i>");
  gtk_widget_show (label130);
  gtk_table_attach (GTK_TABLE (table8), label130, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_use_markup (GTK_LABEL (label130), TRUE);

  label131 = gtk_label_new ("<i>AC</i>");
  gtk_widget_show (label131);
  gtk_table_attach (GTK_TABLE (table8), label131, 0, 1, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_use_markup (GTK_LABEL (label131), TRUE);

  label132 = gtk_label_new ("<i>P</i>");
  gtk_widget_show (label132);
  gtk_table_attach (GTK_TABLE (table8), label132, 0, 1, 3, 4,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_use_markup (GTK_LABEL (label132), TRUE);

  label133 = gtk_label_new ("<i>C</i>");
  gtk_widget_show (label133);
  gtk_table_attach (GTK_TABLE (table8), label133, 0, 1, 4, 5,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_use_markup (GTK_LABEL (label133), TRUE);

  main_flag_s = gtk_label_new (_("0"));
  gtk_widget_show (main_flag_s);
  gtk_table_attach (GTK_TABLE (table8), main_flag_s, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  main_flag_z = gtk_label_new (_("0"));
  gtk_widget_show (main_flag_z);
  gtk_table_attach (GTK_TABLE (table8), main_flag_z, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  main_flag_ac = gtk_label_new (_("0"));
  gtk_widget_show (main_flag_ac);
  gtk_table_attach (GTK_TABLE (table8), main_flag_ac, 1, 2, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  main_flag_p = gtk_label_new (_("0"));
  gtk_widget_show (main_flag_p);
  gtk_table_attach (GTK_TABLE (table8), main_flag_p, 1, 2, 3, 4,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  main_flag_c = gtk_label_new (_("0"));
  gtk_widget_show (main_flag_c);
  gtk_table_attach (GTK_TABLE (table8), main_flag_c, 1, 2, 4, 5,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);

  flagsbox = gtk_hbox_new (FALSE, 5);
  gtk_widget_show (flagsbox);
  gtk_frame_set_label_widget (GTK_FRAME (frame10), flagsbox);

  label163 = gtk_label_new (g_strconcat("<b>", _("Flag"), "</b>", NULL));
  gtk_widget_show (label163);
  gtk_box_pack_start (GTK_BOX (flagsbox), label163, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label163), TRUE);
  gtk_label_set_justify (GTK_LABEL (label163), GTK_JUSTIFY_LEFT);

  frame12 = gtk_frame_new (NULL);
  gtk_widget_show (frame12);
  gtk_box_pack_start (GTK_BOX (vbox9), frame12, FALSE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame12), 5);

  hbox29 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox29);
  gtk_container_add (GTK_CONTAINER (frame12), hbox29);

  vbox13 = gtk_vbox_new (FALSE, 5);
  gtk_widget_show (vbox13);
  gtk_box_pack_start (GTK_BOX (hbox29), vbox13, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (vbox13), 5);

  label154 = gtk_label_new (_("Decimal"));
  gtk_widget_show (label154);
  gtk_box_pack_start (GTK_BOX (vbox13), label154, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label154), GTK_JUSTIFY_LEFT);

  main_entry_dec = gtk_entry_new ();
  gtk_widget_show (main_entry_dec);
  gtk_box_pack_start (GTK_BOX (vbox13), main_entry_dec, FALSE, FALSE, 0);
  gtk_widget_set_tooltip_text (main_entry_dec, _("Enter a decimal number"));
  gtk_entry_set_text (GTK_ENTRY (main_entry_dec), _("0"));

  main_but_to_hex = gtk_button_new ();
  gtk_widget_show (main_but_to_hex);
  gtk_box_pack_start (GTK_BOX (vbox13), main_but_to_hex, FALSE, FALSE, 0);
  gtk_widget_set_tooltip_text (main_but_to_hex, _("Convert this number to hexadecimal"));

  alignment7 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment7);
  gtk_container_add (GTK_CONTAINER (main_but_to_hex), alignment7);

  hbox30 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox30);
  gtk_container_add (GTK_CONTAINER (alignment7), hbox30);

  image293 = gtk_image_new_from_stock (GTK_STOCK_GO_FORWARD, GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image293);
  gtk_box_pack_start (GTK_BOX (hbox30), image293, FALSE, FALSE, 0);

  label156 = gtk_label_new_with_mnemonic (_("To Hex"));
  gtk_widget_show (label156);
  gtk_box_pack_start (GTK_BOX (hbox30), label156, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label156), GTK_JUSTIFY_LEFT);

  vbox14 = gtk_vbox_new (FALSE, 5);
  gtk_widget_show (vbox14);
  gtk_box_pack_start (GTK_BOX (hbox29), vbox14, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (vbox14), 5);

  label155 = gtk_label_new (_("Hex"));
  gtk_widget_show (label155);
  gtk_box_pack_start (GTK_BOX (vbox14), label155, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label155), GTK_JUSTIFY_LEFT);

  main_entry_hex = gtk_entry_new ();
  gtk_widget_show (main_entry_hex);
  gtk_box_pack_start (GTK_BOX (vbox14), main_entry_hex, FALSE, FALSE, 0);
  gtk_widget_set_tooltip_text (main_entry_hex, _("Enter a hexadecimal number"));
  gtk_entry_set_text (GTK_ENTRY (main_entry_hex), _("0"));

  main_but_to_dec = gtk_button_new ();
  gtk_widget_show (main_but_to_dec);
  gtk_box_pack_start (GTK_BOX (vbox14), main_but_to_dec, FALSE, FALSE, 0);
  gtk_widget_set_tooltip_text (main_but_to_dec, _("Convert this number to decimal"));

  alignment8 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment8);
  gtk_container_add (GTK_CONTAINER (main_but_to_dec), alignment8);

  hbox31 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox31);
  gtk_container_add (GTK_CONTAINER (alignment8), hbox31);

  image294 = gtk_image_new_from_stock (GTK_STOCK_GO_BACK, GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image294);
  gtk_box_pack_start (GTK_BOX (hbox31), image294, FALSE, FALSE, 0);

  label157 = gtk_label_new_with_mnemonic (_("To Dec"));
  gtk_widget_show (label157);
  gtk_box_pack_start (GTK_BOX (hbox31), label157, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label157), GTK_JUSTIFY_LEFT);

  hbox38 = gtk_hbox_new (FALSE, 5);
  gtk_widget_show (hbox38);
  gtk_frame_set_label_widget (GTK_FRAME (frame12), hbox38);

  image369 = gtk_image_new_from_stock (GTK_STOCK_DIALOG_INFO, GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image369);
  gtk_box_pack_start (GTK_BOX (hbox38), image369, TRUE, TRUE, 0);

  label153 = gtk_label_new (g_strconcat("<b>", _("Decimal - Hex Convertion"), "</b>", NULL));
  gtk_widget_show (label153);
  gtk_box_pack_start (GTK_BOX (hbox38), label153, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label153), TRUE);
  gtk_label_set_justify (GTK_LABEL (label153), GTK_JUSTIFY_LEFT);

  vbox10 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox10);
  gtk_box_pack_start (GTK_BOX (vbox9), vbox10, FALSE, TRUE, 0);

  frame6 = gtk_frame_new (NULL);
  gtk_widget_show (frame6);
  gtk_box_pack_start (GTK_BOX (vbox10), frame6, FALSE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame6), 5);

  vbox11 = gtk_vbox_new (FALSE, 5);
  gtk_widget_show (vbox11);
  gtk_container_add (GTK_CONTAINER (frame6), vbox11);
  gtk_container_set_border_width (GTK_CONTAINER (vbox11), 5);

  hbox13 = gtk_hbox_new (FALSE, 5);
  gtk_widget_show (hbox13);
  gtk_box_pack_start (GTK_BOX (vbox11), hbox13, TRUE, TRUE, 0);

  main_io_spin_adj = gtk_adjustment_new (0, 0, 255, 1, 10, 0);
  main_io_spin = gtk_spin_button_new (GTK_ADJUSTMENT (main_io_spin_adj), 1, 0);
  gtk_widget_show (main_io_spin);
  gtk_box_pack_start (GTK_BOX (hbox13), main_io_spin, TRUE, TRUE, 0);
  gtk_widget_set_tooltip_text (main_io_spin, _("Change the port address to view here"));
  gtk_spin_button_set_numeric (GTK_SPIN_BUTTON (main_io_spin), TRUE);
  gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (main_io_spin), TRUE);

  main_io_entry = gtk_entry_new ();
  gtk_widget_show (main_io_entry);
  gtk_box_pack_start (GTK_BOX (hbox13), main_io_entry, TRUE, TRUE, 0);
  gtk_widget_set_tooltip_text (main_io_entry, _("Enter new port value and click Update"));
  gtk_entry_set_text (GTK_ENTRY (main_io_entry), _("0"));

  main_io_update = gtk_button_new ();
  gtk_widget_show (main_io_update);
  gtk_box_pack_start (GTK_BOX (vbox11), main_io_update, FALSE, FALSE, 0);
  gtk_widget_set_tooltip_text (main_io_update, _("Update the port value"));

  alignment4 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment4);
  gtk_container_add (GTK_CONTAINER (main_io_update), alignment4);

  hbox16 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox16);
  gtk_container_add (GTK_CONTAINER (alignment4), hbox16);

  image226 = gtk_image_new_from_stock (GTK_STOCK_REFRESH, GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image226);
  gtk_box_pack_start (GTK_BOX (hbox16), image226, FALSE, FALSE, 0);

  label139 = gtk_label_new_with_mnemonic (_("Update Port Value"));
  gtk_widget_show (label139);
  gtk_box_pack_start (GTK_BOX (hbox16), label139, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label139), GTK_JUSTIFY_LEFT);

  hbox36 = gtk_hbox_new (FALSE, 5);
  gtk_widget_show (hbox36);
  gtk_frame_set_label_widget (GTK_FRAME (frame6), hbox36);

  image367 = gtk_image_new_from_stock (GTK_STOCK_JUSTIFY_FILL, GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image367);
  gtk_box_pack_start (GTK_BOX (hbox36), image367, TRUE, TRUE, 0);

  label164 = gtk_label_new (g_strconcat("<b>", _("I/O Ports"), "</b>", NULL));
  gtk_widget_show (label164);
  gtk_box_pack_start (GTK_BOX (hbox36), label164, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label164), TRUE);
  gtk_label_set_justify (GTK_LABEL (label164), GTK_JUSTIFY_LEFT);

  frame8 = gtk_frame_new (NULL);
  gtk_widget_show (frame8);
  gtk_box_pack_start (GTK_BOX (vbox10), frame8, FALSE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame8), 5);

  vbox12 = gtk_vbox_new (FALSE, 5);
  gtk_widget_show (vbox12);
  gtk_container_add (GTK_CONTAINER (frame8), vbox12);
  gtk_container_set_border_width (GTK_CONTAINER (vbox12), 5);

  hbox14 = gtk_hbox_new (FALSE, 5);
  gtk_widget_show (hbox14);
  gtk_box_pack_start (GTK_BOX (vbox12), hbox14, TRUE, TRUE, 0);

  main_mem_spin_adj = gtk_adjustment_new (0, 0, 65535, 1, 10, 0);
  main_mem_spin = gtk_spin_button_new (GTK_ADJUSTMENT (main_mem_spin_adj), 1, 0);
  gtk_widget_show (main_mem_spin);
  gtk_box_pack_start (GTK_BOX (hbox14), main_mem_spin, TRUE, TRUE, 0);
  gtk_widget_set_tooltip_text (main_mem_spin, _("Change the memory location to view here"));
  gtk_spin_button_set_numeric (GTK_SPIN_BUTTON (main_mem_spin), TRUE);
  gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (main_mem_spin), TRUE);

  main_mem_entry = gtk_entry_new ();
  gtk_widget_show (main_mem_entry);
  gtk_box_pack_start (GTK_BOX (hbox14), main_mem_entry, TRUE, TRUE, 0);
  gtk_widget_set_tooltip_text (main_mem_entry, _("Edit new value and click Update"));
  gtk_entry_set_text (GTK_ENTRY (main_mem_entry), _("0"));

  main_mem_update = gtk_button_new ();
  gtk_widget_show (main_mem_update);
  gtk_box_pack_start (GTK_BOX (vbox12), main_mem_update, FALSE, FALSE, 0);
  gtk_widget_set_tooltip_text (main_mem_update, _("Update the current memory location"));

  alignment5 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment5);
  gtk_container_add (GTK_CONTAINER (main_mem_update), alignment5);

  hbox17 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox17);
  gtk_container_add (GTK_CONTAINER (alignment5), hbox17);

  image227 = gtk_image_new_from_stock (GTK_STOCK_REFRESH, GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image227);
  gtk_box_pack_start (GTK_BOX (hbox17), image227, FALSE, FALSE, 0);

  label140 = gtk_label_new_with_mnemonic (_("Update Memory"));
  gtk_widget_show (label140);
  gtk_box_pack_start (GTK_BOX (hbox17), label140, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label140), GTK_JUSTIFY_LEFT);

  hbox37 = gtk_hbox_new (FALSE, 5);
  gtk_widget_show (hbox37);
  gtk_frame_set_label_widget (GTK_FRAME (frame8), hbox37);

  image368 = gtk_image_new_from_stock (GTK_STOCK_JUSTIFY_FILL, GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image368);
  gtk_box_pack_start (GTK_BOX (hbox37), image368, TRUE, TRUE, 0);

  label165 = gtk_label_new (g_strconcat("<b>", _("Memory"), "</b>", NULL));
  gtk_widget_show (label165);
  gtk_box_pack_start (GTK_BOX (hbox37), label165, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label165), TRUE);
  gtk_label_set_justify (GTK_LABEL (label165), GTK_JUSTIFY_LEFT);

  main_hpaned_msg = gtk_hpaned_new ();
  gtk_widget_show (main_hpaned_msg);
  gtk_paned_pack2 (GTK_PANED (main_hpaned_left), main_hpaned_msg, TRUE, FALSE);
  gtk_paned_set_position (GTK_PANED (main_hpaned_msg), 400);

  main_vpaned_data = gtk_vpaned_new ();
  gtk_widget_show (main_vpaned_data);
  gtk_paned_pack2 (GTK_PANED (main_hpaned_msg), main_vpaned_data, FALSE, FALSE);
  gtk_paned_set_position (GTK_PANED (main_vpaned_data), 400);

  main_vbox_center = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (main_vbox_center);
  gtk_paned_pack1 (GTK_PANED (main_hpaned_msg), main_vbox_center, FALSE, FALSE);
  gtk_container_set_border_width (GTK_CONTAINER (main_vbox_center), 5);

  hbox24 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox24);
  gtk_box_pack_start (GTK_BOX (main_vbox_center), hbox24, FALSE, FALSE, 5);

  label147 = gtk_label_new (_("Load me at"));
  gtk_widget_show (label147);
  gtk_box_pack_start (GTK_BOX (hbox24), label147, FALSE, FALSE, 5);
  gtk_label_set_justify (GTK_LABEL (label147), GTK_JUSTIFY_LEFT);

  main_entry_sa = gtk_entry_new ();
  gtk_widget_show (main_entry_sa);
  gtk_box_pack_start (GTK_BOX (hbox24), main_entry_sa, TRUE, TRUE, 0);
  gtk_widget_set_tooltip_text (main_entry_sa, _("Enter the program address.  End with a 'h' if it is a hex address."));
  gtk_entry_set_max_length (GTK_ENTRY (main_entry_sa), 100);

  notebook5 = gtk_notebook_new ();
  gtk_widget_show (notebook5);
  gtk_paned_pack1 (GTK_PANED (main_vpaned_data), notebook5, TRUE, TRUE);

  main_frame_data = gtk_frame_new (NULL);
  gtk_widget_show (main_frame_data);
  gtk_container_add (GTK_CONTAINER (notebook5), main_frame_data);
  gtk_container_set_border_width (GTK_CONTAINER (main_frame_data), 5);

  main_data_scroll = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (main_data_scroll);
  gtk_container_add (GTK_CONTAINER (main_frame_data), main_data_scroll);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (main_data_scroll), GTK_SHADOW_OUT);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (main_data_scroll), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

  label150 = gtk_label_new (_("Variables"));
  gtk_widget_show (label150);
  gtk_frame_set_label_widget (GTK_FRAME (main_frame_data), label150);
  gtk_label_set_justify (GTK_LABEL (label150), GTK_JUSTIFY_LEFT);

  hbox25 = gtk_hbox_new (FALSE, 5);
  gtk_widget_show (hbox25);
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook5), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook5), 0), hbox25);

  image232 = gtk_image_new_from_stock (GTK_STOCK_EXECUTE, GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image232);
  gtk_box_pack_start (GTK_BOX (hbox25), image232, TRUE, TRUE, 0);

  label148 = gtk_label_new (_("Data"));
  gtk_widget_show (label148);
  gtk_box_pack_start (GTK_BOX (hbox25), label148, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label148), GTK_JUSTIFY_LEFT);

  frame11 = gtk_frame_new (NULL);
  gtk_widget_show (frame11);
  gtk_container_add (GTK_CONTAINER (notebook5), frame11);
  gtk_container_set_border_width (GTK_CONTAINER (frame11), 5);

  main_stack_scroll = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (main_stack_scroll);
  gtk_container_add (GTK_CONTAINER (frame11), main_stack_scroll);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (main_stack_scroll), GTK_SHADOW_OUT);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (main_stack_scroll), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

  label152 = gtk_label_new (_("Stack Trace"));
  gtk_widget_show (label152);
  gtk_frame_set_label_widget (GTK_FRAME (frame11), label152);
  gtk_label_set_justify (GTK_LABEL (label152), GTK_JUSTIFY_LEFT);

  hbox26 = gtk_hbox_new (FALSE, 5);
  gtk_widget_show (hbox26);
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook5), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook5), 1), hbox26);

  image233 = gtk_image_new_from_stock (GTK_STOCK_EXECUTE, GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image233);
  gtk_box_pack_start (GTK_BOX (hbox26), image233, TRUE, TRUE, 0);

  label149 = gtk_label_new (_("Stack"));
  gtk_widget_show (label149);
  gtk_box_pack_start (GTK_BOX (hbox26), label149, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label149), GTK_JUSTIFY_LEFT);

  frame14 = gtk_frame_new (NULL);
  gtk_widget_show (frame14);
  gtk_container_add (GTK_CONTAINER (notebook5), frame14);
  gtk_container_set_border_width (GTK_CONTAINER (frame14), 5);

  main_keypad_scroll = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (main_keypad_scroll);
  gtk_container_add (GTK_CONTAINER (frame14), main_keypad_scroll);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (main_keypad_scroll), GTK_SHADOW_OUT);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (main_keypad_scroll), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

  hbox40 = gtk_hbox_new (FALSE, 5);
  gtk_widget_show (hbox40);
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook5), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook5), 2), hbox40);

  image371 = gtk_image_new_from_stock (GTK_STOCK_INDEX, GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image371);
  gtk_box_pack_start (GTK_BOX (hbox40), image371, TRUE, TRUE, 0);

  label168 = gtk_label_new (_("KeyPad"));
  gtk_widget_show (label168);
  gtk_box_pack_start (GTK_BOX (hbox40), label168, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label168), GTK_JUSTIFY_LEFT);
   
  main_memory_frame = gtk_frame_new (NULL);
  gtk_widget_show (main_memory_frame);
  gtk_container_add (GTK_CONTAINER (notebook5), main_memory_frame);
  gtk_container_set_border_width (GTK_CONTAINER (main_memory_frame), 5);

  label178 = gtk_label_new (_("Memory"));
  gtk_widget_show (label178);
  gtk_frame_set_label_widget (GTK_FRAME (main_memory_frame), label178);
  gtk_label_set_justify (GTK_LABEL (label178), GTK_JUSTIFY_LEFT);
  
  label177 = gtk_label_new (_("Memory"));
  gtk_widget_show (label177);
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook5), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook5), 3), label177);
  
  alignment12 = gtk_alignment_new (0.50, 0.50, 1.00, 1.00);
  gtk_widget_show (alignment12);
  gtk_container_add (GTK_CONTAINER (main_memory_frame), alignment12);
  
  vbox19 = gtk_vbox_new (FALSE, 2);
  gtk_widget_show (vbox19);
  gtk_container_add (GTK_CONTAINER (alignment12), vbox19);
  
  hbox48 = gtk_hbox_new (FALSE, 3);
  gtk_widget_show (hbox48);
  gtk_box_pack_start (GTK_BOX (vbox19), hbox48, FALSE, TRUE, 0);
  
  label179 = gtk_label_new (_("Start"));
  gtk_widget_show (label179);
  gtk_box_pack_start (GTK_BOX (hbox48), label179, FALSE, FALSE, 3);
  
  mem_list_start = gtk_entry_new ();
  gtk_widget_show (mem_list_start);
  gtk_box_pack_start (GTK_BOX (hbox48), mem_list_start, TRUE, TRUE, 5);
  
  button12 = gtk_button_new_from_stock (GTK_STOCK_OK);
  gtk_widget_show (button12);
  gtk_box_pack_start (GTK_BOX (hbox48), button12, FALSE, FALSE, 5);
  
  main_memory_scroll = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (main_memory_scroll);
  gtk_container_add (GTK_CONTAINER (vbox19), main_memory_scroll);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (main_memory_scroll), GTK_SHADOW_OUT);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (main_memory_scroll), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

  main_io_frame = gtk_frame_new (NULL);
  gtk_widget_show (main_io_frame);
  gtk_container_add (GTK_CONTAINER (notebook5), main_io_frame);
  gtk_container_set_border_width (GTK_CONTAINER (main_io_frame), 5);

  label180 = gtk_label_new (_("I/O Ports"));
  gtk_widget_show (label180);
  gtk_frame_set_label_widget (GTK_FRAME (main_io_frame), label180);
  gtk_label_set_justify (GTK_LABEL (label178), GTK_JUSTIFY_LEFT);
  
  label181 = gtk_label_new (_("I/O Ports"));
  gtk_widget_show (label181);
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook5), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook5), 4), label181);
  
  alignment13 = gtk_alignment_new (0.50, 0.50, 1.00, 1.00);
  gtk_widget_show (alignment13);
  gtk_container_add (GTK_CONTAINER (main_io_frame), alignment13);
  
  vbox20 = gtk_vbox_new (FALSE, 2);
  gtk_widget_show (vbox20);
  gtk_container_add (GTK_CONTAINER (alignment13), vbox20);
  
  hbox49 = gtk_hbox_new (FALSE, 3);
  gtk_widget_show (hbox49);
  gtk_box_pack_start (GTK_BOX (vbox20), hbox49, FALSE, TRUE, 0);
  
  label182 = gtk_label_new (_("Start"));
  gtk_widget_show (label182);
  gtk_box_pack_start (GTK_BOX (hbox49), label182, FALSE, FALSE, 3);
  
  io_list_start = gtk_entry_new ();
  gtk_widget_show (io_list_start);
  gtk_box_pack_start (GTK_BOX (hbox49), io_list_start, TRUE, TRUE, 5);
  
  button13 = gtk_button_new_from_stock (GTK_STOCK_OK);
  gtk_widget_show (button13);
  gtk_box_pack_start (GTK_BOX (hbox49), button13, FALSE, FALSE, 5);
  
  main_io_scroll = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (main_io_scroll);
  gtk_container_add (GTK_CONTAINER (vbox20), main_io_scroll);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (main_io_scroll), GTK_SHADOW_OUT);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (main_io_scroll), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

  main_progressbar = gtk_progress_bar_new();
  main_statusbar = gtk_statusbar_new();
  gtk_widget_show (main_progressbar);
  gtk_widget_show (main_statusbar);
  status_box = gtk_hbox_new(FALSE, 2);
  gtk_widget_show (status_box);
  gtk_box_pack_end (GTK_BOX (vbox1), status_box, FALSE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (status_box), main_progressbar, FALSE, TRUE, 2);
  gtk_box_pack_start (GTK_BOX (status_box), main_statusbar, TRUE, TRUE, 2);

  g_signal_connect ((gpointer) window_main, "delete_event",
                    G_CALLBACK (on_window_main_delete_event),
                    NULL);
  g_signal_connect ((gpointer) main_entry_dec, "activate",
                    G_CALLBACK (on_main_entry_dec_activate),
                    NULL);
  g_signal_connect ((gpointer) main_but_to_hex, "clicked",
                    G_CALLBACK (on_main_but_to_hex_clicked),
                    NULL);
  g_signal_connect ((gpointer) main_entry_hex, "activate",
                    G_CALLBACK (on_main_entry_hex_activate),
                    NULL);
  g_signal_connect ((gpointer) main_but_to_dec, "clicked",
                    G_CALLBACK (on_main_but_to_dec_clicked),
                    NULL);
  g_signal_connect ((gpointer) main_io_spin, "changed",
                    G_CALLBACK (on_main_io_spin_changed),
                    NULL);
  g_signal_connect ((gpointer) main_io_update, "clicked",
                    G_CALLBACK (on_main_io_update_clicked),
                    NULL);
  g_signal_connect ((gpointer) main_mem_spin, "changed",
                    G_CALLBACK (on_main_mem_spin_changed),
                    NULL);
  g_signal_connect ((gpointer) main_mem_update, "clicked",
                    G_CALLBACK (on_main_mem_update_clicked),
                    NULL);
  g_signal_connect ((gpointer) button12, "clicked",
                    G_CALLBACK (on_mem_list_start_clicked),
                    NULL);
  g_signal_connect ((gpointer) mem_list_start, "activate",
                    G_CALLBACK (on_mem_list_start_changed),
                    NULL);
  g_signal_connect ((gpointer) button13, "clicked",
                    G_CALLBACK (on_io_list_start_clicked),
                    NULL);
  g_signal_connect ((gpointer) io_list_start, "activate",
                    G_CALLBACK (on_io_list_start_changed),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window_main, window_main, "window_main");
  GLADE_HOOKUP_OBJECT (window_main, vbox1, "vbox1");
  GLADE_HOOKUP_OBJECT (window_main, menubar1, "menubar1");
  GLADE_HOOKUP_OBJECT (window_main, handlebox1, "handlebox1");
  GLADE_HOOKUP_OBJECT (window_main, toolbar1, "toolbar1");
  GLADE_HOOKUP_OBJECT (window_main, main_hpaned_left, "main_hpaned_left");
  GLADE_HOOKUP_OBJECT (window_main, vbox9, "vbox9");
  GLADE_HOOKUP_OBJECT (window_main, hbox15, "hbox15");
  GLADE_HOOKUP_OBJECT (window_main, frame9, "frame9");
  GLADE_HOOKUP_OBJECT (window_main, table7, "table7");
  GLADE_HOOKUP_OBJECT (window_main, label107, "label107");
  GLADE_HOOKUP_OBJECT (window_main, label108, "label108");
  GLADE_HOOKUP_OBJECT (window_main, label109, "label109");
  GLADE_HOOKUP_OBJECT (window_main, label110, "label110");
  GLADE_HOOKUP_OBJECT (window_main, label111, "label111");
  GLADE_HOOKUP_OBJECT (window_main, label112, "label112");
  GLADE_HOOKUP_OBJECT (window_main, label113, "label113");
  GLADE_HOOKUP_OBJECT (window_main, main_reg_a, "main_reg_a");
  GLADE_HOOKUP_OBJECT (window_main, main_reg_b, "main_reg_b");
  GLADE_HOOKUP_OBJECT (window_main, main_reg_c, "main_reg_c");
  GLADE_HOOKUP_OBJECT (window_main, main_reg_d, "main_reg_d");
  GLADE_HOOKUP_OBJECT (window_main, main_reg_e, "main_reg_e");
  GLADE_HOOKUP_OBJECT (window_main, main_reg_h, "main_reg_h");
  GLADE_HOOKUP_OBJECT (window_main, main_reg_l, "main_reg_l");
  GLADE_HOOKUP_OBJECT (window_main, main_reg_pswh, "main_reg_pswh");
  GLADE_HOOKUP_OBJECT (window_main, main_reg_pswl, "main_reg_pswl");
  GLADE_HOOKUP_OBJECT (window_main, main_reg_pch, "main_reg_pch");
  GLADE_HOOKUP_OBJECT (window_main, main_reg_pcl, "main_reg_pcl");
  GLADE_HOOKUP_OBJECT (window_main, main_reg_sph, "main_reg_sph");
  GLADE_HOOKUP_OBJECT (window_main, main_reg_spl, "main_reg_spl");
  GLADE_HOOKUP_OBJECT (window_main, main_reg_int_reg, "main_reg_int_reg");
  GLADE_HOOKUP_OBJECT (window_main, label106, "label106");
  GLADE_HOOKUP_OBJECT (window_main, registersbox, "registersbox");
  GLADE_HOOKUP_OBJECT (window_main, label96, "label96");
  GLADE_HOOKUP_OBJECT (window_main, frame10, "frame10");
  GLADE_HOOKUP_OBJECT (window_main, table8, "table8");
  GLADE_HOOKUP_OBJECT (window_main, label129, "label129");
  GLADE_HOOKUP_OBJECT (window_main, label130, "label130");
  GLADE_HOOKUP_OBJECT (window_main, label131, "label131");
  GLADE_HOOKUP_OBJECT (window_main, label132, "label132");
  GLADE_HOOKUP_OBJECT (window_main, label133, "label133");
  GLADE_HOOKUP_OBJECT (window_main, main_flag_s, "main_flag_s");
  GLADE_HOOKUP_OBJECT (window_main, main_flag_z, "main_flag_z");
  GLADE_HOOKUP_OBJECT (window_main, main_flag_ac, "main_flag_ac");
  GLADE_HOOKUP_OBJECT (window_main, main_flag_p, "main_flag_p");
  GLADE_HOOKUP_OBJECT (window_main, main_flag_c, "main_flag_c");
  GLADE_HOOKUP_OBJECT (window_main, flagsbox, "flagsbox");
  GLADE_HOOKUP_OBJECT (window_main, label163, "label163");
  GLADE_HOOKUP_OBJECT (window_main, frame12, "frame12");
  GLADE_HOOKUP_OBJECT (window_main, hbox29, "hbox29");
  GLADE_HOOKUP_OBJECT (window_main, vbox13, "vbox13");
  GLADE_HOOKUP_OBJECT (window_main, label154, "label154");
  GLADE_HOOKUP_OBJECT (window_main, main_entry_dec, "main_entry_dec");
  GLADE_HOOKUP_OBJECT (window_main, main_but_to_hex, "main_but_to_hex");
  GLADE_HOOKUP_OBJECT (window_main, alignment7, "alignment7");
  GLADE_HOOKUP_OBJECT (window_main, hbox30, "hbox30");
  GLADE_HOOKUP_OBJECT (window_main, image293, "image293");
  GLADE_HOOKUP_OBJECT (window_main, label156, "label156");
  GLADE_HOOKUP_OBJECT (window_main, vbox14, "vbox14");
  GLADE_HOOKUP_OBJECT (window_main, label155, "label155");
  GLADE_HOOKUP_OBJECT (window_main, main_entry_hex, "main_entry_hex");
  GLADE_HOOKUP_OBJECT (window_main, main_but_to_dec, "main_but_to_dec");
  GLADE_HOOKUP_OBJECT (window_main, alignment8, "alignment8");
  GLADE_HOOKUP_OBJECT (window_main, hbox31, "hbox31");
  GLADE_HOOKUP_OBJECT (window_main, image294, "image294");
  GLADE_HOOKUP_OBJECT (window_main, label157, "label157");
  GLADE_HOOKUP_OBJECT (window_main, hbox38, "hbox38");
  GLADE_HOOKUP_OBJECT (window_main, image369, "image369");
  GLADE_HOOKUP_OBJECT (window_main, label153, "label153");
  GLADE_HOOKUP_OBJECT (window_main, vbox10, "vbox10");
  GLADE_HOOKUP_OBJECT (window_main, frame6, "frame6");
  GLADE_HOOKUP_OBJECT (window_main, vbox11, "vbox11");
  GLADE_HOOKUP_OBJECT (window_main, hbox13, "hbox13");
  GLADE_HOOKUP_OBJECT (window_main, main_io_spin, "main_io_spin");
  GLADE_HOOKUP_OBJECT (window_main, main_io_entry, "main_io_entry");
  GLADE_HOOKUP_OBJECT (window_main, main_io_update, "main_io_update");
  GLADE_HOOKUP_OBJECT (window_main, alignment4, "alignment4");
  GLADE_HOOKUP_OBJECT (window_main, hbox16, "hbox16");
  GLADE_HOOKUP_OBJECT (window_main, image226, "image226");
  GLADE_HOOKUP_OBJECT (window_main, label139, "label139");
  GLADE_HOOKUP_OBJECT (window_main, hbox36, "hbox36");
  GLADE_HOOKUP_OBJECT (window_main, image367, "image367");
  GLADE_HOOKUP_OBJECT (window_main, label164, "label164");
  GLADE_HOOKUP_OBJECT (window_main, frame8, "frame8");
  GLADE_HOOKUP_OBJECT (window_main, vbox12, "vbox12");
  GLADE_HOOKUP_OBJECT (window_main, hbox14, "hbox14");
  GLADE_HOOKUP_OBJECT (window_main, main_mem_spin, "main_mem_spin");
  GLADE_HOOKUP_OBJECT (window_main, main_mem_entry, "main_mem_entry");
  GLADE_HOOKUP_OBJECT (window_main, main_mem_update, "main_mem_update");
  GLADE_HOOKUP_OBJECT (window_main, alignment5, "alignment5");
  GLADE_HOOKUP_OBJECT (window_main, hbox17, "hbox17");
  GLADE_HOOKUP_OBJECT (window_main, image227, "image227");
  GLADE_HOOKUP_OBJECT (window_main, label140, "label140");
  GLADE_HOOKUP_OBJECT (window_main, hbox37, "hbox37");
  GLADE_HOOKUP_OBJECT (window_main, image368, "image368");
  GLADE_HOOKUP_OBJECT (window_main, label165, "label165");
  GLADE_HOOKUP_OBJECT (window_main, main_hpaned_msg, "main_hpaned_msg");
  GLADE_HOOKUP_OBJECT (window_main, main_vpaned_data, "main_vpaned_data");
  GLADE_HOOKUP_OBJECT (window_main, main_vbox_center, "main_vbox_center");
  GLADE_HOOKUP_OBJECT (window_main, hbox24, "hbox24");
  GLADE_HOOKUP_OBJECT (window_main, label147, "label147");
  GLADE_HOOKUP_OBJECT (window_main, main_entry_sa, "main_entry_sa");
  GLADE_HOOKUP_OBJECT (window_main, notebook5, "notebook5");
  GLADE_HOOKUP_OBJECT (window_main, main_frame_data, "main_frame_data");
  GLADE_HOOKUP_OBJECT (window_main, main_data_scroll, "main_data_scroll");
  GLADE_HOOKUP_OBJECT (window_main, label150, "label150");
  GLADE_HOOKUP_OBJECT (window_main, hbox25, "hbox25");
  GLADE_HOOKUP_OBJECT (window_main, image232, "image232");
  GLADE_HOOKUP_OBJECT (window_main, label148, "label148");
  GLADE_HOOKUP_OBJECT (window_main, frame11, "frame11");
  GLADE_HOOKUP_OBJECT (window_main, main_stack_scroll, "main_stack_scroll");
  GLADE_HOOKUP_OBJECT (window_main, label152, "label152");
  GLADE_HOOKUP_OBJECT (window_main, hbox26, "hbox26");
  GLADE_HOOKUP_OBJECT (window_main, image233, "image233");
  GLADE_HOOKUP_OBJECT (window_main, label149, "label149");
  GLADE_HOOKUP_OBJECT (window_main, frame14, "frame14");
  GLADE_HOOKUP_OBJECT (window_main, main_keypad_scroll, "main_keypad_scroll");
  GLADE_HOOKUP_OBJECT (window_main, hbox40, "hbox40");
  GLADE_HOOKUP_OBJECT (window_main, image371, "image371");
  GLADE_HOOKUP_OBJECT (window_main, label168, "label168");
  GLADE_HOOKUP_OBJECT (window_main, main_memory_frame, "main_memory_frame");
  GLADE_HOOKUP_OBJECT (window_main, alignment12, "alignment12");
  GLADE_HOOKUP_OBJECT (window_main, vbox19, "vbox19");
  GLADE_HOOKUP_OBJECT (window_main, hbox48, "hbox48");
  GLADE_HOOKUP_OBJECT (window_main, label179, "label179");
  GLADE_HOOKUP_OBJECT (window_main, mem_list_start, "mem_list_start");
  GLADE_HOOKUP_OBJECT (window_main, button12, "button12");
  GLADE_HOOKUP_OBJECT (window_main, main_memory_scroll, "main_memory_scroll");
  GLADE_HOOKUP_OBJECT (window_main, label178, "label178");
  GLADE_HOOKUP_OBJECT (window_main, label177, "label177");
  GLADE_HOOKUP_OBJECT (window_main, main_io_frame, "main_io_frame");
  GLADE_HOOKUP_OBJECT (window_main, alignment13, "alignment13");
  GLADE_HOOKUP_OBJECT (window_main, vbox20, "vbox20");
  GLADE_HOOKUP_OBJECT (window_main, hbox49, "hbox49");
  GLADE_HOOKUP_OBJECT (window_main, label182, "label182");
  GLADE_HOOKUP_OBJECT (window_main, io_list_start, "io_list_start");
  GLADE_HOOKUP_OBJECT (window_main, button13, "button13");
  GLADE_HOOKUP_OBJECT (window_main, main_io_scroll, "main_io_scroll");
  GLADE_HOOKUP_OBJECT (window_main, label181, "label181");
  GLADE_HOOKUP_OBJECT (window_main, label180, "label180");
  GLADE_HOOKUP_OBJECT (window_main, main_progressbar, "main_progressbar");
  GLADE_HOOKUP_OBJECT (window_main, main_statusbar, "main_statusbar");
  GLADE_HOOKUP_ACTION_OBJECT (window_main, gtk_ui_manager_get_action (ui_manager, "/MainMenu/FileMenu/New"), "newfile"); 
  GLADE_HOOKUP_ACTION_OBJECT (window_main, gtk_ui_manager_get_action (ui_manager, "/MainMenu/FileMenu/Open"), "openfile"); 
  GLADE_HOOKUP_ACTION_OBJECT (window_main, gtk_ui_manager_get_action (ui_manager, "/MainMenu/FileMenu/Save"), "savefile"); 
  GLADE_HOOKUP_ACTION_OBJECT (window_main, gtk_ui_manager_get_action (ui_manager, "/MainMenu/FileMenu/SaveAs"), "savefileas"); 
  GLADE_HOOKUP_ACTION_OBJECT (window_main, gtk_ui_manager_get_action (ui_manager, "/MainMenu/ResetMenu/Registers"), "resetregisters"); 
  GLADE_HOOKUP_ACTION_OBJECT (window_main, gtk_ui_manager_get_action (ui_manager, "/MainMenu/ResetMenu/Flags"), "resetflags"); 
  GLADE_HOOKUP_ACTION_OBJECT (window_main, gtk_ui_manager_get_action (ui_manager, "/MainMenu/ResetMenu/IOPorts"), "resetports"); 
  GLADE_HOOKUP_ACTION_OBJECT (window_main, gtk_ui_manager_get_action (ui_manager, "/MainMenu/ResetMenu/Memory"), "resetmemory"); 
  GLADE_HOOKUP_ACTION_OBJECT (window_main, gtk_ui_manager_get_action (ui_manager, "/MainMenu/ResetMenu/ResetAll"), "resetall"); 
  GLADE_HOOKUP_ACTION_OBJECT (window_main, gtk_ui_manager_get_action (ui_manager, "/MainMenu/AssemblerMenu/Assemble"), "assemble"); 
  GLADE_HOOKUP_ACTION_OBJECT (window_main, gtk_ui_manager_get_action (ui_manager, "/MainMenu/AssemblerMenu/Listing"), "listing"); 
  GLADE_HOOKUP_ACTION_OBJECT (window_main, gtk_ui_manager_get_action (ui_manager, "/MainMenu/DebugMenu/StopExec"), "stop_debug"); 

  gtk_widget_grab_focus (main_entry_sa);
  return window_main;
}

void
activate_url (GtkAboutDialog *about, const gchar *url, gpointer data)
{
#if GTK_CHECK_VERSION (2, 14, 0)
    gtk_show_uri (NULL, url, GDK_CURRENT_TIME, NULL);
#endif
}

void
create_dialog_about (void)
{
  gchar **authors = read_authors();
  const gchar *documenters[] = {
    "Sridhar Ratnakumar (sridhar.ratna@gmail.com)",
    NULL
  };
  /* TRANSLATORS: Replace this string with your names, one name per line. */
  gchar *name = "GNUSim8085";
  gchar *copyright = "Copyright (C) 2003 Sridhar Ratnakumar";
  gchar *comments = "8085 Microprocessor Simulator";
  gchar *translators = _("translator_credits");
  GdkPixbuf *dialog_about_logo_pixbuf;
  GdkPixbuf *dialog_about_icon_pixbuf;

  if (!strcmp (translators, "translator_credits"))
    translators = NULL;
  dialog_about_logo_pixbuf = create_pixbuf ("gnusim8085.svg");
  if (!dialog_about_logo_pixbuf)
    dialog_about_logo_pixbuf = create_pixbuf ("gnusim8085.ico");

  dialog_about_icon_pixbuf = create_pixbuf ("gnusim8085.svg");
  if (!dialog_about_icon_pixbuf)
    dialog_about_icon_pixbuf = create_pixbuf ("gnusim8085.ico");

  gtk_show_about_dialog (NULL,
						 "name", name,
						 "version", VERSION,
						 "comments", comments,
						 "copyright", copyright,
						 "website", PACKAGE_URL,
						 "logo", dialog_about_logo_pixbuf,
						 "icon", dialog_about_icon_pixbuf,
						 "authors", authors,
						 "documenters", documenters,
						 "translator-credits", translators,
						 "border-width", 5,
						 NULL);

  if (dialog_about_icon_pixbuf)
	g_object_unref (dialog_about_icon_pixbuf);
    
  if (dialog_about_logo_pixbuf)
	g_object_unref (dialog_about_logo_pixbuf);
}

GtkWidget*
create_window_listing (void)
{
  GtkWidget *window_listing;
  GdkPixbuf *window_listing_icon_pixbuf;
  GtkWidget *listing_vbox;
  GtkWidget *hbuttonbox1;
  GtkWidget *listing_save;
  GtkWidget *listing_print;

  window_listing = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window_listing), _("Assembler Listing"));
  gtk_window_set_position (GTK_WINDOW (window_listing), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size (GTK_WINDOW (window_listing), 500, 400);
  window_listing_icon_pixbuf = create_pixbuf ("gnusim8085.svg");
  if (!window_listing_icon_pixbuf)
    window_listing_icon_pixbuf = create_pixbuf ("gnusim8085.ico");

  if (window_listing_icon_pixbuf)
    {
      gtk_window_set_icon (GTK_WINDOW (window_listing), window_listing_icon_pixbuf);
      gdk_pixbuf_unref (window_listing_icon_pixbuf);
    }

  listing_vbox = gtk_vbox_new (FALSE, 2);
  gtk_widget_show (listing_vbox);
  gtk_container_add (GTK_CONTAINER (window_listing), listing_vbox);
  gtk_container_set_border_width (GTK_CONTAINER (listing_vbox), 5);

  hbuttonbox1 = gtk_hbutton_box_new ();
  gtk_widget_show (hbuttonbox1);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (hbuttonbox1), GTK_BUTTONBOX_CENTER);
  gtk_box_pack_start (GTK_BOX (listing_vbox), hbuttonbox1, FALSE, FALSE, 0);

  listing_save = gtk_button_new ();
  gtk_button_set_label (GTK_BUTTON(listing_save), _("Save to file"));
  gtk_button_set_image (GTK_BUTTON(listing_save), gtk_image_new_from_stock (GTK_STOCK_SAVE_AS, GTK_ICON_SIZE_BUTTON));
  gtk_widget_show (listing_save);
  gtk_box_pack_start (GTK_BOX (hbuttonbox1), listing_save, FALSE, FALSE, 0);
  GTK_WIDGET_SET_FLAGS (listing_save, GTK_CAN_DEFAULT);

  g_signal_connect ((gpointer) listing_save, "clicked",
                    G_CALLBACK (on_listing_save_clicked),
                    NULL);

  listing_print = gtk_button_new_from_stock (GTK_STOCK_PRINT);
  gtk_widget_show (listing_print);
  gtk_box_pack_start (GTK_BOX (hbuttonbox1), listing_print, FALSE, FALSE, 0);
  GTK_WIDGET_SET_FLAGS (listing_print, GTK_CAN_DEFAULT);

  g_signal_connect ((gpointer) listing_print, "clicked",
                    G_CALLBACK (on_listing_print_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window_listing, window_listing, "window_listing");
  GLADE_HOOKUP_OBJECT (window_listing, listing_vbox, "listing_vbox");
  GLADE_HOOKUP_OBJECT (window_listing, hbuttonbox1, "hbuttonbox1");
  GLADE_HOOKUP_OBJECT (window_listing, listing_save, "listing_save");
  GLADE_HOOKUP_OBJECT (window_listing, listing_save, "listing_print");

  return window_listing;
}

GtkWidget*
create_window_tutorial (void)
{
  GtkWidget *window_tutorial;
  GdkPixbuf *window_tutorial_icon_pixbuf;
  GtkWidget *tutorial_vbox;

  window_tutorial = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window_tutorial), _("Assembler Listing"));
  gtk_window_set_position (GTK_WINDOW (window_tutorial), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size (GTK_WINDOW (window_tutorial), 500, 400);
  window_tutorial_icon_pixbuf = create_pixbuf ("gnusim8085.svg");
  if (!window_tutorial_icon_pixbuf)
    window_tutorial_icon_pixbuf = create_pixbuf ("gnusim8085.ico");

  if (window_tutorial_icon_pixbuf)
    {
      gtk_window_set_icon (GTK_WINDOW (window_tutorial), window_tutorial_icon_pixbuf);
      gdk_pixbuf_unref (window_tutorial_icon_pixbuf);
    }

  tutorial_vbox = gtk_vbox_new (FALSE, 2);
  gtk_widget_show (tutorial_vbox);
  gtk_container_add (GTK_CONTAINER (window_tutorial), tutorial_vbox);
  gtk_container_set_border_width (GTK_CONTAINER (tutorial_vbox), 5);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window_tutorial, window_tutorial, "window_tutorial");
  GLADE_HOOKUP_OBJECT (window_tutorial, tutorial_vbox, "tutorial_vbox");

  return window_tutorial;
}

GtkWidget*
create_window_start (void)
{
  GtkWidget *window_start;
  GdkPixbuf *window_start_icon_pixbuf;
  GtkWidget *vbox15;
  GtkWidget *frame13;
  GtkWidget *vbox16;
  GtkWidget *vbox17;
  GtkWidget *label159;
  GtkWidget *start_but_tutorial;
  GtkWidget *vbox18;
  GtkWidget *label161;
  GtkWidget *start_but_open;
  GtkWidget *label158;
  GtkWidget *start_but_close;
  GtkWidget *label166;

  window_start = gtk_dialog_new ();
  gtk_window_set_title (GTK_WINDOW (window_start), _("GNUSim8085 start with dialog"));
  gtk_window_set_position (GTK_WINDOW (window_start), GTK_WIN_POS_CENTER);
  gtk_window_set_modal (GTK_WINDOW (window_start), TRUE);
  gtk_window_set_resizable (GTK_WINDOW (window_start), FALSE);
  window_start_icon_pixbuf = create_pixbuf ("gnusim8085.svg");
  if (!window_start_icon_pixbuf)
    window_start_icon_pixbuf = create_pixbuf ("gnusim8085.ico");

  if (window_start_icon_pixbuf)
    {
      gtk_window_set_icon (GTK_WINDOW (window_start), window_start_icon_pixbuf);
      gdk_pixbuf_unref (window_start_icon_pixbuf);
    }

  vbox15 = GTK_DIALOG (window_start)-> vbox;
  gtk_container_set_border_width (GTK_CONTAINER (vbox15), 5);

  frame13 = gtk_frame_new (NULL);
  gtk_widget_show (frame13);
  gtk_box_pack_start (GTK_BOX (vbox15), frame13, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame13), 5);

  vbox16 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox16);
  gtk_container_add (GTK_CONTAINER (frame13), vbox16);

  vbox17 = gtk_vbox_new (FALSE, 5);
  gtk_widget_show (vbox17);
  gtk_box_pack_start (GTK_BOX (vbox16), vbox17, FALSE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (vbox17), 10);

  label159 = gtk_label_new (_("1. How to use this simulator?"));
  gtk_widget_show (label159);
  gtk_box_pack_start (GTK_BOX (vbox17), label159, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label159), GTK_JUSTIFY_LEFT);
  gtk_label_set_line_wrap (GTK_LABEL (label159), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label159), 0, 0.5);

  start_but_tutorial = gtk_button_new ();
  gtk_button_set_label (GTK_BUTTON(start_but_tutorial), _("_Tutorial"));
  gtk_button_set_image (GTK_BUTTON(start_but_tutorial), gtk_image_new_from_stock (GTK_STOCK_HELP, GTK_ICON_SIZE_BUTTON));
  gtk_button_set_use_underline (GTK_BUTTON(start_but_tutorial), TRUE);
  gtk_widget_show (start_but_tutorial);
  gtk_box_pack_start (GTK_BOX (vbox17), start_but_tutorial, FALSE, FALSE, 0);
  gtk_widget_set_tooltip_text (start_but_tutorial, _("A short tutorial on writing assembly code!"));

  vbox18 = gtk_vbox_new (FALSE, 5);
  gtk_widget_show (vbox18);
  gtk_box_pack_start (GTK_BOX (vbox16), vbox18, FALSE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (vbox18), 10);

  label161 = gtk_label_new (_("2. Open an existing assembly program."));
  gtk_widget_show (label161);
  gtk_box_pack_start (GTK_BOX (vbox18), label161, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label161), GTK_JUSTIFY_LEFT);
  gtk_label_set_line_wrap (GTK_LABEL (label161), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label161), 0, 0.5);

  start_but_open = gtk_button_new ();
  gtk_button_set_label (GTK_BUTTON(start_but_open), _("_Open program"));
  gtk_button_set_image (GTK_BUTTON(start_but_open), gtk_image_new_from_stock (GTK_STOCK_OPEN, GTK_ICON_SIZE_BUTTON));
  gtk_button_set_use_underline (GTK_BUTTON(start_but_open), TRUE);
  gtk_widget_show (start_but_open);
  gtk_box_pack_start (GTK_BOX (vbox18), start_but_open, FALSE, FALSE, 0);
  gtk_widget_set_tooltip_text (start_but_open, _("Open an already saved program"));

  label158 = gtk_label_new (_("What do you want to do now?"));
  gtk_widget_show (label158);
  gtk_frame_set_label_widget (GTK_FRAME (frame13), label158);
  gtk_label_set_justify (GTK_LABEL (label158), GTK_JUSTIFY_LEFT);

  start_but_close = gtk_button_new_from_stock (GTK_STOCK_CLOSE);
  gtk_widget_show (start_but_close);
  gtk_box_pack_end (GTK_BOX (vbox15), start_but_close, FALSE, FALSE, 0);
  GTK_WIDGET_SET_FLAGS (start_but_close, GTK_CAN_DEFAULT);

  label166 = gtk_label_new (_("Don't forget to read the documentation \ngiven in \"doc\" directory."));
  gtk_widget_show (label166);
  gtk_box_pack_start (GTK_BOX (vbox15), label166, FALSE, FALSE, 5);

  g_signal_connect ((gpointer) window_start, "delete_event",
                    G_CALLBACK (gtk_widget_destroy),
                    NULL);
  g_signal_connect ((gpointer) start_but_tutorial, "clicked",
                    G_CALLBACK (on_start_but_tutorial_clicked),
                    NULL);
  g_signal_connect ((gpointer) start_but_open, "clicked",
                    G_CALLBACK (on_start_but_open_clicked),
                    NULL);
  g_signal_connect ((gpointer) start_but_close, "clicked",
                    G_CALLBACK (on_start_but_close_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window_start, window_start, "window_start");
  GLADE_HOOKUP_OBJECT (window_start, vbox15, "vbox15");
  GLADE_HOOKUP_OBJECT (window_start, frame13, "frame13");
  GLADE_HOOKUP_OBJECT (window_start, vbox16, "vbox16");
  GLADE_HOOKUP_OBJECT (window_start, vbox17, "vbox17");
  GLADE_HOOKUP_OBJECT (window_start, label159, "label159");
  GLADE_HOOKUP_OBJECT (window_start, start_but_tutorial, "start_but_tutorial");
  GLADE_HOOKUP_OBJECT (window_start, vbox18, "vbox18");
  GLADE_HOOKUP_OBJECT (window_start, label161, "label161");
  GLADE_HOOKUP_OBJECT (window_start, start_but_open, "start_but_open");
  GLADE_HOOKUP_OBJECT (window_start, label158, "label158");
  GLADE_HOOKUP_OBJECT (window_start, start_but_close, "start_but_close");
  GLADE_HOOKUP_OBJECT (window_start, label166, "label166");

  gtk_widget_grab_focus (start_but_close);
  return window_start;
}

GtkWidget*
create_dialog_isymbol (void)
{
  GtkWidget *dialog_isymbol;
  GdkPixbuf *dialog_isymbol_icon_pixbuf;
  GtkWidget *dialog_vbox1;
  GtkWidget *isymbol_vbox;
  GtkWidget *label170;
  GtkWidget *hbox44;
  GtkWidget *label171;
  GtkWidget *entry1;
  GtkWidget *hbox45;
  GtkWidget *label174;
  GtkWidget *isymbol_variables;
  GtkWidget *isymbol_variables_entry;
  GtkWidget *hbox46;
  GtkWidget *label175;
  GtkWidget *isymbol_labels;
  GtkWidget *isymbol_functions_entry;
  GtkWidget *hbox47;
  GtkWidget *label176;
  GtkWidget *isymbol_macros;
  GtkWidget *isymbol_macros_entry;
  GtkWidget *dialog_action_area1;

  dialog_isymbol = gtk_dialog_new_with_buttons (_("Choose a symbol"),
												NULL,
												GTK_DIALOG_MODAL,
												GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
												GTK_STOCK_OK, GTK_RESPONSE_OK,
												NULL);
  gtk_window_set_position (GTK_WINDOW (dialog_isymbol), GTK_WIN_POS_MOUSE);
  gtk_window_set_resizable (GTK_WINDOW (dialog_isymbol), FALSE);
  dialog_isymbol_icon_pixbuf = create_pixbuf ("gnusim8085.svg");
  if (!dialog_isymbol_icon_pixbuf)
    dialog_isymbol_icon_pixbuf = create_pixbuf ("gnusim8085.ico");

  if (dialog_isymbol_icon_pixbuf)
    {
      gtk_window_set_icon (GTK_WINDOW (dialog_isymbol), dialog_isymbol_icon_pixbuf);
      gdk_pixbuf_unref (dialog_isymbol_icon_pixbuf);
    }

  dialog_vbox1 = GTK_DIALOG (dialog_isymbol)->vbox;
  gtk_widget_show (dialog_vbox1);

  isymbol_vbox = gtk_vbox_new (FALSE, 2);
  gtk_widget_show (isymbol_vbox);
  gtk_box_pack_start (GTK_BOX (dialog_vbox1), isymbol_vbox, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (isymbol_vbox), 5);

  label170 = gtk_label_new (_("Enter a symbol or choose one from the lists"));
  gtk_widget_show (label170);
  gtk_box_pack_start (GTK_BOX (isymbol_vbox), label170, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label170), GTK_JUSTIFY_LEFT);

  hbox44 = gtk_hbox_new (FALSE, 5);
  gtk_widget_show (hbox44);
  gtk_box_pack_start (GTK_BOX (isymbol_vbox), hbox44, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (hbox44), 2);

  label171 = gtk_label_new (_("Enter Symbol"));
  gtk_widget_show (label171);
  gtk_box_pack_start (GTK_BOX (hbox44), label171, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label171), GTK_JUSTIFY_LEFT);

  entry1 = gtk_entry_new ();
  gtk_widget_show (entry1);
  gtk_box_pack_start (GTK_BOX (hbox44), entry1, TRUE, TRUE, 0);

  hbox45 = gtk_hbox_new (TRUE, 5);
  gtk_widget_show (hbox45);
  gtk_box_pack_start (GTK_BOX (isymbol_vbox), hbox45, FALSE, FALSE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (hbox45), 2);

  label174 = gtk_label_new (_("Variables List"));
  gtk_widget_show (label174);
  gtk_box_pack_start (GTK_BOX (hbox45), label174, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label174), GTK_JUSTIFY_LEFT);

  isymbol_variables = gtk_combo_new ();
  g_object_set_data (G_OBJECT (GTK_COMBO (isymbol_variables)->popwin),
                     "GladeParentKey", isymbol_variables);
  gtk_widget_show (isymbol_variables);
  gtk_box_pack_start (GTK_BOX (hbox45), isymbol_variables, TRUE, TRUE, 0);
  gtk_combo_set_case_sensitive (GTK_COMBO (isymbol_variables), TRUE);

  isymbol_variables_entry = GTK_COMBO (isymbol_variables)->entry;
  gtk_widget_show (isymbol_variables_entry);
  gtk_editable_set_editable (GTK_EDITABLE (isymbol_variables_entry), FALSE);

  hbox46 = gtk_hbox_new (TRUE, 5);
  gtk_widget_show (hbox46);
  gtk_box_pack_start (GTK_BOX (isymbol_vbox), hbox46, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (hbox46), 2);

  label175 = gtk_label_new (_("Functions List"));
  gtk_widget_show (label175);
  gtk_box_pack_start (GTK_BOX (hbox46), label175, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label175), GTK_JUSTIFY_LEFT);

  isymbol_labels = gtk_combo_new ();
  g_object_set_data (G_OBJECT (GTK_COMBO (isymbol_labels)->popwin),
                     "GladeParentKey", isymbol_labels);
  gtk_widget_show (isymbol_labels);
  gtk_box_pack_start (GTK_BOX (hbox46), isymbol_labels, TRUE, TRUE, 0);
  gtk_combo_set_case_sensitive (GTK_COMBO (isymbol_labels), TRUE);

  isymbol_functions_entry = GTK_COMBO (isymbol_labels)->entry;
  gtk_widget_show (isymbol_functions_entry);
  gtk_editable_set_editable (GTK_EDITABLE (isymbol_functions_entry), FALSE);

  hbox47 = gtk_hbox_new (TRUE, 5);
  gtk_widget_show (hbox47);
  gtk_box_pack_start (GTK_BOX (isymbol_vbox), hbox47, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (hbox47), 2);

  label176 = gtk_label_new (_("Macros List"));
  gtk_widget_show (label176);
  gtk_box_pack_start (GTK_BOX (hbox47), label176, FALSE, FALSE, 0);
  gtk_label_set_justify (GTK_LABEL (label176), GTK_JUSTIFY_LEFT);

  isymbol_macros = gtk_combo_new ();
  g_object_set_data (G_OBJECT (GTK_COMBO (isymbol_macros)->popwin),
                     "GladeParentKey", isymbol_macros);
  gtk_widget_show (isymbol_macros);
  gtk_box_pack_start (GTK_BOX (hbox47), isymbol_macros, TRUE, TRUE, 0);
  gtk_combo_set_case_sensitive (GTK_COMBO (isymbol_macros), TRUE);

  isymbol_macros_entry = GTK_COMBO (isymbol_macros)->entry;
  gtk_widget_show (isymbol_macros_entry);
  gtk_editable_set_editable (GTK_EDITABLE (isymbol_macros_entry), FALSE);

  dialog_action_area1 = GTK_DIALOG (dialog_isymbol)->action_area;
  gtk_widget_show (dialog_action_area1);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (dialog_action_area1), GTK_BUTTONBOX_END);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (dialog_isymbol, dialog_isymbol, "dialog_isymbol");
  GLADE_HOOKUP_OBJECT_NO_REF (dialog_isymbol, dialog_vbox1, "dialog_vbox1");
  GLADE_HOOKUP_OBJECT (dialog_isymbol, isymbol_vbox, "isymbol_vbox");
  GLADE_HOOKUP_OBJECT (dialog_isymbol, label170, "label170");
  GLADE_HOOKUP_OBJECT (dialog_isymbol, hbox44, "hbox44");
  GLADE_HOOKUP_OBJECT (dialog_isymbol, label171, "label171");
  GLADE_HOOKUP_OBJECT (dialog_isymbol, entry1, "entry1");
  GLADE_HOOKUP_OBJECT (dialog_isymbol, hbox45, "hbox45");
  GLADE_HOOKUP_OBJECT (dialog_isymbol, label174, "label174");
  GLADE_HOOKUP_OBJECT (dialog_isymbol, isymbol_variables, "isymbol_variables");
  GLADE_HOOKUP_OBJECT (dialog_isymbol, isymbol_variables_entry, "isymbol_variables_entry");
  GLADE_HOOKUP_OBJECT (dialog_isymbol, hbox46, "hbox46");
  GLADE_HOOKUP_OBJECT (dialog_isymbol, label175, "label175");
  GLADE_HOOKUP_OBJECT (dialog_isymbol, isymbol_labels, "isymbol_labels");
  GLADE_HOOKUP_OBJECT (dialog_isymbol, isymbol_functions_entry, "isymbol_functions_entry");
  GLADE_HOOKUP_OBJECT (dialog_isymbol, hbox47, "hbox47");
  GLADE_HOOKUP_OBJECT (dialog_isymbol, label176, "label176");
  GLADE_HOOKUP_OBJECT (dialog_isymbol, isymbol_macros, "isymbol_macros");
  GLADE_HOOKUP_OBJECT (dialog_isymbol, isymbol_macros_entry, "isymbol_macros_entry");
  GLADE_HOOKUP_OBJECT_NO_REF (dialog_isymbol, dialog_action_area1, "dialog_action_area1");

  gtk_widget_grab_focus (entry1);
  return dialog_isymbol;
}

GtkWidget*
create_dialog_ireg (void)
{
  GtkWidget *dialog_ireg;
  GdkPixbuf *dialog_ireg_icon_pixbuf;
  GtkWidget *dialog_vbox2;
  GtkWidget *ireg;
  GtkWidget *ireg_entry;
  GtkWidget *dialog_action_area2;

  dialog_ireg = gtk_dialog_new_with_buttons (_("Choose a register"),
											 NULL,
											 GTK_DIALOG_MODAL,
											 GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
											 GTK_STOCK_OK, GTK_RESPONSE_OK,
											 NULL);
  gtk_window_set_position (GTK_WINDOW (dialog_ireg), GTK_WIN_POS_MOUSE);
  gtk_window_set_resizable (GTK_WINDOW (dialog_ireg), FALSE);
  dialog_ireg_icon_pixbuf = create_pixbuf ("gnusim8085.svg");
  if (!dialog_ireg_icon_pixbuf)
    dialog_ireg_icon_pixbuf = create_pixbuf ("gnusim8085.ico");

  if (dialog_ireg_icon_pixbuf)
    {
      gtk_window_set_icon (GTK_WINDOW (dialog_ireg), dialog_ireg_icon_pixbuf);
      gdk_pixbuf_unref (dialog_ireg_icon_pixbuf);
    }

  dialog_vbox2 = GTK_DIALOG (dialog_ireg)->vbox;
  gtk_widget_show (dialog_vbox2);

  ireg = gtk_combo_new ();
  g_object_set_data (G_OBJECT (GTK_COMBO (ireg)->popwin),
                     "GladeParentKey", ireg);
  gtk_widget_show (ireg);
  gtk_box_pack_start (GTK_BOX (dialog_vbox2), ireg, FALSE, FALSE, 0);
  gtk_combo_set_value_in_list (GTK_COMBO (ireg), TRUE, FALSE);

  ireg_entry = GTK_COMBO (ireg)->entry;
  gtk_widget_show (ireg_entry);

  dialog_action_area2 = GTK_DIALOG (dialog_ireg)->action_area;
  gtk_widget_show (dialog_action_area2);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (dialog_action_area2), GTK_BUTTONBOX_END);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (dialog_ireg, dialog_ireg, "dialog_ireg");
  GLADE_HOOKUP_OBJECT_NO_REF (dialog_ireg, dialog_vbox2, "dialog_vbox2");
  GLADE_HOOKUP_OBJECT (dialog_ireg, ireg, "ireg");
  GLADE_HOOKUP_OBJECT (dialog_ireg, ireg_entry, "ireg_entry");
  GLADE_HOOKUP_OBJECT_NO_REF (dialog_ireg, dialog_action_area2, "dialog_action_area2");

  return dialog_ireg;
}
