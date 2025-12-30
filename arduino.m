clc
clear

port = "COM4";    % <-- BURAYI DEGISTIR
baud = 9600;

s = serialport(port, baud);
configureTerminator(s, "LF");

disp("Arduino'dan veri aliniyor...")

while true
    satir = readline(s);      % Arduino'dan gelen satir
    parca = split(satir, ",");

    if numel(parca) == 2
        sicaklik = str2double(parca(1));
        nem = str2double(parca(2));

        fprintf("Sicaklik: %.2f C | Nem: %.2f %%\n", sicaklik, nem);
    end

    pause(2)
end