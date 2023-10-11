
%Frequency Modulation 

% Parameters
Fs = 1000;      
Fc = 10000;     % Carrier frequency
Am = 1;         % Amplitude of the message signal
Ac = 2;         % Amplitude of the carrier signal
kf = 1;         % Frequency modulation constant

% Time array
t = 0:1/Fs:1;

% Message signal (sinusoidal)
m = Am*sin(2*pi*100*t);

% FM modulation
y = Ac * cos(2*pi*Fc*t + 2*pi*kf*cumsum(m)/Fs);

% Plot the message signal
subplot(2,1,1);
plot(t, m);
title('Message Signal');
xlabel('Time (s)');
ylabel('Amplitude');

% Plot the FM signal
subplot(2,1,2);
plot(t, y);
title('FM Signal');
xlabel('Time (s)');
ylabel('Amplitude');
