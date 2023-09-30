% Amplitude Modulation (AM) 
% Define parameters
Fs = 1000; % Sampling frequency (Hz)
t = 0:1/Fs:1; % Time vector (1 second duration)
Fc = 100; % Carrier frequency (Hz)
Fm = 10; % Modulating frequency (Hz)
Am = 1; % Modulating amplitude

% Generate modulating signal (message signal)
m = Am * cos(2*pi*Fm*t);

% Generate carrier signal
c = cos(2*pi*Fc*t);

% Perform amplitude modulation
AM_signal = (1 + m) .* c;

% Plot signals
figure;
subplot(3,1,1);
plot(t, m);
title('Modulating Signal');
xlabel('Time (s)');
ylabel('Amplitude');

subplot(3,1,2);
plot(t, c);
title('Carrier Signal');
xlabel('Time (s)');
ylabel('Amplitude');

subplot(3,1,3);
plot(t, AM_signal);
title('AM Signal');
xlabel('Time (s)');
ylabel('Amplitude');

% Frequency domain representation
N = length(AM_signal);
f = linspace(-Fs/2, Fs/2, N);

AM_signal_fft = fftshift(fft(AM_signal)/N);

figure;
plot(f, abs(AM_signal_fft));
title('Frequency Domain Representation');
xlabel('Frequency (Hz)');
ylabel('Amplitude');

