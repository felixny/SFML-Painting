/**
 *  @file   NGUI.cpp
 *  @brief  Nuklear GUI class
 *  @author Team 17
 *  @date   2021-14-12
 ***********************************************/

#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include "NGUI.hpp"
#include "nuklear.h"
#include "nuklear_sfml_gl2.h"

nk_context *NGUI::GetContext() {
    return ctx;
}

/*! \brief  Constructor for gui. Parameter is the SFML window
 *          it will be bound to.
 *
 */
NGUI::NGUI(sf::RenderWindow &window) {
    // Set up the drawing of the Nuklear GUI
    glViewport(0, 0, window.getSize().x, window.getSize().y);
    // Set our context equal to the window that
    // we are going to render to
    ctx = nk_sfml_init(&window);
    // Load Fonts: if none of these are loaded a default font will be used
    //Load Cursor: if you uncomment cursor loading please hide the cursor
    struct nk_font_atlas *atlas;
    nk_sfml_font_stash_begin(&atlas);
    nk_sfml_font_stash_end();
    // Set up a color for the nuklear gui
    bg = (nk_colorf *) malloc(sizeof(nk_colorf));
    bg->r = 0.745f;
    bg->g = 0.89f;
    bg->b = 1.0f;
    bg->a = 1.0f;

}

/*! \brief  Destructor; safely shuts down Nuklear
 *
 */
NGUI::~NGUI() {
    // Free our struct for the background color
    free(bg);
    // Shut down nuklear safely
    nk_sfml_shutdown();
}


/*! \brief  Initializes GUI window.
 *
 */
void NGUI::Init() {
    sf::ContextSettings settings(24, 8, 4, 2, 2);
    gui_window = new sf::RenderWindow(sf::VideoMode(200, 400), "GUI Window", sf::Style::Default, settings);
    gui_window->setVerticalSyncEnabled(true);
    gui_window->setActive(true);

}

/*! \brief  Getter for private variable. Returns the window gui is drawn to
 *
 */
sf::RenderWindow &NGUI::getWindow() { return *gui_window; }

/*! \brief  Renders the gui. Parameter is the app instance linked
 *          to this gui window. Button presses send color
 *          changes/undo/redo to the App window.
 *
 */
void NGUI::DrawGUI(App_Client &app) {

    // GUI
    if (nk_begin(ctx, "Toolbar", nk_rect(28, 25, 145, 355),
                 NK_WINDOW_MOVABLE | NK_TEXT_CENTERED)) {

        static int property = 20;


        nk_layout_row_dynamic(ctx, 35, 2);
        if (nk_button_label(ctx, "black")) {
            app.request_black_color();
            bg->r = 0.0f;
            bg->g = 0.0f;
            bg->b = 0.0f;
        }
        if (nk_button_label(ctx, "white")) {
            app.request_white_color();
            bg->r = 1.0f;
            bg->g = 1.0f;
            bg->b = 1.0f;
        }
        if (nk_button_label(ctx, "red")) {
            app.request_red_color();
            bg->r = 1.0f;
            bg->g = 0.0f;
            bg->b = 0.0f;
        }
        if (nk_button_label(ctx, "green")) {
            app.request_green_color();
            bg->r = 0.0f;
            bg->g = 1.0f;
            bg->b = 0.0f;
        }
        if (nk_button_label(ctx, "blue")) {
            app.request_blue_color();
            bg->r = 0.0f;
            bg->g = 0.0f;
            bg->b = 1.0f;
        }
        if (nk_button_label(ctx, "yellow")) {
            app.request_yellow_color();
            bg->r = 1.0f;
            bg->g = 1.0f;
            bg->b = 0.0f;
        }
        if (nk_button_label(ctx, "magenta")) {
            app.request_magenta_color();
            bg->r = 1.0f;
            bg->g = 0.0f;
            bg->b = 1.0f;
        }
        if (nk_button_label(ctx, "cyan")) {
            app.request_cyan_color();
            bg->r = 0.0f;
            bg->g = 1.0f;
            bg->b = 1.0f;
        }

        nk_layout_row_dynamic(ctx, 35, 1);
        if (nk_button_label(ctx, "Undo")) {
            app.request_undo();
        }
        if (nk_button_label(ctx, "Redo")) {
            app.request_redo();
        }
        if (nk_button_label(ctx, "Clear Canvas")) {
            app.request_canvas_color();
        }

        if (nk_button_label(ctx, "Chat")) {
            app.request_chat();
        }

    }
    nk_end(ctx);
}

/*! \brief  Clears GUI window, used during loop.
 *
 */
void NGUI::ClearAndDraw() {
    glClearColor(bg->r, bg->g, bg->b, bg->a);
    glClear(GL_COLOR_BUFFER_BIT);
    nk_sfml_render(NK_ANTI_ALIASING_ON);
}

/*! \brief  Returns alpha value of the background color of the
 *          gui window.
 *
 */
float NGUI::GetBackgroundAlpha() {
    return bg->a;
}

/*! \brief  Handles events for the GUI window during the loop.
 *
 */
void NGUI::Update(sf::Event event) {
    nk_input_begin(GetContext());
    while (gui_window->pollEvent(event)) {
        // Our close event.
        // Note: We only have a 'minimize' button
        //       in our window right now, so this event is not
        //       going to fire.
        if (event.type == sf::Event::Closed) {
            gui_window->close();
            exit(EXIT_SUCCESS);
        }

            // Capture any keys that are released
        else if (event.type == sf::Event::KeyReleased) {
            // Check if the escape key is pressed.
            if (event.key.code == sf::Keyboard::Escape) {
                gui_window->close();
                exit(EXIT_SUCCESS);
            }
        }
        //else if(event.type == sf::Event::Resized){
        //    glViewport(0, 0, event.size.width, event.size.height);
        //}
        nk_sfml_handle_event(&event);
    }
}
