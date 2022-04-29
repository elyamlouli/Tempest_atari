#ifndef AUDIO
#define AUDIO

#include <string>

// Third Party
#include <SDL.h> 

// Interface for Audio
class ISound{
    public:
        // Destructor is virtual for our interface
        virtual ~ISound() {};
        // Member functions that should be implemented
        virtual void PlaySound() = 0;
        virtual void StopSound() = 0;
};

class Sound : public ISound{

    public:
        // Constructor
        Sound(std::string filepath);
        // Destructor
        ~Sound();
        // PlaySound
        void PlaySound();
        // Stop the sound
        void StopSound();
        // Specific to SDL_Audio API
        void SetupDevice();

    private: 
        SDL_AudioDeviceID m_device;
        SDL_AudioSpec m_audioSpec;
        Uint8*        m_waveStart;
        Uint32        m_waveLength;
};

#endif