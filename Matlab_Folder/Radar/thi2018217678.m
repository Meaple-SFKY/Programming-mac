function thi2018217678(T, B, Rmin, Rmax, R, RCS)
if nargin == 0
    T = 10e-6; 
    B = 30e6; 
    Rmin = 10000;
    Rmax = 15000; 
    R = [10500, 11000, 12000, 12008, 13000, 13002];
    RCS=[1 1 1 1 1 1];
end

C = 3e8;
K = B / T; 
Rwid = Rmax - Rmin;
Twid = 2 * Rwid / C;
Fs = 5 * B;
Ts = 1 / Fs;
Nwid = ceil(Twid / Ts);
t = linspace(2 * Rmin / C, 2 * Rmax / C, Nwid); 
td = ones(M, 1) * t - 2 * R / C * ones(1, Nwid);
Srt = RCS * (exp(j * pi * K * td.^2).*(abs(td) < T / 2));
Nchirp = ceil(T / Ts);
Nfft = 2 ^ nextpow2(Nwid + Nwid - 1);
Srw = fft(Srt, Nfft);
t0 = linspace(-T / 2, T / 2, Nchirp); 
St = exp(j * pi * K * t0.^2);
Sw = fft(St, Nfft);
Sot = fftshift(ifft(Srw.*conj(Sw)));
N0 = Nfft / 2 - Nchirp / 2;
Z = abs(Sot(N0 : N0 + Nwid - 1));
Z = Z / max(Z);
Z = 20 * log10(Z + 1e-6);
subplot(211)
plot(t * 1e6, real(Srt));
axis tight ;
xlabel('回波时间/us');
ylabel('幅度')
title('原始回波信号');
subplot(212)
plot(t * C / 2, Z)
axis([10000, 15000, -60, 0]);
xlabel('距离/km');
ylabel('幅度')
title('距离压缩后信号');