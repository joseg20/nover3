senal = load('fft_analysis.mat');
close all;
fs = 1000; % senal.Fs;
distorted = senal.distorted;
modulation1 = senal.modulation1;
modulation2 = senal.modulation2;
t = (0:length(modulation2)-1) / fs;
figure;
plot(t,modulation2)
hold on
plot(t,modulation1)
%xlim([0 1])

plot(t,modulation1)
w = window(@rectwin, length(modulation1));
m1_w = modulation1.*w;

M1 = fft(m1_w);
M1s = fftshift(M1);
N = length(m1_w);
fn = fs*(0:N-1)/N;
figure;
plot(fn,20*log10(abs(M1s)));

m2_w = modulation2.*w;

M2 = fft(m2_w);
M2s = fftshift(M2);
N = length(m2_w);
fn = fs*(0:N-1)/N;
figure;
plot(fn,20*log10(abs(M2s)));
