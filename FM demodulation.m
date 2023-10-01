% FM demodulation
delta_phi = diff(unwrap(angle(y)));   % Phase difference
m_demod = diff(delta_phi * Fs/(2*pi*kf)); % Demodulated signal

% Plot the demodulated signal
figure;
plot(t(2:end), m_demod);
title('Demodulated Signal');
xlabel('Time (s)');
ylabel('Amplitude');
