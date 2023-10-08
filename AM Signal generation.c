%% This code generates an AM signal by modulating a carrier signal with a sinusoidal modulating signal. 
%It then uses the SDL library to play the generated signal.

%%Please make sure you have the SDL2 library installed on your system and 
% linked properly during compilation. Compile the code using a command like:


#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>

// Define constants
#define AMPLITUDE 1.0
#define FREQUENCY_CARRIER 1000.0  // Carrier frequency in Hz
#define FREQUENCY_MODULATING 100.0  // Modulating frequency in Hz
#define SAMPLING_RATE 44100  // Sampling rate in Hz
#define DURATION 2.0  // Duration of the signal in seconds

// Function to generate AM signal
void generate_am_signal(double* signal, int num_samples) {
    double time_step = 1.0 / SAMPLING_RATE;
    double angular_frequency_carrier = 2.0 * M_PI * FREQUENCY_CARRIER;
    double angular_frequency_modulating = 2.0 * M_PI * FREQUENCY_MODULATING;

    for (int i = 0; i < num_samples; i++) {
        double t = i * time_step;
        signal[i] = (1.0 + AMPLITUDE * sin(angular_frequency_modulating * t)) * sin(angular_frequency_carrier * t);
    }
}

int main() {
    int num_samples = (int)(DURATION * SAMPLING_RATE);
    double signal[num_samples];

    generate_am_signal(signal, num_samples);

    // Initialize SDL
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("SDL Initialization failed: %s\n", SDL_GetError());
        return 1;
    }

    // Create an SDL audio spec
    SDL_AudioSpec spec;
    spec.freq = SAMPLING_RATE;
    spec.format = AUDIO_F32;
    spec.channels = 1;
    spec.samples = num_samples;
    spec.callback = NULL;

    // Open an audio device
    SDL_AudioDeviceID device = SDL_OpenAudioDevice(NULL, 0, &spec, NULL, 0);
    if (device == 0) {
        printf("Failed to open audio device: %s\n", SDL_GetError());
        return 1;
    }

    // Play the signal
    SDL_QueueAudio(device, signal, num_samples * sizeof(double));
    SDL_PauseAudioDevice(device, 0);

    // Wait for a while
    SDL_Delay(2000);

    // Clean up and quit
    SDL_CloseAudioDevice(device);
    SDL_Quit();

    return 0;
}


%% gcc -o am_signal_generator am_signal_generator.c -lm -lSDL2
