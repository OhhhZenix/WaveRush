#include "FontManager.hpp"
#include <string>
#include <vector>
#include <sstream>

FontManager::~FontManager()
{
    if (m_FontList.empty())
        return;

    for (std::pair<std::string, TTF_Font *>f_Member : m_FontList)
    {
        if (f_Member.second)
            TTF_CloseFont(f_Member.second);
    }
}

void FontManager::LoadFont(const char* p_Path)
{
    // Open font
    TTF_Font *f_Font = TTF_OpenFont(p_Path, 64);

    if (!f_Font)
    {
        std::cout << "[Font] \""<< p_Path << "\" not found.\n";
        return;
    }

    // Tokenize to get the name
    std::stringstream f_Tokenizer(p_Path);
    std::string f_Filename;
    while (getline(f_Tokenizer, f_Filename, '/'));
    
    std::cout << f_Filename << " stored.\n";

    m_FontList.emplace(f_Filename, f_Font);
}

TTF_Font *FontManager::GetFont(const std::string& p_FontName)
{
    TTF_Font *f_Font = m_FontList.at(p_FontName);
    if (f_Font)
    {
        std::cout << "[Font] \"" << p_FontName << "\" found.";
        return f_Font;
    }

    std::cout << "[Font] \"" << p_FontName << "\" Is not stored.";
    return nullptr;
}