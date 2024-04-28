#include "TextRenderer.h"
#include "Core/Engine/Assets/ImageBank.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"
#include "Font.h"
#include "Core/Engine/Engine.h"

namespace zw
{
    TextRenderer::TextRenderer(Engine& engine) : m_engine(engine)
    {
        TTF_Init();
        auto fontPath = k_relFontsPath + "DefaultFont.ttf";
        auto font20 = std::make_shared<Font>(fontPath, 20);
        auto font30 = std::make_shared<Font>(fontPath, 30);
        auto font50 = std::make_shared<Font>(fontPath, 50);
        m_fonts.insert({ FontSizes::_20, font20 });
        m_fonts.insert({ FontSizes::_30, font30 });
        m_fonts.insert({ FontSizes::_50, font50 });
    }

    void TextRenderer::RenderText(RID rid, const std::string &text, ColorF color, bool centerAlign,
                                  FontSizes fontSize, std::string &outUniqueNameID, SizeF &outSize) const
    {
        // auto font = m_fonts.at(fontSize)->SDLFont();

        // if (!font) 
        //     return;

        // auto colorSDL = color.ToSDLColor();
        // auto outlineColorSDL = k_outlineColor.ToSDLColor();
        // auto textOutlineSurf = TTF_RenderText_Blended(m_fonts.at(fontSize)->OutlineSDLFont().get(),
        //                                               text.c_str(), outlineColorSDL);

        // if (!textOutlineSurf)
        //     return;
        // auto textSurf = TTF_RenderText_Blended(font.get(), text.c_str(), colorSDL);
        // if (!textSurf)
        //     return;
        // glEnable(GL_TEXTURE_2D);
        // auto uniqueNameID = m_uniqueNameIDs.at(rid);
        // auto imgID = _<Engine>().ImageBank()->GetImage(uniqueNameID);
        // glBindTexture(GL_TEXTURE_2D, imgID);
        // // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        // // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // // glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        // // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        // // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        // auto w = textOutlineSurf->w;
        // auto h = textOutlineSurf->h;
        // auto img
        //     = SDL_CreateRGBSurface(SDL_SWSURFACE, w, h, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
        // auto canvSz = GetCanvasSize(m_engine);

        // SDL_Rect textSrcRect;
        // SDL_Rect textOutlineSrcRect;
        // SDL_Rect textDestRect;
        // SDL_Rect textOutlineDestRect;

        // textSrcRect = SDL_Rect{ 0, 0, textSurf ? textSurf->w : 0, textSurf ? textSurf->h : 0 };
        // textOutlineSrcRect = SDL_Rect{ 0, 0, textOutlineSurf ? textOutlineSurf->w : 0,
        //                                textOutlineSurf ? textOutlineSurf->h : 0 };
        // textDestRect = textSrcRect;

        // textDestRect.x += Font::k_fontOutlineWidth;
        // textDestRect.w -= 2 * Font::k_fontOutlineWidth;
        // textDestRect.y += Font::k_fontOutlineWidth;
        // textDestRect.h -= 2 * Font::k_fontOutlineWidth;
        // textOutlineDestRect = textOutlineSrcRect;
        // textOutlineDestRect.y = 1;

        // SDL_BlitSurface(textOutlineSurf, &textOutlineSrcRect, img, &textOutlineDestRect);
        // SDL_BlitSurface(textSurf, &textSrcRect, img, &textDestRect);
        // glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img->w, img->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, img->pixels);
        // auto width = textSurf ? static_cast<float>(textSurf->w) / canvSz.w : 0;
        // auto height = textSurf ? static_cast<float>(textSurf->h) / canvSz.h : 0;
        // outUniqueNameID = uniqueNameID;
        // outSize = { width, height };
        // SDL_FreeSurface(img);
        // SDL_FreeSurface(textSurf);
        // SDL_FreeSurface(textOutlineSurf);
    }

    RID TextRenderer::NewString()
    {
        return -1;
        // static int s_idCounter = 0;
        // auto id = s_idCounter++;
        // auto uniqueName = "RenderedImage" + std::to_string(id);
        // auto ridImage = _<Engine>().ImageBank()->CreateBlankImage(uniqueName);
        // m_uniqueNameIDs.insert({ ridImage, uniqueName });
        // auto ridGLResource = _<ImageRenderer>().NewImage();
        // m_ridsGLResources.insert({ ridImage, ridGLResource });

        // return ridImage;
    }

    void TextRenderer::DrawString(RID rid, const std::string &text, PointF position, ColorF color,
                                  bool centerAlign, FontSizes fontSize)
    {
        // std::string uniqueNameID;
        // SizeF size;
        // RenderText(rid, text, color, centerAlign, fontSize, uniqueNameID, size);
        // auto canvSz = GetCanvasSize(m_engine);
        // auto rect = RectF{ position.x, position.y, size.w, size.h };
        // int text_w;
        // int text_h;
        // TTF_SizeText(m_fonts.at(fontSize)->SDLFont().get(), text.data(), &text_w, &text_h);
        // // rect.h *= GetAspectRatio(_<GraphicsView>()->Window());
        // // rect.y -= static_cast<float>(text_h) / canvSz.h / 2.0f;

        // if (centerAlign)
        // {
        //     rect.x -= static_cast<float>(text_w) / static_cast<float>(canvSz.h) / 2.0f / GetAspectRatio(m_engine);
        //     rect.y -= static_cast<float>(text_h) / static_cast<float>(canvSz.h) / 2.0f;
        // }

        // auto scale = 1.0f;
        // rect.x += rect.w / 2.0f - rect.w / 2.0f * scale;
        // rect.y += rect.h / 2.0f - rect.h / 2.0f * scale;
        // rect.w *= scale;
        // rect.h *= scale;
        // auto ridGLResource = m_ridsGLResources.at(rid);
        // _<ImageRenderer>().DrawImage(ridGLResource, uniqueNameID, rect, false);
    }

    SizeF TextRenderer::MeasureString(const std::string &text, FontSizes fontSize) const
    {
        auto font = m_fonts.at(fontSize)->SDLFont();
        int text_w;
        int text_h;
        TTF_SizeText(font.get(), text.data(), &text_w, &text_h);
        auto canvSz = GetCanvasSize(m_engine);
        return { static_cast<float>(text_w) / canvSz.w, static_cast<float>(text_h) / canvSz.h };
    }
}