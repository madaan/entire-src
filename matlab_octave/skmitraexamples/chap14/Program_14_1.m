     % Program 14_1
     % Frequency Responses of Johnston's QMF Filters
     % Type in prototype lowpass filter coefficients
     B1 = input('Filter coefficients = ');
     B1 = [B1 fliplr(B1)];
     % Generate the complementary highpass filter
     L = length(B1);
     for k = 1:L
          B2(k) = ((-1)^k)*B1(k);
     end
     %  Compute the gain responses of the two filters
     [H1z, w] = freqz(B1, 1, 256);
     h1 = abs(H1z); g1 = 20*log10(h1);
     [H2z, w] = freqz(B2, 1, 256);
     h2 = abs(H2z); g2 = 20*log10(h2);
     %  Plot the gain responses of the two filters
     plot(w/pi, g1,'-',w/pi, g2,'--');grid
     xlabel('\omega/\pi'); ylabel('Gain, dB')
     pause
     % Compute the sum of the squared-magnitude responses
     for i = 1:256,
          sum(i) = (h1(i)*h1(i)) + (h2(i)*h2(i));
     end
     d =10*log10(sum);
     % Plot the amplitude distortion
     plot(w/pi,d);grid;
     xlabel('\omega/\pi'); ylabel('Amplitude distortion, dB')