#include "audio_manager.hpp"
#include <stdlib.h>
#include <iostream>

sf::SoundBuffer AudioManager::loadSfxFromFileIntoBuffer(std::string filePath) {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(filePath)) {
        throw std::runtime_error("SFX failed to load for path " + filePath);
    }
    return buffer;
}