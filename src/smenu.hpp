/*============================================================================
Copyright (c) 2024 Raspberry Pi Holdings Ltd.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the copyright holder nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================*/

#ifndef WIDGETS_SMENU_HPP
#define WIDGETS_SMENU_HPP

#include <widget.hpp>
#include <gtkmm/button.h>

extern "C" {
#include <menu-cache.h>
#include <libfm/fm-gtk.h>
#include "smenu.h"
extern void menu_init (MenuPlugin *m);
extern void menu_update_display (MenuPlugin *m);
extern void menu_set_padding (MenuPlugin *m);
extern void menu_show_menu (MenuPlugin *m);
extern void menu_destructor (gpointer user_data);
}

class WayfireSmenu : public WayfireWidget
{
    std::unique_ptr <Gtk::Button> plugin;

    WfOption <int> icon_size {"panel/icon_size"};
    WfOption <std::string> bar_pos {"panel/position"};
    sigc::connection icon_timer;

    WfOption <int> padding {"panel/smenu_padding"};
    WfOption <int> search_height {"panel/smenu_search_height"};
    WfOption <bool> search_fixed {"panel/smenu_search_fixed"};

    /* plugin */
    MenuPlugin *m;

  public:

    void init (Gtk::HBox *container) override;
    void command (const char *cmd) override;
    virtual ~WayfireSmenu ();
    void icon_size_changed_cb (void);
    void bar_pos_changed_cb (void);
    void search_param_changed_cb (void);
    void padding_changed_cb (void);
    bool set_icon (void);
};

#endif /* end of include guard: WIDGETS_SMENU_HPP */

/* End of file */
/*----------------------------------------------------------------------------*/
