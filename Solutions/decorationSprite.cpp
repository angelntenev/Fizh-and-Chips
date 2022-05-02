#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>
#include "decorationSprite.h"



DecorationSprite DecorationSprite::getDecoration(Vector2f loc, DecorationSprite decorationSprite, bool isRockOrSeaweed)
{
    if (isRockOrSeaweed == false)
    {
        decorationSprite.setTexture(spritesheetSeaWeed);
        decorationSprite.setTextureRect(IntRect(Vector2(0, 0), Vector2(64, 64)));
        decorationSprite.setOrigin(Vector2f(32, 32));
    }
    decorationSprite.setPosition(loc);
    return decorationSprite;
}

std::vector<DecorationSprite> DecorationSprite::allDecorations(std::vector<DecorationSprite> _decorations)
{
    return _decorations;
}

DecorationSprite::DecorationSprite(bool rockORseaweed)
{
    if (rockORseaweed == false)
    {
        setTexture(spritesheetSeaWeed);
        setTextureRect(IntRect(Vector2(0, 0), Vector2(64, 64)));
        setOrigin(Vector2f(32, 32));
    }
}