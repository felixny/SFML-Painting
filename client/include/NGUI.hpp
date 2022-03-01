/**
 *  @file   NGUI.hpp
 *  @brief  Nuklear GUI class interface
 *  @author Team 17
 *  @date   2021-14-12
 ***********************************************/
#ifndef GUI_HPP
#define GUI_HPP

#include <SFML/Graphics.hpp>
#include "App_Client.hpp"

// Forward declarations so we do not have to
// include nuklear library
struct nk_context;
struct nk_colorf;

class NGUI {
public:
    NGUI();
    NGUI(sf::RenderWindow &window);
    ~NGUI();

    struct nk_context *GetContext();
    void DrawGUI(App_Client &app);
    void ClearAndDraw();
    float GetBackgroundAlpha();
    int GetOp();
    void Init();
    sf::RenderWindow &getWindow();
    void Update(sf::Event event);

private:
    struct nk_context *ctx;
    struct nk_colorf *bg;
    sf::RenderWindow *gui_window;
};


#endif
