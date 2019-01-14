/**
 *  Copyright (C) 2017 3D Repo Ltd
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
//------------------------------------------------------------------------------
#include <QIcon>
#include <QIconEngine>
#include <QPainter>
#include <QRect>
#include <QVariantMap>
#include <QPalette>
#include <QBrush>
#include <QRawFont>
#include <QPainterPath>
#include <QDebug>
#include <QFile>
#include <QFontDatabase>

#include <iostream>
//------------------------------------------------------------------------------

namespace repo {

class RepoMaterialIcons : public QObject
{
    Q_OBJECT

private:

    //! Singleton constructor
    RepoMaterialIcons(QObject *parent = nullptr);

    //! Singleton destructor
    ~RepoMaterialIcons() {}

    //! Singleton copy constructor
    RepoMaterialIcons(const RepoMaterialIcons &);

    //! Singleton comparison
    void operator = (RepoMaterialIcons const&);

public:

    //--------------------------------------------------------------------------
    //
    // Getters
    //
    //--------------------------------------------------------------------------

    //! Returns a singleton instance of the RepoFontAwesome class.
    static RepoMaterialIcons &getInstance();

    //--------------------------------------------------------------------------

    static QIcon getMenuIcon(const QColor &color = QColor(Qt::white))
    {
        return getIconStatic(0xE5D2, color);
    }

    static QIcon getMoreVertIcon(const QColor &color = QColor(Qt::white))
    {
        return getIconStatic(0xE5D4, color);
    }

    static QIcon getAddIcon(const QColor &color = QColor(Qt::white))
    {
        return getIconStatic(0xE145, color);
    }

    static QIcon getPersonIcon(const QColor &color = QColor(Qt::white))
    {
        return getIconStatic(0xE7FD, color);
    }

    static QIcon getPeopleIcon(const QColor &color = QColor(Qt::white))
    {
        return getIconStatic(0xE7EF, color);
    }

    static QIcon getBusinessIcon(const QColor &color = QColor(Qt::white))
    {
        return getIconStatic(0xE0AF, color);
    }

    static QIcon getAccountCircleIcon(const QColor &color = QColor(Qt::white))
    {
        return getIconStatic(0xE853, color);
    }

    static QIcon getAccountBoxIcon(const QColor &color = QColor(Qt::white))
    {
        return getIconStatic(0xE851, color);
    }

    static QIcon getArrowBackIcon(const QColor &color = QColor(Qt::white))
    {
        return getIconStatic(0xE5C4, color);
    }

    static QIcon getNotificationsNoneIcon(const QColor &color = QColor(Qt::white))
    {
        return getIconStatic(0xE7F5, color);
    }

    static QIcon getClearIcon(const QColor &color = QColor(Qt::white))
    {
        return getIconStatic(0xE5CD, color);
    }

    static QIcon getSearchIcon(const QColor &color = QColor(Qt::white))
    {
        return getIconStatic(0xE8B6, color);
    }

    static QIcon getAssignmentIcon(const QColor &color = QColor(Qt::white))
    {
        return getIconStatic(0xE85D, color);
    }

    static QIcon getEmailIcon(const QColor &color = QColor(Qt::white))
    {
        return getIconStatic(0xE0BE, color);
    }

    static QIcon getDeleteIcon(const QColor &color = QColor(Qt::white))
    {
        return getIconStatic(0xE872, color);
    }


//    //! Returns commit icon.
//    static QIcon getCommitIcon()
//    {
//        return getIconStatic(volume_off); /*getInstance().getIcon(
//                    RepoMaterialIcons::fa_upload, QColor(Qt::darkGreen));*/
//    }

    //--------------------------------------------------------------------------

    QIcon getIcon(int iconOn);
    QIcon getIcon(int iconOn, const QColor &color);
    QIcon getIcon(int iconOn, int iconOff);

    //! Returns icon in a static way.
    //    static QIcon getIconStatic(int iconOn)
    //    { return RepoFontAwesome::getInstance().getIcon(iconOn); }

    static QIcon getIconStatic(int hex, const QColor &color = QColor(Qt::black))
    {
        return getInstance().getIcon(hex, color);
    }

    /*!
            * Returns a font with a given size in pixels.
            */
    QFont getFont(int size);

    //! Returns a pointer to the raw font for glyphs extraction.
    QRawFont *getRawFont();

    //! Returns a glyph index in raw font for given icon unicode character.
    quint32 getGlyphIndex(int icon);

    //! Returns a painter path for given icon unicode character.
    QPainterPath getPainterPath(int icon);

    //! Returns the font-name that is used as an icon-map
    inline QString getFontName() { return fontName; }

    static QColor COLOR_NORMAL;
    static QColor COLOR_DISABLED;
    static QColor COLOR_ACTIVE;
    static QColor COLOR_SELECTED;

private:

    QString fontName; //!< Global font name

    QRawFont *rawFont; //! Raw font to extract individual glyphs

public:

    //--------------------------------------------------------------------------       
    // http://zavoloklom.github.io/material-design-iconic-font/cheatsheet.html
    // Font based on version 2.2.0
    // See also https://materialdesignicons.com/cheatsheet
    enum Icons
    {
        _3d_rotation = 0xf101,
        airplane_off = 0xf102,
        airplane = 0xf103,
        album = 0xf104,
        archive = 0xf105,
        assignment_account = 0xf106,
        assignment_alert = 0xf107,
        assignment_check = 0xf108,
        assignment_o = 0xf109,
        assignment_return = 0xf10a,
        assignment_returned = 0xf10b,
        assignment = 0xf10c,
        attachment_alt = 0xf10d,
        attachment = 0xf10e,
        audio = 0xf10f,
        badge_check = 0xf110,
        balance_wallet = 0xf111,
        balance = 0xf112,
        battery_alert = 0xf113,
        battery_flash = 0xf114,
        battery_unknown = 0xf115,
        battery = 0xf116,
        bike = 0xf117,
        block_alt = 0xf118,
        block = 0xf119,
        boat = 0xf11a,
        book_image = 0xf11b,
        book = 0xf11c,
        bookmark_outline = 0xf11d,
        bookmark = 0xf11e,
        brush = 0xf11f,
        bug = 0xf120,
        bus = 0xf121,
        cake = 0xf122,
        car_taxi = 0xf123,
        car_wash = 0xf124,
        car = 0xf125,
        card_giftcard = 0xf126,
        card_membership = 0xf127,
        card_travel = 0xf128,
        card = 0xf129,
        case_check = 0xf12a,
        case_download = 0xf12b,
        case_play = 0xf12c,
        case_ = 0xf12d,
        cast_connected = 0xf12e,
        cast = 0xf12f,
        chart_donut = 0xf130,
        chart = 0xf131,
        city_alt = 0xf132,
        city = 0xf133,
        close_circle_o = 0xf134,
        close_circle = 0xf135,
        close = 0xf136,
        cocktail = 0xf137,
        code_setting = 0xf138,
        code_smartphone = 0xf139,
        code = 0xf13a,
        coffee = 0xf13b,
        collection_bookmark = 0xf13c,
        collection_case_play = 0xf13d,
        collection_folder_image = 0xf13e,
        collection_image_o = 0xf13f,
        collection_image = 0xf140,
        collection_item_1 = 0xf141,
        collection_item_2 = 0xf142,
        collection_item_3 = 0xf143,
        collection_item_4 = 0xf144,
        collection_item_5 = 0xf145,
        collection_item_6 = 0xf146,
        collection_item_7 = 0xf147,
        collection_item_8 = 0xf148,
        collection_item_9_plus = 0xf149,
        collection_item_9 = 0xf14a,
        collection_item = 0xf14b,
        collection_music = 0xf14c,
        collection_pdf = 0xf14d,
        collection_plus = 0xf14e,
        collection_speaker = 0xf14f,
        collection_text = 0xf150,
        collection_video = 0xf151,
        compass = 0xf152,
        cutlery = 0xf153,
        delete_ = 0xf154,
        dialpad = 0xf155,
        dns = 0xf156,
        drink = 0xf157,
        edit = 0xf158,
        email_open = 0xf159,
        email = 0xf15a,
        eye_off = 0xf15b,
        eye = 0xf15c,
        eyedropper = 0xf15d,
        favorite_outline = 0xf15e,
        favorite = 0xf15f,
        filter_list = 0xf160,
        fire = 0xf161,
        flag = 0xf162,
        flare = 0xf163,
        flash_auto = 0xf164,
        flash_off = 0xf165,
        flash = 0xf166,
        flip = 0xf167,
        flower_alt = 0xf168,
        flower = 0xf169,
        font = 0xf16a,
        fullscreen_alt = 0xf16b,
        fullscreen_exit = 0xf16c,
        fullscreen = 0xf16d,
        functions = 0xf16e,
        gas_station = 0xf16f,
        gesture = 0xf170,
        globe_alt = 0xf171,
        globe_lock = 0xf172,
        globe = 0xf173,
        graduation_cap = 0xf174,
        group = 0xf3e9,
        home = 0xf175,
        hospital_alt = 0xf176,
        hospital = 0xf177,
        hotel = 0xf178,
        hourglass_alt = 0xf179,
        hourglass_outline = 0xf17a,
        hourglass = 0xf17b,
        http = 0xf17c,
        image_alt = 0xf17d,
        image_o = 0xf17e,
        image = 0xf17f,
        inbox = 0xf180,
        invert_colors_off = 0xf181,
        invert_colors = 0xf182,
        key = 0xf183,
        label_alt_outline = 0xf184,
        label_alt = 0xf185,
        label_heart = 0xf186,
        label = 0xf187,
        labels = 0xf188,
        lamp = 0xf189,
        landscape = 0xf18a,
        layers_off = 0xf18b,
        layers = 0xf18c,
        library = 0xf18d,
        link = 0xf18e,
        lock_open = 0xf18f,
        lock_outline = 0xf190,
        lock = 0xf191,
        mail_reply_all = 0xf192,
        mail_reply = 0xf193,
        mail_send = 0xf194,
        mall = 0xf195,
        map = 0xf196,
        menu = 0xf197,
        money_box = 0xf198,
        money_off = 0xf199,
        money = 0xf19a,
        more_vert = 0xf19b,
        more = 0xf19c,
        movie_alt = 0xf19d,
        movie = 0xf19e,
        nature_people = 0xf19f,
        nature = 0xf1a0,
        navigation = 0xf1a1,
        open_in_browser = 0xf1a2,
        open_in_new = 0xf1a3,
        palette = 0xf1a4,
        parking = 0xf1a5,
        pin_account = 0xf1a6,
        pin_assistant = 0xf1a7,
        pin_drop = 0xf1a8,
        pin_help = 0xf1a9,
        pin_off = 0xf1aa,
        pin = 0xf1ab,
        pizza = 0xf1ac,
        plaster = 0xf1ad,
        power_setting = 0xf1ae,
        power = 0xf1af,
        print = 0xf1b0,
        puzzle_piece = 0xf1b1,
        quote = 0xf1b2,
        railway = 0xf1b3,
        receipt = 0xf1b4,
        refresh_alt = 0xf1b5,
        refresh_sync_alert = 0xf1b6,
        refresh_sync_off = 0xf1b7,
        refresh_sync = 0xf1b8,
        refresh = 0xf1b9,
        roller = 0xf1ba,
        ruler = 0xf1bb,
        scissors = 0xf1bc,
        screen_rotation_lock = 0xf1bd,
        screen_rotation = 0xf1be,
        search_for = 0xf1bf,
        search_in_file = 0xf1c0,
        search_in_page = 0xf1c1,
        search_replace = 0xf1c2,
        search = 0xf1c3,
        seat = 0xf1c4,
        settings_square = 0xf1c5,
        settings = 0xf1c6,
        shape = 0xf3eb,
        shield_check = 0xf1c7,
        shield_security = 0xf1c8,
        shopping_basket = 0xf1c9,
        shopping_cart_plus = 0xf1ca,
        shopping_cart = 0xf1cb,
        sign_in = 0xf1cc,
        sort_amount_asc = 0xf1cd,
        sort_amount_desc = 0xf1ce,
        sort_asc = 0xf1cf,
        sort_desc = 0xf1d0,
        spellcheck = 0xf1d1,
        spinner = 0xf3ec,
        storage = 0xf1d2,
        store_24 = 0xf1d3,
        store = 0xf1d4,
        subway = 0xf1d5,
        sun = 0xf1d6,
        tab_unselected = 0xf1d7,
        tab = 0xf1d8,
        tag_close = 0xf1d9,
        tag_more = 0xf1da,
        tag = 0xf1db,
        thumb_down = 0xf1dc,
        thumb_up_down = 0xf1dd,
        thumb_up = 0xf1de,
        ticket_star = 0xf1df,
        toll = 0xf1e0,
        toys = 0xf1e1,
        traffic = 0xf1e2,
        translate = 0xf1e3,
        triangle_down = 0xf1e4,
        triangle_up = 0xf1e5,
        truck = 0xf1e6,
        turning_sign = 0xf1e7,
        ungroup = 0xf3ed,
        wallpaper = 0xf1e8,
        washing_machine = 0xf1e9,
        window_maximize = 0xf1ea,
        window_minimize = 0xf1eb,
        window_restore = 0xf1ec,
        wrench = 0xf1ed,
        zoom_in = 0xf1ee,
        zoom_out = 0xf1ef,
        alert_circle_o = 0xf1f0,
        alert_circle = 0xf1f1,
        alert_octagon = 0xf1f2,
        alert_polygon = 0xf1f3,
        alert_triangle = 0xf1f4,
        help_outline = 0xf1f5,
        help = 0xf1f6,
        info_outline = 0xf1f7,
        info = 0xf1f8,
        notifications_active = 0xf1f9,
        notifications_add = 0xf1fa,
        notifications_none = 0xf1fb,
        notifications_off = 0xf1fc,
        notifications_paused = 0xf1fd,
        notifications = 0xf1fe,
        account_add = 0xf1ff,
        account_box_mail = 0xf200,
        account_box_o = 0xf201,
        account_box_phone = 0xf202,
        account_box = 0xf203,
        account_calendar = 0xf204,
        account_circle = 0xf205,
        account_o = 0xf206,
        account = 0xf207,
        accounts_add = 0xf208,
        accounts_alt = 0xf209,
        accounts_list_alt = 0xf20a,
        accounts_list = 0xf20b,
        accounts_outline = 0xf20c,
        accounts = 0xf20d,
        face = 0xf20e,
        female = 0xf20f,
        male_alt = 0xf210,
        male_female = 0xf211,
        male = 0xf212,
        mood_bad = 0xf213,
        mood = 0xf214,
        run = 0xf215,
        walk = 0xf216,
        cloud_box = 0xf217,
        cloud_circle = 0xf218,
        cloud_done = 0xf219,
        cloud_download = 0xf21a,
        cloud_off = 0xf21b,
        cloud_outline_alt = 0xf21c,
        cloud_outline = 0xf21d,
        cloud_upload = 0xf21e,
        cloud = 0xf21f,
        download = 0xf220,
        file_plus = 0xf221,
        file_text = 0xf222,
        file = 0xf223,
        folder_outline = 0xf224,
        folder_person = 0xf225,
        folder_star_alt = 0xf226,
        folder_star = 0xf227,
        folder = 0xf228,
        gif = 0xf229,
        upload = 0xf22a,
        border_all = 0xf22b,
        border_bottom = 0xf22c,
        border_clear = 0xf22d,
        border_color = 0xf22e,
        border_horizontal = 0xf22f,
        border_inner = 0xf230,
        border_left = 0xf231,
        border_outer = 0xf232,
        border_right = 0xf233,
        border_style = 0xf234,
        border_top = 0xf235,
        border_vertical = 0xf236,
        copy = 0xf237,
        crop = 0xf238,
        format_align_center = 0xf239,
        format_align_justify = 0xf23a,
        format_align_left = 0xf23b,
        format_align_right = 0xf23c,
        format_bold = 0xf23d,
        format_clear_all = 0xf23e,
        format_clear = 0xf23f,
        format_color_fill = 0xf240,
        format_color_reset = 0xf241,
        format_color_text = 0xf242,
        format_indent_decrease = 0xf243,
        format_indent_increase = 0xf244,
        format_italic = 0xf245,
        format_line_spacing = 0xf246,
        format_list_bulleted = 0xf247,
        format_list_numbered = 0xf248,
        format_ltr = 0xf249,
        format_rtl = 0xf24a,
        format_size = 0xf24b,
        format_strikethrough_s = 0xf24c,
        format_strikethrough = 0xf24d,
        format_subject = 0xf24e,
        format_underlined = 0xf24f,
        format_valign_bottom = 0xf250,
        format_valign_center = 0xf251,
        format_valign_top = 0xf252,
        redo = 0xf253,
        select_all = 0xf254,
        space_bar = 0xf255,
        text_format = 0xf256,
        transform = 0xf257,
        undo = 0xf258,
        wrap_text = 0xf259,
        comment_alert = 0xf25a,
        comment_alt_text = 0xf25b,
        comment_alt = 0xf25c,
        comment_edit = 0xf25d,
        comment_image = 0xf25e,
        comment_list = 0xf25f,
        comment_more = 0xf260,
        comment_outline = 0xf261,
        comment_text_alt = 0xf262,
        comment_text = 0xf263,
        comment_video = 0xf264,
        comment = 0xf265,
        comments = 0xf266,
        check_all = 0xf267,
        check_circle_u = 0xf268,
        check_circle = 0xf269,
        check_square = 0xf26a,
        check = 0xf26b,
        circle_o = 0xf26c,
        circle = 0xf26d,
        dot_circle_alt = 0xf26e,
        dot_circle = 0xf26f,
        minus_circle_outline = 0xf270,
        minus_circle = 0xf271,
        minus_square = 0xf272,
        minus = 0xf273,
        plus_circle_o_duplicate = 0xf274,
        plus_circle_o = 0xf275,
        plus_circle = 0xf276,
        plus_square = 0xf277,
        plus = 0xf278,
        square_o = 0xf279,
        star_circle = 0xf27a,
        star_half = 0xf27b,
        star_outline = 0xf27c,
        star = 0xf27d,
        bluetooth_connected = 0xf27e,
        bluetooth_off = 0xf27f,
        bluetooth_search = 0xf280,
        bluetooth_setting = 0xf281,
        bluetooth = 0xf282,
        camera_add = 0xf283,
        camera_alt = 0xf284,
        camera_bw = 0xf285,
        camera_front = 0xf286,
        camera_mic = 0xf287,
        camera_party_mode = 0xf288,
        camera_rear = 0xf289,
        camera_roll = 0xf28a,
        camera_switch = 0xf28b,
        camera = 0xf28c,
        card_alert = 0xf28d,
        card_off = 0xf28e,
        card_sd = 0xf28f,
        card_sim = 0xf290,
        desktop_mac = 0xf291,
        desktop_windows = 0xf292,
        device_hub = 0xf293,
        devices_off = 0xf294,
        devices = 0xf295,
        dock = 0xf296,
        floppy = 0xf297,
        gamepad = 0xf298,
        gps_dot = 0xf299,
        gps_off = 0xf29a,
        gps = 0xf29b,
        headset_mic = 0xf29c,
        headset = 0xf29d,
        input_antenna = 0xf29e,
        input_composite = 0xf29f,
        input_hdmi = 0xf2a0,
        input_power = 0xf2a1,
        input_svideo = 0xf2a2,
        keyboard_hide = 0xf2a3,
        keyboard = 0xf2a4,
        laptop_chromebook = 0xf2a5,
        laptop_mac = 0xf2a6,
        laptop = 0xf2a7,
        mic_off = 0xf2a8,
        mic_outline = 0xf2a9,
        mic_setting = 0xf2aa,
        mic = 0xf2ab,
        mouse = 0xf2ac,
        network_alert = 0xf2ad,
        network_locked = 0xf2ae,
        network_off = 0xf2af,
        network_outline = 0xf2b0,
        network_setting = 0xf2b1,
        network = 0xf2b2,
        phone_bluetooth = 0xf2b3,
        phone_end = 0xf2b4,
        phone_forwarded = 0xf2b5,
        phone_in_talk = 0xf2b6,
        phone_locked = 0xf2b7,
        phone_missed = 0xf2b8,
        phone_msg = 0xf2b9,
        phone_paused = 0xf2ba,
        phone_ring = 0xf2bb,
        phone_setting = 0xf2bc,
        phone_sip = 0xf2bd,
        phone = 0xf2be,
        portable_wifi_changes = 0xf2bf,
        portable_wifi_off = 0xf2c0,
        portable_wifi = 0xf2c1,
        radio = 0xf2c2,
        reader = 0xf2c3,
        remote_control_alt = 0xf2c4,
        remote_control = 0xf2c5,
        router = 0xf2c6,
        scanner = 0xf2c7,
        smartphone_android = 0xf2c8,
        smartphone_download = 0xf2c9,
        smartphone_erase = 0xf2ca,
        smartphone_info = 0xf2cb,
        smartphone_iphone = 0xf2cc,
        smartphone_landscape_lock = 0xf2cd,
        smartphone_landscape = 0xf2ce,
        smartphone_lock = 0xf2cf,
        smartphone_portrait_lock = 0xf2d0,
        smartphone_ring = 0xf2d1,
        smartphone_setting = 0xf2d2,
        smartphone_setup = 0xf2d3,
        smartphone = 0xf2d4,
        speaker = 0xf2d5,
        tablet_android = 0xf2d6,
        tablet_mac = 0xf2d7,
        tablet = 0xf2d8,
        tv_alt_play = 0xf2d9,
        tv_list = 0xf2da,
        tv_play = 0xf2db,
        tv = 0xf2dc,
        usb = 0xf2dd,
        videocam_off = 0xf2de,
        videocam_switch = 0xf2df,
        videocam = 0xf2e0,
        watch = 0xf2e1,
        wifi_alt_2 = 0xf2e2,
        wifi_alt = 0xf2e3,
        wifi_info = 0xf2e4,
        wifi_lock = 0xf2e5,
        wifi_off = 0xf2e6,
        wifi_outline = 0xf2e7,
        wifi = 0xf2e8,
        arrow_left_bottom = 0xf2e9,
        arrow_left = 0xf2ea,
        arrow_merge = 0xf2eb,
        arrow_missed = 0xf2ec,
        arrow_right_top = 0xf2ed,
        arrow_right = 0xf2ee,
        arrow_split = 0xf2ef,
        arrows = 0xf2f0,
        caret_down_circle = 0xf2f1,
        caret_down = 0xf2f2,
        caret_left_circle = 0xf2f3,
        caret_left = 0xf2f4,
        caret_right_circle = 0xf2f5,
        caret_right = 0xf2f6,
        caret_up_circle = 0xf2f7,
        caret_up = 0xf2f8,
        chevron_down = 0xf2f9,
        chevron_left = 0xf2fa,
        chevron_right = 0xf2fb,
        chevron_up = 0xf2fc,
        forward = 0xf2fd,
        long_arrow_down = 0xf2fe,
        long_arrow_left = 0xf2ff,
        long_arrow_return = 0xf300,
        long_arrow_right = 0xf301,
        long_arrow_tab = 0xf302,
        long_arrow_up = 0xf303,
        rotate_ccw = 0xf304,
        rotate_cw = 0xf305,
        rotate_left = 0xf306,
        rotate_right = 0xf307,
        square_down = 0xf308,
        square_right = 0xf309,
        swap_alt = 0xf30a,
        swap_vertical_circle = 0xf30b,
        swap_vertical = 0xf30c,
        swap = 0xf30d,
        trending_down = 0xf30e,
        trending_flat = 0xf30f,
        trending_up = 0xf310,
        unfold_less = 0xf311,
        unfold_more = 0xf312,
        apps = 0xf313,
        grid_off = 0xf314,
        grid = 0xf315,
        view_agenda = 0xf316,
        view_array = 0xf317,
        view_carousel = 0xf318,
        view_column = 0xf319,
        view_comfy = 0xf31a,
        view_compact = 0xf31b,
        view_dashboard = 0xf31c,
        view_day = 0xf31d,
        view_headline = 0xf31e,
        view_list_alt = 0xf31f,
        view_list = 0xf320,
        view_module = 0xf321,
        view_quilt = 0xf322,
        view_stream = 0xf323,
        view_subtitles = 0xf324,
        view_toc = 0xf325,
        view_web = 0xf326,
        view_week = 0xf327,
        widgets = 0xf328,
        alarm_check = 0xf329,
        alarm_off = 0xf32a,
        alarm_plus = 0xf32b,
        alarm_snooze = 0xf32c,
        alarm = 0xf32d,
        calendar_alt = 0xf32e,
        calendar_check = 0xf32f,
        calendar_close = 0xf330,
        calendar_note = 0xf331,
        calendar = 0xf332,
        time_countdown = 0xf333,
        time_interval = 0xf334,
        time_restore_setting = 0xf335,
        time_restore = 0xf336,
        time = 0xf337,
        timer_off = 0xf338,
        timer = 0xf339,
        android_alt = 0xf33a,
        android = 0xf33b,
        apple = 0xf33c,
        behance = 0xf33d,
        codepen = 0xf33e,
        dribbble = 0xf33f,
        dropbox = 0xf340,
        evernote = 0xf341,
        facebook_box = 0xf342,
        facebook = 0xf343,
        github_box = 0xf344,
        github = 0xf345,
        google_drive = 0xf346,
        google_earth = 0xf347,
        google_glass = 0xf348,
        google_maps = 0xf349,
        google_pages = 0xf34a,
        google_play = 0xf34b,
        google_plus_box = 0xf34c,
        google_plus = 0xf34d,
        google = 0xf34e,
        instagram = 0xf34f,
        language_css3 = 0xf350,
        language_html5 = 0xf351,
        language_javascript = 0xf352,
        language_python_alt = 0xf353,
        language_python = 0xf354,
        lastfm = 0xf355,
        linkedin_box = 0xf356,
        paypal = 0xf357,
        pinterest_box = 0xf358,
        pocket = 0xf359,
        polymer = 0xf35a,
        rss = 0xf3ea,
        share = 0xf35b,
        stackoverflow = 0xf35c,
        steam_square = 0xf35d,
        steam = 0xf35e,
        twitter_box = 0xf35f,
        twitter = 0xf360,
        vk = 0xf361,
        wikipedia = 0xf362,
        windows = 0xf363,
        _500px = 0xf3ee,
        _8tracks = 0xf3ef,
        amazon = 0xf3f0,
        blogger = 0xf3f1,
        delicious = 0xf3f2,
        disqus = 0xf3f3,
        flattr = 0xf3f4,
        flickr = 0xf3f5,
        github_alt = 0xf3f6,
        google_old = 0xf3f7,
        linkedin = 0xf3f8,
        odnoklassniki = 0xf3f9,
        outlook = 0xf3fa,
        paypal_alt = 0xf3fb,
        pinterest = 0xf3fc,
        playstation = 0xf3fd,
        reddit = 0xf3fe,
        skype = 0xf3ff,
        slideshare = 0xf400,
        soundcloud = 0xf401,
        tumblr = 0xf402,
        twitch = 0xf403,
        vimeo = 0xf404,
        whatsapp = 0xf405,
        xbox = 0xf406,
        yahoo = 0xf407,
        youtube_play = 0xf408,
        youtube = 0xf409,
        aspect_ratio_alt = 0xf364,
        aspect_ratio = 0xf365,
        blur_circular = 0xf366,
        blur_linear = 0xf367,
        blur_off = 0xf368,
        blur = 0xf369,
        brightness_2 = 0xf36a,
        brightness_3 = 0xf36b,
        brightness_4 = 0xf36c,
        brightness_5 = 0xf36d,
        brightness_6 = 0xf36e,
        brightness_7 = 0xf36f,
        brightness_auto = 0xf370,
        brightness_setting = 0xf371,
        broken_image = 0xf372,
        center_focus_strong = 0xf373,
        center_focus_weak = 0xf374,
        compare = 0xf375,
        crop_16_9 = 0xf376,
        crop_3_2 = 0xf377,
        crop_5_4 = 0xf378,
        crop_7_5 = 0xf379,
        crop_din = 0xf37a,
        crop_free = 0xf37b,
        crop_landscape = 0xf37c,
        crop_portrait = 0xf37d,
        crop_square = 0xf37e,
        exposure_alt = 0xf37f,
        exposure = 0xf380,
        filter_b_and_w = 0xf381,
        filter_center_focus = 0xf382,
        filter_frames = 0xf383,
        filter_tilt_shift = 0xf384,
        gradient = 0xf385,
        grain = 0xf386,
        graphic_eq = 0xf387,
        hdr_off = 0xf388,
        hdr_strong = 0xf389,
        hdr_weak = 0xf38a,
        hdr = 0xf38b,
        iridescent = 0xf38c,
        leak_off = 0xf38d,
        leak = 0xf38e,
        looks = 0xf38f,
        loupe = 0xf390,
        panorama_horizontal = 0xf391,
        panorama_vertical = 0xf392,
        panorama_wide_angle = 0xf393,
        photo_size_select_large = 0xf394,
        photo_size_select_small = 0xf395,
        picture_in_picture = 0xf396,
        slideshow = 0xf397,
        texture = 0xf398,
        tonality = 0xf399,
        vignette = 0xf39a,
        wb_auto = 0xf39b,
        eject_alt = 0xf39c,
        eject = 0xf39d,
        equalizer = 0xf39e,
        fast_forward = 0xf39f,
        fast_rewind = 0xf3a0,
        forward_10 = 0xf3a1,
        forward_30 = 0xf3a2,
        forward_5 = 0xf3a3,
        hearing = 0xf3a4,
        pause_circle_outline = 0xf3a5,
        pause_circle = 0xf3a6,
        pause = 0xf3a7,
        play_circle_outline = 0xf3a8,
        play_circle = 0xf3a9,
        play = 0xf3aa,
        playlist_audio = 0xf3ab,
        playlist_plus = 0xf3ac,
        repeat_one = 0xf3ad,
        repeat = 0xf3ae,
        replay_10 = 0xf3af,
        replay_30 = 0xf3b0,
        replay_5 = 0xf3b1,
        replay = 0xf3b2,
        shuffle = 0xf3b3,
        skip_next = 0xf3b4,
        skip_previous = 0xf3b5,
        stop = 0xf3b6,
        surround_sound = 0xf3b7,
        tune = 0xf3b8,
        volume_down = 0xf3b9,
        volume_mute = 0xf3ba,
        volume_off = 0xf3bb,
        volume_up = 0xf3bc,
        n_1_square = 0xf3bd,
        n_2_square = 0xf3be,
        n_3_square = 0xf3bf,
        n_4_square = 0xf3c0,
        n_5_square = 0xf3c1,
        n_6_square = 0xf3c2,
        neg_1 = 0xf3c3,
        neg_2 = 0xf3c4,
        plus_1 = 0xf3c5,
        plus_2 = 0xf3c6,
        sec_10 = 0xf3c7,
        sec_3 = 0xf3c8,
        zero = 0xf3c9,
        airline_seat_flat_angled = 0xf3ca,
        airline_seat_flat = 0xf3cb,
        airline_seat_individual_suite = 0xf3cc,
        airline_seat_legroom_extra = 0xf3cd,
        airline_seat_legroom_normal = 0xf3ce,
        airline_seat_legroom_reduced = 0xf3cf,
        airline_seat_recline_extra = 0xf3d0,
        airline_seat_recline_normal = 0xf3d1,
        airplay = 0xf3d2,
        closed_caption = 0xf3d3,
        confirmation_number = 0xf3d4,
        developer_board = 0xf3d5,
        disc_full = 0xf3d6,
        explicit_ = 0xf3d7,
        flight_land = 0xf3d8,
        flight_takeoff = 0xf3d9,
        flip_to_back = 0xf3da,
        flip_to_front = 0xf3db,
        group_work = 0xf3dc,
        hd = 0xf3dd,
        hq = 0xf3de,
        markunread_mailbox = 0xf3df,
        memory = 0xf3e0,
        nfc = 0xf3e1,
        play_for_work = 0xf3e2,
        power_input = 0xf3e3,
        present_to_all = 0xf3e4,
        satellite = 0xf3e5,
        tap_and_play = 0xf3e6,
        vibration = 0xf3e7,
        voicemail = 0xf3e8
    };

}; // end class


class RepoIconEngine : public QIconEngine
{
public:

    RepoIconEngine(
            RepoMaterialIcons* awesome,
            const QChar& iconOn,
            const QChar& iconOff,
            const QColor& colorActive = RepoMaterialIcons::COLOR_NORMAL)
        : materialIcons(awesome)
        , iconOn(iconOn)
        , iconOff(iconOff)
        , colorActive(colorActive) {}


    virtual ~RepoIconEngine() {}

    RepoIconEngine* clone() const
    {
        return new RepoIconEngine(
                    materialIcons,
                    iconOn,
                    iconOff,
                    colorActive);
    }

    virtual void paint(QPainter* painter,
                       const QRect& rect,
                       QIcon::Mode mode,
                       QIcon::State state)
    {
        painter->save();
        QChar icon;
        QColor color;

        if (state == QIcon::On)
            icon = iconOn;
        else if (state == QIcon::Off)
            icon = iconOff;

        switch (mode)
        {
        case QIcon::Normal:
            color = colorActive;
            break;
        case QIcon::Disabled:
            color = QColor(70,70,70,60);
            break;
        case QIcon::Active:
            color = colorActive;
            break;
        case QIcon::Selected:
            color = QColor(10,10,10);
            break;
        }

        painter->setFont(materialIcons->getFont(qRound(rect.height() * 0.9f)));
        painter->setPen(color);
        painter->drawText(rect, icon,
                          QTextOption(Qt::AlignCenter | Qt::AlignVCenter));
        painter->restore();
    }

    virtual QPixmap pixmap(
            const QSize &size,
            QIcon::Mode mode,
            QIcon::State state)
    {
        QPixmap pixMap(size);
        pixMap.fill(Qt::transparent);
        {
            QPainter painter(&pixMap);
            paint(&painter, QRect(QPoint(0, 0), size), mode, state);
        }
        return pixMap;
    }

private:

    RepoMaterialIcons* materialIcons;
    QChar iconOn;
    QChar iconOff;
    QColor colorActive;

}; // end class

}

