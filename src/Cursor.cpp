#include "Cursor.hpp"

using namespace wp;

void Cursor::setCursorID(uint8_t id)
{
    switch (id)
    {
    case WAIT_LOADING:
        curs = LoadCursor(nullptr, IDC_WAIT);
        break;
    case BACK_LOADING:
        curs = LoadCursor(nullptr, IDC_APPSTARTING);
        break;
    case ARROW:
        curs = LoadCursor(nullptr, IDC_ARROW);
        break;
    case CROSS:
        curs = LoadCursor(nullptr, IDC_CROSS);
        break;
    case CLICK:
        curs = LoadCursor(nullptr, IDC_HAND);
        break;
    case HELP:
        curs = LoadCursor(nullptr, IDC_HELP);
        break;
    case TEXT_SELECT:
        curs = LoadCursor(nullptr, IDC_IBEAM);
        break;
    case UNABLE:
        curs = LoadCursor(nullptr, IDC_NO);
        break;
    case SIZE_ALL:
        curs = LoadCursor(nullptr, IDC_SIZEALL);
        break;
    case SIZE_TOPLEFT_BOTRIGHT:
        curs = LoadCursor(nullptr, IDC_SIZENWSE);
        break;
    case SIZE_TOP_BOT:
        curs = LoadCursor(nullptr, IDC_SIZENS);
        break;
    case SIZE_LEFT_RIGHT:
        curs = LoadCursor(nullptr, IDC_SIZEWE);
        break;
    case SIZE_TOPRIGHT_BOTLEFT:
        curs = LoadCursor(nullptr, IDC_SIZENESW);
        break;
    case UP_ARROW:
        curs = LoadCursor(nullptr, IDC_UPARROW);
        break;
    }
}
void Cursor::setCursorFromFile(sf::String const& filename)
{
    curs = LoadCursorFromFile((LPSTR)filename.toUtf8().c_str());
}
void Cursor::apply(sf::Window const& window) const
{
    SetClassLongPtr(window.getSystemHandle(), GCLP_HCURSOR, reinterpret_cast<LONG_PTR>(curs));
}
