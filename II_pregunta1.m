f1 = 100;
a1 = 0.5;
f2 = 500;
a2 = 1.5;
fs = 5000;
t = 0:1/fs:0.1;

tono1 = a1*sin(2*pi*f1*t);
tono2 = a2*sin(2*pi*f2*t);
ruido = sqrt(2) * randn(1, length(t));

x_ruido = tono1 + tono2 + ruido;
x_limpio = tono1 + tono2;

plot(t,x_ruido);
title('Señal suma de Tonos puros más ruido')
ylabel('Amplitud')
xlabel('Tiempo (s)')

%%

X_ruido = fft(x_ruido);
X_limpio = fft(x_limpio);
N = length(x_ruido);
fn = fs*(0:N-1)/N;
plot(fn,(abs(X_ruido)));
hold on
plot(fn,(abs(X_limpio)));
xlim([0 1000]);
title('Magnitud fft señal con y sin ruido')
ylabel('Amplitud')
xlabel('Frecuencia (Hz)')
legend('Señal con ruido', 'Señal sin ruido')

%%

X_ruidoN = X_ruido/max(X_ruido);
X_limpioN = X_limpio/max(X_limpio);

plot(fn, 20*log10(abs(X_ruidoN)));
hold on
plot(fn, 20*log10(abs(X_limpioN)));
xlim([0 1000]);
ylim([-60 0]);

title('Magnitud fft señal con y sin ruido')
ylabel('Amplitud (dB)')
xlabel('Frecuencia (Hz)')
legend('Señal con ruido', 'Señal sin ruido')

%% Cambio a 1s de duracion

t = 0:1/fs:1;

tono1 = a1*sin(2*pi*f1*t);
tono2 = a2*sin(2*pi*f2*t);
ruido = sqrt(2) * randn(1, length(t));

x_ruido = tono1 + tono2 + ruido;
x_limpio = tono1 + tono2;

X_ruido = fft(x_ruido);
X_limpio = fft(x_limpio);
N = length(x_ruido);
fn = fs*(0:N-1)/N;

X_ruidoN = X_ruido/max(X_ruido);
X_limpioN = X_limpio/max(X_limpio);

plot(fn, 20*log10(abs(X_ruidoN)));
hold on
plot(fn, 20*log10(abs(X_limpioN)));
xlim([0 1000]);
ylim([-60 0]);

title('Magnitud fft señal con y sin ruido')
ylabel('Amplitud (dB)')
xlabel('Frecuencia (Hz)')
legend('Señal con ruido', 'Señal sin ruido')