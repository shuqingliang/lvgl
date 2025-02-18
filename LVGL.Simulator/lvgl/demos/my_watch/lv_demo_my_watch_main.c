/**
 * @file lv_demo_music_main.c
 *
 */

 /*********************
  *      INCLUDES
  *********************/
#include "lv_demo_my_watch_main.h"

  /* 使用宏定义窗口的宽度和高度 */
#define WINDOW_WIDTH  240
#define WINDOW_HEIGHT 280

static lv_obj_t* win1;   // 第一个页面
static lv_obj_t* win2;   // 第二个页面
static lv_obj_t* scr;     // 当前显示的页面

// 定义按钮为全局变量
lv_obj_t* btn1;
lv_obj_t* btn2;

lv_obj_t* label1;
lv_obj_t* label2;
lv_obj_t* label3;
lv_obj_t* label4;

static void btn_event_handler(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* btn = lv_event_get_target(e);  // 获取触发事件的按钮
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        if (btn == btn1) {  // 如果点击的是window1中的按钮
            lv_scr_load_anim(win2, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, false);  // 切换到window2，动画从右向左滑动
        }
        else if (btn == btn2) {  // 如果点击的是window2中的按钮
            lv_scr_load_anim(win1, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0, false);  // 切换到window1，动画从左向右滑动
        }
        break;
    }
    default:
        break;
    }
}

// 页面1创建
void create_window1() {
    /* 创建一个新的窗口 */
    win1 = lv_obj_create(NULL);
    lv_obj_set_size(win1, WINDOW_WIDTH, WINDOW_HEIGHT); /* 设置窗口的大小 */
    lv_obj_align(win1, LV_ALIGN_CENTER, 0, 0); /* 将窗口居中显示 */

    /* 创建一个标题栏 */
    label1 = lv_label_create(win1);
    lv_label_set_text(label1, "This is the 1 Window");
    lv_obj_align(label1, LV_ALIGN_TOP_MID, 0, 10); /* 设置标题的位置 */

    /* 在窗口1中创建一个按键 */
    btn1 = lv_btn_create(win1);
    lv_obj_set_size(btn1, 150, 50);
    lv_obj_align(btn1, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_event_cb(btn1, btn_event_handler, LV_EVENT_CLICKED, NULL);  // 设置按键事件

    label3 = lv_label_create(btn1);
    lv_label_set_text(label3, "Go to Window 2");
}

// 页面2创建
void create_window2() {
    // 创建第二个页面
    //win2 = lv_obj_create(NULL);
    win2 = lv_obj_create(NULL);
    lv_obj_set_size(win2, WINDOW_WIDTH, WINDOW_HEIGHT); /* 设置窗口的大小 */
    lv_obj_align(win2, LV_ALIGN_CENTER, 0, 0); /* 将窗口居中显示 */

    /* 创建一个标题栏 */
    label2 = lv_label_create(win2);
    lv_label_set_text(label2, "This is the 2 Window");
    lv_obj_align(label2, LV_ALIGN_TOP_MID, 0, 10); /* 设置标题的位置 */

    /* 在窗口2中创建一个按键 */
    btn2 = lv_btn_create(win2);  // 确保按钮是新的
    lv_obj_set_size(btn2, 150, 50);
    lv_obj_align(btn2, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_event_cb(btn2, btn_event_handler, LV_EVENT_CLICKED, NULL);  // 设置按键事件

    label4 = lv_label_create(btn2);
    lv_label_set_text(label4, "Go to Window 1");
}

// my_watch_page_switch 函数：创建两个页面并进行页面切换
void my_watch_page_switch(void)
{
    // 创建第一个页面
    create_window1();

    // 创建第二个页面
    create_window2();

    // 设置当前窗口为新创建的窗口
    lv_scr_load(win1);  // 将 win1 设置为当前窗口
}
