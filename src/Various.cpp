#include "Various.hpp"

namespace wp
{
    std::string Various::oneWayCrypt(std::string const& str, unsigned int l)
    {
        if (str.size() == 0)
            return str;
        std::string result;
        const int size = str.size();
        const int key1 = str[0]%str[str[(895289981+l)%size]%size]+1;
        const int key2 = str[str[(189289529+l)%size]%size]%str[str[(368279989+l)%size]%size]+1;
        const int key3 = str[str[(816528975+l)%size]%size]%str[str[(757398241+l)%size]%size]+1;
        for (int i = 0;i<l;i++)
            result += "0";
        uint64_t totalNumber = 0;
        for (int i = 0;i<size;i++)
            totalNumber += str[i];

        for (int i = 0;i<std::max(size, (int)l);i++)
        {
            uint64_t c = str[i%size];
            c += (key1+key2)/2;
            c %= key1+key2+key3;
            c *= i*std::max(std::max(key1, key2), key3);
            c /= std::min(std::min(key1, key2), key3);
            c += totalNumber%(key1*key2*key3);
            result[i%l] -= (key1+key2+key3)%(c%150+1);
            result[i%l] += c;
        }
        return result;
    }
    std::string Various::crypt(std::string const& str, std::string const& key)
    {
        long keyI = 0;
        for (int i = 0;i<key.size();i++)
        {
            if (i%2)
                keyI += i*key[i];
            else
                keyI -= i*key[i];
        }
        int added = (str.size()%5)*10;
        std::string result;
        unsigned char precCar = 0, car;
        for (int i = 0;i<str.size();i++)
        {
            car = str[i];
            car += precCar - 45 + added - keyI + i%5*(modulo(keyI, (long)5*i*pow(-1, i)));
            precCar = car;
            std::string hex = decToHex(car);
            if (hex.size() < 2)
                hex = "0" + hex;
            result += hex;
        }
        return result;
    }
    std::string Various::uncrypt(std::string const& code, std::string const& key)
    {
        long keyI = 0;
        for (int i = 0;i<key.size();i++)
        {
            if (i%2)
                keyI += i*key[i];
            else
                keyI -= i*key[i];
        }
        if (code.size()%2 == 1)
            return std::string();
        std::string result;
        unsigned char precCar = 0, car;
        std::string newStr;
        for (int i = 0;i<code.size();i+=2)
        {
            std::string caractere;
            caractere += code[i];
            caractere += code[i+1];
            newStr += (unsigned char)hexToDec(caractere);
        }
        int added = (newStr.size()%5)*10;
        for (int i = 0;i<newStr.size();i++)
        {
            car = newStr[i];
            car -= precCar - 45 + added - keyI + i%5*(modulo(keyI, (long)5*i*pow(-1, i)));
            precCar = newStr[i];
            result += car;
        }
        return result;
    }
    double Various::getAngle(sf::Vector2f const& vec)
    {
        sf::Vector2f vec2 = vec;
        double angle = 0;
        if (vec.x < 0 && -vec.y >= 0)
        {
            angle = 90;
            vec2.y = -vec.x;
            vec2.x = -vec.y;
        }
        else if (-vec.y < 0 && vec.x < 0)
        {
            angle = 180;
            vec2.x = -vec.x;
            vec2.y = vec.y;
        }
        else if (-vec.y < 0 && vec.x >= 0)
        {
            angle = 270;
            vec2.y = vec.x;
            vec2.x = vec.y;
        }
        else
            vec2.y *= -1;
        if (vec2.y == 0)
            return 0;
        angle += atan(vec2.y/vec2.x)*180/PI;

        return angle;
    }
    std::string Various::getMouseKey(sf::Mouse::Button key)
    {
        switch (key)
        {
        case sf::Mouse::Left:
            return "Mouse1";
            break;
        case sf::Mouse::Middle:
            return "Mouse3";
            break;
        case sf::Mouse::Right:
            return "Mouse2";
            break;
        case sf::Mouse::XButton1:
            return "Mouse4";
            break;
        case sf::Mouse::XButton2:
            return "Mouse5";
            break;
        }
        return "";
    }
    std::string Various::getKeyboardKey(sf::Keyboard::Key key)
    {
        switch (key)
        {
        case sf::Keyboard::A:
            return "A";
            break;
        case sf::Keyboard::Add:
            return "Add";
            break;
        case sf::Keyboard::B:
            return "B";
            break;
        case sf::Keyboard::BackSlash:
            return "BackSlash";
            break;
        case sf::Keyboard::BackSpace:
            return "BackSpace";
            break;
        case sf::Keyboard::C:
            return "C";
            break;
        case sf::Keyboard::Comma:
            return "Comma";
            break;
        case sf::Keyboard::D:
            return "D";
            break;
        case sf::Keyboard::Dash:
            return "Dash";
            break;
        case sf::Keyboard::Delete:
            return "Delete";
            break;
        case sf::Keyboard::Divide:
            return "Divide";
            break;
        case sf::Keyboard::Down:
            return "Down";
            break;
        case sf::Keyboard::E:
            return "E";
            break;
        case sf::Keyboard::End:
            return "End";
            break;
        case sf::Keyboard::Equal:
            return "Equal";
            break;
        case sf::Keyboard::Escape:
            return "Escape";
            break;
        case sf::Keyboard::F:
            return "F";
            break;
        case sf::Keyboard::F1:
            return "F1";
            break;
        case sf::Keyboard::F10:
            return "F10";
            break;
        case sf::Keyboard::F11:
            return "F11";
            break;
        case sf::Keyboard::F12:
            return "F12";
            break;
        case sf::Keyboard::F13:
            return "F13";
            break;
        case sf::Keyboard::F14:
            return "F14";
            break;
        case sf::Keyboard::F15:
            return "F1";
            break;
        case sf::Keyboard::F2:
            return "F2";
            break;
        case sf::Keyboard::F3:
            return "F3";
            break;
        case sf::Keyboard::F4:
            return "F4";
            break;
        case sf::Keyboard::F5:
            return "F5";
            break;
        case sf::Keyboard::F6:
            return "F6";
            break;
        case sf::Keyboard::F7:
            return "F7";
            break;
        case sf::Keyboard::F8:
            return "F8";
            break;
        case sf::Keyboard::F9:
            return "F9";
            break;
        case sf::Keyboard::G:
            return "G";
            break;
        case sf::Keyboard::H:
            return "H";
            break;
        case sf::Keyboard::Home:
            return "Home";
            break;
        case sf::Keyboard::I:
            return "I";
            break;
        case sf::Keyboard::Insert:
            return "Insert";
            break;
        case sf::Keyboard::J:
            return "J";
            break;
        case sf::Keyboard::K:
            return "K";
            break;
        case sf::Keyboard::L:
            return "L";
            break;
        case sf::Keyboard::LAlt:
            return "LAlt";
            break;
        case sf::Keyboard::LBracket:
            return "LBracket";
            break;
        case sf::Keyboard::LControl:
            return "LControl";
            break;
        case sf::Keyboard::Left:
            return "Left";
            break;
        case sf::Keyboard::LShift:
            return "LShift";
            break;
        case sf::Keyboard::LSystem:
            return "LSystem";
            break;
        case sf::Keyboard::M:
            return "M";
            break;
        case sf::Keyboard::Menu:
            return "Menu";
            break;
        case sf::Keyboard::Multiply:
            return "Multiply";
            break;
        case sf::Keyboard::N:
            return "N";
            break;
        case sf::Keyboard::Num0:
            return "Num0";
            break;
        case sf::Keyboard::Num1:
            return "Num1";
            break;
        case sf::Keyboard::Num2:
            return "Num2";
            break;
        case sf::Keyboard::Num3:
            return "Num3";
            break;
        case sf::Keyboard::Num4:
            return "Num4";
            break;
        case sf::Keyboard::Num5:
            return "Num5";
            break;
        case sf::Keyboard::Num6:
            return "Num6";
            break;
        case sf::Keyboard::Num7:
            return "Num7";
            break;
        case sf::Keyboard::Num8:
            return "Num8";
            break;
        case sf::Keyboard::Num9:
            return "Num9";
            break;
        case sf::Keyboard::Numpad0:
            return "Numpad0";
            break;
        case sf::Keyboard::Numpad1:
            return "Numpad1";
            break;
        case sf::Keyboard::Numpad2:
            return "Numpad2";
            break;
        case sf::Keyboard::Numpad3:
            return "Numpad3";
            break;
        case sf::Keyboard::Numpad4:
            return "Numpad4";
            break;
        case sf::Keyboard::Numpad5:
            return "Numpad5";
            break;
        case sf::Keyboard::Numpad6:
            return "Numpad6";
            break;
        case sf::Keyboard::Numpad7:
            return "Numpad7";
            break;
        case sf::Keyboard::Numpad8:
            return "Numpad8";
            break;
        case sf::Keyboard::Numpad9:
            return "Numpad9";
            break;
        case sf::Keyboard::O:
            return "O";
            break;
        case sf::Keyboard::P:
            return "P";
            break;
        case sf::Keyboard::PageDown:
            return "PageDown";
            break;
        case sf::Keyboard::PageUp:
            return "PageUp";
            break;
        case sf::Keyboard::Pause:
            return "Pause";
            break;
        case sf::Keyboard::Period:
            return "Period";
            break;
        case sf::Keyboard::Q:
            return "Q";
            break;
        case sf::Keyboard::Quote:
            return "Quote";
            break;
        case sf::Keyboard::R:
            return "R";
            break;
        case sf::Keyboard::RAlt:
            return "RAlt";
            break;
        case sf::Keyboard::RBracket:
            return "RBracket";
            break;
        case sf::Keyboard::RControl:
            return "RControl";
            break;
        case sf::Keyboard::Return:
            return "Return";
            break;
        case sf::Keyboard::Right:
            return "Right";
            break;
        case sf::Keyboard::RShift:
            return "RShift";
            break;
        case sf::Keyboard::RSystem:
            return "RSystem";
            break;
        case sf::Keyboard::S:
            return "S";
            break;
        case sf::Keyboard::SemiColon:
            return "SemiColon";
            break;
        case sf::Keyboard::Slash:
            return "Slash";
            break;
        case sf::Keyboard::Space:
            return "Space";
            break;
        case sf::Keyboard::Subtract:
            return "Subtract";
            break;
        case sf::Keyboard::T:
            return "T";
            break;
        case sf::Keyboard::Tab:
            return "Tab";
            break;
        case sf::Keyboard::Tilde:
            return "Tilde";
            break;
        case sf::Keyboard::U:
            return "U";
            break;
        case sf::Keyboard::Unknown:
            return "Unknown";
            break;
        case sf::Keyboard::Up:
            return "Up";
            break;
        case sf::Keyboard::V:
            return "V";
            break;
        case sf::Keyboard::W:
            return "W";
            break;
        case sf::Keyboard::X:
            return "X";
            break;
        case sf::Keyboard::Y:
            return "Y";
            break;
        case sf::Keyboard::Z:
            return "Z";
            break;
        }
        return "";
    }
    double Various::modulo(double nb, double mod)
    {
        int frac = nb/mod;
        nb -= frac*mod;
        if (nb < 0)
            nb += mod;
        return nb;
    }
    double Various::randomDouble(double min, double max)
    {
        double nb = rand();
        nb /= (double)RAND_MAX;
        return linearInter(min, max, nb);
    }
    sf::Image Various::loadImageFromResource(const std::string& name)
    {
        HRSRC rsrcData = FindResource(nullptr, name.c_str(), RT_RCDATA);
        if (!rsrcData)
            return sf::Image();

        DWORD rsrcDataSize = SizeofResource(nullptr, rsrcData);
        if (rsrcDataSize <= 0)
            return sf::Image();

        HGLOBAL grsrcData = LoadResource(nullptr, rsrcData);
        if (!grsrcData)
            return sf::Image();

        LPVOID firstByte = LockResource(grsrcData);
        if (!firstByte)
            return sf::Image();

        sf::Image image;
        if (!image.loadFromMemory(firstByte, rsrcDataSize))
            return sf::Image();

        return image;
    }
    sf::Font Various::loadFontFromResource(const std::string& name)
    {
        HRSRC rsrcData = FindResource(nullptr, name.c_str(), RT_RCDATA);
        if (!rsrcData)
            return sf::Font();

        DWORD rsrcDataSize = SizeofResource(nullptr, rsrcData);
        if (rsrcDataSize <= 0)
            return sf::Font();

        HGLOBAL grsrcData = LoadResource(nullptr, rsrcData);
        if (!grsrcData)
            return sf::Font();

        LPVOID firstByte = LockResource(grsrcData);
        if (!firstByte)
            return sf::Font();

        sf::Font font;
        if (!font.loadFromMemory(firstByte, rsrcDataSize))
            return sf::Font();

        return font;
    }
    sf::SoundBuffer Various::loadSoundFromResource(const std::string& name)
    {
        HRSRC rsrcData = FindResource(nullptr, name.c_str(), RT_RCDATA);
        if (!rsrcData)
            return sf::SoundBuffer();

        DWORD rsrcDataSize = SizeofResource(nullptr, rsrcData);
        if (rsrcDataSize <= 0)
            return sf::SoundBuffer();

        HGLOBAL grsrcData = LoadResource(nullptr, rsrcData);
        if (!grsrcData)
            return sf::SoundBuffer();

        LPVOID firstByte = LockResource(grsrcData);
        if (!firstByte)
            return sf::SoundBuffer();

        sf::SoundBuffer sound;
        if (!sound.loadFromMemory(firstByte, rsrcDataSize))
            return sf::SoundBuffer();

        return sound;
    }

    std::string Various::loadStringFromResource(const std::string& name)
    {
        HRSRC rsrcData = FindResource(nullptr, name.c_str(), RT_RCDATA);
        if (!rsrcData)
            return std::string();

        DWORD rsrcDataSize = SizeofResource(nullptr, rsrcData);
        if (rsrcDataSize <= 0)
            return std::string();

        HGLOBAL grsrcData = LoadResource(nullptr, rsrcData);
        if (!grsrcData)
            return std::string();

        LPVOID firstByte = LockResource(grsrcData);
        if (!firstByte)
            return std::string();

        std::string string;
        for (int i = 0;i<rsrcDataSize;i++)
            string += *(char*)(firstByte + i);

        return string;
    }


    bool Various::shapeCollision(sf::Vector2f pt, sf::ConvexShape const& shape, sf::Vector2f infinitePoint)
    {
        if (shape.getPointCount() < 3)
            return false;
        int i;
        int nbintersections = 0;
        for(i=0;i<shape.getPointCount();i++)
        {
         sf::Vector2f A = shape.getPoint(i);
         sf::Vector2f B;
         if (i==shape.getPointCount()-1)
             B = shape.getPoint(0);
         else
             B = shape.getPoint(i+1);
         int iseg;
         {
            sf::Vector2f D,E;
            D = B - A;
            E = pt - infinitePoint;
            double denom = D.x*E.y - D.y*E.x;
            double t = - (A.x*E.y-infinitePoint.x*E.y-E.x*A.y+E.x*infinitePoint.y) / denom;
            double u = - (-D.x*A.y+D.x*infinitePoint.y+D.y*A.x-D.y*infinitePoint.x) / denom;
            if (denom==0)
            {
                iseg = -1;
            }
            else if (t<0 || t>=1)
                iseg = 0;
            else if (u<0 || u>=1)
                iseg = 0;
            else
                iseg = 1;
         }
         if (iseg == -1)
             return shapeCollision(pt, shape, infinitePoint);
         nbintersections+=iseg;
        }
        if (nbintersections%2==1)
         return true;
        else
         return false;
    }
    bool Various::shapeCollision(sf::Vector2f pt, std::vector<sf::Vector2f> const& shape, sf::Vector2f infinitePoint)
    {
        if (shape.size() < 3)
            return false;
        int i;
        int nbintersections = 0;
        for(i=0;i<shape.size();i++)
        {
         sf::Vector2f A = shape[i];
         sf::Vector2f B;
         if (i==shape.size()-1)
             B = shape[0];
         else
             B = shape[i+1];
         int iseg;
         {
            sf::Vector2f D,E;
            D = B - A;
            E = pt - infinitePoint;
            double denom = D.x*E.y - D.y*E.x;
            double t = - (A.x*E.y-infinitePoint.x*E.y-E.x*A.y+E.x*infinitePoint.y) / denom;
            double u = - (-D.x*A.y+D.x*infinitePoint.y+D.y*A.x-D.y*infinitePoint.x) / denom;
            if (denom==0)
            {
                iseg = -1;
            }
            else if (t<0 || t>=1)
                iseg = 0;
            else if (u<0 || u>=1)
                iseg = 0;
            else
                iseg = 1;
         }
         if (iseg == -1)
             return shapeCollision(pt, shape, infinitePoint);
         nbintersections+=iseg;
        }
        if (nbintersections%2==1)
         return true;
        else
         return false;
    }
    bool Various::segmentCollision(sf::Vector2f A, sf::Vector2f B, sf::Vector2f I, sf::Vector2f P)
    {
        sf::Vector2f D,E;
        D.x = B.x - A.x;
        D.y = B.y - A.y;
        E.x = P.x - I.x;
        E.y = P.y - I.y;
        double denom = D.x*E.y - D.y*E.x;
        if (denom==0)
           return false;
        double t = - (A.x*E.y-I.x*E.y-E.x*A.y+E.x*I.y) / denom;
        if (t<0 || t>=1)
          return false;
        double u = - (-D.x*A.y+D.x*I.y+D.y*A.x-D.y*I.x) / denom;
        if (u<0 || u>=1)
          return false;
        return true;
    }
    void Various::copyToClipboard(const std::string& str)
    {
        if(OpenClipboard(nullptr))
        {
            HGLOBAL h;
            EmptyClipboard();
            h = GlobalAlloc(GHND, str.size() + 1);
            if(h)
            {
                char *p = (char*)GlobalLock(h);
                if(p)
                {
                    strcpy(p, str.c_str());
                    GlobalUnlock(h);
                    SetClipboardData(CF_TEXT, h);
                }
                GlobalFree(h);
            }
            CloseClipboard();
        }
    }
    std::string Various::getClipboardContent()
    {
        char* s;
        if(OpenClipboard(nullptr))
        {
            std::string str;
            HANDLE h = GetClipboardData(CF_TEXT);
            if(h)
            {
                s = (char*)GlobalLock(h);
                GlobalUnlock(h);
                CloseClipboard();
                str = s;
            }
            CloseClipboard();
            return str;
        }
        else
            return "";
    }
}
