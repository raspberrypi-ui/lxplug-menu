#ifndef WIDGETS_SMENU_HPP
#define WIDGETS_SMENU_HPP

#include <widget.hpp>
#include <gtkmm/button.h>

extern "C" {
#include <menu-cache.h>
#include <libfm/fm-gtk.h>
#include "menu.h"
extern void menu_init (MenuPlugin *m);
extern void menu_update_display (MenuPlugin *m);
extern void menu_show_menu (MenuPlugin *m);
extern void menu_destructor (gpointer user_data);
}

class WayfireSmenu : public WayfireWidget
{
    std::unique_ptr <Gtk::Button> plugin;

    WfOption <int> icon_size {"panel/icon_size"};
    WfOption <std::string> bar_pos {"panel/position"};
    WfOption <int> padding {"panel/smenu_padding"};
    WfOption <int> search_height {"panel/smenu_search_height"};
    WfOption <bool> search_fixed {"panel/smenu_search_fixed"};
    sigc::connection icon_timer;

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
