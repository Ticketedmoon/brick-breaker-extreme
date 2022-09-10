#include <SFML/Audio.hpp>

class AudioManager {

public:
    static sf::SoundBuffer loadSfxFromFileIntoBuffer(std::string filePath);
};