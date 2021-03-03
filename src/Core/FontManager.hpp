#pragma once

#include "Core/PCH.hpp"
#include <unordered_map>


class FontManager{

    private:
        std::unordered_map<std::string, TTF_Font*> m_FontList;

    public:
        ~FontManager();

        void LoadFont(const char *p_Path);

        TTF_Font *GetFont(const std::string& p_FontName);
};